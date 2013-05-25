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



#ifndef _SVTOOLS_TOOLBOXCONTROLLER_HXX
#define _SVTOOLS_TOOLBOXCONTROLLER_HXX

#include "svtools/svtdllapi.h"
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/lang/XInitialization.hpp>
#include <com/sun/star/util/XUpdatable.hpp>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/frame/XDispatch.hpp>
#include <com/sun/star/frame/XStatusListener.hpp>
#include <com/sun/star/frame/XToolbarController.hpp>
#include <com/sun/star/util/XURLTransformer.hpp>
#include <com/sun/star/frame/XLayoutManager.hpp>
#include <cppuhelper/weak.hxx>
#include <cppuhelper/interfacecontainer.hxx>
#include <comphelper/broadcasthelper.hxx>
#include <com/sun/star/util/XURLTransformer.hpp>
#include <comphelper/proparrhlp.hxx>
#include <comphelper/property.hxx>
#include <comphelper/propertycontainer.hxx>
#include <cppuhelper/propshlp.hxx>
#include <cppuhelper/interfacecontainer.hxx>
#include <tools/link.hxx>

//end
#ifndef INCLUDED_HASH_MAP
#include <hash_map>
#define INCLUDED_HASH_MAP
#endif

class ToolBox;

namespace svt
{

struct DispatchInfo;

class SVT_DLLPUBLIC ToolboxController : public ::com::sun::star::frame::XStatusListener,
                          public ::com::sun::star::frame::XToolbarController,
                          public ::com::sun::star::lang::XInitialization,
                          public ::com::sun::star::util::XUpdatable,
                          public ::com::sun::star::lang::XComponent,
                          public ::comphelper::OMutexAndBroadcastHelper,//shizhoubo
			              public ::comphelper::OPropertyContainer,//shizhoubo
                          public ::comphelper::OPropertyArrayUsageHelper< ToolboxController >,//shizhoubo
						  public ::cppu::OWeakObject
{
	private:
		sal_Bool  m_bSupportVisiable; //shizhoubo
    public:
        ToolboxController( const com::sun::star::uno::Reference< com::sun::star::lang::XMultiServiceFactory >& rServiceManager,
                           const ::com::sun::star::uno::Reference< ::com::sun::star::frame::XFrame >& xFrame,
                           const rtl::OUString& aCommandURL );
        ToolboxController();
        virtual ~ToolboxController();        
        
        ::com::sun::star::uno::Reference< ::com::sun::star::frame::XFrame > getFrameInterface() const;
        ::com::sun::star::uno::Reference< ::com::sun::star::lang::XMultiServiceFactory > getServiceManager() const;
        ::com::sun::star::uno::Reference< ::com::sun::star::frame::XLayoutManager > getLayoutManager() const;

        void updateStatus( const rtl::OUString aCommandURL );
        void updateStatus();
        
        // XInterface
		virtual ::com::sun::star::uno::Any SAL_CALL queryInterface( const ::com::sun::star::uno::Type& aType ) throw (::com::sun::star::uno::RuntimeException);
		virtual void SAL_CALL acquire() throw ();
		virtual void SAL_CALL release() throw ();

        // XInitialization
        virtual void SAL_CALL initialize( const ::com::sun::star::uno::Sequence< ::com::sun::star::uno::Any >& aArguments ) throw (::com::sun::star::uno::Exception, ::com::sun::star::uno::RuntimeException);
            
        // XUpdatable
        virtual void SAL_CALL update() throw (::com::sun::star::uno::RuntimeException);
        
        // XComponent
        virtual void SAL_CALL dispose() throw (::com::sun::star::uno::RuntimeException);
        virtual void SAL_CALL addEventListener( const ::com::sun::star::uno::Reference< ::com::sun::star::lang::XEventListener >& xListener ) throw (::com::sun::star::uno::RuntimeException);
        virtual void SAL_CALL removeEventListener( const ::com::sun::star::uno::Reference< ::com::sun::star::lang::XEventListener >& aListener ) throw (::com::sun::star::uno::RuntimeException);
		
        // XEventListener
        using cppu::OPropertySetHelper::disposing;
		virtual void SAL_CALL disposing( const com::sun::star::lang::EventObject& Source ) throw ( ::com::sun::star::uno::RuntimeException );
		
        // XStatusListener
		virtual void SAL_CALL statusChanged( const ::com::sun::star::frame::FeatureStateEvent& Event ) throw ( ::com::sun::star::uno::RuntimeException ) = 0;

        // XToolbarController
        virtual void SAL_CALL execute( sal_Int16 KeyModifier ) throw (::com::sun::star::uno::RuntimeException);
        virtual void SAL_CALL click() throw (::com::sun::star::uno::RuntimeException);
        virtual void SAL_CALL doubleClick() throw (::com::sun::star::uno::RuntimeException);
        virtual ::com::sun::star::uno::Reference< ::com::sun::star::awt::XWindow > SAL_CALL createPopupWindow() throw (::com::sun::star::uno::RuntimeException);
        virtual ::com::sun::star::uno::Reference< ::com::sun::star::awt::XWindow > SAL_CALL createItemWindow( const ::com::sun::star::uno::Reference< ::com::sun::star::awt::XWindow >& Parent ) throw (::com::sun::star::uno::RuntimeException);
		// OPropertySetHelper //shizhoubo
		virtual void SAL_CALL setFastPropertyValue_NoBroadcast( sal_Int32 nHandle, const com::sun::star::uno::Any& rValue ) throw(com::sun::star::uno::Exception);
		virtual sal_Bool SAL_CALL convertFastPropertyValue( com::sun::star::uno::Any& rConvertedValue, com::sun::star::uno::Any& rOldValue, sal_Int32 nHandle, const com::sun::star::uno::Any& rValue) throw(com::sun::star::lang::IllegalArgumentException);
        // XPropertySet //shizhoubo
		virtual ::com::sun::star::uno::Reference< com::sun::star::beans::XPropertySetInfo>  SAL_CALL getPropertySetInfo() throw(::com::sun::star::uno::RuntimeException);
		virtual ::cppu::IPropertyArrayHelper& SAL_CALL getInfoHelper();
		// OPropertyArrayUsageHelper //shizhoubo
		virtual ::cppu::IPropertyArrayHelper* createArrayHelper( ) const;
 

		const rtl::OUString& getCommandURL() const { return  m_aCommandURL; }
		const rtl::OUString& getModuleName() const { return m_sModuleName; }

		void dispatchCommand( const ::rtl::OUString& sCommandURL, const ::com::sun::star::uno::Sequence< ::com::sun::star::beans::PropertyValue >& rArgs );

		void enable( bool bEnable );

        DECL_STATIC_LINK( ToolboxController, ExecuteHdl_Impl, DispatchInfo* );

    protected:
        bool getToolboxId( sal_uInt16& rItemId, ToolBox** ppToolBox );
		void setSupportVisiableProperty(sal_Bool bValue); //shizhoubo
        struct Listener
        {
            Listener( const ::com::sun::star::util::URL& rURL, const ::com::sun::star::uno::Reference< ::com::sun::star::frame::XDispatch >& rDispatch ) :
                aURL( rURL ), xDispatch( rDispatch ) {}
            
            ::com::sun::star::util::URL aURL;
            ::com::sun::star::uno::Reference< ::com::sun::star::frame::XDispatch > xDispatch;
        };

        typedef ::std::hash_map< ::rtl::OUString,
				                 com::sun::star::uno::Reference< com::sun::star::frame::XDispatch >,
                                 ::rtl::OUStringHash,
								 ::std::equal_to< ::rtl::OUString > > URLToDispatchMap;
        
        // methods to support status forwarder, known by the old sfx2 toolbox controller implementation
        void addStatusListener( const rtl::OUString& aCommandURL );
        void removeStatusListener( const rtl::OUString& aCommandURL );
        void bindListener();
        void unbindListener();
        sal_Bool isBound() const;
        sal_Bool hasBigImages() const;
        sal_Bool isHighContrast() const;
        // TODO remove
        ::com::sun::star::uno::Reference< ::com::sun::star::util::XURLTransformer > getURLTransformer() const;
        // TODO remove
		::com::sun::star::uno::Reference< ::com::sun::star::awt::XWindow > getParent() const;

        sal_Bool                                                                            m_bInitialized : 1,
                                                                                            m_bDisposed : 1;
        sal_uInt16                                                                          m_nToolBoxId;
		::com::sun::star::uno::Reference< ::com::sun::star::frame::XFrame >					m_xFrame;
        ::com::sun::star::uno::Reference< ::com::sun::star::lang::XMultiServiceFactory >    m_xServiceManager;
        rtl::OUString                                                                       m_aCommandURL;
        URLToDispatchMap                                                                    m_aListenerMap;
        ::cppu::OMultiTypeInterfaceContainerHelper                                          m_aListenerContainer;   /// container for ALL Listener

        ::com::sun::star::uno::Reference< ::com::sun::star::awt::XWindow >          m_xParentWindow;
        ::com::sun::star::uno::Reference< ::com::sun::star::util::XURLTransformer > m_xUrlTransformer;
        rtl::OUString m_sModuleName;
        
};

}

#endif // _SVTOOLS_TOOLBOXCONTROLLER_HXX
