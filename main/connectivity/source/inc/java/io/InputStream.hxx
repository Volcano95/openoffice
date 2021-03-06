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


#ifndef _CONNECTIVITY_JAVA_IO_INPUTSTREAM_HXX_
#define _CONNECTIVITY_JAVA_IO_INPUTSTREAM_HXX_

#include "java/lang/Object.hxx"
#include <cppuhelper/implbase1.hxx>
#include <com/sun/star/io/XInputStream.hpp>

namespace connectivity
{
	
	//**************************************************************
	//************ Class: java.io.InputStream
	//**************************************************************
	class java_io_InputStream : public java_lang_Object,
								public ::cppu::WeakImplHelper1< ::com::sun::star::io::XInputStream>
	{
	protected:
	// statische Daten fuer die Klasse
		static jclass theClass;
		virtual ~java_io_InputStream();
	public:
		virtual jclass getMyClass() const;		
		// ein Konstruktor, der fuer das Returnen des Objektes benoetigt wird:
		java_io_InputStream( JNIEnv * pEnv, jobject myObj );
		// XInputStream
		virtual sal_Int32 SAL_CALL readBytes( ::com::sun::star::uno::Sequence< sal_Int8 >& aData, sal_Int32 nBytesToRead ) throw(::com::sun::star::io::NotConnectedException, ::com::sun::star::io::BufferSizeExceededException, ::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException);
		virtual sal_Int32 SAL_CALL readSomeBytes( ::com::sun::star::uno::Sequence< sal_Int8 >& aData, sal_Int32 nMaxBytesToRead ) throw(::com::sun::star::io::NotConnectedException, ::com::sun::star::io::BufferSizeExceededException, ::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException);
		virtual void SAL_CALL skipBytes( sal_Int32 nBytesToSkip ) throw(::com::sun::star::io::NotConnectedException, ::com::sun::star::io::BufferSizeExceededException, ::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException);
		virtual sal_Int32 SAL_CALL available(  ) throw(::com::sun::star::io::NotConnectedException, ::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException);
		virtual void SAL_CALL closeInput(  ) throw(::com::sun::star::io::NotConnectedException, ::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException);
	};
}
#endif // _CONNECTIVITY_JAVA_IO_INPUTSTREAM_HXX_

