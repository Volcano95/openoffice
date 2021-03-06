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



#include "oox/ppt/slidetransitioncontext.hxx"

#include "comphelper/anytostring.hxx"
#include "cppuhelper/exc_hlp.hxx"

#include <com/sun/star/beans/XMultiPropertySet.hpp>
#include <com/sun/star/container/XNamed.hpp>

#include <oox/ppt/backgroundproperties.hxx>
#include "oox/ppt/slidefragmenthandler.hxx"
#include "oox/ppt/soundactioncontext.hxx"
#include "oox/drawingml/shapegroupcontext.hxx"
#include "oox/helper/attributelist.hxx"

using rtl::OUString;
using namespace ::com::sun::star;
using namespace ::oox::core;
using namespace ::oox::drawingml;
using namespace ::com::sun::star::uno;
using namespace ::com::sun::star::xml::sax;
using namespace ::com::sun::star::container;

namespace oox { namespace ppt {


SlideTransitionContext::SlideTransitionContext( ContextHandler& rParent, const Reference< XFastAttributeList >& xAttribs, PropertyMap & aProperties ) throw()
: ContextHandler( rParent )
, maSlideProperties( aProperties )
, mbHasTransition( sal_False )
{
	AttributeList attribs(xAttribs);

	// ST_TransitionSpeed
	maTransition.setOoxTransitionSpeed( xAttribs->getOptionalValueToken( XML_spd, XML_fast ) );

	// TODO
	attribs.getBool( XML_advClick, true );

	// careful. if missing, no auto advance... 0 looks like a valid value
  // for auto advance
	if(attribs.hasAttribute( XML_advTm ))
	{
		// TODO
		xAttribs->getOptionalValue( XML_advTm );
	}
}

SlideTransitionContext::~SlideTransitionContext() throw()
{

}

Reference< XFastContextHandler > SlideTransitionContext::createFastChildContext( sal_Int32 aElementToken, const Reference< XFastAttributeList >& xAttribs ) throw (SAXException, RuntimeException)
{
	Reference< XFastContextHandler > xRet;

	switch( aElementToken )
	{
	case PPT_TOKEN( blinds ):
	case PPT_TOKEN( checker ):
	case PPT_TOKEN( comb ):
	case PPT_TOKEN( randomBar ):
		if (!mbHasTransition)
		{
			mbHasTransition = true;
			maTransition.setOoxTransitionType( aElementToken, xAttribs->getOptionalValueToken( XML_dir, XML_horz ), 0);
			// ST_Direction { XML_horz, XML_vert }
		}
		break;
	case PPT_TOKEN( cover ):
	case PPT_TOKEN( pull ):
		if (!mbHasTransition)
		{
			mbHasTransition = true;
			maTransition.setOoxTransitionType( aElementToken, xAttribs->getOptionalValueToken( XML_dir, XML_l ), 0 );
			// ST_TransitionEightDirectionType { ST_TransitionSideDirectionType {
			//                                   XML_d, XML_d, XML_r, XML_u },
			//                                   ST_TransitionCornerDirectionType {
			//                                   XML_ld, XML_lu, XML_rd, XML_ru }
		}
		break;
	case PPT_TOKEN( cut ):
	case PPT_TOKEN( fade ):
		if (!mbHasTransition)
		{
			mbHasTransition = true;
			AttributeList attribs(xAttribs);
			// CT_OptionalBlackTransition xdb:bool
			maTransition.setOoxTransitionType( aElementToken, attribs.getBool( XML_thruBlk, false ), 0);
		}
		break;
	case PPT_TOKEN( push ):
	case PPT_TOKEN( wipe ):
		if (!mbHasTransition)
		{
			mbHasTransition = true;
			maTransition.setOoxTransitionType( aElementToken, xAttribs->getOptionalValueToken( XML_dir, XML_l ), 0 );
			// ST_TransitionSideDirectionType { XML_d, XML_l, XML_r, XML_u }
		}
		break;
	case PPT_TOKEN( split ):
		if (!mbHasTransition)
		{
			mbHasTransition = true;
			maTransition.setOoxTransitionType( aElementToken, xAttribs->getOptionalValueToken( XML_orient, XML_horz ),	xAttribs->getOptionalValueToken( XML_dir, XML_out ) );
			// ST_Direction { XML_horz, XML_vert }
			// ST_TransitionInOutDirectionType { XML_out, XML_in }
		}
		break;
	case PPT_TOKEN( zoom ):
		if (!mbHasTransition)
		{
			mbHasTransition = true;
			maTransition.setOoxTransitionType( aElementToken, xAttribs->getOptionalValueToken( XML_dir, XML_out ), 0 );
			// ST_TransitionInOutDirectionType { XML_out, XML_in }
		}
		break;
	case PPT_TOKEN( wheel ):
		if (!mbHasTransition)
		{
			mbHasTransition = true;
			AttributeList attribs(xAttribs);
            maTransition.setOoxTransitionType( aElementToken, attribs.getUnsigned( XML_spokes, 4 ), 0 );
			// unsignedInt
		}
		break;
	case PPT_TOKEN( circle ):
	case PPT_TOKEN( diamond ):
	case PPT_TOKEN( dissolve ):
	case PPT_TOKEN( newsflash ):
	case PPT_TOKEN( plus ):
	case PPT_TOKEN( random ):
	case PPT_TOKEN( wedge ):
		// CT_Empty
		if (!mbHasTransition)
		{
			mbHasTransition = true;
			maTransition.setOoxTransitionType( aElementToken, 0, 0 );
		}
		break;


	case PPT_TOKEN( sndAc ): // CT_TransitionSoundAction
		//"Sound"
        xRet.set( new SoundActionContext ( *this, maSlideProperties ) );
		break;
	case PPT_TOKEN( extLst ): // CT_OfficeArtExtensionList
        return xRet;
	default:
		break;
	}

	if( !xRet.is() )
		xRet.set(this);

	return xRet;
}

void SlideTransitionContext::endFastElement( sal_Int32 aElement ) throw (::com::sun::star::xml::sax::SAXException, RuntimeException)
{
	if( aElement == (PPT_TOKEN( transition )) )
	{
		if( mbHasTransition )
		{
			maTransition.setSlideProperties( maSlideProperties );
			mbHasTransition = false;
		}
	}
}


} }

