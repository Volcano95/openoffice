/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



// MARKER(update_precomp.py): autogen include statement, do not remove
#include "precompiled_xmloff.hxx"
#include <tools/debug.hxx>
#include <xmloff/xmlimp.hxx>
#include <xmloff/nmspmap.hxx>
#include "xmloff/xmlnmspe.hxx"
#include <xmloff/xmltoken.hxx>
#include "txtparai.hxx"
#include "txtlists.hxx"
#include "XMLTextListBlockContext.hxx"
#include <xmloff/txtimp.hxx>
// --> OD 2008-05-08 #refactorlists#
#include <com/sun/star/container/XNameContainer.hpp>
#include <com/sun/star/style/XStyle.hpp>
#include <xmloff/xmlnumi.hxx>
// <--

#include "XMLTextListItemContext.hxx"


using ::rtl::OUString;
using ::rtl::OUStringBuffer;

using namespace ::com::sun::star;
using namespace ::com::sun::star::uno;
using namespace ::xmloff::token;

TYPEINIT1( XMLTextListItemContext, SvXMLImportContext );

XMLTextListItemContext::XMLTextListItemContext(
                        SvXMLImport& rImport,
                        XMLTextImportHelper& rTxtImp,
                        const sal_uInt16 nPrfx,
                        const OUString& rLName,
                        const Reference< xml::sax::XAttributeList > & xAttrList,
                        const sal_Bool bIsHeader )
    : SvXMLImportContext( rImport, nPrfx, rLName ),
      rTxtImport( rTxtImp ),
      nStartValue( -1 ),
      // --> OD 2008-05-07 #refactorlists#
      mnSubListCount( 0 ),
      mxNumRulesOverride()
      // <--
{
    static ::rtl::OUString s_NumberingRules(
        RTL_CONSTASCII_USTRINGPARAM("NumberingRules"));
	sal_Int16 nAttrCount = xAttrList.is() ? xAttrList->getLength() : 0;
	for( sal_Int16 i=0; i < nAttrCount; i++ )
	{
		const OUString& rAttrName = xAttrList->getNameByIndex( i );
		const OUString& rValue = xAttrList->getValueByIndex( i );

		OUString aLocalName;
		sal_uInt16 nPrefix =
			GetImport().GetNamespaceMap().GetKeyByAttrName( rAttrName,
															&aLocalName );
		if( !bIsHeader && XML_NAMESPACE_TEXT == nPrefix &&
			IsXMLToken( aLocalName, XML_START_VALUE ) )
		{
			sal_Int32 nTmp = rValue.toInt32();
			if( nTmp >= 0 && nTmp <= SHRT_MAX )
				nStartValue = (sal_Int16)nTmp;
		}
        // --> OD 2008-05-08 #refactorlists#
        else if ( nPrefix == XML_NAMESPACE_TEXT &&
                  IsXMLToken( aLocalName, XML_STYLE_OVERRIDE ) )
        {
            const ::rtl::OUString sListStyleOverrideName = rValue;
            if ( sListStyleOverrideName.getLength() > 0 )
            {
                OUString sDisplayStyleName(
                        GetImport().GetStyleDisplayName( XML_STYLE_FAMILY_TEXT_LIST,
                                                         sListStyleOverrideName ) );
                const Reference < container::XNameContainer >& rNumStyles =
                                                    rTxtImp.GetNumberingStyles();
                if( rNumStyles.is() && rNumStyles->hasByName( sDisplayStyleName ) )
                {
                    Reference < style::XStyle > xStyle;
                    Any aAny = rNumStyles->getByName( sDisplayStyleName );
                    aAny >>= xStyle;

                    uno::Reference< beans::XPropertySet > xPropSet( xStyle, UNO_QUERY );
                    aAny = xPropSet->getPropertyValue(s_NumberingRules);
                    aAny >>= mxNumRulesOverride;
                }
                else
                {
                    const SvxXMLListStyleContext* pListStyle =
                                        rTxtImp.FindAutoListStyle( sListStyleOverrideName );
                    if( pListStyle )
                    {
                        mxNumRulesOverride = pListStyle->GetNumRules();
                        if( !mxNumRulesOverride.is() )
                        {
                            pListStyle->CreateAndInsertAuto();
                            mxNumRulesOverride = pListStyle->GetNumRules();
                        }
                    }
                }
            }
        }
        // <--
		else if ( (XML_NAMESPACE_XML == nPrefix) &&
			 IsXMLToken(aLocalName, XML_ID)   )
		{
			(void) rValue;
//FIXME: there is no UNO API for list items
		}
	}

	// If this is a <text:list-item> element, then remember it as a sign
	// that a bullet has to be generated.
	if( !bIsHeader ) {
		rTxtImport.GetTextListHelper().SetListItem( this );
    }

}

XMLTextListItemContext::~XMLTextListItemContext()
{
}

void XMLTextListItemContext::EndElement()
{
	// finish current list item
	rTxtImport.GetTextListHelper().SetListItem( 0 );
}

SvXMLImportContext *XMLTextListItemContext::CreateChildContext(
		sal_uInt16 nPrefix,
		const OUString& rLocalName,
		const Reference< xml::sax::XAttributeList > & xAttrList )
{
	SvXMLImportContext *pContext = 0;

	const SvXMLTokenMap& rTokenMap = rTxtImport.GetTextElemTokenMap();
	sal_Bool bHeading = sal_False;
	switch( rTokenMap.Get( nPrefix, rLocalName ) )
	{
	case XML_TOK_TEXT_H:
		bHeading = sal_True;
	case XML_TOK_TEXT_P:
		pContext = new XMLParaContext( GetImport(),
									   nPrefix, rLocalName,
									   xAttrList, bHeading );
        if (rTxtImport.IsProgress())
            GetImport().GetProgressBarHelper()->Increment();

		break;
	case XML_TOK_TEXT_LIST:
        // --> OD 2008-05-07 #refactorlists#
//        pContext = new XMLTextListBlockContext( GetImport(), rTxtImport,
//                                            nPrefix, rLocalName,
//                                            xAttrList );
        ++mnSubListCount;
		pContext = new XMLTextListBlockContext( GetImport(), rTxtImport,
                                                nPrefix, rLocalName,
                                                xAttrList,
                                                (mnSubListCount > 1) );
        // <--
		break;
	}

	if( !pContext )
		pContext = new SvXMLImportContext( GetImport(), nPrefix, rLocalName );

	return pContext;
}


