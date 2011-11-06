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
#include "XMLAutoTextEventExport.hxx"
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/xml/sax/XDocumentHandler.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/document/XEventsSupplier.hpp>
#include <com/sun/star/container/XNameReplace.hpp>
#include <com/sun/star/container/XNameAccess.hpp>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/uno/Sequence.hxx>

#ifndef _COM_SUN_STAR_UNO_EXCEPTION_HPP
#include <com/sun/star/uno/Exception.hpp>
#endif

// #110680#
//#ifndef _COMPHELPER_PROCESSFACTORY_HXX_
//#include <comphelper/processfactory.hxx>
//#endif
#include <rtl/ustrbuf.hxx>
#include "xmloff/xmlnmspe.hxx"
#include <xmloff/nmspmap.hxx>
#include <xmloff/xmltoken.hxx>
#include <xmloff/XMLEventExport.hxx>
#include <tools/debug.hxx>


using namespace ::com::sun::star;
using namespace ::xmloff::token;

// #110680#
// using ::comphelper::getProcessServiceFactory;
using ::rtl::OUString;
using ::rtl::OUStringBuffer;
using ::std::set;
using ::com::sun::star::beans::XPropertySet;
using ::com::sun::star::beans::PropertyValue;
using ::com::sun::star::container::XNameAccess;
using ::com::sun::star::container::XNameReplace;
using ::com::sun::star::document::XEventsSupplier;
using ::com::sun::star::frame::XModel;
using ::com::sun::star::lang::XMultiServiceFactory;
using ::com::sun::star::uno::Any;
using ::com::sun::star::uno::Exception;
using ::com::sun::star::uno::Reference;
using ::com::sun::star::uno::Sequence;
using ::com::sun::star::uno::XInterface;
using ::com::sun::star::uno::UNO_QUERY;
using ::com::sun::star::xml::sax::XDocumentHandler;


const sal_Char sAPI_AutoText[] = "com.sun.star.text.AutoTextContainer";


// #110680#
XMLAutoTextEventExport::XMLAutoTextEventExport(
	const ::com::sun::star::uno::Reference< ::com::sun::star::lang::XMultiServiceFactory >& xServiceFactory,
		sal_uInt16 nFlags
	) 
:		SvXMLExport( xServiceFactory, MAP_INCH, XML_AUTO_TEXT, nFlags ),
		sEventType(RTL_CONSTASCII_USTRINGPARAM("EventType")),
		sNone(RTL_CONSTASCII_USTRINGPARAM("None"))
{
}

// #110680#
XMLAutoTextEventExport::XMLAutoTextEventExport(
	const ::com::sun::star::uno::Reference< ::com::sun::star::lang::XMultiServiceFactory >& xServiceFactory,
	const OUString& rFileName,
	const Reference<XDocumentHandler> & rHandler,
	const Reference<XModel> & rModel,
	const Reference<XNameAccess> & rEvents,
	sal_uInt16 /*nFlags*/ ) 
:	SvXMLExport( xServiceFactory, rFileName, rHandler, rModel, MAP_INCH ),
	xEvents(rEvents),
	sEventType(RTL_CONSTASCII_USTRINGPARAM("EventType")),
	sNone(RTL_CONSTASCII_USTRINGPARAM("None"))
{
}

XMLAutoTextEventExport::~XMLAutoTextEventExport()
{
}


void XMLAutoTextEventExport::initialize( 
	const Sequence<Any> & rArguments )
		throw(uno::Exception, uno::RuntimeException)
{
	if (rArguments.getLength() > 1)
	{
		Reference<XEventsSupplier> xSupplier;
		rArguments[1] >>= xSupplier;
		if (xSupplier.is())
		{
			Reference<XNameAccess> xAccess(xSupplier->getEvents(), UNO_QUERY);
			xEvents = xAccess;
		}
		else
		{
			Reference<XNameReplace> xReplace;
			rArguments[1] >>= xReplace;
			if (xReplace.is())
			{
				Reference<XNameAccess> xAccess(xReplace, UNO_QUERY);
				xEvents = xAccess;
			}
			else
			{
				rArguments[1] >>= xEvents;
			}
		}
	}

	// call super class (for XHandler)
	SvXMLExport::initialize(rArguments);
}


sal_uInt32 XMLAutoTextEventExport::exportDoc( enum XMLTokenEnum )
{
	if( (getExportFlags() & EXPORT_OASIS) == 0 )
	{
		Reference< lang::XMultiServiceFactory > xFactory = getServiceFactory();
		if( xFactory.is() )
		{
			try
			{

				Sequence<Any> aArgs( 1 );
				aArgs[0] <<= GetDocHandler();

				// get filter component
				Reference< xml::sax::XDocumentHandler > xTmpDocHandler(
					xFactory->createInstanceWithArguments(
					OUString::createFromAscii("com.sun.star.comp.Oasis2OOoTransformer"),
								aArgs), UNO_QUERY);
				OSL_ENSURE( xTmpDocHandler.is(),
					"can't instantiate OASIS transformer component" );
				if( xTmpDocHandler.is() )
				{
					SetDocHandler( xTmpDocHandler );
				}
			}
			catch( com::sun::star::uno::Exception& )
			{
			}
		}
	}
	if (hasEvents())
	{
		GetDocHandler()->startDocument();

		addNamespaces();

		{
			// container element
			SvXMLElementExport aContainerElement(
				*this, XML_NAMESPACE_OOO, XML_AUTO_TEXT_EVENTS, 
				sal_True, sal_True);

			exportEvents();
		}

		// and close document again
		GetDocHandler()->endDocument();
	}

	return 0;
}

