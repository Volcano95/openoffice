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



// MARKER(update_precomp.py): Generated on 2006-09-01 17:50:08.279739

#ifdef PRECOMPILED_HEADERS
//---MARKER---
#include "sal/config.h"
#include "com/sun/star/accessibility/AccessibleEventId.hpp"
#include "com/sun/star/accessibility/AccessibleEventObject.hpp"
#include "com/sun/star/accessibility/AccessibleRelationType.hpp"
#include "com/sun/star/accessibility/AccessibleRole.hpp"
#include "com/sun/star/accessibility/AccessibleStateType.hpp"
#include "com/sun/star/accessibility/AccessibleTextType.hpp"
#include "com/sun/star/accessibility/IllegalAccessibleComponentStateException.hpp"
#include "com/sun/star/accessibility/TextSegment.hpp"
#include "com/sun/star/accessibility/XAccessible.hpp"
#include "com/sun/star/accessibility/XAccessibleAction.hpp"
#include "com/sun/star/accessibility/XAccessibleContext.hpp"
#include "com/sun/star/accessibility/XAccessibleEventBroadcaster.hpp"
#include "com/sun/star/accessibility/XAccessibleEventListener.hpp"
#include "com/sun/star/accessibility/XAccessibleImage.hpp"
#include "com/sun/star/accessibility/XAccessibleRelationSet.hpp"
#include "com/sun/star/accessibility/XAccessibleSelection.hpp"
#include "com/sun/star/accessibility/XAccessibleStateSet.hpp"
#include "com/sun/star/accessibility/XAccessibleTable.hpp"
#include "com/sun/star/accessibility/XAccessibleTextAttributes.hpp"
#include "com/sun/star/accessibility/XAccessibleValue.hpp"
#include "com/sun/star/awt/CharSet.hpp"
#include "com/sun/star/awt/FocusChangeReason.hpp"
#include "com/sun/star/awt/FontDescriptor.hpp"
#include "com/sun/star/awt/FontFamily.hpp"
#include "com/sun/star/awt/FontPitch.hpp"
#include "com/sun/star/awt/FontSlant.hpp"
#include "com/sun/star/awt/FontType.hpp"
#include "com/sun/star/awt/FontWeight.hpp"
#include "com/sun/star/awt/FontWidth.hpp"
#include "com/sun/star/awt/Gradient.hpp"
#include "com/sun/star/awt/GradientStyle.hpp"
#include "com/sun/star/awt/Key.hpp"
#include "com/sun/star/awt/KeyEvent.hpp"
#include "com/sun/star/awt/KeyModifier.hpp"
#include "com/sun/star/awt/LineEndFormat.hpp"
#include "com/sun/star/awt/PosSize.hpp"
#include "com/sun/star/awt/RasterOperation.hpp"
#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/awt/ScrollBarOrientation.hpp"
#include "com/sun/star/awt/SimpleFontMetric.hpp"
#include "com/sun/star/awt/Size.hpp"
#include "com/sun/star/awt/TextAlign.hpp"
#include "com/sun/star/awt/VisualEffect.hpp"
#include "com/sun/star/awt/WindowAttribute.hpp"
#include "com/sun/star/awt/WindowDescriptor.hpp"
#include "com/sun/star/awt/XBitmap.hpp"
#include "com/sun/star/awt/XCheckBox.hpp"
#include "com/sun/star/awt/XComboBox.hpp"
#include "com/sun/star/awt/XControl.hpp"
#include "com/sun/star/awt/XControlContainer.hpp"
#include "com/sun/star/awt/XControlModel.hpp"
#include "com/sun/star/awt/XDevice.hpp"
#include "com/sun/star/awt/XFocusListener.hpp"
#include "com/sun/star/awt/XFont.hpp"
#include "com/sun/star/awt/XGraphics.hpp"
#include "com/sun/star/awt/XImageConsumer.hpp"
#include "com/sun/star/awt/XItemListener.hpp"
#include "com/sun/star/awt/XLayoutConstrains.hpp"
#include "com/sun/star/awt/XListBox.hpp"
#include "com/sun/star/awt/XMouseListener.hpp"
#include "com/sun/star/awt/XProgressMonitor.hpp"
#include "com/sun/star/awt/XTabController.hpp"
#include "com/sun/star/awt/XTabControllerModel.hpp"
#include "com/sun/star/awt/XTextListener.hpp"
#include "com/sun/star/awt/XToolkit.hpp"
#include "com/sun/star/awt/XVclWindowPeer.hpp"
#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/awt/XWindowListener.hpp"
#include "com/sun/star/awt/XWindowPeer.hpp"
#include "com/sun/star/beans/NamedValue.hpp"
#include "com/sun/star/beans/PropertyAttribute.hpp"
#include "com/sun/star/beans/PropertyChangeEvent.hpp"
#include "com/sun/star/beans/PropertyState.hpp"
#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/beans/PropertyValues.hdl"
#include "com/sun/star/beans/PropertyValues.hpp"
#include "com/sun/star/beans/XFastPropertySet.hpp"
#include "com/sun/star/beans/XIntrospection.hpp"
#include "com/sun/star/beans/XMultiPropertySet.hpp"
#include "com/sun/star/beans/XMultiPropertyStates.hpp"
#include "com/sun/star/beans/XPropertyChangeListener.hpp"
#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/beans/XPropertySetInfo.hpp"
#include "com/sun/star/beans/XPropertyState.hpp"
#include "com/sun/star/chart/ChartAxisArrangeOrderType.hpp"
#include "com/sun/star/container/ContainerEvent.hpp"
#include "com/sun/star/container/NoSuchElementException.hpp"
#include "com/sun/star/container/XChild.hpp"
#include "com/sun/star/container/XContainer.hpp"
#include "com/sun/star/container/XContainerListener.hpp"
#include "com/sun/star/container/XContainerQuery.hpp"
#include "com/sun/star/container/XContentEnumerationAccess.hpp"
#include "com/sun/star/container/XEnumeration.hpp"
#include "com/sun/star/container/XEnumerationAccess.hpp"
#include "com/sun/star/container/XHierarchicalNameAccess.hpp"
#include "com/sun/star/container/XIdentifierContainer.hpp"
#include "com/sun/star/container/XIndexAccess.hpp"
#include "com/sun/star/container/XIndexContainer.hpp"
#include "com/sun/star/container/XIndexReplace.hpp"
#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/container/XNameContainer.hpp"
#include "com/sun/star/container/XNameReplace.hpp"
#include "com/sun/star/container/XNamed.hpp"
#include "com/sun/star/container/XSet.hpp"
#include "com/sun/star/datatransfer/DataFlavor.hpp"
#include "com/sun/star/datatransfer/XTransferable.hpp"
#include "com/sun/star/datatransfer/clipboard/XClipboard.hpp"
#include "com/sun/star/datatransfer/clipboard/XFlushableClipboard.hpp"
#include "com/sun/star/datatransfer/dnd/DNDConstants.hpp"
#include "com/sun/star/datatransfer/dnd/XDragGestureRecognizer.hpp"
#include "com/sun/star/datatransfer/dnd/XDropTarget.hpp"
#include "com/sun/star/document/EventObject.hpp"
#include "com/sun/star/document/UpdateDocMode.hpp"
#include "com/sun/star/document/XActionLockable.hpp"
#include "com/sun/star/document/XBinaryStreamResolver.hpp"
#include "com/sun/star/document/XDocumentInfoSupplier.hpp"
#include "com/sun/star/document/XEmbeddedObjectResolver.hpp"
#include "com/sun/star/document/XEventBroadcaster.hpp"
#include "com/sun/star/document/XEventListener.hpp"
#include "com/sun/star/document/XEventsSupplier.hpp"
#include "com/sun/star/document/XExporter.hpp"
#include "com/sun/star/document/XFilter.hpp"
#include "com/sun/star/document/XGraphicObjectResolver.hpp"
#include "com/sun/star/document/XImporter.hpp"
#include "com/sun/star/document/XLinkTargetSupplier.hpp"
#include "com/sun/star/document/XMimeTypeInfo.hpp"
#include "com/sun/star/drawing/BitmapMode.hpp"
#include "com/sun/star/drawing/CameraGeometry.hpp"
#include "com/sun/star/drawing/CircleKind.hpp"
#include "com/sun/star/drawing/ColorMode.hpp"
#include "com/sun/star/drawing/ConnectionType.hpp"
#include "com/sun/star/drawing/ConnectorType.hpp"
#include "com/sun/star/drawing/DashStyle.hpp"
#include "com/sun/star/drawing/Direction3D.hpp"
#include "com/sun/star/drawing/DoubleSequence.hpp"
#include "com/sun/star/drawing/EnhancedCustomShapeAdjustmentValue.hpp"
#include "com/sun/star/drawing/EnhancedCustomShapeGluePointType.hpp"
#include "com/sun/star/drawing/EnhancedCustomShapeParameter.hpp"
#include "com/sun/star/drawing/EnhancedCustomShapeParameterPair.hpp"
#include "com/sun/star/drawing/EnhancedCustomShapeParameterType.hpp"
#include "com/sun/star/drawing/EnhancedCustomShapeSegment.hpp"
#include "com/sun/star/drawing/EnhancedCustomShapeSegmentCommand.hpp"
#include "com/sun/star/drawing/EnhancedCustomShapeTextFrame.hpp"
#include "com/sun/star/drawing/EnhancedCustomShapeTextPathMode.hpp"
#include "com/sun/star/drawing/FillStyle.hpp"
#include "com/sun/star/drawing/FlagSequence.hpp"
#include "com/sun/star/drawing/Hatch.hpp"
#include "com/sun/star/drawing/HomogenMatrix.hpp"
#include "com/sun/star/drawing/HomogenMatrix3.hpp"
#include "com/sun/star/drawing/LineDash.hpp"
#include "com/sun/star/drawing/LineJoint.hpp"
#include "com/sun/star/drawing/LineStyle.hpp"
#include "com/sun/star/drawing/MeasureKind.hpp"
#include "com/sun/star/drawing/MeasureTextHorzPos.hpp"
#include "com/sun/star/drawing/MeasureTextVertPos.hpp"
#include "com/sun/star/drawing/NormalsKind.hpp"
#include "com/sun/star/drawing/PolyPolygonShape3D.hpp"
#include "com/sun/star/drawing/PolygonFlags.hpp"
#include "com/sun/star/drawing/PolygonKind.hpp"
#include "com/sun/star/drawing/Position3D.hpp"
#include "com/sun/star/drawing/ProjectionMode.hpp"
#include "com/sun/star/drawing/RectanglePoint.hpp"
#include "com/sun/star/drawing/ShadeMode.hpp"
#include "com/sun/star/drawing/TextAdjust.hpp"
#include "com/sun/star/drawing/TextAnimationDirection.hpp"
#include "com/sun/star/drawing/TextAnimationKind.hpp"
#include "com/sun/star/drawing/TextFitToSizeType.hpp"
#include "com/sun/star/drawing/TextHorizontalAdjust.hpp"
#include "com/sun/star/drawing/TextVerticalAdjust.hpp"
#include "com/sun/star/drawing/TextureKind.hpp"
#include "com/sun/star/drawing/TextureMode.hpp"
#include "com/sun/star/drawing/TextureProjectionMode.hpp"
#include "com/sun/star/drawing/XGluePointsSupplier.hpp"
#include "com/sun/star/drawing/XShapeDescriptor.hpp"
#include "com/sun/star/embed/Aspects.hpp"
#include "com/sun/star/embed/ElementModes.hpp"
#include "com/sun/star/embed/EmbedMisc.hpp"
#include "com/sun/star/embed/EmbedStates.hpp"
#include "com/sun/star/embed/EntryInitModes.hpp"
#include "com/sun/star/embed/NoVisualAreaSizeException.hpp"
#include "com/sun/star/embed/XEmbedObjectCreator.hpp"
#include "com/sun/star/embed/XEmbedObjectFactory.hpp"
#include "com/sun/star/embed/XEmbedPersist.hpp"
#include "com/sun/star/embed/XEmbeddedObject.hpp"
#include "com/sun/star/embed/XInsertObjectDialog.hpp"
#include "com/sun/star/embed/XLinkageSupport.hpp"
#include "com/sun/star/embed/XStorage.hpp"
#include "com/sun/star/embed/XTransactedObject.hpp"
#include "com/sun/star/form/DatabaseDeleteEvent.hpp"
#include "com/sun/star/form/DatabaseParameterEvent.hpp"
#include "com/sun/star/form/ErrorEvent.hpp"
#include "com/sun/star/form/FormButtonType.hpp"
#include "com/sun/star/form/FormComponentType.hpp"
#include "com/sun/star/form/ListSourceType.hpp"
#include "com/sun/star/form/NavigationBarMode.hpp"
#include "com/sun/star/form/TabulatorCycle.hpp"
#include "com/sun/star/form/XBoundComponent.hpp"
#include "com/sun/star/form/XBoundControl.hpp"
#include "com/sun/star/form/XConfirmDeleteBroadcaster.hpp"
#include "com/sun/star/form/XConfirmDeleteListener.hpp"
#include "com/sun/star/form/XDatabaseParameterBroadcaster2.hpp"
#include "com/sun/star/form/XDatabaseParameterListener.hpp"
#include "com/sun/star/form/XForm.hpp"
#include "com/sun/star/form/XFormComponent.hpp"
#include "com/sun/star/form/XFormController.hpp"
#include "com/sun/star/form/XFormControllerListener.hpp"
#include "com/sun/star/form/XFormsSupplier.hpp"
#include "com/sun/star/form/XFormsSupplier2.hpp"
#include "com/sun/star/form/XGrid.hpp"
#include "com/sun/star/form/XGridColumnFactory.hpp"
#include "com/sun/star/form/XGridFieldDataSupplier.hpp"
#include "com/sun/star/form/XGridPeer.hpp"
#include "com/sun/star/form/XImageProducerSupplier.hpp"
#include "com/sun/star/form/XLoadListener.hpp"
#include "com/sun/star/form/XLoadable.hpp"
#include "com/sun/star/form/XReset.hpp"
#include "com/sun/star/form/XResetListener.hpp"
#include "com/sun/star/form/binding/XBindableValue.hpp"
#include "com/sun/star/form/binding/XListEntrySink.hpp"
#include "com/sun/star/form/binding/XValueBinding.hpp"
#include "com/sun/star/form/submission/XSubmissionSupplier.hpp"
#include "com/sun/star/form/validation/XFormComponentValidityListener.hpp"
#include "com/sun/star/form/validation/XValidatableFormComponent.hpp"
#include "com/sun/star/frame/DispatchDescriptor.hpp"
#include "com/sun/star/frame/DispatchInformation.hpp"
#include "com/sun/star/frame/FeatureStateEvent.hpp"
#include "com/sun/star/frame/FrameSearchFlag.hpp"
#include "com/sun/star/frame/XComponentLoader.hpp"
#include "com/sun/star/frame/XController.hpp"
#include "com/sun/star/frame/XDesktop.hpp"
#include "com/sun/star/frame/XDispatch.hpp"
#include "com/sun/star/frame/XDispatchInformationProvider.hpp"
#include "com/sun/star/frame/XDispatchProvider.hpp"
#include "com/sun/star/frame/XDispatchProviderInterception.hpp"
#include "com/sun/star/frame/XDispatchProviderInterceptor.hpp"
#include "com/sun/star/frame/XFrame.hpp"
#include "com/sun/star/frame/XFrameActionListener.hpp"
#include "com/sun/star/frame/XFrames.hpp"
#include "com/sun/star/frame/XFramesSupplier.hpp"
#include "com/sun/star/frame/XInterceptorInfo.hpp"
#include "com/sun/star/frame/XModel.hpp"
#include "com/sun/star/frame/XModuleManager.hpp"
#include "com/sun/star/frame/XStatusListener.hpp"
#include "com/sun/star/frame/XStorable.hpp"
#include "com/sun/star/frame/XSynchronousDispatch.hpp"
#include "com/sun/star/frame/status/ClipboardFormats.hpp"
#include "com/sun/star/frame/status/FontHeight.hpp"
#include "com/sun/star/frame/status/ItemStatus.hpp"
#include "com/sun/star/frame/status/LeftRightMargin.hpp"
#include "com/sun/star/frame/status/UpperLowerMargin.hpp"
#include "com/sun/star/frame/status/UpperLowerMarginScale.hpp"
#include "com/sun/star/gallery/GalleryItemType.hpp"
#include "com/sun/star/gallery/XGalleryItem.hpp"
#include "com/sun/star/gallery/XGalleryTheme.hpp"
#include "com/sun/star/gallery/XGalleryThemeProvider.hpp"
#include "com/sun/star/graphic/XGraphic.hpp"
#include "com/sun/star/graphic/XGraphicProvider.hpp"
#include "com/sun/star/graphic/XGraphicRenderer.hpp"
#include "com/sun/star/i18n/CharacterIteratorMode.hdl"
#include "com/sun/star/i18n/CharacterIteratorMode.hpp"
#include "com/sun/star/i18n/CollatorOptions.hpp"
#include "com/sun/star/i18n/ForbiddenCharacters.hpp"
#include "com/sun/star/i18n/InputSequenceCheckMode.hpp"
#include "com/sun/star/i18n/KCharacterType.hpp"
#include "com/sun/star/i18n/ScriptType.hdl"
#include "com/sun/star/i18n/ScriptType.hpp"
#include "com/sun/star/i18n/TextConversionOption.hdl"
#include "com/sun/star/i18n/TextConversionOption.hpp"
#include "com/sun/star/i18n/TextConversionType.hpp"
#include "com/sun/star/i18n/TransliterationModules.hpp"
#include "com/sun/star/i18n/UnicodeScript.hpp"
#include "com/sun/star/i18n/UnicodeType.hdl"
#include "com/sun/star/i18n/WordType.hpp"
#include "com/sun/star/i18n/XBreakIterator.hpp"
#include "com/sun/star/i18n/XExtendedInputSequenceChecker.hpp"
#include "com/sun/star/i18n/XExtendedTextConversion.hpp"
#include "com/sun/star/i18n/XForbiddenCharacters.hpp"
#include "com/sun/star/i18n/XTextConversion.hpp"
#include "com/sun/star/inspection/XObjectInspector.hpp"
#include "com/sun/star/inspection/XObjectInspectorModel.hpp"
#include "com/sun/star/io/IOException.hpp"
#include "com/sun/star/io/XActiveDataControl.hpp"
#include "com/sun/star/io/XActiveDataSink.hpp"
#include "com/sun/star/io/XActiveDataSource.hpp"
#include "com/sun/star/io/XInputStream.hpp"
#include "com/sun/star/io/XInputStreamProvider.hpp"
#include "com/sun/star/io/XMarkableStream.hpp"
#include "com/sun/star/io/XObjectInputStream.hpp"
#include "com/sun/star/io/XObjectOutputStream.hpp"
#include "com/sun/star/io/XOutputStream.hpp"
#include "com/sun/star/io/XPersistObject.hpp"
#include "com/sun/star/io/XSeekable.hdl"
#include "com/sun/star/io/XStream.hpp"
#include "com/sun/star/lang/DisposedException.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/lang/IndexOutOfBoundsException.hpp"
#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/lang/NoSupportException.hpp"
#include "com/sun/star/lang/ServiceNotRegisteredException.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/lang/XInitialization.hpp"
#include "com/sun/star/lang/XMultiComponentFactory.hpp"
#include "com/sun/star/lang/XMultiServiceFactory.hpp"
#include "com/sun/star/lang/XServiceDisplayName.hpp"
#include "com/sun/star/lang/XServiceInfo.hpp"
#include "com/sun/star/lang/XServiceName.hpp"
#include "com/sun/star/lang/XSingleComponentFactory.hpp"
#include "com/sun/star/lang/XTypeProvider.hpp"
#include "com/sun/star/lang/XUnoTunnel.hpp"
#include "com/sun/star/linguistic2/ConversionDictionaryType.hpp"
#include "com/sun/star/linguistic2/ConversionDirection.hdl"
#include "com/sun/star/linguistic2/ConversionPropertyType.hpp"
#include "com/sun/star/linguistic2/DictionaryEvent.hpp"
#include "com/sun/star/linguistic2/DictionaryEventFlags.hpp"
#include "com/sun/star/linguistic2/DictionaryListEvent.hpp"
#include "com/sun/star/linguistic2/DictionaryListEventFlags.hpp"
#include "com/sun/star/linguistic2/DictionaryType.hpp"
#include "com/sun/star/linguistic2/SpellFailure.hpp"
#include "com/sun/star/linguistic2/XAvailableLocales.hpp"
#include "com/sun/star/linguistic2/XConversionDictionary.hpp"
#include "com/sun/star/linguistic2/XConversionDictionaryList.hpp"
#include "com/sun/star/linguistic2/XConversionPropertyType.hpp"
#include "com/sun/star/linguistic2/XDictionary.hpp"
#include "com/sun/star/linguistic2/XDictionary1.hpp"
#include "com/sun/star/linguistic2/XDictionaryEntry.hpp"
#include "com/sun/star/linguistic2/XDictionaryEventListener.hpp"
#include "com/sun/star/linguistic2/XDictionaryList.hpp"
#include "com/sun/star/linguistic2/XDictionaryListEventListener.hpp"
#include "com/sun/star/linguistic2/XHyphenatedWord.hpp"
#include "com/sun/star/linguistic2/XHyphenator.hpp"
#include "com/sun/star/linguistic2/XLinguServiceManager.hdl"
#include "com/sun/star/linguistic2/XLinguServiceManager.hpp"
#include "com/sun/star/linguistic2/XMeaning.hpp"
#include "com/sun/star/linguistic2/XPossibleHyphens.hpp"
#include "com/sun/star/linguistic2/XSpellAlternatives.hpp"
#include "com/sun/star/linguistic2/XSpellChecker.hpp"
#include "com/sun/star/linguistic2/XSpellChecker1.hpp"
#include "com/sun/star/linguistic2/XSupportedLocales.hpp"
#include "com/sun/star/linguistic2/XThesaurus.hpp"
#include "com/sun/star/media/XPlayer.hpp"
#include "com/sun/star/media/ZoomLevel.hpp"
#include "com/sun/star/plugin/PluginDescription.hpp"
#include "com/sun/star/plugin/XPluginManager.hpp"
#include "com/sun/star/reflection/XIdlClass.hpp"
#include "com/sun/star/reflection/XIdlMethod.hpp"
#include "com/sun/star/reflection/XInterfaceMethodTypeDescription.hpp"
#include "com/sun/star/reflection/XProxyFactory.hpp"
#include "com/sun/star/registry/XRegistryKey.hpp"
#include "com/sun/star/registry/XSimpleRegistry.hpp"
#include "com/sun/star/script/ScriptEvent.hpp"
#include "com/sun/star/script/ScriptEventDescriptor.hpp"
#include "com/sun/star/script/XEventAttacherManager.hpp"
#include "com/sun/star/script/XInvocation.hpp"
#include "com/sun/star/script/XLibraryContainer.hpp"
#include "com/sun/star/script/XScriptListener.hpp"
#include "com/sun/star/script/XTypeConverter.hpp"
#include "com/sun/star/script/browse/BrowseNodeFactoryViewTypes.hpp"
#include "com/sun/star/script/browse/BrowseNodeTypes.hpp"
#include "com/sun/star/script/browse/XBrowseNode.hpp"
#include "com/sun/star/script/browse/XBrowseNodeFactory.hpp"
#include "com/sun/star/script/provider/ScriptErrorRaisedException.hpp"
#include "com/sun/star/script/provider/ScriptExceptionRaisedException.hpp"
#include "com/sun/star/script/provider/ScriptFrameworkErrorType.hpp"
#include "com/sun/star/script/provider/XScriptProvider.hpp"
#include "com/sun/star/script/provider/XScriptProviderSupplier.hpp"
#include "com/sun/star/sdb/CommandType.hpp"
#include "com/sun/star/sdb/ParametersRequest.hpp"
#include "com/sun/star/sdb/RowChangeAction.hpp"
#include "com/sun/star/sdb/RowChangeEvent.hpp"
#include "com/sun/star/sdb/SQLContext.hpp"
#include "com/sun/star/sdb/SQLErrorEvent.hpp"
#include "com/sun/star/sdb/XColumn.hpp"
#include "com/sun/star/sdb/XColumnUpdate.hpp"
#include "com/sun/star/sdb/XCompletedConnection.hpp"
#include "com/sun/star/sdb/XInteractionSupplyParameters.hpp"
#include "com/sun/star/sdb/XQueriesSupplier.hpp"
#include "com/sun/star/sdb/XResultSetAccess.hpp"
#include "com/sun/star/sdb/XRowSetApproveBroadcaster.hpp"
#include "com/sun/star/sdb/XRowSetApproveListener.hpp"
#include "com/sun/star/sdb/XRowSetSupplier.hpp"
#include "com/sun/star/sdb/XSQLErrorBroadcaster.hpp"
#include "com/sun/star/sdb/XSQLErrorListener.hpp"
#include "com/sun/star/sdb/XSQLQueryComposer.hpp"
#include "com/sun/star/sdb/XSQLQueryComposerFactory.hpp"
#include "com/sun/star/sdb/XSingleSelectQueryComposer.hpp"
#include "com/sun/star/sdbc/ColumnValue.hpp"
#include "com/sun/star/sdbc/DataType.hpp"
#include "com/sun/star/sdbc/ResultSetConcurrency.hpp"
#include "com/sun/star/sdbc/ResultSetType.hpp"
#include "com/sun/star/sdbc/XConnection.hpp"
#include "com/sun/star/sdbc/XDataSource.hpp"
#include "com/sun/star/sdbc/XDatabaseMetaData.hpp"
#include "com/sun/star/sdbc/XPreparedStatement.hpp"
#include "com/sun/star/sdbc/XResultSet.hpp"
#include "com/sun/star/sdbc/XResultSetUpdate.hpp"
#include "com/sun/star/sdbc/XRow.hpp"
#include "com/sun/star/sdbc/XRowSet.hpp"
#include "com/sun/star/sdbc/XRowSetListener.hpp"
#include "com/sun/star/sdbc/XStatement.hpp"
#include "com/sun/star/sdbcx/Privilege.hpp"
#include "com/sun/star/sdbcx/XColumnsSupplier.hpp"
#include "com/sun/star/sdbcx/XDataDescriptorFactory.hpp"
#include "com/sun/star/sdbcx/XDeleteRows.hpp"
#include "com/sun/star/sdbcx/XRowLocate.hpp"
#include "com/sun/star/sdbcx/XTablesSupplier.hpp"
#include "com/sun/star/security/XDocumentDigitalSignatures.hpp"
#include "com/sun/star/style/BreakType.hpp"
#include "com/sun/star/style/CaseMap.hpp"
#include "com/sun/star/style/GraphicLocation.hpp"
#include "com/sun/star/style/LineSpacing.hpp"
#include "com/sun/star/style/LineSpacingMode.hpp"
#include "com/sun/star/style/NumberingType.hpp"
#include "com/sun/star/style/PageStyleLayout.hpp"
#include "com/sun/star/style/ParagraphAdjust.hpp"
#include "com/sun/star/style/TabStop.hpp"
#include "com/sun/star/style/VerticalAlignment.hpp"
#include "com/sun/star/style/XStyle.hpp"
#include "com/sun/star/style/XStyleFamiliesSupplier.hpp"
#include "com/sun/star/table/BorderLine.hpp"
#include "com/sun/star/table/CellAddress.hpp"
#include "com/sun/star/table/CellContentType.hpp"
#include "com/sun/star/table/CellHoriJustify.hpp"
#include "com/sun/star/table/CellOrientation.hpp"
#include "com/sun/star/table/CellRangeAddress.hpp"
#include "com/sun/star/table/CellVertJustify.hpp"
#include "com/sun/star/table/ShadowFormat.hpp"
#include "com/sun/star/table/ShadowLocation.hpp"
#include "com/sun/star/table/TableBorder.hpp"
#include "com/sun/star/table/TableOrientation.hpp"
#include "com/sun/star/task/XInteractionHandler.hpp"
#include "com/sun/star/task/XStatusIndicator.hpp"
#include "com/sun/star/task/XStatusIndicatorFactory.hpp"
#include "com/sun/star/text/CharacterCompressionType.hpp"
#include "com/sun/star/text/ControlCharacter.hpp"
#include "com/sun/star/text/FilenameDisplayFormat.hpp"
#include "com/sun/star/text/FontEmphasis.hpp"
#include "com/sun/star/text/GraphicCrop.hpp"
#include "com/sun/star/text/HoriOrientation.hpp"
#include "com/sun/star/text/RelOrientation.hpp"
#include "com/sun/star/text/RubyAdjust.hpp"
#include "com/sun/star/text/TextContentAnchorType.hpp"
#include "com/sun/star/text/VertOrientation.hpp"
#include "com/sun/star/text/WrapTextMode.hpp"
#include "com/sun/star/text/WritingMode.hpp"
#include "com/sun/star/text/WritingMode2.hpp"
#include "com/sun/star/text/XDefaultNumberingProvider.hpp"
#include "com/sun/star/text/XNumberingFormatter.hpp"
#include "com/sun/star/text/XNumberingTypeInfo.hpp"
#include "com/sun/star/text/XRubySelection.hpp"
#include "com/sun/star/text/XSimpleText.hpp"
#include "com/sun/star/text/XText.hpp"
#include "com/sun/star/text/XTextContent.hpp"
#include "com/sun/star/text/XTextCursor.hpp"
#include "com/sun/star/text/XTextField.hdl"
#include "com/sun/star/text/XTextField.hpp"
#include "com/sun/star/text/XTextRange.hpp"
#include "com/sun/star/text/XTextRangeCompare.hpp"
#include "com/sun/star/text/XTextRangeMover.hpp"
#include "com/sun/star/ucb/CommandAbortedException.hpp"
#include "com/sun/star/ucb/NameClash.hpp"
#include "com/sun/star/ucb/NumberedSortingInfo.hpp"
#include "com/sun/star/ucb/TransferInfo.hpp"
#include "com/sun/star/ucb/XAnyCompare.hpp"
#include "com/sun/star/ucb/XAnyCompareFactory.hpp"
#include "com/sun/star/ucb/XCommandEnvironment.hpp"
#include "com/sun/star/ucb/XContent.hpp"
#include "com/sun/star/ucb/XContentAccess.hpp"
#include "com/sun/star/ucb/XContentProvider.hpp"
#include "com/sun/star/ucb/XSimpleFileAccess.hpp"
#include "com/sun/star/ucb/XSortedDynamicResultSetFactory.hpp"
#include "com/sun/star/ui/ImageType.hpp"
#include "com/sun/star/ui/ItemStyle.hpp"
#include "com/sun/star/ui/ItemType.hpp"
#include "com/sun/star/ui/UIElementType.hpp"
#include "com/sun/star/ui/XImageManager.hpp"
#include "com/sun/star/ui/XModuleUIConfigurationManager.hpp"
#include "com/sun/star/ui/XModuleUIConfigurationManagerSupplier.hpp"
#include "com/sun/star/ui/XUIConfiguration.hpp"
#include "com/sun/star/ui/XUIConfigurationListener.hpp"
#include "com/sun/star/ui/XUIConfigurationManager.hpp"
#include "com/sun/star/ui/XUIConfigurationManagerSupplier.hpp"
#include "com/sun/star/ui/XUIConfigurationPersistence.hpp"
#include "com/sun/star/ui/XUIConfigurationStorage.hpp"
#include "com/sun/star/ui/XUIElement.hpp"
#include "com/sun/star/ui/dialogs/CommonFilePickerElementIds.hpp"
#include "com/sun/star/ui/dialogs/ExecutableDialogResults.hpp"
#include "com/sun/star/ui/dialogs/ExtendedFilePickerElementIds.hpp"
#include "com/sun/star/ui/dialogs/FilePreviewImageFormats.hpp"
#include "com/sun/star/ui/dialogs/ListboxControlActions.hpp"
#include "com/sun/star/ui/dialogs/TemplateDescription.hpp"
#include "com/sun/star/ui/dialogs/XExecutableDialog.hpp"
#include "com/sun/star/ui/dialogs/XFilePicker.hpp"
#include "com/sun/star/ui/dialogs/XFilePickerControlAccess.hpp"
#include "com/sun/star/ui/dialogs/XFilePickerListener.hpp"
#include "com/sun/star/ui/dialogs/XFilePickerNotifier.hpp"
#include "com/sun/star/ui/dialogs/XFilePreview.hpp"
#include "com/sun/star/ui/dialogs/XFilterManager.hpp"
#include "com/sun/star/ui/dialogs/XFolderPicker.hpp"
#include "com/sun/star/uno/Any.h"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Reference.h"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Sequence.h"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.h"
#include "com/sun/star/uno/XAggregation.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/XNamingService.hpp"
#include "com/sun/star/util/Date.hpp"
#include "com/sun/star/util/DateTime.hpp"
#include "com/sun/star/util/Language.hpp"
#include "com/sun/star/util/MeasureUnit.hpp"
#include "com/sun/star/util/NumberFormat.hpp"
#include "com/sun/star/util/SearchAlgorithms.hpp"
#include "com/sun/star/util/SearchFlags.hpp"
#include "com/sun/star/util/SearchOptions.hpp"
#include "com/sun/star/util/SearchResult.hpp"
#include "com/sun/star/util/SortField.hpp"
#include "com/sun/star/util/SortFieldType.hpp"
#include "com/sun/star/util/URL.hpp"
#include "com/sun/star/util/XCancellable.hpp"
#include "com/sun/star/util/XChangesBatch.hpp"
#include "com/sun/star/util/XCloneable.hpp"
#include "com/sun/star/util/XCloseable.hpp"
#include "com/sun/star/util/XFlushable.hpp"
#include "com/sun/star/util/XLocalizedAliases.hpp"
#include "com/sun/star/util/XModeChangeBroadcaster.hpp"
#include "com/sun/star/util/XModeChangeListener.hpp"
#include "com/sun/star/util/XModeSelector.hpp"
#include "com/sun/star/util/XModifiable.hpp"
#include "com/sun/star/util/XModifyBroadcaster.hpp"
#include "com/sun/star/util/XModifyListener.hpp"
#include "com/sun/star/util/XNumberFormatTypes.hpp"
#include "com/sun/star/util/XNumberFormats.hpp"
#include "com/sun/star/util/XNumberFormatsSupplier.hpp"
#include "com/sun/star/util/XNumberFormatter.hpp"
#include "com/sun/star/util/XTextSearch.hpp"
#include "com/sun/star/util/XURLTransformer.hpp"
#include "com/sun/star/util/logging/LogLevel.hpp"
#include "com/sun/star/util/logging/XLogger.hpp"
#include "com/sun/star/view/XSelectionChangeListener.hpp"
#include "com/sun/star/view/XSelectionSupplier.hpp"
#include "com/sun/star/xforms/XFormsSupplier.hpp"
#include "com/sun/star/xforms/XFormsUIHelper1.hpp"
#include "com/sun/star/xforms/XModel.hpp"
#include "com/sun/star/xforms/XSubmission.hpp"
#include "com/sun/star/xml/AttributeData.hpp"
#include "com/sun/star/xml/dom/DOMException.hpp"
#include "com/sun/star/xml/dom/XDocument.hpp"
#include "com/sun/star/xml/dom/XNode.hpp"
#include "com/sun/star/xml/dom/events/XEventListener.hpp"
#include "com/sun/star/xml/dom/events/XEventTarget.hpp"
#include "com/sun/star/xml/sax/InputSource.hpp"
#include "com/sun/star/xml/sax/SAXParseException.hpp"
#include "com/sun/star/xml/sax/XAttributeList.hpp"
#include "com/sun/star/xml/sax/XDocumentHandler.hpp"
#include "com/sun/star/xml/sax/XParser.hpp"
#include "comphelper/accessibleeventnotifier.hxx"
#include "comphelper/anytostring.hxx"
#include "comphelper/broadcasthelper.hxx"
#include "comphelper/componentcontext.hxx"
#include "comphelper/configurationhelper.hxx"
#include "comphelper/container.hxx"
#include "comphelper/embeddedobjectcontainer.hxx"
#include "comphelper/enumhelper.hxx"
#include "comphelper/implementationreference.hxx"
#include "comphelper/interaction.hxx"
#include "comphelper/numbers.hxx"
#include "comphelper/processfactory.hxx"
#include "comphelper/propertycontainer.hxx"
#include "comphelper/propertysethelper.hxx"
#include "comphelper/regpathhelper.hxx"
#include "comphelper/scopeguard.hxx"
#include "comphelper/seqstream.hxx"
#include "comphelper/sequence.hxx"
#include "comphelper/sequenceashashmap.hxx"
#include "comphelper/sequenceasvector.hxx"
#include "comphelper/servicehelper.hxx"
#include "comphelper/storagehelper.hxx"
#include "comphelper/types.hxx"
#include "comphelper/uno3.hxx"
#include "cppuhelper/bootstrap.hxx"
#include "cppuhelper/compbase12.hxx"
#include "cppuhelper/compbase2.hxx"
#include "cppuhelper/compbase3.hxx"
#include "cppuhelper/compbase4.hxx"
#include "cppuhelper/compbase6.hxx"
#include "cppuhelper/compbase7.hxx"
#include "cppuhelper/component.hxx"
#include "cppuhelper/component_context.hxx"
#include "cppuhelper/exc_hlp.hxx"
#include "cppuhelper/factory.hxx"
#include "cppuhelper/implbase1.hxx"
#include "cppuhelper/implbase11.hxx"
#include "cppuhelper/implbase12.hxx"
#include "cppuhelper/implbase2.hxx"
#include "cppuhelper/implbase3.hxx"
#include "cppuhelper/implbase4.hxx"
#include "cppuhelper/implbase5.hxx"
#include "cppuhelper/implbase6.hxx"
#include "cppuhelper/implbase8.hxx"
#include "cppuhelper/implementationentry.hxx"
#include "cppuhelper/interfacecontainer.h"
#include "cppuhelper/interfacecontainer.hxx"
#include "cppuhelper/propshlp.hxx"
#include "cppuhelper/queryinterface.hxx"
#include "cppuhelper/servicefactory.hxx"
#include "cppuhelper/typeprovider.hxx"
#include "cppuhelper/weak.hxx"
#include "cppuhelper/weakagg.hxx"
#include "cppuhelper/weakref.hxx"
#include "i18npool/lang.h"
#include "i18npool/mslangid.hxx"
#include "linguistic/lngprops.hxx"
#include "osl/diagnose.h"
#include "osl/endian.h"
#include "osl/file.hxx"
#include "osl/interlck.h"
#include "osl/module.h"
#include "osl/module.hxx"
#include "osl/mutex.hxx"
#include "osl/nlsupport.h"
#include "osl/process.h"
#include "osl/security.hxx"
#include "rsc/rscsfx.hxx"
#include "rtl/bootstrap.hxx"
#include "rtl/cipher.h"
#include "rtl/crc.h"
#include "rtl/digest.h"
#include "rtl/locale.h"
#include "rtl/logfile.hxx"
#include "rtl/math.hxx"
#include "rtl/memory.h"
#include "rtl/tencinfo.h"
#include "rtl/textenc.h"
#include "rtl/ustrbuf.hxx"
#include "rtl/ustring.hxx"
#include "rtl/uuid.h"
#include "sal/config.h"
#include "sal/main.h"
#include "sal/types.h"
#include "svl/srchdefs.hxx"
#include "sot/clsids.hxx"
#include "sot/exchange.hxx"
#include "sot/factory.hxx"
#include "sot/formats.hxx"
#include <map>
#include <set>
#include <slist>
#include <vector>
#include "svtools/FilterConfigItem.hxx"
#include "svtools/accessibilityoptions.hxx"
#include "svl/adrparse.hxx"
#include "svtools/apearcfg.hxx"
#include "svl/brdcst.hxx"
#include "unotools/cacheoptions.hxx"
#include "svl/cjkoptions.hxx"
#include "unotools/cmdoptions.hxx"
#include "svl/cntwall.hxx"
#include "svtools/colorcfg.hxx"
#include "svl/ctloptions.hxx"
#include "unotools/defaultoptions.hxx"
#include "unotools/dynamicmenuoptions.hxx"
#include "svtools/ehdl.hxx"
#include "svl/eitem.hxx"
#include "unotools/eventcfg.hxx"
#include "unotools/extendedsecurityoptions.hxx"
#include "svl/filenotation.hxx"
#include "svl/flagitem.hxx"
#include "unotools/fltrcfg.hxx"
#include "unotools/fontoptions.hxx"
#include "svtools/fontsubstconfig.hxx"
#include "svtools/helpopt.hxx"
#include "svl/hint.hxx"
#include "svtools/htmlkywd.hxx"
#include "svtools/htmltokn.h"
#include "svl/intitem.hxx"
#include "svl/isethint.hxx"
#include "svl/itemiter.hxx"
#include "svl/itempool.hxx"
#include "svl/itemprop.hxx"
#include "svl/itemset.hxx"
#include "unotools/javaoptions.hxx"
#include "svl/languageoptions.hxx"
#include "unotools/lingucfg.hxx"
#include "unotools/linguprops.hxx"
#include "svl/lngmisc.hxx"
#include "svtools/localresaccess.hxx"
#include "svl/lstner.hxx"
#include "svl/macitem.hxx"
#include "svtools/menuoptions.hxx"
#include "svl/metitem.hxx"
#include "unotools/misccfg.hxx"
#include "svtools/miscopt.hxx"
#include "unotools/moduleoptions.hxx"
#include "svl/numuno.hxx"
#include "unotools/optionsdlg.hxx"
#include "svtools/parhtml.hxx"
#include "svtools/parrtf.hxx"
#include "unotools/pathoptions.hxx"
#include "svl/poolitem.hxx"
#include "unotools/printwarningoptions.hxx"
#include "svl/ptitem.hxx"
#include "svl/rectitem.hxx"
#include "svl/rngitem.hxx"
#include "svtools/rtfkeywd.hxx"
#include "svtools/rtfout.hxx"
#include "svtools/rtftoken.h"
#include "unotools/saveopt.hxx"
#include "unotools/searchopt.hxx"
#include "unotools/securityoptions.hxx"
#include "svl/sfontitm.hxx"
#include "svl/slstitm.hxx"
#include "svl/smplhint.hxx"
#include "svtools/soerr.hxx"
#include "unotools/sourceviewconfig.hxx"
#include "unotools/startoptions.hxx"
#include "svtools/stdmenu.hxx"
#include "svtools/stringtransfer.hxx"
#include "svl/stritem.hxx"
#include "svl/style.hxx"
#include "svl/svarray.hxx"
#include "svl/svstdarr.hxx"
#include "unotools/syslocaleoptions.hxx"
#include "svl/szitem.hxx"
#include "svtools/textdata.hxx"
#include "svtools/transfer.hxx"
#include "svtools/txtcmp.hxx"
#include "svl/undo.hxx"
#include "unotools/undoopt.hxx"
#include "svtools/unoevent.hxx"
#include "svtools/unoimap.hxx"
#include "svl/urihelper.hxx"
#include "svl/urlbmk.hxx"
#include "unotools/useroptions.hxx"
#include "unotools/viewoptions.hxx"
#include "svl/visitem.hxx"
#include "svl/whiter.hxx"
#include "sys/stat.h"
#include "sys/types.h"
#include "toolkit/awt/vclxdevice.hxx"
#include "toolkit/controls/unocontrol.hxx"
#include "tools/bigint.hxx"
#include "tools/color.hxx"
#include "tools/config.hxx"
#include "tools/contnr.hxx"
#include "tools/debug.hxx"
#include "tools/diagnose_ex.h"
#include "tools/dynary.hxx"
#include "tools/errcode.hxx"
#include "tools/errinf.hxx"
#include "tools/fract.hxx"
#include "tools/gen.hxx"
#include "tools/globname.hxx"
#include "tools/inetdef.hxx"
#include "tools/line.hxx"
#include "tools/link.hxx"
#include "tools/list.hxx"
#include "tools/multisel.hxx"
#include "tools/poly.hxx"
#include "tools/rc.h"
#include "tools/rc.hxx"
#include "tools/rcid.h"
#include "tools/ref.hxx"
#include "tools/resary.hxx"
#include "tools/resid.hxx"
#include "tools/resmgr.hxx"
#include "tools/rtti.hxx"
#include "tools/shl.hxx"
#include "tools/solar.h"
#include "tools/stack.hxx"
#include "tools/string.hxx"
#include "tools/table.hxx"
#include "tools/tenccvt.hxx"
#include "tools/urlobj.hxx"
#include "tools/vcompat.hxx"
#include "tools/vector2d.hxx"
#include "tools/weakbase.hxx"
#include "tools/wldcrd.hxx"
#include "tools/zcodec.hxx"
#include "ucbhelper/commandenvironment.hxx"
#include "ucbhelper/configurationkeys.hxx"
#include "ucbhelper/content.hxx"
#include "ucbhelper/contentbroker.hxx"
#include "unicode/ubidi.h"
#include "uno/lbnames.h"
#include "uno/mapping.hxx"
#include "unotools/accessiblerelationsethelper.hxx"
#include "unotools/accessiblestatesethelper.hxx"
#include "unotools/bootstrap.hxx"
#include "unotools/charclass.hxx"
#include "unotools/collatorwrapper.hxx"
#include "unotools/configitem.hxx"
#include "unotools/configmgr.hxx"
#include "unotools/confignode.hxx"
#include "unotools/configpathes.hxx"
#include "unotools/configvaluecontainer.hxx"
#include "unotools/localfilehelper.hxx"
#include "unotools/processfactory.hxx"
#include "comphelper/servicehelper.hxx"
#include "unotools/streamwrap.hxx"
#include "unotools/textsearch.hxx"
#include "unotools/transliterationwrapper.hxx"
#include "unotools/ucbhelper.hxx"
#include "vcl/abstdlg.hxx"
#include "vcl/animate.hxx"
#include "vcl/bitmap.hxx"
#include "vcl/bitmapex.hxx"
#include "vcl/bmpacc.hxx"
#include "vcl/cmdevt.h"
#include "vcl/configsettings.hxx"
#include "vcl/controllayout.hxx"
#include "vcl/cursor.hxx"
#include "vcl/decoview.hxx"
#include "vcl/dndhelp.hxx"
#include "tools/fldunit.hxx"
#include "vcl/fntstyle.hxx"
#include "unotools/fontcvt.hxx"
#include "vcl/gdimtf.hxx"
#include "vcl/help.hxx"
#include "vcl/image.hxx"
#include "vcl/jobset.hxx"
#include "vcl/keycodes.hxx"
#include "vcl/mapmod.hxx"
#include "vcl/menu.hxx"
#include "vcl/mnemonic.hxx"
#include "vcl/pointr.hxx"
#include "vcl/region.hxx"
#include "vcl/salbtype.hxx"
#include "vcl/stdtext.hxx"
#include "vcl/timer.hxx"
#include "vcl/unohelp.hxx"
#include "vcl/unohelp2.hxx"
#include "vcl/wall.hxx"
#include "tools/wintypes.hxx"
#include "vos/mutex.hxx"
#include "vos/ref.hxx"
#include "vos/refernce.hxx"
#include "vos/thread.hxx"
#include "vos/xception.hxx"
#include "xmloff/DashStyle.hxx"
#include "xmloff/GradientStyle.hxx"
#include "xmloff/HatchStyle.hxx"
#include "xmloff/ImageStyle.hxx"
#include "xmloff/MarkerStyle.hxx"
#include "xmloff/attrlist.hxx"
#include "xmloff/nmspmap.hxx"
#include "xmloff/xmlcnimp.hxx"
#include "xmloff/xmlictxt.hxx"
#include "xmloff/xmlnmspe.hxx"
#include "xmloff/xmlstyle.hxx"
#include "xmloff/xmltoken.hxx"
//---MARKER---
#endif