sal_Bool XMLAutoTextEventExport::hasEvents()
{
	// TODO: provide full implementation that check for presence of events
	return xEvents.is();
}

void XMLAutoTextEventExport::addNamespaces()
{
	// namespaces for office:, text: and script:
	GetAttrList().AddAttribute( 
		GetNamespaceMap().GetAttrNameByIndex( XML_NAMESPACE_OFFICE ), 
		GetNamespaceMap().GetNameByIndex( XML_NAMESPACE_OFFICE ) );
	GetAttrList().AddAttribute( 
		GetNamespaceMap().GetAttrNameByIndex( XML_NAMESPACE_TEXT ), 
		GetNamespaceMap().GetNameByIndex( XML_NAMESPACE_TEXT ) );
	GetAttrList().AddAttribute( 
		GetNamespaceMap().GetAttrNameByIndex( XML_NAMESPACE_SCRIPT ), 
		GetNamespaceMap().GetNameByIndex( XML_NAMESPACE_SCRIPT ) );
	GetAttrList().AddAttribute( 
		GetNamespaceMap().GetAttrNameByIndex( XML_NAMESPACE_DOM ), 
		GetNamespaceMap().GetNameByIndex( XML_NAMESPACE_DOM ) );
	GetAttrList().AddAttribute( 
		GetNamespaceMap().GetAttrNameByIndex( XML_NAMESPACE_OOO ), 
		GetNamespaceMap().GetNameByIndex( XML_NAMESPACE_OOO ) );
	GetAttrList().AddAttribute( 
		GetNamespaceMap().GetAttrNameByIndex( XML_NAMESPACE_XLINK ), 
		GetNamespaceMap().GetNameByIndex( XML_NAMESPACE_XLINK ) );
}

void XMLAutoTextEventExport::exportEvents()
{
	DBG_ASSERT(hasEvents(), "no events to export!");

	GetEventExport().Export(xEvents, sal_True);
}



// methods without content:

void XMLAutoTextEventExport::_ExportMeta() {}
void XMLAutoTextEventExport::_ExportScripts() {}
void XMLAutoTextEventExport::_ExportFontDecls() {}
void XMLAutoTextEventExport::_ExportStyles( sal_Bool ) {}
void XMLAutoTextEventExport::_ExportAutoStyles() {}
void XMLAutoTextEventExport::_ExportMasterStyles() {}
void XMLAutoTextEventExport::_ExportChangeTracking() {}
void XMLAutoTextEventExport::_ExportContent() {}



// methods to support the component registration

Sequence< OUString > SAL_CALL XMLAutoTextEventExport_getSupportedServiceNames()
	throw()
{
	Sequence< OUString > aSeq( 1 );
	aSeq[0] = XMLAutoTextEventExport_getImplementationName();
	return aSeq;
}

OUString SAL_CALL XMLAutoTextEventExport_getImplementationName() throw()
{
	return OUString( RTL_CONSTASCII_USTRINGPARAM( 
		"com.sun.star.comp.Writer.XMLOasisAutotextEventsExporter" ) );
}

Reference< XInterface > SAL_CALL XMLAutoTextEventExport_createInstance(
		const Reference< XMultiServiceFactory > & rSMgr)
	throw( Exception )
{
	// #110680#
	// return (cppu::OWeakObject*)new XMLAutoTextEventExport;
	return (cppu::OWeakObject*)new XMLAutoTextEventExport(rSMgr, EXPORT_ALL|EXPORT_OASIS);
}

// methods to support the component registration

Sequence< OUString > SAL_CALL XMLAutoTextEventExportOOO_getSupportedServiceNames()
	throw()
{
	Sequence< OUString > aSeq( 1 );
	aSeq[0] = XMLAutoTextEventExportOOO_getImplementationName();
	return aSeq;
}

OUString SAL_CALL XMLAutoTextEventExportOOO_getImplementationName() throw()
{
	return OUString( RTL_CONSTASCII_USTRINGPARAM( 
		"com.sun.star.comp.Writer.XMLAutotextEventsExporter" ) );
}

Reference< XInterface > SAL_CALL XMLAutoTextEventExportOOO_createInstance(
		const Reference< XMultiServiceFactory > & rSMgr)
	throw( Exception )
{
	// #110680#
	// return (cppu::OWeakObject*)new XMLAutoTextEventExport;
	return (cppu::OWeakObject*)new XMLAutoTextEventExport(rSMgr,EXPORT_ALL);
}

