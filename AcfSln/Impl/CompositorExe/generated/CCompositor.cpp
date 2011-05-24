/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
**
**	This file may be used under the terms of the GNU Lesser
**	General Public License version 2.1 as published by the Free Software
**	Foundation and appearing in the file LicenseLGPL.txt included in the
**	packaging of this file.  Please review the following information to
**	ensure the GNU Lesser General Public License version 2.1 requirements
**	will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "CCompositor.h"


// ACF includes
#include "icomp/TAttribute.h"
#include "icomp/TMultiAttribute.h"
#include "icomp/CRegistryElement.h"
#include "icomp/CCompositePackageStaticInfo.h"

// ACF component includes
#include "BasePck/BasePck.h"
#include "CmpstrPck/CmpstrPck.h"
#include "QtGuiPck/QtGuiPck.h"
#include "QtPck/QtPck.h"
#include "QtViewPck/QtViewPck.h"



CCompositor::CCompositor()
{
	SetComponentContext(&s_mainComponentContext, NULL, false);
}


// static attributes
icomp::CRegistryElement CCompositor::s_mainElement;
CCompositor::CMainRegistry CCompositor::s_mainRegistry;
CCompositor::CLocalEnvironmentManager CCompositor::s_localEnvironmentManager;
icomp::CCompositeComponentContext CCompositor::s_mainComponentContext(&s_mainElement, &s_localEnvironmentManager, &s_mainRegistry, &s_localEnvironmentManager, NULL);


// Embedded class CMainRegistry

CCompositor::CMainRegistry::CMainRegistry()
{
	// element 'Application' of type CmpstrVoce::CompositorApplication
	icomp::IRegistry::ElementInfo* infoApplicationPtr = InsertElementInfo(
				"Application",
				icomp::CComponentAddress("CmpstrVoce", "CompositorApplication"),
				true);
	if ((infoApplicationPtr != NULL) && infoApplicationPtr->elementPtr.IsValid()){
		// create and set attribute value for 'CompositorTemplate'
		icomp::IRegistryElement::AttributeInfo* attrInfoCompositorTemplatePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("CompositorTemplate", "icomp::CMultiReferenceAttribute");
		if (attrInfoCompositorTemplatePtr != NULL){
			attrInfoCompositorTemplatePtr->attributePtr.SetPtr(new icomp::CMultiReferenceAttribute);
			I_ASSERT(attrInfoCompositorTemplatePtr->attributePtr.IsValid());

			icomp::TMultiAttribute<std::string>* nattrInfoCompositorTemplatePtr = dynamic_cast<icomp::TMultiAttribute<std::string>*>(attrInfoCompositorTemplatePtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoCompositorTemplatePtr != NULL);

			nattrInfoCompositorTemplatePtr->Reset();
			nattrInfoCompositorTemplatePtr->InsertValue("CompositorTemplate");
		}

		// create and set attribute value for 'MainWindowsComponents'
		icomp::IRegistryElement::AttributeInfo* attrInfoMainWindowsComponentsPtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("MainWindowsComponents", "icomp::CMultiReferenceAttribute");
		if (attrInfoMainWindowsComponentsPtr != NULL){
			attrInfoMainWindowsComponentsPtr->attributePtr.SetPtr(new icomp::CMultiReferenceAttribute);
			I_ASSERT(attrInfoMainWindowsComponentsPtr->attributePtr.IsValid());

			icomp::TMultiAttribute<std::string>* nattrInfoMainWindowsComponentsPtr = dynamic_cast<icomp::TMultiAttribute<std::string>*>(attrInfoMainWindowsComponentsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoMainWindowsComponentsPtr != NULL);

			nattrInfoMainWindowsComponentsPtr->Reset();
			nattrInfoMainWindowsComponentsPtr->InsertValue("MainWindowComponents/AttributeEditorDock");
			nattrInfoMainWindowsComponentsPtr->InsertValue("MainWindowComponents/LogDock");
			nattrInfoMainWindowsComponentsPtr->InsertValue("MainWindowComponents/PackageOverviewDock");
			nattrInfoMainWindowsComponentsPtr->InsertValue("MainWindowComponents/QuickHelpDock");
		}
	}

	// element 'CompositorTemplate' of type CmpstrVoce::CompositorTemplate
	icomp::IRegistry::ElementInfo* infoCompositorTemplatePtr = InsertElementInfo(
				"CompositorTemplate",
				icomp::CComponentAddress("CmpstrVoce", "CompositorTemplate"),
				true);
	if ((infoCompositorTemplatePtr != NULL) && infoCompositorTemplatePtr->elementPtr.IsValid()){
		// create and set attribute value for 'ConfigFilePath'
		icomp::IRegistryElement::AttributeInfo* attrInfoConfigFilePathPtr = infoCompositorTemplatePtr->elementPtr->InsertAttributeInfo("ConfigFilePath", "icomp::CReferenceAttribute");
		if (attrInfoConfigFilePathPtr != NULL){
			attrInfoConfigFilePathPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoConfigFilePathPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrConfigFilePathPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoConfigFilePathPtr->attributePtr.GetPtr());
			I_ASSERT(attrConfigFilePathPtr != NULL);
			attrConfigFilePathPtr->SetValue("Application/ConfigFile");
		}

		// create and set attribute value for 'DocumentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentManagerPtr = infoCompositorTemplatePtr->elementPtr->InsertAttributeInfo("DocumentManager", "icomp::CReferenceAttribute");
		if (attrInfoDocumentManagerPtr != NULL){
			attrInfoDocumentManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoDocumentManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrDocumentManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoDocumentManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrDocumentManagerPtr != NULL);
			attrDocumentManagerPtr->SetValue("Application/DocumentManager");
		}

		// create and set attribute value for 'Log'
		icomp::IRegistryElement::AttributeInfo* attrInfoLogPtr = infoCompositorTemplatePtr->elementPtr->InsertAttributeInfo("Log", "icomp::CReferenceAttribute");
		if (attrInfoLogPtr != NULL){
			attrInfoLogPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoLogPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrLogPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoLogPtr->attributePtr.GetPtr());
			I_ASSERT(attrLogPtr != NULL);
			attrLogPtr->SetValue("MainWindowComponents/LogDock");
		}

		// create and set attribute value for 'MainWindow'
		icomp::IRegistryElement::AttributeInfo* attrInfoMainWindowPtr = infoCompositorTemplatePtr->elementPtr->InsertAttributeInfo("MainWindow", "icomp::CReferenceAttribute");
		if (attrInfoMainWindowPtr != NULL){
			attrInfoMainWindowPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoMainWindowPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrMainWindowPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoMainWindowPtr->attributePtr.GetPtr());
			I_ASSERT(attrMainWindowPtr != NULL);
			attrMainWindowPtr->SetValue("Application");
		}

		// create and set attribute value for 'PreviewCommandFile'
		icomp::IRegistryElement::AttributeInfo* attrInfoPreviewCommandFilePtr = infoCompositorTemplatePtr->elementPtr->InsertAttributeInfo("PreviewCommandFile", "icomp::CReferenceAttribute");
		if (attrInfoPreviewCommandFilePtr != NULL){
			attrInfoPreviewCommandFilePtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoPreviewCommandFilePtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrPreviewCommandFilePtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoPreviewCommandFilePtr->attributePtr.GetPtr());
			I_ASSERT(attrPreviewCommandFilePtr != NULL);
			attrPreviewCommandFilePtr->SetValue("Application/PreviewCommandFile");
		}

		// create and set attribute value for 'QuickHelpViewer'
		icomp::IRegistryElement::AttributeInfo* attrInfoQuickHelpViewerPtr = infoCompositorTemplatePtr->elementPtr->InsertAttributeInfo("QuickHelpViewer", "icomp::CReferenceAttribute");
		if (attrInfoQuickHelpViewerPtr != NULL){
			attrInfoQuickHelpViewerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoQuickHelpViewerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrQuickHelpViewerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoQuickHelpViewerPtr->attributePtr.GetPtr());
			I_ASSERT(attrQuickHelpViewerPtr != NULL);
			attrQuickHelpViewerPtr->SetValue("MainWindowComponents/QuickHelpDock");
		}

		// create and set attribute value for 'RegistrySelectionObservers'
		icomp::IRegistryElement::AttributeInfo* attrInfoRegistrySelectionObserversPtr = infoCompositorTemplatePtr->elementPtr->InsertAttributeInfo("RegistrySelectionObservers", "icomp::CMultiReferenceAttribute");
		if (attrInfoRegistrySelectionObserversPtr != NULL){
			attrInfoRegistrySelectionObserversPtr->attributePtr.SetPtr(new icomp::CMultiReferenceAttribute);
			I_ASSERT(attrInfoRegistrySelectionObserversPtr->attributePtr.IsValid());

			icomp::TMultiAttribute<std::string>* nattrInfoRegistrySelectionObserversPtr = dynamic_cast<icomp::TMultiAttribute<std::string>*>(attrInfoRegistrySelectionObserversPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoRegistrySelectionObserversPtr != NULL);

			nattrInfoRegistrySelectionObserversPtr->Reset();
			nattrInfoRegistrySelectionObserversPtr->InsertValue("MainWindowComponents/AttributeEditorDock");
			nattrInfoRegistrySelectionObserversPtr->InsertValue("MainWindowComponents/PackageOverviewDock");
		}

		// create and set attribute value for 'VersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionInfoPtr = infoCompositorTemplatePtr->elementPtr->InsertAttributeInfo("VersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoVersionInfoPtr != NULL){
			attrInfoVersionInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoVersionInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrVersionInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoVersionInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionInfoPtr != NULL);
			attrVersionInfoPtr->SetValue("Application");
		}
	}

	// element 'MainWindowComponents' of type CmpstrVoce::CompositorDockWidgets
	icomp::IRegistry::ElementInfo* infoMainWindowComponentsPtr = InsertElementInfo(
				"MainWindowComponents",
				icomp::CComponentAddress("CmpstrVoce", "CompositorDockWidgets"),
				true);
	if ((infoMainWindowComponentsPtr != NULL) && infoMainWindowComponentsPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ConsistencyInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoConsistencyInfoPtr = infoMainWindowComponentsPtr->elementPtr->InsertAttributeInfo("ConsistencyInfo", "icomp::CReferenceAttribute");
		if (attrInfoConsistencyInfoPtr != NULL){
			attrInfoConsistencyInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoConsistencyInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrConsistencyInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoConsistencyInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrConsistencyInfoPtr != NULL);
			attrConsistencyInfoPtr->SetValue("CompositorTemplate");
		}

		// create and set attribute value for 'DocManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocManagerPtr = infoMainWindowComponentsPtr->elementPtr->InsertAttributeInfo("DocManager", "icomp::CReferenceAttribute");
		if (attrInfoDocManagerPtr != NULL){
			attrInfoDocManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoDocManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrDocManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoDocManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrDocManagerPtr != NULL);
			attrDocManagerPtr->SetValue("Model");
		}

		// create and set attribute value for 'DocuEditorFileParam'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocuEditorFileParamPtr = infoMainWindowComponentsPtr->elementPtr->InsertAttributeInfo("DocuEditorFileParam", "icomp::CReferenceAttribute");
		if (attrInfoDocuEditorFileParamPtr != NULL){
			attrInfoDocuEditorFileParamPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoDocuEditorFileParamPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrDocuEditorFileParamPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoDocuEditorFileParamPtr->attributePtr.GetPtr());
			I_ASSERT(attrDocuEditorFileParamPtr != NULL);
			attrDocuEditorFileParamPtr->SetValue("Application/HtmlEditorFile");
		}

		// create and set attribute value for 'DocumentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentManagerPtr = infoMainWindowComponentsPtr->elementPtr->InsertAttributeInfo("DocumentManager", "icomp::CReferenceAttribute");
		if (attrInfoDocumentManagerPtr != NULL){
			attrInfoDocumentManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoDocumentManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrDocumentManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoDocumentManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrDocumentManagerPtr != NULL);
			attrDocumentManagerPtr->SetValue("Application/DocumentManager");
		}

		// create and set attribute value for 'EnvironmentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoEnvironmentManagerPtr = infoMainWindowComponentsPtr->elementPtr->InsertAttributeInfo("EnvironmentManager", "icomp::CReferenceAttribute");
		if (attrInfoEnvironmentManagerPtr != NULL){
			attrInfoEnvironmentManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoEnvironmentManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrEnvironmentManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoEnvironmentManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrEnvironmentManagerPtr != NULL);
			attrEnvironmentManagerPtr->SetValue("CompositorTemplate");
		}

		// create and set attribute value for 'MetaInfoManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoMetaInfoManagerPtr = infoMainWindowComponentsPtr->elementPtr->InsertAttributeInfo("MetaInfoManager", "icomp::CReferenceAttribute");
		if (attrInfoMetaInfoManagerPtr != NULL){
			attrInfoMetaInfoManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoMetaInfoManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrMetaInfoManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoMetaInfoManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrMetaInfoManagerPtr != NULL);
			attrMetaInfoManagerPtr->SetValue("CompositorTemplate");
		}

		// create and set attribute value for 'TechDocuViewerFileParam'
		icomp::IRegistryElement::AttributeInfo* attrInfoTechDocuViewerFileParamPtr = infoMainWindowComponentsPtr->elementPtr->InsertAttributeInfo("TechDocuViewerFileParam", "icomp::CReferenceAttribute");
		if (attrInfoTechDocuViewerFileParamPtr != NULL){
			attrInfoTechDocuViewerFileParamPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoTechDocuViewerFileParamPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrTechDocuViewerFileParamPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoTechDocuViewerFileParamPtr->attributePtr.GetPtr());
			I_ASSERT(attrTechDocuViewerFileParamPtr != NULL);
			attrTechDocuViewerFileParamPtr->SetValue("Application/HtmlBrowserFile");
		}

		// create and set attribute value for 'VersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionInfoPtr = infoMainWindowComponentsPtr->elementPtr->InsertAttributeInfo("VersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoVersionInfoPtr != NULL){
			attrInfoVersionInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoVersionInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrVersionInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoVersionInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionInfoPtr != NULL);
			attrVersionInfoPtr->SetValue("Application");
		}
	}

	// interface export
	SetElementInterfaceExported(
				"Application",
				"ibase::IApplication",
				true);
}


// Embedded class CAcfGuiVocePck

CCompositor::CAcfGuiVocePck::CAcfGuiVocePck(const icomp::IComponentEnvironmentManager* managerPtr)
:	icomp::CCompositePackageStaticInfo("AcfGuiVoce", managerPtr)

{
	RegisterEmbeddedComponent("Log");
	RegisterEmbeddedComponent("LogDock");
	RegisterEmbeddedComponent("MultiDocApp");
	RegisterEmbeddedComponent("SettingsPersistence");
}


// Embedded class CLogRegistry

CCompositor::CAcfGuiVocePck::CLogRegistry::CLogRegistry()
{
	// element 'LogGui' of type QtGuiPck::LogGui
	icomp::IRegistry::ElementInfo* infoLogGuiPtr = InsertElementInfo(
				"LogGui",
				icomp::CComponentAddress("QtGuiPck", "LogGui"),
				true);
	if ((infoLogGuiPtr != NULL) && infoLogGuiPtr->elementPtr.IsValid()){
		// create and set attribute value for 'DefaultMode'
		icomp::IRegistryElement::AttributeInfo* attrInfoDefaultModePtr = infoLogGuiPtr->elementPtr->InsertAttributeInfo("DefaultMode", "icomp::TAttribute<int>");
		if (attrInfoDefaultModePtr != NULL){
			attrInfoDefaultModePtr->exportId = "DefaultMode";
		}

		// create and set attribute value for 'Exporter'
		icomp::IRegistryElement::AttributeInfo* attrInfoExporterPtr = infoLogGuiPtr->elementPtr->InsertAttributeInfo("Exporter", "icomp::CReferenceAttribute");
		if (attrInfoExporterPtr != NULL){
			attrInfoExporterPtr->exportId = "Exporter";
		}

		// create and set attribute value for 'MaxMessageCount'
		icomp::IRegistryElement::AttributeInfo* attrInfoMaxMessageCountPtr = infoLogGuiPtr->elementPtr->InsertAttributeInfo("MaxMessageCount", "icomp::TAttribute<int>");
		if (attrInfoMaxMessageCountPtr != NULL){
			attrInfoMaxMessageCountPtr->exportId = "MaxMessageCount";
		}
	}

	// element 'LogModel' of type BasePck::Log
	icomp::IRegistry::ElementInfo* infoLogModelPtr = InsertElementInfo(
				"LogModel",
				icomp::CComponentAddress("BasePck", "Log"),
				true);
	if ((infoLogModelPtr != NULL) && infoLogModelPtr->elementPtr.IsValid()){
		// create and set attribute value for 'MaxMessageCount'
		icomp::IRegistryElement::AttributeInfo* attrInfoMaxMessageCountPtr = infoLogModelPtr->elementPtr->InsertAttributeInfo("MaxMessageCount", "icomp::TAttribute<int>");
		if (attrInfoMaxMessageCountPtr != NULL){
			attrInfoMaxMessageCountPtr->exportId = "MaxMessageCount";
		}
	}

	// element 'ModelEditorGui' of type QtGuiPck::ModelEditorGui
	icomp::IRegistry::ElementInfo* infoModelEditorGuiPtr = InsertElementInfo(
				"ModelEditorGui",
				icomp::CComponentAddress("QtGuiPck", "ModelEditorGui"),
				true);
	if ((infoModelEditorGuiPtr != NULL) && infoModelEditorGuiPtr->elementPtr.IsValid()){
		// create and set attribute value for 'Model'
		icomp::IRegistryElement::AttributeInfo* attrInfoModelPtr = infoModelEditorGuiPtr->elementPtr->InsertAttributeInfo("Model", "icomp::CReferenceAttribute");
		if (attrInfoModelPtr != NULL){
			attrInfoModelPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoModelPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrModelPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoModelPtr->attributePtr.GetPtr());
			I_ASSERT(attrModelPtr != NULL);
			attrModelPtr->SetValue("LogModel");
		}

		// create and set attribute value for 'SlaveEditorGui'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveEditorGuiPtr = infoModelEditorGuiPtr->elementPtr->InsertAttributeInfo("SlaveEditorGui", "icomp::CReferenceAttribute");
		if (attrInfoSlaveEditorGuiPtr != NULL){
			attrInfoSlaveEditorGuiPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSlaveEditorGuiPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSlaveEditorGuiPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSlaveEditorGuiPtr->attributePtr.GetPtr());
			I_ASSERT(attrSlaveEditorGuiPtr != NULL);
			attrSlaveEditorGuiPtr->SetValue("LogGui");
		}
	}

	// interface export
	SetElementInterfaceExported(
				"LogModel",
				"ibase::IMessageConsumer",
				true);
	SetElementInterfaceExported(
				"LogModel",
				"ibase::IMessageContainer",
				true);
	SetElementInterfaceExported(
				"ModelEditorGui",
				"iqtgui::IGuiObject",
				true);
}


// Embedded class CLogDockRegistry

CCompositor::CAcfGuiVocePck::CLogDockRegistry::CLogDockRegistry()
{
	// element 'FileDialogLoader' of type QtGuiPck::FileDialogLoader
	icomp::IRegistry::ElementInfo* infoFileDialogLoaderPtr = InsertElementInfo(
				"FileDialogLoader",
				icomp::CComponentAddress("QtGuiPck", "FileDialogLoader"),
				true);
	if ((infoFileDialogLoaderPtr != NULL) && infoFileDialogLoaderPtr->elementPtr.IsValid()){
		// create and set attribute value for 'Loaders'
		icomp::IRegistryElement::AttributeInfo* attrInfoLoadersPtr = infoFileDialogLoaderPtr->elementPtr->InsertAttributeInfo("Loaders", "icomp::CMultiReferenceAttribute");
		if (attrInfoLoadersPtr != NULL){
			attrInfoLoadersPtr->attributePtr.SetPtr(new icomp::CMultiReferenceAttribute);
			I_ASSERT(attrInfoLoadersPtr->attributePtr.IsValid());

			icomp::TMultiAttribute<std::string>* nattrInfoLoadersPtr = dynamic_cast<icomp::TMultiAttribute<std::string>*>(attrInfoLoadersPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoLoadersPtr != NULL);

			nattrInfoLoadersPtr->Reset();
			nattrInfoLoadersPtr->InsertValue("XmlFileSerializer");
		}

		// create and set attribute value for 'Log'
		icomp::IRegistryElement::AttributeInfo* attrInfoLogPtr = infoFileDialogLoaderPtr->elementPtr->InsertAttributeInfo("Log", "icomp::CReferenceAttribute");
		if (attrInfoLogPtr != NULL){
			attrInfoLogPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoLogPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrLogPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoLogPtr->attributePtr.GetPtr());
			I_ASSERT(attrLogPtr != NULL);
			attrLogPtr->SetValue("Log");
		}
	}

	// element 'Log' of type AcfGuiVoce::Log
	icomp::IRegistry::ElementInfo* infoLogPtr = InsertElementInfo(
				"Log",
				icomp::CComponentAddress("AcfGuiVoce", "Log"),
				true);
	if ((infoLogPtr != NULL) && infoLogPtr->elementPtr.IsValid()){
		// create and set attribute value for 'Exporter'
		icomp::IRegistryElement::AttributeInfo* attrInfoExporterPtr = infoLogPtr->elementPtr->InsertAttributeInfo("Exporter", "icomp::CReferenceAttribute");
		if (attrInfoExporterPtr != NULL){
			attrInfoExporterPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoExporterPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrExporterPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoExporterPtr->attributePtr.GetPtr());
			I_ASSERT(attrExporterPtr != NULL);
			attrExporterPtr->SetValue("FileDialogLoader");
		}
	}

	// element 'LogDock' of type QtGuiPck::DockWidgetGui
	icomp::IRegistry::ElementInfo* infoLogDockPtr = InsertElementInfo(
				"LogDock",
				icomp::CComponentAddress("QtGuiPck", "DockWidgetGui"),
				true);
	if ((infoLogDockPtr != NULL) && infoLogDockPtr->elementPtr.IsValid()){
		// create and set attribute value for 'AllowedDockAreas'
		icomp::IRegistryElement::AttributeInfo* attrInfoAllowedDockAreasPtr = infoLogDockPtr->elementPtr->InsertAttributeInfo("AllowedDockAreas", "icomp::TAttribute<int>");
		if (attrInfoAllowedDockAreasPtr != NULL){
			attrInfoAllowedDockAreasPtr->exportId = "AllowedDockAreas";
			attrInfoAllowedDockAreasPtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoAllowedDockAreasPtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrAllowedDockAreasPtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoAllowedDockAreasPtr->attributePtr.GetPtr());
			I_ASSERT(attrAllowedDockAreasPtr != NULL);
			attrAllowedDockAreasPtr->SetValue(12);
		}

		// create and set attribute value for 'DockArea'
		icomp::IRegistryElement::AttributeInfo* attrInfoDockAreaPtr = infoLogDockPtr->elementPtr->InsertAttributeInfo("DockArea", "icomp::TAttribute<int>");
		if (attrInfoDockAreaPtr != NULL){
			attrInfoDockAreaPtr->exportId = "DockArea";
			attrInfoDockAreaPtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoDockAreaPtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrDockAreaPtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoDockAreaPtr->attributePtr.GetPtr());
			I_ASSERT(attrDockAreaPtr != NULL);
			attrDockAreaPtr->SetValue(3);
		}

		// create and set attribute value for 'DockTitle'
		icomp::IRegistryElement::AttributeInfo* attrInfoDockTitlePtr = infoLogDockPtr->elementPtr->InsertAttributeInfo("DockTitle", "icomp::TAttribute<istd::CString>");
		if (attrInfoDockTitlePtr != NULL){
			attrInfoDockTitlePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoDockTitlePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrDockTitlePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoDockTitlePtr->attributePtr.GetPtr());
			I_ASSERT(attrDockTitlePtr != NULL);
			attrDockTitlePtr->SetValue(L"Log");
		}

		// create and set attribute value for 'SlaveGui'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveGuiPtr = infoLogDockPtr->elementPtr->InsertAttributeInfo("SlaveGui", "icomp::CReferenceAttribute");
		if (attrInfoSlaveGuiPtr != NULL){
			attrInfoSlaveGuiPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSlaveGuiPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSlaveGuiPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSlaveGuiPtr->attributePtr.GetPtr());
			I_ASSERT(attrSlaveGuiPtr != NULL);
			attrSlaveGuiPtr->SetValue("Log");
		}
	}

	// element 'XmlFileSerializer' of type BasePck::XmlFileSerializer
	icomp::IRegistry::ElementInfo* infoXmlFileSerializerPtr = InsertElementInfo(
				"XmlFileSerializer",
				icomp::CComponentAddress("BasePck", "XmlFileSerializer"),
				true);
	if ((infoXmlFileSerializerPtr != NULL) && infoXmlFileSerializerPtr->elementPtr.IsValid()){
		// create and set attribute value for 'FileExtensions'
		icomp::IRegistryElement::AttributeInfo* attrInfoFileExtensionsPtr = infoXmlFileSerializerPtr->elementPtr->InsertAttributeInfo("FileExtensions", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoFileExtensionsPtr != NULL){
			attrInfoFileExtensionsPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoFileExtensionsPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoFileExtensionsPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoFileExtensionsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoFileExtensionsPtr != NULL);

			nattrInfoFileExtensionsPtr->Reset();
			nattrInfoFileExtensionsPtr->InsertValue(L"xlog");
		}

		// create and set attribute value for 'Log'
		icomp::IRegistryElement::AttributeInfo* attrInfoLogPtr = infoXmlFileSerializerPtr->elementPtr->InsertAttributeInfo("Log", "icomp::CReferenceAttribute");
		if (attrInfoLogPtr != NULL){
			attrInfoLogPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoLogPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrLogPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoLogPtr->attributePtr.GetPtr());
			I_ASSERT(attrLogPtr != NULL);
			attrLogPtr->SetValue("Log");
		}

		// create and set attribute value for 'TypeDescriptions'
		icomp::IRegistryElement::AttributeInfo* attrInfoTypeDescriptionsPtr = infoXmlFileSerializerPtr->elementPtr->InsertAttributeInfo("TypeDescriptions", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoTypeDescriptionsPtr != NULL){
			attrInfoTypeDescriptionsPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoTypeDescriptionsPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoTypeDescriptionsPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoTypeDescriptionsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoTypeDescriptionsPtr != NULL);

			nattrInfoTypeDescriptionsPtr->Reset();
			nattrInfoTypeDescriptionsPtr->InsertValue(L"Log XML file");
		}

		// create and set attribute value for 'VersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionInfoPtr = infoXmlFileSerializerPtr->elementPtr->InsertAttributeInfo("VersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoVersionInfoPtr != NULL){
			attrInfoVersionInfoPtr->exportId = "VersionInfo";
		}
	}

	// interface export
	SetElementInterfaceExported(
				"Log",
				"ibase::IMessageConsumer",
				true);
	SetElementInterfaceExported(
				"Log",
				"ibase::IMessageContainer",
				true);
	SetElementInterfaceExported(
				"LogDock",
				"iqtgui::IMainWindowComponent",
				true);
}


// Embedded class CMultiDocAppRegistry

CCompositor::CAcfGuiVocePck::CMultiDocAppRegistry::CMultiDocAppRegistry()
{
	// element 'AboutGui' of type QtGuiPck::AboutGui
	icomp::IRegistry::ElementInfo* infoAboutGuiPtr = InsertElementInfo(
				"AboutGui",
				icomp::CComponentAddress("QtGuiPck", "AboutGui"),
				true);
	if ((infoAboutGuiPtr != NULL) && infoAboutGuiPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ApplicationInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationInfoPtr = infoAboutGuiPtr->elementPtr->InsertAttributeInfo("ApplicationInfo", "icomp::CReferenceAttribute");
		if (attrInfoApplicationInfoPtr != NULL){
			attrInfoApplicationInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoApplicationInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrApplicationInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoApplicationInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrApplicationInfoPtr != NULL);
			attrApplicationInfoPtr->SetValue("ApplicationInfo");
		}

		// create and set attribute value for 'DescriptionText'
		icomp::IRegistryElement::AttributeInfo* attrInfoDescriptionTextPtr = infoAboutGuiPtr->elementPtr->InsertAttributeInfo("DescriptionText", "icomp::TAttribute<istd::CString>");
		if (attrInfoDescriptionTextPtr != NULL){
			attrInfoDescriptionTextPtr->exportId = "AboutDescriptionText";
		}

		// create and set attribute value for 'LogoPath'
		icomp::IRegistryElement::AttributeInfo* attrInfoLogoPathPtr = infoAboutGuiPtr->elementPtr->InsertAttributeInfo("LogoPath", "icomp::TAttribute<istd::CString>");
		if (attrInfoLogoPathPtr != NULL){
			attrInfoLogoPathPtr->exportId = "LogoPath";
		}

		// create and set attribute value for 'VersionIds'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdsPtr = infoAboutGuiPtr->elementPtr->InsertAttributeInfo("VersionIds", "icomp::TMultiAttribute<int>");
		if (attrInfoVersionIdsPtr != NULL){
			attrInfoVersionIdsPtr->exportId = "DisplayVersionIds";
		}

		// create and set attribute value for 'VersionNames'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionNamesPtr = infoAboutGuiPtr->elementPtr->InsertAttributeInfo("VersionNames", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoVersionNamesPtr != NULL){
			attrInfoVersionNamesPtr->exportId = "DisplayVersionNames";
		}
	}

	// element 'App' of type QtGuiPck::GuiApplication
	icomp::IRegistry::ElementInfo* infoAppPtr = InsertElementInfo(
				"App",
				icomp::CComponentAddress("QtGuiPck", "GuiApplication"),
				true);
	if ((infoAppPtr != NULL) && infoAppPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ApplicationInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationInfoPtr = infoAppPtr->elementPtr->InsertAttributeInfo("ApplicationInfo", "icomp::CReferenceAttribute");
		if (attrInfoApplicationInfoPtr != NULL){
			attrInfoApplicationInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoApplicationInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrApplicationInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoApplicationInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrApplicationInfoPtr != NULL);
			attrApplicationInfoPtr->SetValue("ApplicationInfo");
		}

		// create and set attribute value for 'IconPath'
		icomp::IRegistryElement::AttributeInfo* attrInfoIconPathPtr = infoAppPtr->elementPtr->InsertAttributeInfo("IconPath", "icomp::TAttribute<istd::CString>");
		if (attrInfoIconPathPtr != NULL){
			attrInfoIconPathPtr->exportId = "IconPath";
		}

		// create and set attribute value for 'MainGui'
		icomp::IRegistryElement::AttributeInfo* attrInfoMainGuiPtr = infoAppPtr->elementPtr->InsertAttributeInfo("MainGui", "icomp::CReferenceAttribute");
		if (attrInfoMainGuiPtr != NULL){
			attrInfoMainGuiPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoMainGuiPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrMainGuiPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoMainGuiPtr->attributePtr.GetPtr());
			I_ASSERT(attrMainGuiPtr != NULL);
			attrMainGuiPtr->SetValue("MainGui");
		}

		// create and set attribute value for 'SplashScreen'
		icomp::IRegistryElement::AttributeInfo* attrInfoSplashScreenPtr = infoAppPtr->elementPtr->InsertAttributeInfo("SplashScreen", "icomp::CReferenceAttribute");
		if (attrInfoSplashScreenPtr != NULL){
			attrInfoSplashScreenPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSplashScreenPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSplashScreenPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSplashScreenPtr->attributePtr.GetPtr());
			I_ASSERT(attrSplashScreenPtr != NULL);
			attrSplashScreenPtr->SetValue("SplashScreen");
		}

		// create and set attribute value for 'StyleSheet'
		icomp::IRegistryElement::AttributeInfo* attrInfoStyleSheetPtr = infoAppPtr->elementPtr->InsertAttributeInfo("StyleSheet", "icomp::TAttribute<istd::CString>");
		if (attrInfoStyleSheetPtr != NULL){
			attrInfoStyleSheetPtr->exportId = "StyleSheet";
			attrInfoStyleSheetPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoStyleSheetPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrStyleSheetPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoStyleSheetPtr->attributePtr.GetPtr());
			I_ASSERT(attrStyleSheetPtr != NULL);
			attrStyleSheetPtr->SetValue(L":/Style/Resources/Style/AcfStyle.ass");
		}
	}

	// element 'ApplicationInfo' of type BasePck::ApplicationInfo
	icomp::IRegistry::ElementInfo* infoApplicationInfoPtr = InsertElementInfo(
				"ApplicationInfo",
				icomp::CComponentAddress("BasePck", "ApplicationInfo"),
				true);
	if ((infoApplicationInfoPtr != NULL) && infoApplicationInfoPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ApplicationName'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationNamePtr = infoApplicationInfoPtr->elementPtr->InsertAttributeInfo("ApplicationName", "icomp::TAttribute<istd::CString>");
		if (attrInfoApplicationNamePtr != NULL){
			attrInfoApplicationNamePtr->exportId = "ApplicationName";
		}

		// create and set attribute value for 'ApplicationSubname'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationSubnamePtr = infoApplicationInfoPtr->elementPtr->InsertAttributeInfo("ApplicationSubname", "icomp::TAttribute<istd::CString>");
		if (attrInfoApplicationSubnamePtr != NULL){
			attrInfoApplicationSubnamePtr->exportId = "ApplicationSubname";
		}

		// create and set attribute value for 'ApplicationType'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationTypePtr = infoApplicationInfoPtr->elementPtr->InsertAttributeInfo("ApplicationType", "icomp::TAttribute<istd::CString>");
		if (attrInfoApplicationTypePtr != NULL){
			attrInfoApplicationTypePtr->exportId = "ApplicationType";
		}

		// create and set attribute value for 'CompanyName'
		icomp::IRegistryElement::AttributeInfo* attrInfoCompanyNamePtr = infoApplicationInfoPtr->elementPtr->InsertAttributeInfo("CompanyName", "icomp::TAttribute<istd::CString>");
		if (attrInfoCompanyNamePtr != NULL){
			attrInfoCompanyNamePtr->exportId = "CompanyName";
		}

		// create and set attribute value for 'LegalCopyright'
		icomp::IRegistryElement::AttributeInfo* attrInfoLegalCopyrightPtr = infoApplicationInfoPtr->elementPtr->InsertAttributeInfo("LegalCopyright", "icomp::TAttribute<istd::CString>");
		if (attrInfoLegalCopyrightPtr != NULL){
			attrInfoLegalCopyrightPtr->exportId = "LegalCopyright";
		}

		// create and set attribute value for 'ProductName'
		icomp::IRegistryElement::AttributeInfo* attrInfoProductNamePtr = infoApplicationInfoPtr->elementPtr->InsertAttributeInfo("ProductName", "icomp::TAttribute<istd::CString>");
		if (attrInfoProductNamePtr != NULL){
			attrInfoProductNamePtr->exportId = "ProductName";
		}

		// create and set attribute value for 'VersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionInfoPtr = infoApplicationInfoPtr->elementPtr->InsertAttributeInfo("VersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoVersionInfoPtr != NULL){
			attrInfoVersionInfoPtr->exportId = "VersionInfo";
		}
	}

	// element 'DocumentTemplate' of type BasePck::CompositeDocumentTemplate
	icomp::IRegistry::ElementInfo* infoDocumentTemplatePtr = InsertElementInfo(
				"DocumentTemplate",
				icomp::CComponentAddress("BasePck", "CompositeDocumentTemplate"),
				true);
	if ((infoDocumentTemplatePtr != NULL) && infoDocumentTemplatePtr->elementPtr.IsValid()){
		// create and set attribute value for 'SlaveTemplates'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveTemplatesPtr = infoDocumentTemplatePtr->elementPtr->InsertAttributeInfo("SlaveTemplates", "icomp::CMultiReferenceAttribute");
		if (attrInfoSlaveTemplatesPtr != NULL){
			attrInfoSlaveTemplatesPtr->exportId = "DocumentTemplates";
		}
	}

	// element 'MainGui' of type QtGuiPck::MainWindowGui
	icomp::IRegistry::ElementInfo* infoMainGuiPtr = InsertElementInfo(
				"MainGui",
				icomp::CComponentAddress("QtGuiPck", "MainWindowGui"),
				true);
	if ((infoMainGuiPtr != NULL) && infoMainGuiPtr->elementPtr.IsValid()){
		// create and set attribute value for 'AboutGui'
		icomp::IRegistryElement::AttributeInfo* attrInfoAboutGuiPtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("AboutGui", "icomp::CReferenceAttribute");
		if (attrInfoAboutGuiPtr != NULL){
			attrInfoAboutGuiPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoAboutGuiPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrAboutGuiPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoAboutGuiPtr->attributePtr.GetPtr());
			I_ASSERT(attrAboutGuiPtr != NULL);
			attrAboutGuiPtr->SetValue("AboutGui");
		}

		// create and set attribute value for 'ApplicationInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationInfoPtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("ApplicationInfo", "icomp::CReferenceAttribute");
		if (attrInfoApplicationInfoPtr != NULL){
			attrInfoApplicationInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoApplicationInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrApplicationInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoApplicationInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrApplicationInfoPtr != NULL);
			attrApplicationInfoPtr->SetValue("ApplicationInfo");
		}

		// create and set attribute value for 'DocumentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentManagerPtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("DocumentManager", "icomp::CReferenceAttribute");
		if (attrInfoDocumentManagerPtr != NULL){
			attrInfoDocumentManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoDocumentManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrDocumentManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoDocumentManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrDocumentManagerPtr != NULL);
			attrDocumentManagerPtr->SetValue("Workspace");
		}

		// create and set attribute value for 'IconSize'
		icomp::IRegistryElement::AttributeInfo* attrInfoIconSizePtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("IconSize", "icomp::TAttribute<int>");
		if (attrInfoIconSizePtr != NULL){
			attrInfoIconSizePtr->exportId = "IconSize";
			attrInfoIconSizePtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoIconSizePtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrIconSizePtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoIconSizePtr->attributePtr.GetPtr());
			I_ASSERT(attrIconSizePtr != NULL);
			attrIconSizePtr->SetValue(24);
		}

		// create and set attribute value for 'IsCopyPathVisible'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsCopyPathVisiblePtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("IsCopyPathVisible", "icomp::TAttribute<bool>");
		if (attrInfoIsCopyPathVisiblePtr != NULL){
			attrInfoIsCopyPathVisiblePtr->exportId = "IsCopyPathVisible";
		}

		// create and set attribute value for 'IsNestingEnabled'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsNestingEnabledPtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("IsNestingEnabled", "icomp::TAttribute<bool>");
		if (attrInfoIsNestingEnabledPtr != NULL){
			attrInfoIsNestingEnabledPtr->exportId = "IsNestingEnabled";
		}

		// create and set attribute value for 'IsOpenContainingFolderVisible'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsOpenContainingFolderVisiblePtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("IsOpenContainingFolderVisible", "icomp::TAttribute<bool>");
		if (attrInfoIsOpenContainingFolderVisiblePtr != NULL){
			attrInfoIsOpenContainingFolderVisiblePtr->exportId = "IsOpenContainingFolderVisible";
		}

		// create and set attribute value for 'MainWindowComponents'
		icomp::IRegistryElement::AttributeInfo* attrInfoMainWindowComponentsPtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("MainWindowComponents", "icomp::CMultiReferenceAttribute");
		if (attrInfoMainWindowComponentsPtr != NULL){
			attrInfoMainWindowComponentsPtr->exportId = "MainWindowComponents";
		}

		// create and set attribute value for 'MaxRecentFiles'
		icomp::IRegistryElement::AttributeInfo* attrInfoMaxRecentFilesPtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("MaxRecentFiles", "icomp::TAttribute<int>");
		if (attrInfoMaxRecentFilesPtr != NULL){
			attrInfoMaxRecentFilesPtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoMaxRecentFilesPtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrMaxRecentFilesPtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoMaxRecentFilesPtr->attributePtr.GetPtr());
			I_ASSERT(attrMaxRecentFilesPtr != NULL);
			attrMaxRecentFilesPtr->SetValue(10);
		}

		// create and set attribute value for 'SettingsGui'
		icomp::IRegistryElement::AttributeInfo* attrInfoSettingsGuiPtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("SettingsGui", "icomp::CReferenceAttribute");
		if (attrInfoSettingsGuiPtr != NULL){
			attrInfoSettingsGuiPtr->exportId = "SettingsGui";
		}

		// create and set attribute value for 'SettingsProvider'
		icomp::IRegistryElement::AttributeInfo* attrInfoSettingsProviderPtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("SettingsProvider", "icomp::CReferenceAttribute");
		if (attrInfoSettingsProviderPtr != NULL){
			attrInfoSettingsProviderPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSettingsProviderPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSettingsProviderPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSettingsProviderPtr->attributePtr.GetPtr());
			I_ASSERT(attrSettingsProviderPtr != NULL);
			attrSettingsProviderPtr->SetValue("SettingsProvider");
		}

		// create and set attribute value for 'UseIconText'
		icomp::IRegistryElement::AttributeInfo* attrInfoUseIconTextPtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("UseIconText", "icomp::TAttribute<bool>");
		if (attrInfoUseIconTextPtr != NULL){
			attrInfoUseIconTextPtr->exportId = "UseIconText";
		}

		// create and set attribute value for 'Workspace'
		icomp::IRegistryElement::AttributeInfo* attrInfoWorkspacePtr = infoMainGuiPtr->elementPtr->InsertAttributeInfo("Workspace", "icomp::CReferenceAttribute");
		if (attrInfoWorkspacePtr != NULL){
			attrInfoWorkspacePtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoWorkspacePtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrWorkspacePtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoWorkspacePtr->attributePtr.GetPtr());
			I_ASSERT(attrWorkspacePtr != NULL);
			attrWorkspacePtr->SetValue("Workspace");
		}
	}

	// element 'SettingsProvider' of type QtPck::ApplicationSettingsProvider
	icomp::IRegistry::ElementInfo* infoSettingsProviderPtr = InsertElementInfo(
				"SettingsProvider",
				icomp::CComponentAddress("QtPck", "ApplicationSettingsProvider"),
				true);
	if ((infoSettingsProviderPtr != NULL) && infoSettingsProviderPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ApplicationInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationInfoPtr = infoSettingsProviderPtr->elementPtr->InsertAttributeInfo("ApplicationInfo", "icomp::CReferenceAttribute");
		if (attrInfoApplicationInfoPtr != NULL){
			attrInfoApplicationInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoApplicationInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrApplicationInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoApplicationInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrApplicationInfoPtr != NULL);
			attrApplicationInfoPtr->SetValue("ApplicationInfo");
		}
	}

	// element 'SplashScreen' of type QtGuiPck::SplashScreen
	icomp::IRegistry::ElementInfo* infoSplashScreenPtr = InsertElementInfo(
				"SplashScreen",
				icomp::CComponentAddress("QtGuiPck", "SplashScreen"),
				true);
	if ((infoSplashScreenPtr != NULL) && infoSplashScreenPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ApplicationInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationInfoPtr = infoSplashScreenPtr->elementPtr->InsertAttributeInfo("ApplicationInfo", "icomp::CReferenceAttribute");
		if (attrInfoApplicationInfoPtr != NULL){
			attrInfoApplicationInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoApplicationInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrApplicationInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoApplicationInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrApplicationInfoPtr != NULL);
			attrApplicationInfoPtr->SetValue("ApplicationInfo");
		}

		// create and set attribute value for 'ImagePath'
		icomp::IRegistryElement::AttributeInfo* attrInfoImagePathPtr = infoSplashScreenPtr->elementPtr->InsertAttributeInfo("ImagePath", "icomp::TAttribute<istd::CString>");
		if (attrInfoImagePathPtr != NULL){
			attrInfoImagePathPtr->exportId = "SplashScreenImage";
		}

		// create and set attribute value for 'ShowApplicationName'
		icomp::IRegistryElement::AttributeInfo* attrInfoShowApplicationNamePtr = infoSplashScreenPtr->elementPtr->InsertAttributeInfo("ShowApplicationName", "icomp::TAttribute<bool>");
		if (attrInfoShowApplicationNamePtr != NULL){
			attrInfoShowApplicationNamePtr->exportId = "ShowSplashApplicationName";
		}

		// create and set attribute value for 'ShowApplicationSubName'
		icomp::IRegistryElement::AttributeInfo* attrInfoShowApplicationSubNamePtr = infoSplashScreenPtr->elementPtr->InsertAttributeInfo("ShowApplicationSubName", "icomp::TAttribute<bool>");
		if (attrInfoShowApplicationSubNamePtr != NULL){
			attrInfoShowApplicationSubNamePtr->exportId = "ShowSplashApplicationSubName";
		}

		// create and set attribute value for 'ShowLegalCopyright'
		icomp::IRegistryElement::AttributeInfo* attrInfoShowLegalCopyrightPtr = infoSplashScreenPtr->elementPtr->InsertAttributeInfo("ShowLegalCopyright", "icomp::TAttribute<bool>");
		if (attrInfoShowLegalCopyrightPtr != NULL){
			attrInfoShowLegalCopyrightPtr->exportId = "ShowSplashLegalCopyright";
		}

		// create and set attribute value for 'ShowProductName'
		icomp::IRegistryElement::AttributeInfo* attrInfoShowProductNamePtr = infoSplashScreenPtr->elementPtr->InsertAttributeInfo("ShowProductName", "icomp::TAttribute<bool>");
		if (attrInfoShowProductNamePtr != NULL){
			attrInfoShowProductNamePtr->exportId = "ShowSplashProductName";
		}

		// create and set attribute value for 'ShowProductType'
		icomp::IRegistryElement::AttributeInfo* attrInfoShowProductTypePtr = infoSplashScreenPtr->elementPtr->InsertAttributeInfo("ShowProductType", "icomp::TAttribute<bool>");
		if (attrInfoShowProductTypePtr != NULL){
			attrInfoShowProductTypePtr->exportId = "ShowSplashProductType";
		}

		// create and set attribute value for 'VersionIds'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdsPtr = infoSplashScreenPtr->elementPtr->InsertAttributeInfo("VersionIds", "icomp::TMultiAttribute<int>");
		if (attrInfoVersionIdsPtr != NULL){
			attrInfoVersionIdsPtr->exportId = "DisplayVersionIds";
		}

		// create and set attribute value for 'VersionNames'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionNamesPtr = infoSplashScreenPtr->elementPtr->InsertAttributeInfo("VersionNames", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoVersionNamesPtr != NULL){
			attrInfoVersionNamesPtr->exportId = "DisplayVersionNames";
		}
	}

	// element 'Workspace' of type QtGuiPck::MultiDocWorkspaceGui
	icomp::IRegistry::ElementInfo* infoWorkspacePtr = InsertElementInfo(
				"Workspace",
				icomp::CComponentAddress("QtGuiPck", "MultiDocWorkspaceGui"),
				true);
	if ((infoWorkspacePtr != NULL) && infoWorkspacePtr->elementPtr.IsValid()){
		// create and set attribute value for 'DocumentTemplate'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentTemplatePtr = infoWorkspacePtr->elementPtr->InsertAttributeInfo("DocumentTemplate", "icomp::CReferenceAttribute");
		if (attrInfoDocumentTemplatePtr != NULL){
			attrInfoDocumentTemplatePtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoDocumentTemplatePtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrDocumentTemplatePtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoDocumentTemplatePtr->attributePtr.GetPtr());
			I_ASSERT(attrDocumentTemplatePtr != NULL);
			attrDocumentTemplatePtr->SetValue("DocumentTemplate");
		}

		// create and set attribute value for 'SettingsProvider'
		icomp::IRegistryElement::AttributeInfo* attrInfoSettingsProviderPtr = infoWorkspacePtr->elementPtr->InsertAttributeInfo("SettingsProvider", "icomp::CReferenceAttribute");
		if (attrInfoSettingsProviderPtr != NULL){
			attrInfoSettingsProviderPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSettingsProviderPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSettingsProviderPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSettingsProviderPtr->attributePtr.GetPtr());
			I_ASSERT(attrSettingsProviderPtr != NULL);
			attrSettingsProviderPtr->SetValue("SettingsProvider");
		}

		// create and set attribute value for 'ShowViewMaximized'
		icomp::IRegistryElement::AttributeInfo* attrInfoShowViewMaximizedPtr = infoWorkspacePtr->elementPtr->InsertAttributeInfo("ShowViewMaximized", "icomp::TAttribute<bool>");
		if (attrInfoShowViewMaximizedPtr != NULL){
			attrInfoShowViewMaximizedPtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoShowViewMaximizedPtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrShowViewMaximizedPtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoShowViewMaximizedPtr->attributePtr.GetPtr());
			I_ASSERT(attrShowViewMaximizedPtr != NULL);
			attrShowViewMaximizedPtr->SetValue(true);
		}
	}

	// interface export
	SetElementInterfaceExported(
				"App",
				"ibase::IApplication",
				true);
	SetElementInterfaceExported(
				"ApplicationInfo",
				"ibase::IApplicationInfo",
				true);
	SetElementInterfaceExported(
				"Workspace",
				"idoc::IDocumentManager",
				true);
	SetElementInterfaceExported(
				"Workspace",
				"imod::IModel",
				true);

	// component export
	SetElementExported(
				"SettingsProvider",
				"SettingsProvider");
	SetElementExported(
				"Workspace",
				"Workspace");
}


// Embedded class CSettingsPersistenceRegistry

CCompositor::CAcfGuiVocePck::CSettingsPersistenceRegistry::CSettingsPersistenceRegistry()
{
	// element 'AutoPersistence' of type BasePck::AutoPersistence
	icomp::IRegistry::ElementInfo* infoAutoPersistencePtr = InsertElementInfo(
				"AutoPersistence",
				icomp::CComponentAddress("BasePck", "AutoPersistence"),
				true);
	if ((infoAutoPersistencePtr != NULL) && infoAutoPersistencePtr->elementPtr.IsValid()){
		infoAutoPersistencePtr->elementPtr->SetElementFlags(1);

		// create and set attribute value for 'FileLoader'
		icomp::IRegistryElement::AttributeInfo* attrInfoFileLoaderPtr = infoAutoPersistencePtr->elementPtr->InsertAttributeInfo("FileLoader", "icomp::CReferenceAttribute");
		if (attrInfoFileLoaderPtr != NULL){
			attrInfoFileLoaderPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoFileLoaderPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrFileLoaderPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoFileLoaderPtr->attributePtr.GetPtr());
			I_ASSERT(attrFileLoaderPtr != NULL);
			attrFileLoaderPtr->SetValue("SettingsSerializer");
		}

		// create and set attribute value for 'Object'
		icomp::IRegistryElement::AttributeInfo* attrInfoObjectPtr = infoAutoPersistencePtr->elementPtr->InsertAttributeInfo("Object", "icomp::CReferenceAttribute");
		if (attrInfoObjectPtr != NULL){
			attrInfoObjectPtr->exportId = "Object";
		}

		// create and set attribute value for 'RestoreonBegin'
		icomp::IRegistryElement::AttributeInfo* attrInfoRestoreonBeginPtr = infoAutoPersistencePtr->elementPtr->InsertAttributeInfo("RestoreonBegin", "icomp::TAttribute<bool>");
		if (attrInfoRestoreonBeginPtr != NULL){
			attrInfoRestoreonBeginPtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoRestoreonBeginPtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrRestoreonBeginPtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoRestoreonBeginPtr->attributePtr.GetPtr());
			I_ASSERT(attrRestoreonBeginPtr != NULL);
			attrRestoreonBeginPtr->SetValue(true);
		}

		// create and set attribute value for 'StoreOnEnd'
		icomp::IRegistryElement::AttributeInfo* attrInfoStoreOnEndPtr = infoAutoPersistencePtr->elementPtr->InsertAttributeInfo("StoreOnEnd", "icomp::TAttribute<bool>");
		if (attrInfoStoreOnEndPtr != NULL){
			attrInfoStoreOnEndPtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoStoreOnEndPtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrStoreOnEndPtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoStoreOnEndPtr->attributePtr.GetPtr());
			I_ASSERT(attrStoreOnEndPtr != NULL);
			attrStoreOnEndPtr->SetValue(true);
		}
	}

	// element 'SettingsSerializer' of type QtPck::SettingsSerializer
	icomp::IRegistry::ElementInfo* infoSettingsSerializerPtr = InsertElementInfo(
				"SettingsSerializer",
				icomp::CComponentAddress("QtPck", "SettingsSerializer"),
				true);
	if ((infoSettingsSerializerPtr != NULL) && infoSettingsSerializerPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ApplicationInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationInfoPtr = infoSettingsSerializerPtr->elementPtr->InsertAttributeInfo("ApplicationInfo", "icomp::CReferenceAttribute");
		if (attrInfoApplicationInfoPtr != NULL){
			attrInfoApplicationInfoPtr->exportId = "ApplicationInfo";
		}

		// create and set attribute value for 'Log'
		icomp::IRegistryElement::AttributeInfo* attrInfoLogPtr = infoSettingsSerializerPtr->elementPtr->InsertAttributeInfo("Log", "icomp::CReferenceAttribute");
		if (attrInfoLogPtr != NULL){
			attrInfoLogPtr->exportId = "Log";
		}

		// create and set attribute value for 'RootKey'
		icomp::IRegistryElement::AttributeInfo* attrInfoRootKeyPtr = infoSettingsSerializerPtr->elementPtr->InsertAttributeInfo("RootKey", "icomp::TAttribute<istd::CString>");
		if (attrInfoRootKeyPtr != NULL){
			attrInfoRootKeyPtr->exportId = "RootKey";
		}
	}

}


// Embedded class CAcfSlnVocePck

CCompositor::CAcfSlnVocePck::CAcfSlnVocePck(const icomp::IComponentEnvironmentManager* managerPtr)
:	icomp::CCompositePackageStaticInfo("AcfSlnVoce", managerPtr)

{
	RegisterEmbeddedComponent("VersionInfo");
}


// Embedded class CVersionInfoRegistry

CCompositor::CAcfSlnVocePck::CVersionInfoRegistry::CVersionInfoRegistry()
{
	// element 'BaseInfo' of type AcfVoce::VersionInfo
	icomp::IRegistry::ElementInfo* infoBaseInfoPtr = InsertElementInfo(
				"BaseInfo",
				icomp::CComponentAddress("AcfVoce", "VersionInfo"),
				true);
	if ((infoBaseInfoPtr != NULL) && infoBaseInfoPtr->elementPtr.IsValid()){
		// create and set attribute value for 'IsExtensionUsed'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsExtensionUsedPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("IsExtensionUsed", "icomp::TAttribute<bool>");
		if (attrInfoIsExtensionUsedPtr != NULL){
			attrInfoIsExtensionUsedPtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoIsExtensionUsedPtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrIsExtensionUsedPtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoIsExtensionUsedPtr->attributePtr.GetPtr());
			I_ASSERT(attrIsExtensionUsedPtr != NULL);
			attrIsExtensionUsedPtr->SetValue(true);
		}

		// create and set attribute value for 'KnownVersionNames'
		icomp::IRegistryElement::AttributeInfo* attrInfoKnownVersionNamesPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("KnownVersionNames", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoKnownVersionNamesPtr != NULL){
			attrInfoKnownVersionNamesPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoKnownVersionNamesPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoKnownVersionNamesPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoKnownVersionNamesPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoKnownVersionNamesPtr != NULL);

			nattrInfoKnownVersionNamesPtr->Reset();
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.2.0");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.3.0");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.3.1");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.3.2");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.4.0");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.4.1");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.4.2");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.4.3");
		}

		// create and set attribute value for 'KnownVersions'
		icomp::IRegistryElement::AttributeInfo* attrInfoKnownVersionsPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("KnownVersions", "icomp::TMultiAttribute<int>");
		if (attrInfoKnownVersionsPtr != NULL){
			attrInfoKnownVersionsPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<int>);
			I_ASSERT(attrInfoKnownVersionsPtr->attributePtr.IsValid());

			icomp::CMultiIntAttribute* nattrInfoKnownVersionsPtr = dynamic_cast<icomp::CMultiIntAttribute*>(attrInfoKnownVersionsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoKnownVersionsPtr != NULL);

			nattrInfoKnownVersionsPtr->Reset();
			nattrInfoKnownVersionsPtr->InsertValue(127);
			nattrInfoKnownVersionsPtr->InsertValue(144);
			nattrInfoKnownVersionsPtr->InsertValue(148);
			nattrInfoKnownVersionsPtr->InsertValue(183);
			nattrInfoKnownVersionsPtr->InsertValue(209);
			nattrInfoKnownVersionsPtr->InsertValue(292);
			nattrInfoKnownVersionsPtr->InsertValue(307);
			nattrInfoKnownVersionsPtr->InsertValue(313);
		}

		// create and set attribute value for 'SlaveVersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveVersionInfoPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("SlaveVersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoSlaveVersionInfoPtr != NULL){
			attrInfoSlaveVersionInfoPtr->exportId = "SlaveVersionInfo";
		}

		// create and set attribute value for 'VersionId'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("VersionId", "icomp::TAttribute<int>");
		if (attrInfoVersionIdPtr != NULL){
			attrInfoVersionIdPtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoVersionIdPtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrVersionIdPtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoVersionIdPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionIdPtr != NULL);
			attrVersionIdPtr->SetValue(1);
		}

		// create and set attribute value for 'VersionIdDesc'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdDescPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("VersionIdDesc", "icomp::TAttribute<istd::CString>");
		if (attrInfoVersionIdDescPtr != NULL){
			attrInfoVersionIdDescPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoVersionIdDescPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrVersionIdDescPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoVersionIdDescPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionIdDescPtr != NULL);
			attrVersionIdDescPtr->SetValue(L"ACF-Solutions");
		}

		// create and set attribute value for 'VersionNumber'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionNumberPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("VersionNumber", "icomp::TAttribute<int>");
		if (attrInfoVersionNumberPtr != NULL){
			attrInfoVersionNumberPtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoVersionNumberPtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrVersionNumberPtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoVersionNumberPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionNumberPtr != NULL);
			attrVersionNumberPtr->SetValue(338);
		}
	}

	// element 'VersionInfo' of type BasePck::VersionInfo
	icomp::IRegistry::ElementInfo* infoVersionInfoPtr = InsertElementInfo(
				"VersionInfo",
				icomp::CComponentAddress("BasePck", "VersionInfo"),
				true);
	if ((infoVersionInfoPtr != NULL) && infoVersionInfoPtr->elementPtr.IsValid()){
		// create and set attribute value for 'IsExtensionUsed'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsExtensionUsedPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("IsExtensionUsed", "icomp::TAttribute<bool>");
		if (attrInfoIsExtensionUsedPtr != NULL){
			attrInfoIsExtensionUsedPtr->exportId = "IsExtensionUsed";
		}

		// create and set attribute value for 'KnownVersionNames'
		icomp::IRegistryElement::AttributeInfo* attrInfoKnownVersionNamesPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("KnownVersionNames", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoKnownVersionNamesPtr != NULL){
			attrInfoKnownVersionNamesPtr->exportId = "KnownVersionNames";
		}

		// create and set attribute value for 'KnownVersions'
		icomp::IRegistryElement::AttributeInfo* attrInfoKnownVersionsPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("KnownVersions", "icomp::TMultiAttribute<int>");
		if (attrInfoKnownVersionsPtr != NULL){
			attrInfoKnownVersionsPtr->exportId = "KnownVersions";
		}

		// create and set attribute value for 'SlaveVersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveVersionInfoPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("SlaveVersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoSlaveVersionInfoPtr != NULL){
			attrInfoSlaveVersionInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSlaveVersionInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSlaveVersionInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSlaveVersionInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrSlaveVersionInfoPtr != NULL);
			attrSlaveVersionInfoPtr->SetValue("BaseInfo");
		}

		// create and set attribute value for 'VersionId'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("VersionId", "icomp::TAttribute<int>");
		if (attrInfoVersionIdPtr != NULL){
			attrInfoVersionIdPtr->exportId = "VersionId";
		}

		// create and set attribute value for 'VersionIdDesc'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdDescPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("VersionIdDesc", "icomp::TAttribute<istd::CString>");
		if (attrInfoVersionIdDescPtr != NULL){
			attrInfoVersionIdDescPtr->exportId = "VersionIdDesc";
		}

		// create and set attribute value for 'VersionNumber'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionNumberPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("VersionNumber", "icomp::TAttribute<int>");
		if (attrInfoVersionNumberPtr != NULL){
			attrInfoVersionNumberPtr->exportId = "VersionNumber";
		}
	}

	// interface export
	SetElementInterfaceExported(
				"VersionInfo",
				"iser::IVersionInfo",
				true);
}


// Embedded class CAcfVocePck

CCompositor::CAcfVocePck::CAcfVocePck(const icomp::IComponentEnvironmentManager* managerPtr)
:	icomp::CCompositePackageStaticInfo("AcfVoce", managerPtr)

{
	RegisterEmbeddedComponent("VersionInfo");
}


// Embedded class CVersionInfoRegistry

CCompositor::CAcfVocePck::CVersionInfoRegistry::CVersionInfoRegistry()
{
	// element 'BaseInfo' of type BasePck::VersionInfo
	icomp::IRegistry::ElementInfo* infoBaseInfoPtr = InsertElementInfo(
				"BaseInfo",
				icomp::CComponentAddress("BasePck", "VersionInfo"),
				true);
	if ((infoBaseInfoPtr != NULL) && infoBaseInfoPtr->elementPtr.IsValid()){
		// create and set attribute value for 'IsExtensionUsed'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsExtensionUsedPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("IsExtensionUsed", "icomp::TAttribute<bool>");
		if (attrInfoIsExtensionUsedPtr != NULL){
			attrInfoIsExtensionUsedPtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoIsExtensionUsedPtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrIsExtensionUsedPtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoIsExtensionUsedPtr->attributePtr.GetPtr());
			I_ASSERT(attrIsExtensionUsedPtr != NULL);
			attrIsExtensionUsedPtr->SetValue(true);
		}

		// create and set attribute value for 'KnownVersionNames'
		icomp::IRegistryElement::AttributeInfo* attrInfoKnownVersionNamesPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("KnownVersionNames", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoKnownVersionNamesPtr != NULL){
			attrInfoKnownVersionNamesPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoKnownVersionNamesPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoKnownVersionNamesPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoKnownVersionNamesPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoKnownVersionNamesPtr != NULL);

			nattrInfoKnownVersionNamesPtr->Reset();
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.9.0");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.9.1");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.9.2");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.9.3");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.9.4");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.9.5");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.9.6");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.9.7");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.9.8");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.9.9");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"1.0.0");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"1.0.1");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"1.1.0");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"1.2.0");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"1.3.0");
		}

		// create and set attribute value for 'KnownVersions'
		icomp::IRegistryElement::AttributeInfo* attrInfoKnownVersionsPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("KnownVersions", "icomp::TMultiAttribute<int>");
		if (attrInfoKnownVersionsPtr != NULL){
			attrInfoKnownVersionsPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<int>);
			I_ASSERT(attrInfoKnownVersionsPtr->attributePtr.IsValid());

			icomp::CMultiIntAttribute* nattrInfoKnownVersionsPtr = dynamic_cast<icomp::CMultiIntAttribute*>(attrInfoKnownVersionsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoKnownVersionsPtr != NULL);

			nattrInfoKnownVersionsPtr->Reset();
			nattrInfoKnownVersionsPtr->InsertValue(940);
			nattrInfoKnownVersionsPtr->InsertValue(965);
			nattrInfoKnownVersionsPtr->InsertValue(1017);
			nattrInfoKnownVersionsPtr->InsertValue(1055);
			nattrInfoKnownVersionsPtr->InsertValue(1120);
			nattrInfoKnownVersionsPtr->InsertValue(1234);
			nattrInfoKnownVersionsPtr->InsertValue(1335);
			nattrInfoKnownVersionsPtr->InsertValue(1375);
			nattrInfoKnownVersionsPtr->InsertValue(1384);
			nattrInfoKnownVersionsPtr->InsertValue(1461);
			nattrInfoKnownVersionsPtr->InsertValue(1504);
			nattrInfoKnownVersionsPtr->InsertValue(1603);
			nattrInfoKnownVersionsPtr->InsertValue(1644);
			nattrInfoKnownVersionsPtr->InsertValue(1688);
			nattrInfoKnownVersionsPtr->InsertValue(1705);
		}

		// create and set attribute value for 'SlaveVersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveVersionInfoPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("SlaveVersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoSlaveVersionInfoPtr != NULL){
			attrInfoSlaveVersionInfoPtr->exportId = "SlaveVersionInfo";
		}

		// create and set attribute value for 'VersionId'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("VersionId", "icomp::TAttribute<int>");
		if (attrInfoVersionIdPtr != NULL){
			attrInfoVersionIdPtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoVersionIdPtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrVersionIdPtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoVersionIdPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionIdPtr != NULL);
			attrVersionIdPtr->SetValue(0);
		}

		// create and set attribute value for 'VersionIdDesc'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdDescPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("VersionIdDesc", "icomp::TAttribute<istd::CString>");
		if (attrInfoVersionIdDescPtr != NULL){
			attrInfoVersionIdDescPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoVersionIdDescPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrVersionIdDescPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoVersionIdDescPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionIdDescPtr != NULL);
			attrVersionIdDescPtr->SetValue(L"ACF");
		}

		// create and set attribute value for 'VersionNumber'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionNumberPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("VersionNumber", "icomp::TAttribute<int>");
		if (attrInfoVersionNumberPtr != NULL){
			attrInfoVersionNumberPtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoVersionNumberPtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrVersionNumberPtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoVersionNumberPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionNumberPtr != NULL);
			attrVersionNumberPtr->SetValue(1774);
		}
	}

	// element 'VersionInfo' of type BasePck::VersionInfo
	icomp::IRegistry::ElementInfo* infoVersionInfoPtr = InsertElementInfo(
				"VersionInfo",
				icomp::CComponentAddress("BasePck", "VersionInfo"),
				true);
	if ((infoVersionInfoPtr != NULL) && infoVersionInfoPtr->elementPtr.IsValid()){
		// create and set attribute value for 'IsExtensionUsed'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsExtensionUsedPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("IsExtensionUsed", "icomp::TAttribute<bool>");
		if (attrInfoIsExtensionUsedPtr != NULL){
			attrInfoIsExtensionUsedPtr->exportId = "IsExtensionUsed";
		}

		// create and set attribute value for 'KnownVersionNames'
		icomp::IRegistryElement::AttributeInfo* attrInfoKnownVersionNamesPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("KnownVersionNames", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoKnownVersionNamesPtr != NULL){
			attrInfoKnownVersionNamesPtr->exportId = "KnownVersionNames";
		}

		// create and set attribute value for 'KnownVersions'
		icomp::IRegistryElement::AttributeInfo* attrInfoKnownVersionsPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("KnownVersions", "icomp::TMultiAttribute<int>");
		if (attrInfoKnownVersionsPtr != NULL){
			attrInfoKnownVersionsPtr->exportId = "KnownVersions";
		}

		// create and set attribute value for 'SlaveVersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveVersionInfoPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("SlaveVersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoSlaveVersionInfoPtr != NULL){
			attrInfoSlaveVersionInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSlaveVersionInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSlaveVersionInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSlaveVersionInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrSlaveVersionInfoPtr != NULL);
			attrSlaveVersionInfoPtr->SetValue("BaseInfo");
		}

		// create and set attribute value for 'VersionId'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("VersionId", "icomp::TAttribute<int>");
		if (attrInfoVersionIdPtr != NULL){
			attrInfoVersionIdPtr->exportId = "VersionId";
		}

		// create and set attribute value for 'VersionIdDesc'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdDescPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("VersionIdDesc", "icomp::TAttribute<istd::CString>");
		if (attrInfoVersionIdDescPtr != NULL){
			attrInfoVersionIdDescPtr->exportId = "VersionIdDesc";
		}

		// create and set attribute value for 'VersionNumber'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionNumberPtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("VersionNumber", "icomp::TAttribute<int>");
		if (attrInfoVersionNumberPtr != NULL){
			attrInfoVersionNumberPtr->exportId = "VersionNumber";
		}
	}

	// interface export
	SetElementInterfaceExported(
				"VersionInfo",
				"iser::IVersionInfo",
				true);
}


// Embedded class CCmpstrVocePck

CCompositor::CCmpstrVocePck::CCmpstrVocePck(const icomp::IComponentEnvironmentManager* managerPtr)
:	icomp::CCompositePackageStaticInfo("CmpstrVoce", managerPtr)

{
	RegisterEmbeddedComponent("AttributeEditorDock");
	RegisterEmbeddedComponent("ClassHelpDock");
	RegisterEmbeddedComponent("CompositorApplication");
	RegisterEmbeddedComponent("CompositorDockWidgets");
	RegisterEmbeddedComponent("CompositorSettings");
	RegisterEmbeddedComponent("CompositorSettingsDialog");
	RegisterEmbeddedComponent("CompositorTemplate");
	RegisterEmbeddedComponent("PackageOverviewDock");
	RegisterEmbeddedComponent("VisualRegistryView");
}


// Embedded class CAttributeEditorDockRegistry

CCompositor::CCmpstrVocePck::CAttributeEditorDockRegistry::CAttributeEditorDockRegistry()
{
	// element 'AttributeDock' of type QtGuiPck::DockWidgetGui
	icomp::IRegistry::ElementInfo* infoAttributeDockPtr = InsertElementInfo(
				"AttributeDock",
				icomp::CComponentAddress("QtGuiPck", "DockWidgetGui"),
				true);
	if ((infoAttributeDockPtr != NULL) && infoAttributeDockPtr->elementPtr.IsValid()){
		// create and set attribute value for 'DockArea'
		icomp::IRegistryElement::AttributeInfo* attrInfoDockAreaPtr = infoAttributeDockPtr->elementPtr->InsertAttributeInfo("DockArea", "icomp::TAttribute<int>");
		if (attrInfoDockAreaPtr != NULL){
			attrInfoDockAreaPtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoDockAreaPtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrDockAreaPtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoDockAreaPtr->attributePtr.GetPtr());
			I_ASSERT(attrDockAreaPtr != NULL);
			attrDockAreaPtr->SetValue(1);
		}

		// create and set attribute value for 'DockTitle'
		icomp::IRegistryElement::AttributeInfo* attrInfoDockTitlePtr = infoAttributeDockPtr->elementPtr->InsertAttributeInfo("DockTitle", "icomp::TAttribute<istd::CString>");
		if (attrInfoDockTitlePtr != NULL){
			attrInfoDockTitlePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoDockTitlePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrDockTitlePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoDockTitlePtr->attributePtr.GetPtr());
			I_ASSERT(attrDockTitlePtr != NULL);
			attrDockTitlePtr->SetValue(L"Selected component");
		}

		// create and set attribute value for 'SlaveGui'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveGuiPtr = infoAttributeDockPtr->elementPtr->InsertAttributeInfo("SlaveGui", "icomp::CReferenceAttribute");
		if (attrInfoSlaveGuiPtr != NULL){
			attrInfoSlaveGuiPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSlaveGuiPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSlaveGuiPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSlaveGuiPtr->attributePtr.GetPtr());
			I_ASSERT(attrSlaveGuiPtr != NULL);
			attrSlaveGuiPtr->SetValue("AttributeEditor");
		}
	}

	// element 'AttributeEditor' of type CmpstrPck::AttributeEditor
	icomp::IRegistry::ElementInfo* infoAttributeEditorPtr = InsertElementInfo(
				"AttributeEditor",
				icomp::CComponentAddress("CmpstrPck", "AttributeEditor"),
				true);
	if ((infoAttributeEditorPtr != NULL) && infoAttributeEditorPtr->elementPtr.IsValid()){
		// create and set attribute value for 'AttributeSelectionObserver'
		icomp::IRegistryElement::AttributeInfo* attrInfoAttributeSelectionObserverPtr = infoAttributeEditorPtr->elementPtr->InsertAttributeInfo("AttributeSelectionObserver", "icomp::CReferenceAttribute");
		if (attrInfoAttributeSelectionObserverPtr != NULL){
			attrInfoAttributeSelectionObserverPtr->exportId = "AttributeSelectionObserver";
		}

		// create and set attribute value for 'ConsistencyInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoConsistencyInfoPtr = infoAttributeEditorPtr->elementPtr->InsertAttributeInfo("ConsistencyInfo", "icomp::CReferenceAttribute");
		if (attrInfoConsistencyInfoPtr != NULL){
			attrInfoConsistencyInfoPtr->exportId = "ConsistencyInfo";
		}

		// create and set attribute value for 'MetaInfoManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoMetaInfoManagerPtr = infoAttributeEditorPtr->elementPtr->InsertAttributeInfo("MetaInfoManager", "icomp::CReferenceAttribute");
		if (attrInfoMetaInfoManagerPtr != NULL){
			attrInfoMetaInfoManagerPtr->exportId = "MetaInfoManager";
		}

		// create and set attribute value for 'QuickHelpViewer'
		icomp::IRegistryElement::AttributeInfo* attrInfoQuickHelpViewerPtr = infoAttributeEditorPtr->elementPtr->InsertAttributeInfo("QuickHelpViewer", "icomp::CReferenceAttribute");
		if (attrInfoQuickHelpViewerPtr != NULL){
			attrInfoQuickHelpViewerPtr->exportId = "QuickHelpViewer";
		}

		// create and set attribute value for 'RegistryPropGui'
		icomp::IRegistryElement::AttributeInfo* attrInfoRegistryPropGuiPtr = infoAttributeEditorPtr->elementPtr->InsertAttributeInfo("RegistryPropGui", "icomp::CReferenceAttribute");
		if (attrInfoRegistryPropGuiPtr != NULL){
			attrInfoRegistryPropGuiPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoRegistryPropGuiPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrRegistryPropGuiPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoRegistryPropGuiPtr->attributePtr.GetPtr());
			I_ASSERT(attrRegistryPropGuiPtr != NULL);
			attrRegistryPropGuiPtr->SetValue("RegistryPropEditor");
		}
	}

	// element 'RegistryPropEditor' of type CmpstrPck::RegistryPropEditor
	icomp::IRegistry::ElementInfo* infoRegistryPropEditorPtr = InsertElementInfo(
				"RegistryPropEditor",
				icomp::CComponentAddress("CmpstrPck", "RegistryPropEditor"),
				true);
	if ((infoRegistryPropEditorPtr != NULL) && infoRegistryPropEditorPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ConsistencyInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoConsistencyInfoPtr = infoRegistryPropEditorPtr->elementPtr->InsertAttributeInfo("ConsistencyInfo", "icomp::CReferenceAttribute");
		if (attrInfoConsistencyInfoPtr != NULL){
			attrInfoConsistencyInfoPtr->exportId = "ConsistencyInfo";
		}
	}

	// interface export
	SetElementInterfaceExported(
				"AttributeEditor",
				"imod::IModelEditor",
				true);
	SetElementInterfaceExported(
				"AttributeEditor",
				"imod::IObserver",
				true);
	SetElementInterfaceExported(
				"AttributeDock",
				"iqtgui::IMainWindowComponent",
				true);
}


// Embedded class CClassHelpDockRegistry

CCompositor::CCmpstrVocePck::CClassHelpDockRegistry::CClassHelpDockRegistry()
{
	// element 'ComponentHelpFileProvider' of type CmpstrPck::ComponentHelpFileProvider
	icomp::IRegistry::ElementInfo* infoComponentHelpFileProviderPtr = InsertElementInfo(
				"ComponentHelpFileProvider",
				icomp::CComponentAddress("CmpstrPck", "ComponentHelpFileProvider"),
				true);
	if ((infoComponentHelpFileProviderPtr != NULL) && infoComponentHelpFileProviderPtr->elementPtr.IsValid()){
		// create and set attribute value for 'MetaInfoManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoMetaInfoManagerPtr = infoComponentHelpFileProviderPtr->elementPtr->InsertAttributeInfo("MetaInfoManager", "icomp::CReferenceAttribute");
		if (attrInfoMetaInfoManagerPtr != NULL){
			attrInfoMetaInfoManagerPtr->exportId = "MetaInfoManager";
		}
	}

	// element 'QuickHelpDock' of type QtGuiPck::DockWidgetGui
	icomp::IRegistry::ElementInfo* infoQuickHelpDockPtr = InsertElementInfo(
				"QuickHelpDock",
				icomp::CComponentAddress("QtGuiPck", "DockWidgetGui"),
				true);
	if ((infoQuickHelpDockPtr != NULL) && infoQuickHelpDockPtr->elementPtr.IsValid()){
		// create and set attribute value for 'DockArea'
		icomp::IRegistryElement::AttributeInfo* attrInfoDockAreaPtr = infoQuickHelpDockPtr->elementPtr->InsertAttributeInfo("DockArea", "icomp::TAttribute<int>");
		if (attrInfoDockAreaPtr != NULL){
			attrInfoDockAreaPtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoDockAreaPtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrDockAreaPtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoDockAreaPtr->attributePtr.GetPtr());
			I_ASSERT(attrDockAreaPtr != NULL);
			attrDockAreaPtr->SetValue(3);
		}

		// create and set attribute value for 'DockTitle'
		icomp::IRegistryElement::AttributeInfo* attrInfoDockTitlePtr = infoQuickHelpDockPtr->elementPtr->InsertAttributeInfo("DockTitle", "icomp::TAttribute<istd::CString>");
		if (attrInfoDockTitlePtr != NULL){
			attrInfoDockTitlePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoDockTitlePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrDockTitlePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoDockTitlePtr->attributePtr.GetPtr());
			I_ASSERT(attrDockTitlePtr != NULL);
			attrDockTitlePtr->SetValue(L"Quick Help");
		}

		// create and set attribute value for 'SlaveGui'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveGuiPtr = infoQuickHelpDockPtr->elementPtr->InsertAttributeInfo("SlaveGui", "icomp::CReferenceAttribute");
		if (attrInfoSlaveGuiPtr != NULL){
			attrInfoSlaveGuiPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSlaveGuiPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSlaveGuiPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSlaveGuiPtr->attributePtr.GetPtr());
			I_ASSERT(attrSlaveGuiPtr != NULL);
			attrSlaveGuiPtr->SetValue("QuickHelpViewer");
		}
	}

	// element 'QuickHelpViewer' of type CmpstrPck::QuickHelpViewer
	icomp::IRegistry::ElementInfo* infoQuickHelpViewerPtr = InsertElementInfo(
				"QuickHelpViewer",
				icomp::CComponentAddress("CmpstrPck", "QuickHelpViewer"),
				true);
	if ((infoQuickHelpViewerPtr != NULL) && infoQuickHelpViewerPtr->elementPtr.IsValid()){
		// create and set attribute value for 'DocuEditorFileParam'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocuEditorFileParamPtr = infoQuickHelpViewerPtr->elementPtr->InsertAttributeInfo("DocuEditorFileParam", "icomp::CReferenceAttribute");
		if (attrInfoDocuEditorFileParamPtr != NULL){
			attrInfoDocuEditorFileParamPtr->exportId = "DocuEditorFileParam";
		}

		// create and set attribute value for 'HelpFileProvider'
		icomp::IRegistryElement::AttributeInfo* attrInfoHelpFileProviderPtr = infoQuickHelpViewerPtr->elementPtr->InsertAttributeInfo("HelpFileProvider", "icomp::CReferenceAttribute");
		if (attrInfoHelpFileProviderPtr != NULL){
			attrInfoHelpFileProviderPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoHelpFileProviderPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrHelpFileProviderPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoHelpFileProviderPtr->attributePtr.GetPtr());
			I_ASSERT(attrHelpFileProviderPtr != NULL);
			attrHelpFileProviderPtr->SetValue("ComponentHelpFileProvider");
		}

		// create and set attribute value for 'MetaInfoManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoMetaInfoManagerPtr = infoQuickHelpViewerPtr->elementPtr->InsertAttributeInfo("MetaInfoManager", "icomp::CReferenceAttribute");
		if (attrInfoMetaInfoManagerPtr != NULL){
			attrInfoMetaInfoManagerPtr->exportId = "MetaInfoManager";
		}

		// create and set attribute value for 'TechDocuViewerParam'
		icomp::IRegistryElement::AttributeInfo* attrInfoTechDocuViewerParamPtr = infoQuickHelpViewerPtr->elementPtr->InsertAttributeInfo("TechDocuViewerParam", "icomp::CReferenceAttribute");
		if (attrInfoTechDocuViewerParamPtr != NULL){
			attrInfoTechDocuViewerParamPtr->exportId = "TechDocuViewerFileParam";
		}

		// create and set attribute value for 'TechHelpFileProvider'
		icomp::IRegistryElement::AttributeInfo* attrInfoTechHelpFileProviderPtr = infoQuickHelpViewerPtr->elementPtr->InsertAttributeInfo("TechHelpFileProvider", "icomp::CReferenceAttribute");
		if (attrInfoTechHelpFileProviderPtr != NULL){
			attrInfoTechHelpFileProviderPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoTechHelpFileProviderPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrTechHelpFileProviderPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoTechHelpFileProviderPtr->attributePtr.GetPtr());
			I_ASSERT(attrTechHelpFileProviderPtr != NULL);
			attrTechHelpFileProviderPtr->SetValue("DoxygenHelpFileProvider");
		}
	}

	// interface export
	SetElementInterfaceExported(
				"QuickHelpViewer",
				"idoc::IHelpViewer",
				true);
	SetElementInterfaceExported(
				"QuickHelpViewer",
				"iqtgui::IGuiObject",
				true);
	SetElementInterfaceExported(
				"QuickHelpDock",
				"iqtgui::IMainWindowComponent",
				true);
}


// Embedded class CCompositorApplicationRegistry

CCompositor::CCmpstrVocePck::CCompositorApplicationRegistry::CCompositorApplicationRegistry()
{
	// element 'Application' of type AcfGuiVoce::MultiDocApp
	icomp::IRegistry::ElementInfo* infoApplicationPtr = InsertElementInfo(
				"Application",
				icomp::CComponentAddress("AcfGuiVoce", "MultiDocApp"),
				true);
	if ((infoApplicationPtr != NULL) && infoApplicationPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ApplicationName'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationNamePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("ApplicationName", "icomp::TAttribute<istd::CString>");
		if (attrInfoApplicationNamePtr != NULL){
			attrInfoApplicationNamePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoApplicationNamePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrApplicationNamePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoApplicationNamePtr->attributePtr.GetPtr());
			I_ASSERT(attrApplicationNamePtr != NULL);
			attrApplicationNamePtr->SetValue(L"Compositor");
		}

		// create and set attribute value for 'ApplicationSubname'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationSubnamePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("ApplicationSubname", "icomp::TAttribute<istd::CString>");
		if (attrInfoApplicationSubnamePtr != NULL){
			attrInfoApplicationSubnamePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoApplicationSubnamePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrApplicationSubnamePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoApplicationSubnamePtr->attributePtr.GetPtr());
			I_ASSERT(attrApplicationSubnamePtr != NULL);
			attrApplicationSubnamePtr->SetValue(L"ACF Registry Editor");
		}

		// create and set attribute value for 'CompanyName'
		icomp::IRegistryElement::AttributeInfo* attrInfoCompanyNamePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("CompanyName", "icomp::TAttribute<istd::CString>");
		if (attrInfoCompanyNamePtr != NULL){
			attrInfoCompanyNamePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoCompanyNamePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrCompanyNamePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoCompanyNamePtr->attributePtr.GetPtr());
			I_ASSERT(attrCompanyNamePtr != NULL);
			attrCompanyNamePtr->SetValue(L"ImagingTools");
		}

		// create and set attribute value for 'DocumentTemplates'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentTemplatesPtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("DocumentTemplates", "icomp::CMultiReferenceAttribute");
		if (attrInfoDocumentTemplatesPtr != NULL){
			attrInfoDocumentTemplatesPtr->exportId = "CompositorTemplate";
		}

		// create and set attribute value for 'IconPath'
		icomp::IRegistryElement::AttributeInfo* attrInfoIconPathPtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("IconPath", "icomp::TAttribute<istd::CString>");
		if (attrInfoIconPathPtr != NULL){
			attrInfoIconPathPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoIconPathPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrIconPathPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoIconPathPtr->attributePtr.GetPtr());
			I_ASSERT(attrIconPathPtr != NULL);
			attrIconPathPtr->SetValue(L":/Icons/CompositorIcon.svg");
		}

		// create and set attribute value for 'IconSize'
		icomp::IRegistryElement::AttributeInfo* attrInfoIconSizePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("IconSize", "icomp::TAttribute<int>");
		if (attrInfoIconSizePtr != NULL){
			attrInfoIconSizePtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoIconSizePtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrIconSizePtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoIconSizePtr->attributePtr.GetPtr());
			I_ASSERT(attrIconSizePtr != NULL);
			attrIconSizePtr->SetValue(32);
		}

		// create and set attribute value for 'IsCopyPathVisible'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsCopyPathVisiblePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("IsCopyPathVisible", "icomp::TAttribute<bool>");
		if (attrInfoIsCopyPathVisiblePtr != NULL){
			attrInfoIsCopyPathVisiblePtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoIsCopyPathVisiblePtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrIsCopyPathVisiblePtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoIsCopyPathVisiblePtr->attributePtr.GetPtr());
			I_ASSERT(attrIsCopyPathVisiblePtr != NULL);
			attrIsCopyPathVisiblePtr->SetValue(true);
		}

		// create and set attribute value for 'IsOpenContainingFolderVisible'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsOpenContainingFolderVisiblePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("IsOpenContainingFolderVisible", "icomp::TAttribute<bool>");
		if (attrInfoIsOpenContainingFolderVisiblePtr != NULL){
			attrInfoIsOpenContainingFolderVisiblePtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoIsOpenContainingFolderVisiblePtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrIsOpenContainingFolderVisiblePtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoIsOpenContainingFolderVisiblePtr->attributePtr.GetPtr());
			I_ASSERT(attrIsOpenContainingFolderVisiblePtr != NULL);
			attrIsOpenContainingFolderVisiblePtr->SetValue(true);
		}

		// create and set attribute value for 'LegalCopyright'
		icomp::IRegistryElement::AttributeInfo* attrInfoLegalCopyrightPtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("LegalCopyright", "icomp::TAttribute<istd::CString>");
		if (attrInfoLegalCopyrightPtr != NULL){
			attrInfoLegalCopyrightPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoLegalCopyrightPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrLegalCopyrightPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoLegalCopyrightPtr->attributePtr.GetPtr());
			I_ASSERT(attrLegalCopyrightPtr != NULL);
			attrLegalCopyrightPtr->SetValue(L"\x00A9 Copyright 2011 Witold Gantzke & Kirill Lepskiy\nAll rights reserved\n\nThis tool is a part of ACF Solutions project\nSee 'License.txt' for license information");
		}

		// create and set attribute value for 'LogoPath'
		icomp::IRegistryElement::AttributeInfo* attrInfoLogoPathPtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("LogoPath", "icomp::TAttribute<istd::CString>");
		if (attrInfoLogoPathPtr != NULL){
			attrInfoLogoPathPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoLogoPathPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrLogoPathPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoLogoPathPtr->attributePtr.GetPtr());
			I_ASSERT(attrLogoPathPtr != NULL);
			attrLogoPathPtr->SetValue(L":/Icons/CompositorLogo.svg");
		}

		// create and set attribute value for 'MainWindowComponents'
		icomp::IRegistryElement::AttributeInfo* attrInfoMainWindowComponentsPtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("MainWindowComponents", "icomp::CMultiReferenceAttribute");
		if (attrInfoMainWindowComponentsPtr != NULL){
			attrInfoMainWindowComponentsPtr->exportId = "MainWindowsComponents";
		}

		// create and set attribute value for 'ProductName'
		icomp::IRegistryElement::AttributeInfo* attrInfoProductNamePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("ProductName", "icomp::TAttribute<istd::CString>");
		if (attrInfoProductNamePtr != NULL){
			attrInfoProductNamePtr->exportId = "ProductName";
			attrInfoProductNamePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoProductNamePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrProductNamePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoProductNamePtr->attributePtr.GetPtr());
			I_ASSERT(attrProductNamePtr != NULL);
			attrProductNamePtr->SetValue(L"ACF-Solutions");
		}

		// create and set attribute value for 'ProductType'
		icomp::IRegistryElement::AttributeInfo* attrInfoProductTypePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("ProductType", "icomp::TAttribute<istd::CString>");
		if (attrInfoProductTypePtr != NULL){
			attrInfoProductTypePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoProductTypePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrProductTypePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoProductTypePtr->attributePtr.GetPtr());
			I_ASSERT(attrProductTypePtr != NULL);
			attrProductTypePtr->SetValue(L"");
		}

		// create and set attribute value for 'SettingsGui'
		icomp::IRegistryElement::AttributeInfo* attrInfoSettingsGuiPtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("SettingsGui", "icomp::CReferenceAttribute");
		if (attrInfoSettingsGuiPtr != NULL){
			attrInfoSettingsGuiPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSettingsGuiPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSettingsGuiPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSettingsGuiPtr->attributePtr.GetPtr());
			I_ASSERT(attrSettingsGuiPtr != NULL);
			attrSettingsGuiPtr->SetValue("Settings");
		}

		// create and set attribute value for 'ShowSplashApplicationName'
		icomp::IRegistryElement::AttributeInfo* attrInfoShowSplashApplicationNamePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("ShowSplashApplicationName", "icomp::TAttribute<bool>");
		if (attrInfoShowSplashApplicationNamePtr != NULL){
			attrInfoShowSplashApplicationNamePtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoShowSplashApplicationNamePtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrShowSplashApplicationNamePtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoShowSplashApplicationNamePtr->attributePtr.GetPtr());
			I_ASSERT(attrShowSplashApplicationNamePtr != NULL);
			attrShowSplashApplicationNamePtr->SetValue(false);
		}

		// create and set attribute value for 'ShowSplashProductName'
		icomp::IRegistryElement::AttributeInfo* attrInfoShowSplashProductNamePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("ShowSplashProductName", "icomp::TAttribute<bool>");
		if (attrInfoShowSplashProductNamePtr != NULL){
			attrInfoShowSplashProductNamePtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoShowSplashProductNamePtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrShowSplashProductNamePtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoShowSplashProductNamePtr->attributePtr.GetPtr());
			I_ASSERT(attrShowSplashProductNamePtr != NULL);
			attrShowSplashProductNamePtr->SetValue(false);
		}

		// create and set attribute value for 'SlaveVersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveVersionInfoPtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("SlaveVersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoSlaveVersionInfoPtr != NULL){
			attrInfoSlaveVersionInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSlaveVersionInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSlaveVersionInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSlaveVersionInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrSlaveVersionInfoPtr != NULL);
			attrSlaveVersionInfoPtr->SetValue("VersionInfo");
		}

		// create and set attribute value for 'SplashScreenImage'
		icomp::IRegistryElement::AttributeInfo* attrInfoSplashScreenImagePtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("SplashScreenImage", "icomp::TAttribute<istd::CString>");
		if (attrInfoSplashScreenImagePtr != NULL){
			attrInfoSplashScreenImagePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoSplashScreenImagePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrSplashScreenImagePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoSplashScreenImagePtr->attributePtr.GetPtr());
			I_ASSERT(attrSplashScreenImagePtr != NULL);
			attrSplashScreenImagePtr->SetValue(L":/Images/CompositorSplashScreen");
		}

		// create and set attribute value for 'VersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionInfoPtr = infoApplicationPtr->elementPtr->InsertAttributeInfo("VersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoVersionInfoPtr != NULL){
			attrInfoVersionInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoVersionInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrVersionInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoVersionInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionInfoPtr != NULL);
			attrVersionInfoPtr->SetValue("VersionInfo");
		}
	}

	// element 'Settings' of type CmpstrVoce::CompositorSettingsDialog
	icomp::IRegistry::ElementInfo* infoSettingsPtr = InsertElementInfo(
				"Settings",
				icomp::CComponentAddress("CmpstrVoce", "CompositorSettingsDialog"),
				true);
	if ((infoSettingsPtr != NULL) && infoSettingsPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ApplicationInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationInfoPtr = infoSettingsPtr->elementPtr->InsertAttributeInfo("ApplicationInfo", "icomp::CReferenceAttribute");
		if (attrInfoApplicationInfoPtr != NULL){
			attrInfoApplicationInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoApplicationInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrApplicationInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoApplicationInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrApplicationInfoPtr != NULL);
			attrApplicationInfoPtr->SetValue("Application");
		}

		// create and set attribute value for 'VersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionInfoPtr = infoSettingsPtr->elementPtr->InsertAttributeInfo("VersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoVersionInfoPtr != NULL){
			attrInfoVersionInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoVersionInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrVersionInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoVersionInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionInfoPtr != NULL);
			attrVersionInfoPtr->SetValue("Application");
		}
	}

	// element 'VersionInfo' of type AcfSlnVoce::VersionInfo
	icomp::IRegistry::ElementInfo* infoVersionInfoPtr = InsertElementInfo(
				"VersionInfo",
				icomp::CComponentAddress("AcfSlnVoce", "VersionInfo"),
				true);
	if ((infoVersionInfoPtr != NULL) && infoVersionInfoPtr->elementPtr.IsValid()){
		// create and set attribute value for 'CompanyName'
		icomp::IRegistryElement::AttributeInfo* attrInfoCompanyNamePtr = infoVersionInfoPtr->elementPtr->InsertAttributeInfo("CompanyName", "icomp::TAttribute<istd::CString>");
		if (attrInfoCompanyNamePtr != NULL){
			attrInfoCompanyNamePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoCompanyNamePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrCompanyNamePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoCompanyNamePtr->attributePtr.GetPtr());
			I_ASSERT(attrCompanyNamePtr != NULL);
			attrCompanyNamePtr->SetValue(L"ImagingTools");
		}
	}

	// interface export
	SetElementInterfaceExported(
				"Application",
				"ibase::IApplication",
				true);
	SetElementInterfaceExported(
				"Application",
				"ibase::IApplicationInfo",
				true);
	SetElementInterfaceExported(
				"Application",
				"iser::IVersionInfo",
				true);

	// component export
	SetElementExported(
				"ConfigFile",
				"Settings/ConfigFile");
	SetElementExported(
				"DocumentManager",
				"Application/Workspace");
	SetElementExported(
				"HtmlBrowserFile",
				"Settings/HtmlBrowserFile");
	SetElementExported(
				"HtmlEditorFile",
				"Settings/HtmlEditorFile");
	SetElementExported(
				"PreviewCommandFile",
				"Settings/PreviewCommandFile");
}


// Embedded class CCompositorDockWidgetsRegistry

CCompositor::CCmpstrVocePck::CCompositorDockWidgetsRegistry::CCompositorDockWidgetsRegistry()
{
	// element 'AttributeEditorDock' of type CmpstrVoce::AttributeEditorDock
	icomp::IRegistry::ElementInfo* infoAttributeEditorDockPtr = InsertElementInfo(
				"AttributeEditorDock",
				icomp::CComponentAddress("CmpstrVoce", "AttributeEditorDock"),
				true);
	if ((infoAttributeEditorDockPtr != NULL) && infoAttributeEditorDockPtr->elementPtr.IsValid()){
		// create and set attribute value for 'AttributeSelectionObserver'
		icomp::IRegistryElement::AttributeInfo* attrInfoAttributeSelectionObserverPtr = infoAttributeEditorDockPtr->elementPtr->InsertAttributeInfo("AttributeSelectionObserver", "icomp::CReferenceAttribute");
		if (attrInfoAttributeSelectionObserverPtr != NULL){
			attrInfoAttributeSelectionObserverPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoAttributeSelectionObserverPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrAttributeSelectionObserverPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoAttributeSelectionObserverPtr->attributePtr.GetPtr());
			I_ASSERT(attrAttributeSelectionObserverPtr != NULL);
			attrAttributeSelectionObserverPtr->SetValue("PackageOverviewDock");
		}

		// create and set attribute value for 'ConsistencyInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoConsistencyInfoPtr = infoAttributeEditorDockPtr->elementPtr->InsertAttributeInfo("ConsistencyInfo", "icomp::CReferenceAttribute");
		if (attrInfoConsistencyInfoPtr != NULL){
			attrInfoConsistencyInfoPtr->exportId = "ConsistencyInfo";
		}

		// create and set attribute value for 'MetaInfoManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoMetaInfoManagerPtr = infoAttributeEditorDockPtr->elementPtr->InsertAttributeInfo("MetaInfoManager", "icomp::CReferenceAttribute");
		if (attrInfoMetaInfoManagerPtr != NULL){
			attrInfoMetaInfoManagerPtr->exportId = "MetaInfoManager";
		}

		// create and set attribute value for 'QuickHelpViewer'
		icomp::IRegistryElement::AttributeInfo* attrInfoQuickHelpViewerPtr = infoAttributeEditorDockPtr->elementPtr->InsertAttributeInfo("QuickHelpViewer", "icomp::CReferenceAttribute");
		if (attrInfoQuickHelpViewerPtr != NULL){
			attrInfoQuickHelpViewerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoQuickHelpViewerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrQuickHelpViewerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoQuickHelpViewerPtr->attributePtr.GetPtr());
			I_ASSERT(attrQuickHelpViewerPtr != NULL);
			attrQuickHelpViewerPtr->SetValue("QuickHelpDock");
		}
	}

	// element 'LogDock' of type AcfGuiVoce::LogDock
	icomp::IRegistry::ElementInfo* infoLogDockPtr = InsertElementInfo(
				"LogDock",
				icomp::CComponentAddress("AcfGuiVoce", "LogDock"),
				true);
	if ((infoLogDockPtr != NULL) && infoLogDockPtr->elementPtr.IsValid()){
		// create and set attribute value for 'VersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionInfoPtr = infoLogDockPtr->elementPtr->InsertAttributeInfo("VersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoVersionInfoPtr != NULL){
			attrInfoVersionInfoPtr->exportId = "VersionInfo";
		}
	}

	// element 'PackageOverviewDock' of type CmpstrVoce::PackageOverviewDock
	icomp::IRegistry::ElementInfo* infoPackageOverviewDockPtr = InsertElementInfo(
				"PackageOverviewDock",
				icomp::CComponentAddress("CmpstrVoce", "PackageOverviewDock"),
				true);
	if ((infoPackageOverviewDockPtr != NULL) && infoPackageOverviewDockPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ConsistencyInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoConsistencyInfoPtr = infoPackageOverviewDockPtr->elementPtr->InsertAttributeInfo("ConsistencyInfo", "icomp::CReferenceAttribute");
		if (attrInfoConsistencyInfoPtr != NULL){
			attrInfoConsistencyInfoPtr->exportId = "ConsistencyInfo";
		}

		// create and set attribute value for 'DocumentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentManagerPtr = infoPackageOverviewDockPtr->elementPtr->InsertAttributeInfo("DocumentManager", "icomp::CReferenceAttribute");
		if (attrInfoDocumentManagerPtr != NULL){
			attrInfoDocumentManagerPtr->exportId = "DocumentManager";
		}

		// create and set attribute value for 'EnvironmentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoEnvironmentManagerPtr = infoPackageOverviewDockPtr->elementPtr->InsertAttributeInfo("EnvironmentManager", "icomp::CReferenceAttribute");
		if (attrInfoEnvironmentManagerPtr != NULL){
			attrInfoEnvironmentManagerPtr->exportId = "EnvironmentManager";
		}

		// create and set attribute value for 'QuickHelpViewer'
		icomp::IRegistryElement::AttributeInfo* attrInfoQuickHelpViewerPtr = infoPackageOverviewDockPtr->elementPtr->InsertAttributeInfo("QuickHelpViewer", "icomp::CReferenceAttribute");
		if (attrInfoQuickHelpViewerPtr != NULL){
			attrInfoQuickHelpViewerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoQuickHelpViewerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrQuickHelpViewerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoQuickHelpViewerPtr->attributePtr.GetPtr());
			I_ASSERT(attrQuickHelpViewerPtr != NULL);
			attrQuickHelpViewerPtr->SetValue("QuickHelpDock");
		}
	}

	// element 'QuickHelpDock' of type CmpstrVoce::ClassHelpDock
	icomp::IRegistry::ElementInfo* infoQuickHelpDockPtr = InsertElementInfo(
				"QuickHelpDock",
				icomp::CComponentAddress("CmpstrVoce", "ClassHelpDock"),
				true);
	if ((infoQuickHelpDockPtr != NULL) && infoQuickHelpDockPtr->elementPtr.IsValid()){
		// create and set attribute value for 'DocuEditorFileParam'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocuEditorFileParamPtr = infoQuickHelpDockPtr->elementPtr->InsertAttributeInfo("DocuEditorFileParam", "icomp::CReferenceAttribute");
		if (attrInfoDocuEditorFileParamPtr != NULL){
			attrInfoDocuEditorFileParamPtr->exportId = "DocuEditorFileParam";
		}

		// create and set attribute value for 'MetaInfoManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoMetaInfoManagerPtr = infoQuickHelpDockPtr->elementPtr->InsertAttributeInfo("MetaInfoManager", "icomp::CReferenceAttribute");
		if (attrInfoMetaInfoManagerPtr != NULL){
			attrInfoMetaInfoManagerPtr->exportId = "MetaInfoManager";
		}

		// create and set attribute value for 'TechDocuViewerFileParam'
		icomp::IRegistryElement::AttributeInfo* attrInfoTechDocuViewerFileParamPtr = infoQuickHelpDockPtr->elementPtr->InsertAttributeInfo("TechDocuViewerFileParam", "icomp::CReferenceAttribute");
		if (attrInfoTechDocuViewerFileParamPtr != NULL){
			attrInfoTechDocuViewerFileParamPtr->exportId = "TechDocuViewerFileParam";
		}
	}


	// component export
	SetElementExported(
				"AttributeEditorDock",
				"AttributeEditorDock");
	SetElementExported(
				"LogDock",
				"LogDock");
	SetElementExported(
				"PackageOverviewDock",
				"PackageOverviewDock");
	SetElementExported(
				"QuickHelpDock",
				"QuickHelpDock");
}


// Embedded class CCompositorSettingsRegistry

CCompositor::CCmpstrVocePck::CCompositorSettingsRegistry::CCompositorSettingsRegistry()
{
	// element 'ConfigFile' of type BasePck::FileNameParam
	icomp::IRegistry::ElementInfo* infoConfigFilePtr = InsertElementInfo(
				"ConfigFile",
				icomp::CComponentAddress("BasePck", "FileNameParam"),
				true);
	if ((infoConfigFilePtr != NULL) && infoConfigFilePtr->elementPtr.IsValid()){
		// create and set attribute value for 'DefaultPath'
		icomp::IRegistryElement::AttributeInfo* attrInfoDefaultPathPtr = infoConfigFilePtr->elementPtr->InsertAttributeInfo("DefaultPath", "icomp::TAttribute<istd::CString>");
		if (attrInfoDefaultPathPtr != NULL){
			attrInfoDefaultPathPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoDefaultPathPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrDefaultPathPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoDefaultPathPtr->attributePtr.GetPtr());
			I_ASSERT(attrDefaultPathPtr != NULL);
			attrDefaultPathPtr->SetValue(L"$(ACFSLNDIR)/Config/Full.xpc");
		}

		// create and set attribute value for 'PathType'
		icomp::IRegistryElement::AttributeInfo* attrInfoPathTypePtr = infoConfigFilePtr->elementPtr->InsertAttributeInfo("PathType", "icomp::TAttribute<int>");
		if (attrInfoPathTypePtr != NULL){
			attrInfoPathTypePtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoPathTypePtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrPathTypePtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoPathTypePtr->attributePtr.GetPtr());
			I_ASSERT(attrPathTypePtr != NULL);
			attrPathTypePtr->SetValue(1);
		}
	}

	// element 'HtmlBrowserFile' of type BasePck::FileNameParam
	icomp::IRegistry::ElementInfo* infoHtmlBrowserFilePtr = InsertElementInfo(
				"HtmlBrowserFile",
				icomp::CComponentAddress("BasePck", "FileNameParam"),
				true);
	if ((infoHtmlBrowserFilePtr != NULL) && infoHtmlBrowserFilePtr->elementPtr.IsValid()){
		// create and set attribute value for 'PathType'
		icomp::IRegistryElement::AttributeInfo* attrInfoPathTypePtr = infoHtmlBrowserFilePtr->elementPtr->InsertAttributeInfo("PathType", "icomp::TAttribute<int>");
		if (attrInfoPathTypePtr != NULL){
			attrInfoPathTypePtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoPathTypePtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrPathTypePtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoPathTypePtr->attributePtr.GetPtr());
			I_ASSERT(attrPathTypePtr != NULL);
			attrPathTypePtr->SetValue(1);
		}
	}

	// element 'HtmlEditorFile' of type BasePck::FileNameParam
	icomp::IRegistry::ElementInfo* infoHtmlEditorFilePtr = InsertElementInfo(
				"HtmlEditorFile",
				icomp::CComponentAddress("BasePck", "FileNameParam"),
				true);
	if ((infoHtmlEditorFilePtr != NULL) && infoHtmlEditorFilePtr->elementPtr.IsValid()){
		// create and set attribute value for 'PathType'
		icomp::IRegistryElement::AttributeInfo* attrInfoPathTypePtr = infoHtmlEditorFilePtr->elementPtr->InsertAttributeInfo("PathType", "icomp::TAttribute<int>");
		if (attrInfoPathTypePtr != NULL){
			attrInfoPathTypePtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoPathTypePtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrPathTypePtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoPathTypePtr->attributePtr.GetPtr());
			I_ASSERT(attrPathTypePtr != NULL);
			attrPathTypePtr->SetValue(1);
		}
	}

	// element 'PreviewCommandFile' of type BasePck::FileNameParam
	icomp::IRegistry::ElementInfo* infoPreviewCommandFilePtr = InsertElementInfo(
				"PreviewCommandFile",
				icomp::CComponentAddress("BasePck", "FileNameParam"),
				true);
	if ((infoPreviewCommandFilePtr != NULL) && infoPreviewCommandFilePtr->elementPtr.IsValid()){
		// create and set attribute value for 'DefaultPath'
		icomp::IRegistryElement::AttributeInfo* attrInfoDefaultPathPtr = infoPreviewCommandFilePtr->elementPtr->InsertAttributeInfo("DefaultPath", "icomp::TAttribute<istd::CString>");
		if (attrInfoDefaultPathPtr != NULL){
			attrInfoDefaultPathPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoDefaultPathPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrDefaultPathPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoDefaultPathPtr->attributePtr.GetPtr());
			I_ASSERT(attrDefaultPathPtr != NULL);
			attrDefaultPathPtr->SetValue(L"$(ACFDIR)/Bin/$(ConfigurationName)/Acf.exe");
		}

		// create and set attribute value for 'PathType'
		icomp::IRegistryElement::AttributeInfo* attrInfoPathTypePtr = infoPreviewCommandFilePtr->elementPtr->InsertAttributeInfo("PathType", "icomp::TAttribute<int>");
		if (attrInfoPathTypePtr != NULL){
			attrInfoPathTypePtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoPathTypePtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrPathTypePtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoPathTypePtr->attributePtr.GetPtr());
			I_ASSERT(attrPathTypePtr != NULL);
			attrPathTypePtr->SetValue(1);
		}
	}

	// element 'Settings' of type BasePck::ComposedParamsSet
	icomp::IRegistry::ElementInfo* infoSettingsPtr = InsertElementInfo(
				"Settings",
				icomp::CComponentAddress("BasePck", "ComposedParamsSet"),
				true);
	if ((infoSettingsPtr != NULL) && infoSettingsPtr->elementPtr.IsValid()){
		// create and set attribute value for 'Parameters'
		icomp::IRegistryElement::AttributeInfo* attrInfoParametersPtr = infoSettingsPtr->elementPtr->InsertAttributeInfo("Parameters", "icomp::CMultiReferenceAttribute");
		if (attrInfoParametersPtr != NULL){
			attrInfoParametersPtr->attributePtr.SetPtr(new icomp::CMultiReferenceAttribute);
			I_ASSERT(attrInfoParametersPtr->attributePtr.IsValid());

			icomp::TMultiAttribute<std::string>* nattrInfoParametersPtr = dynamic_cast<icomp::TMultiAttribute<std::string>*>(attrInfoParametersPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoParametersPtr != NULL);

			nattrInfoParametersPtr->Reset();
			nattrInfoParametersPtr->InsertValue("ConfigFile");
			nattrInfoParametersPtr->InsertValue("PreviewCommandFile");
			nattrInfoParametersPtr->InsertValue("HtmlBrowserFile");
			nattrInfoParametersPtr->InsertValue("HtmlEditorFile");
		}

		// create and set attribute value for 'ParametersId'
		icomp::IRegistryElement::AttributeInfo* attrInfoParametersIdPtr = infoSettingsPtr->elementPtr->InsertAttributeInfo("ParametersId", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoParametersIdPtr != NULL){
			attrInfoParametersIdPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoParametersIdPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoParametersIdPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoParametersIdPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoParametersIdPtr != NULL);

			nattrInfoParametersIdPtr->Reset();
			nattrInfoParametersIdPtr->InsertValue(L"ConfigFile");
			nattrInfoParametersIdPtr->InsertValue(L"PreviewCommandFile");
			nattrInfoParametersIdPtr->InsertValue(L"HtmlBrowserFile");
			nattrInfoParametersIdPtr->InsertValue(L"HtmlEditorFile");
		}
	}

	// interface export
	SetElementInterfaceExported(
				"Settings",
				"imod::IModel",
				true);
	SetElementInterfaceExported(
				"Settings",
				"iprm::IParamsSet",
				true);
	SetElementInterfaceExported(
				"Settings",
				"iser::ISerializable",
				true);
	SetElementInterfaceExported(
				"Settings",
				"istd::IChangeable",
				true);

	// component export
	SetElementExported(
				"ConfigFile",
				"ConfigFile");
	SetElementExported(
				"HtmlBrowserFile",
				"HtmlBrowserFile");
	SetElementExported(
				"HtmlEditorFile",
				"HtmlEditorFile");
	SetElementExported(
				"PreviewCommandFile",
				"PreviewCommandFile");
}


// Embedded class CCompositorSettingsDialogRegistry

CCompositor::CCmpstrVocePck::CCompositorSettingsDialogRegistry::CCompositorSettingsDialogRegistry()
{
	// element 'ConfigFileGui' of type QtGuiPck::FileNameParamGui
	icomp::IRegistry::ElementInfo* infoConfigFileGuiPtr = InsertElementInfo(
				"ConfigFileGui",
				icomp::CComponentAddress("QtGuiPck", "FileNameParamGui"),
				true);
	if ((infoConfigFileGuiPtr != NULL) && infoConfigFileGuiPtr->elementPtr.IsValid()){
		// create and set attribute value for 'FileTypeInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoFileTypeInfoPtr = infoConfigFileGuiPtr->elementPtr->InsertAttributeInfo("FileTypeInfo", "icomp::CReferenceAttribute");
		if (attrInfoFileTypeInfoPtr != NULL){
			attrInfoFileTypeInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoFileTypeInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrFileTypeInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoFileTypeInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrFileTypeInfoPtr != NULL);
			attrFileTypeInfoPtr->SetValue("ConfigFileInfo");
		}
	}

	// element 'ConfigFileInfo' of type BasePck::FileTypeInfo
	icomp::IRegistry::ElementInfo* infoConfigFileInfoPtr = InsertElementInfo(
				"ConfigFileInfo",
				icomp::CComponentAddress("BasePck", "FileTypeInfo"),
				true);
	if ((infoConfigFileInfoPtr != NULL) && infoConfigFileInfoPtr->elementPtr.IsValid()){
		// create and set attribute value for 'FileExtensions'
		icomp::IRegistryElement::AttributeInfo* attrInfoFileExtensionsPtr = infoConfigFileInfoPtr->elementPtr->InsertAttributeInfo("FileExtensions", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoFileExtensionsPtr != NULL){
			attrInfoFileExtensionsPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoFileExtensionsPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoFileExtensionsPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoFileExtensionsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoFileExtensionsPtr != NULL);

			nattrInfoFileExtensionsPtr->Reset();
			nattrInfoFileExtensionsPtr->InsertValue(L"xpc");
		}

		// create and set attribute value for 'TypeDescriptions'
		icomp::IRegistryElement::AttributeInfo* attrInfoTypeDescriptionsPtr = infoConfigFileInfoPtr->elementPtr->InsertAttributeInfo("TypeDescriptions", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoTypeDescriptionsPtr != NULL){
			attrInfoTypeDescriptionsPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoTypeDescriptionsPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoTypeDescriptionsPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoTypeDescriptionsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoTypeDescriptionsPtr != NULL);

			nattrInfoTypeDescriptionsPtr->Reset();
			nattrInfoTypeDescriptionsPtr->InsertValue(L"ACF component configuration");
		}
	}

	// element 'HtmlBrowserFileGui' of type QtGuiPck::FileNameParamGui
	InsertElementInfo(
				"HtmlBrowserFileGui",
				icomp::CComponentAddress("QtGuiPck", "FileNameParamGui"),
				true);
	// element 'HtmlEditorFileGui' of type QtGuiPck::FileNameParamGui
	InsertElementInfo(
				"HtmlEditorFileGui",
				icomp::CComponentAddress("QtGuiPck", "FileNameParamGui"),
				true);
	// element 'PreviewCommandFileGui' of type QtGuiPck::FileNameParamGui
	icomp::IRegistry::ElementInfo* infoPreviewCommandFileGuiPtr = InsertElementInfo(
				"PreviewCommandFileGui",
				icomp::CComponentAddress("QtGuiPck", "FileNameParamGui"),
				true);
	if ((infoPreviewCommandFileGuiPtr != NULL) && infoPreviewCommandFileGuiPtr->elementPtr.IsValid()){
		// create and set attribute value for 'FileTypeInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoFileTypeInfoPtr = infoPreviewCommandFileGuiPtr->elementPtr->InsertAttributeInfo("FileTypeInfo", "icomp::CReferenceAttribute");
		if (attrInfoFileTypeInfoPtr != NULL){
			attrInfoFileTypeInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoFileTypeInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrFileTypeInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoFileTypeInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrFileTypeInfoPtr != NULL);
			attrFileTypeInfoPtr->SetValue("PreviewCommandFileInfo");
		}
	}

	// element 'PreviewCommandFileInfo' of type BasePck::FileTypeInfo
	icomp::IRegistry::ElementInfo* infoPreviewCommandFileInfoPtr = InsertElementInfo(
				"PreviewCommandFileInfo",
				icomp::CComponentAddress("BasePck", "FileTypeInfo"),
				true);
	if ((infoPreviewCommandFileInfoPtr != NULL) && infoPreviewCommandFileInfoPtr->elementPtr.IsValid()){
		// create and set attribute value for 'FileExtensions'
		icomp::IRegistryElement::AttributeInfo* attrInfoFileExtensionsPtr = infoPreviewCommandFileInfoPtr->elementPtr->InsertAttributeInfo("FileExtensions", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoFileExtensionsPtr != NULL){
			attrInfoFileExtensionsPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoFileExtensionsPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoFileExtensionsPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoFileExtensionsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoFileExtensionsPtr != NULL);

			nattrInfoFileExtensionsPtr->Reset();
			nattrInfoFileExtensionsPtr->InsertValue(L"exe");
			nattrInfoFileExtensionsPtr->InsertValue(L"bat");
		}

		// create and set attribute value for 'TypeDescriptions'
		icomp::IRegistryElement::AttributeInfo* attrInfoTypeDescriptionsPtr = infoPreviewCommandFileInfoPtr->elementPtr->InsertAttributeInfo("TypeDescriptions", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoTypeDescriptionsPtr != NULL){
			attrInfoTypeDescriptionsPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoTypeDescriptionsPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoTypeDescriptionsPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoTypeDescriptionsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoTypeDescriptionsPtr != NULL);

			nattrInfoTypeDescriptionsPtr->Reset();
			nattrInfoTypeDescriptionsPtr->InsertValue(L"Windows executable");
			nattrInfoTypeDescriptionsPtr->InsertValue(L"Script file");
		}
	}

	// element 'Settings' of type CmpstrVoce::CompositorSettings
	InsertElementInfo(
				"Settings",
				icomp::CComponentAddress("CmpstrVoce", "CompositorSettings"),
				true);
	// element 'SettingsDialog' of type QtGuiPck::ModelDialogGui
	icomp::IRegistry::ElementInfo* infoSettingsDialogPtr = InsertElementInfo(
				"SettingsDialog",
				icomp::CComponentAddress("QtGuiPck", "ModelDialogGui"),
				true);
	if ((infoSettingsDialogPtr != NULL) && infoSettingsDialogPtr->elementPtr.IsValid()){
		// create and set attribute value for 'DialogIconPath'
		icomp::IRegistryElement::AttributeInfo* attrInfoDialogIconPathPtr = infoSettingsDialogPtr->elementPtr->InsertAttributeInfo("DialogIconPath", "icomp::TAttribute<istd::CString>");
		if (attrInfoDialogIconPathPtr != NULL){
			attrInfoDialogIconPathPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoDialogIconPathPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrDialogIconPathPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoDialogIconPathPtr->attributePtr.GetPtr());
			I_ASSERT(attrDialogIconPathPtr != NULL);
			attrDialogIconPathPtr->SetValue(L":/Icons/Settings.svg");
		}

		// create and set attribute value for 'DialogTitle'
		icomp::IRegistryElement::AttributeInfo* attrInfoDialogTitlePtr = infoSettingsDialogPtr->elementPtr->InsertAttributeInfo("DialogTitle", "icomp::TAttribute<istd::CString>");
		if (attrInfoDialogTitlePtr != NULL){
			attrInfoDialogTitlePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoDialogTitlePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrDialogTitlePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoDialogTitlePtr->attributePtr.GetPtr());
			I_ASSERT(attrDialogTitlePtr != NULL);
			attrDialogTitlePtr->SetValue(L"Settings");
		}

		// create and set attribute value for 'Gui'
		icomp::IRegistryElement::AttributeInfo* attrInfoGuiPtr = infoSettingsDialogPtr->elementPtr->InsertAttributeInfo("Gui", "icomp::CReferenceAttribute");
		if (attrInfoGuiPtr != NULL){
			attrInfoGuiPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoGuiPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrGuiPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoGuiPtr->attributePtr.GetPtr());
			I_ASSERT(attrGuiPtr != NULL);
			attrGuiPtr->SetValue("SettingsGui");
		}

		// create and set attribute value for 'Model'
		icomp::IRegistryElement::AttributeInfo* attrInfoModelPtr = infoSettingsDialogPtr->elementPtr->InsertAttributeInfo("Model", "icomp::CReferenceAttribute");
		if (attrInfoModelPtr != NULL){
			attrInfoModelPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoModelPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrModelPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoModelPtr->attributePtr.GetPtr());
			I_ASSERT(attrModelPtr != NULL);
			attrModelPtr->SetValue("Settings");
		}

		// create and set attribute value for 'ModelEditor'
		icomp::IRegistryElement::AttributeInfo* attrInfoModelEditorPtr = infoSettingsDialogPtr->elementPtr->InsertAttributeInfo("ModelEditor", "icomp::CReferenceAttribute");
		if (attrInfoModelEditorPtr != NULL){
			attrInfoModelEditorPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoModelEditorPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrModelEditorPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoModelEditorPtr->attributePtr.GetPtr());
			I_ASSERT(attrModelEditorPtr != NULL);
			attrModelEditorPtr->SetValue("SettingsGui");
		}

		// create and set attribute value for 'ModelObserver'
		icomp::IRegistryElement::AttributeInfo* attrInfoModelObserverPtr = infoSettingsDialogPtr->elementPtr->InsertAttributeInfo("ModelObserver", "icomp::CReferenceAttribute");
		if (attrInfoModelObserverPtr != NULL){
			attrInfoModelObserverPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoModelObserverPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrModelObserverPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoModelObserverPtr->attributePtr.GetPtr());
			I_ASSERT(attrModelObserverPtr != NULL);
			attrModelObserverPtr->SetValue("SettingsGui");
		}

		// create and set attribute value for 'WorkingDataFactory'
		icomp::IRegistryElement::AttributeInfo* attrInfoWorkingDataFactoryPtr = infoSettingsDialogPtr->elementPtr->InsertAttributeInfo("WorkingDataFactory", "icomp::CFactoryAttribute");
		if (attrInfoWorkingDataFactoryPtr != NULL){
			attrInfoWorkingDataFactoryPtr->attributePtr.SetPtr(new icomp::CFactoryAttribute);
			I_ASSERT(attrInfoWorkingDataFactoryPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrWorkingDataFactoryPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoWorkingDataFactoryPtr->attributePtr.GetPtr());
			I_ASSERT(attrWorkingDataFactoryPtr != NULL);
			attrWorkingDataFactoryPtr->SetValue("Settings");
		}
	}

	// element 'SettingsGui' of type QtGuiPck::ComposedParamsSetGui
	icomp::IRegistry::ElementInfo* infoSettingsGuiPtr = InsertElementInfo(
				"SettingsGui",
				icomp::CComponentAddress("QtGuiPck", "ComposedParamsSetGui"),
				true);
	if ((infoSettingsGuiPtr != NULL) && infoSettingsGuiPtr->elementPtr.IsValid()){
		// create and set attribute value for 'Editors'
		icomp::IRegistryElement::AttributeInfo* attrInfoEditorsPtr = infoSettingsGuiPtr->elementPtr->InsertAttributeInfo("Editors", "icomp::CMultiReferenceAttribute");
		if (attrInfoEditorsPtr != NULL){
			attrInfoEditorsPtr->attributePtr.SetPtr(new icomp::CMultiReferenceAttribute);
			I_ASSERT(attrInfoEditorsPtr->attributePtr.IsValid());

			icomp::TMultiAttribute<std::string>* nattrInfoEditorsPtr = dynamic_cast<icomp::TMultiAttribute<std::string>*>(attrInfoEditorsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoEditorsPtr != NULL);

			nattrInfoEditorsPtr->Reset();
			nattrInfoEditorsPtr->InsertValue("ConfigFileGui");
			nattrInfoEditorsPtr->InsertValue("PreviewCommandFileGui");
			nattrInfoEditorsPtr->InsertValue("HtmlBrowserFileGui");
			nattrInfoEditorsPtr->InsertValue("HtmlEditorFileGui");
		}

		// create and set attribute value for 'Ids'
		icomp::IRegistryElement::AttributeInfo* attrInfoIdsPtr = infoSettingsGuiPtr->elementPtr->InsertAttributeInfo("Ids", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoIdsPtr != NULL){
			attrInfoIdsPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoIdsPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoIdsPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoIdsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoIdsPtr != NULL);

			nattrInfoIdsPtr->Reset();
			nattrInfoIdsPtr->InsertValue(L"ConfigFile");
			nattrInfoIdsPtr->InsertValue(L"PreviewCommandFile");
			nattrInfoIdsPtr->InsertValue(L"HtmlBrowserFile");
			nattrInfoIdsPtr->InsertValue(L"HtmlEditorFile");
		}

		// create and set attribute value for 'Names'
		icomp::IRegistryElement::AttributeInfo* attrInfoNamesPtr = infoSettingsGuiPtr->elementPtr->InsertAttributeInfo("Names", "icomp::TMultiAttribute<istd::CString>");
		if (attrInfoNamesPtr != NULL){
			attrInfoNamesPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<istd::CString>);
			I_ASSERT(attrInfoNamesPtr->attributePtr.IsValid());

			icomp::CMultiStringAttribute* nattrInfoNamesPtr = dynamic_cast<icomp::CMultiStringAttribute*>(attrInfoNamesPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoNamesPtr != NULL);

			nattrInfoNamesPtr->Reset();
			nattrInfoNamesPtr->InsertValue(L"Configuration File");
			nattrInfoNamesPtr->InsertValue(L"ACF Command Path");
			nattrInfoNamesPtr->InsertValue(L"HTML Browser");
			nattrInfoNamesPtr->InsertValue(L"HTML Editor");
		}
	}

	// element 'SettingsPersistence' of type AcfGuiVoce::SettingsPersistence
	icomp::IRegistry::ElementInfo* infoSettingsPersistencePtr = InsertElementInfo(
				"SettingsPersistence",
				icomp::CComponentAddress("AcfGuiVoce", "SettingsPersistence"),
				true);
	if ((infoSettingsPersistencePtr != NULL) && infoSettingsPersistencePtr->elementPtr.IsValid()){
		infoSettingsPersistencePtr->elementPtr->SetElementFlags(1);

		// create and set attribute value for 'ApplicationInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoApplicationInfoPtr = infoSettingsPersistencePtr->elementPtr->InsertAttributeInfo("ApplicationInfo", "icomp::CReferenceAttribute");
		if (attrInfoApplicationInfoPtr != NULL){
			attrInfoApplicationInfoPtr->exportId = "ApplicationInfo";
		}

		// create and set attribute value for 'Log'
		icomp::IRegistryElement::AttributeInfo* attrInfoLogPtr = infoSettingsPersistencePtr->elementPtr->InsertAttributeInfo("Log", "icomp::CReferenceAttribute");
		if (attrInfoLogPtr != NULL){
			attrInfoLogPtr->exportId = "Log";
		}

		// create and set attribute value for 'Object'
		icomp::IRegistryElement::AttributeInfo* attrInfoObjectPtr = infoSettingsPersistencePtr->elementPtr->InsertAttributeInfo("Object", "icomp::CReferenceAttribute");
		if (attrInfoObjectPtr != NULL){
			attrInfoObjectPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoObjectPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrObjectPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoObjectPtr->attributePtr.GetPtr());
			I_ASSERT(attrObjectPtr != NULL);
			attrObjectPtr->SetValue("Settings");
		}

		// create and set attribute value for 'RootKey'
		icomp::IRegistryElement::AttributeInfo* attrInfoRootKeyPtr = infoSettingsPersistencePtr->elementPtr->InsertAttributeInfo("RootKey", "icomp::TAttribute<istd::CString>");
		if (attrInfoRootKeyPtr != NULL){
			attrInfoRootKeyPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoRootKeyPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrRootKeyPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoRootKeyPtr->attributePtr.GetPtr());
			I_ASSERT(attrRootKeyPtr != NULL);
			attrRootKeyPtr->SetValue(L"ApplicationSettings");
		}
	}

	// interface export
	SetElementInterfaceExported(
				"SettingsDialog",
				"iqtgui::IDialog",
				true);
	SetElementInterfaceExported(
				"SettingsGui",
				"iqtgui::IGuiObject",
				true);

	// component export
	SetElementExported(
				"ConfigFile",
				"Settings/ConfigFile");
	SetElementExported(
				"HtmlBrowserFile",
				"Settings/HtmlBrowserFile");
	SetElementExported(
				"HtmlEditorFile",
				"Settings/HtmlEditorFile");
	SetElementExported(
				"PreviewCommandFile",
				"Settings/PreviewCommandFile");
	SetElementExported(
				"SettingsGui",
				"SettingsGui");
}


// Embedded class CCompositorTemplateRegistry

CCompositor::CCmpstrVocePck::CCompositorTemplateRegistry::CCompositorTemplateRegistry()
{
	// element 'DocumentTemplate' of type QtPck::ExtendedDocumentTemplate
	icomp::IRegistry::ElementInfo* infoDocumentTemplatePtr = InsertElementInfo(
				"DocumentTemplate",
				icomp::CComponentAddress("QtPck", "ExtendedDocumentTemplate"),
				true);
	if ((infoDocumentTemplatePtr != NULL) && infoDocumentTemplatePtr->elementPtr.IsValid()){
		// create and set attribute value for 'DocumentFactory'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentFactoryPtr = infoDocumentTemplatePtr->elementPtr->InsertAttributeInfo("DocumentFactory", "icomp::CFactoryAttribute");
		if (attrInfoDocumentFactoryPtr != NULL){
			attrInfoDocumentFactoryPtr->attributePtr.SetPtr(new icomp::CFactoryAttribute);
			I_ASSERT(attrInfoDocumentFactoryPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrDocumentFactoryPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoDocumentFactoryPtr->attributePtr.GetPtr());
			I_ASSERT(attrDocumentFactoryPtr != NULL);
			attrDocumentFactoryPtr->SetValue("VisualRegistry");
		}

		// create and set attribute value for 'DocumentLoader'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentLoaderPtr = infoDocumentTemplatePtr->elementPtr->InsertAttributeInfo("DocumentLoader", "icomp::CReferenceAttribute");
		if (attrInfoDocumentLoaderPtr != NULL){
			attrInfoDocumentLoaderPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoDocumentLoaderPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrDocumentLoaderPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoDocumentLoaderPtr->attributePtr.GetPtr());
			I_ASSERT(attrDocumentLoaderPtr != NULL);
			attrDocumentLoaderPtr->SetValue("RegistryLoader");
		}

		// create and set attribute value for 'IsEditSupported'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsEditSupportedPtr = infoDocumentTemplatePtr->elementPtr->InsertAttributeInfo("IsEditSupported", "icomp::TAttribute<bool>");
		if (attrInfoIsEditSupportedPtr != NULL){
			attrInfoIsEditSupportedPtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoIsEditSupportedPtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrIsEditSupportedPtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoIsEditSupportedPtr->attributePtr.GetPtr());
			I_ASSERT(attrIsEditSupportedPtr != NULL);
			attrIsEditSupportedPtr->SetValue(true);
		}

		// create and set attribute value for 'IsNewSupported'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsNewSupportedPtr = infoDocumentTemplatePtr->elementPtr->InsertAttributeInfo("IsNewSupported", "icomp::TAttribute<bool>");
		if (attrInfoIsNewSupportedPtr != NULL){
			attrInfoIsNewSupportedPtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoIsNewSupportedPtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrIsNewSupportedPtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoIsNewSupportedPtr->attributePtr.GetPtr());
			I_ASSERT(attrIsNewSupportedPtr != NULL);
			attrIsNewSupportedPtr->SetValue(true);
		}

		// create and set attribute value for 'ViewFactory'
		icomp::IRegistryElement::AttributeInfo* attrInfoViewFactoryPtr = infoDocumentTemplatePtr->elementPtr->InsertAttributeInfo("ViewFactory", "icomp::CFactoryAttribute");
		if (attrInfoViewFactoryPtr != NULL){
			attrInfoViewFactoryPtr->attributePtr.SetPtr(new icomp::CFactoryAttribute);
			I_ASSERT(attrInfoViewFactoryPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrViewFactoryPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoViewFactoryPtr->attributePtr.GetPtr());
			I_ASSERT(attrViewFactoryPtr != NULL);
			attrViewFactoryPtr->SetValue("VisualRegistryView");
		}
	}

	// element 'PackagesLoaderExt' of type CmpstrPck::PackagesLoaderExt
	icomp::IRegistry::ElementInfo* infoPackagesLoaderExtPtr = InsertElementInfo(
				"PackagesLoaderExt",
				icomp::CComponentAddress("CmpstrPck", "PackagesLoaderExt"),
				true);
	if ((infoPackagesLoaderExtPtr != NULL) && infoPackagesLoaderExtPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ConfigFilePath'
		icomp::IRegistryElement::AttributeInfo* attrInfoConfigFilePathPtr = infoPackagesLoaderExtPtr->elementPtr->InsertAttributeInfo("ConfigFilePath", "icomp::CReferenceAttribute");
		if (attrInfoConfigFilePathPtr != NULL){
			attrInfoConfigFilePathPtr->exportId = "ConfigFilePath";
		}

		// create and set attribute value for 'Log'
		icomp::IRegistryElement::AttributeInfo* attrInfoLogPtr = infoPackagesLoaderExtPtr->elementPtr->InsertAttributeInfo("Log", "icomp::CReferenceAttribute");
		if (attrInfoLogPtr != NULL){
			attrInfoLogPtr->exportId = "Log";
		}

		// create and set attribute value for 'RegistryLoader'
		icomp::IRegistryElement::AttributeInfo* attrInfoRegistryLoaderPtr = infoPackagesLoaderExtPtr->elementPtr->InsertAttributeInfo("RegistryLoader", "icomp::CReferenceAttribute");
		if (attrInfoRegistryLoaderPtr != NULL){
			attrInfoRegistryLoaderPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoRegistryLoaderPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrRegistryLoaderPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoRegistryLoaderPtr->attributePtr.GetPtr());
			I_ASSERT(attrRegistryLoaderPtr != NULL);
			attrRegistryLoaderPtr->SetValue("RegistryLoader");
		}
	}

	// element 'Preview' of type CmpstrPck::RegistryPreview
	icomp::IRegistry::ElementInfo* infoPreviewPtr = InsertElementInfo(
				"Preview",
				icomp::CComponentAddress("CmpstrPck", "RegistryPreview"),
				true);
	if ((infoPreviewPtr != NULL) && infoPreviewPtr->elementPtr.IsValid()){
		// create and set attribute value for 'CommandFileName'
		icomp::IRegistryElement::AttributeInfo* attrInfoCommandFileNamePtr = infoPreviewPtr->elementPtr->InsertAttributeInfo("CommandFileName", "icomp::CReferenceAttribute");
		if (attrInfoCommandFileNamePtr != NULL){
			attrInfoCommandFileNamePtr->exportId = "PreviewCommandFile";
		}

		// create and set attribute value for 'EnvironmentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoEnvironmentManagerPtr = infoPreviewPtr->elementPtr->InsertAttributeInfo("EnvironmentManager", "icomp::CReferenceAttribute");
		if (attrInfoEnvironmentManagerPtr != NULL){
			attrInfoEnvironmentManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoEnvironmentManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrEnvironmentManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoEnvironmentManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrEnvironmentManagerPtr != NULL);
			attrEnvironmentManagerPtr->SetValue("PackagesLoaderExt");
		}

		// create and set attribute value for 'VersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionInfoPtr = infoPreviewPtr->elementPtr->InsertAttributeInfo("VersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoVersionInfoPtr != NULL){
			attrInfoVersionInfoPtr->exportId = "VersionInfo";
		}
	}

	// element 'RegistryCodeSaver' of type BasePck::RegistryCodeSaver
	icomp::IRegistry::ElementInfo* infoRegistryCodeSaverPtr = InsertElementInfo(
				"RegistryCodeSaver",
				icomp::CComponentAddress("BasePck", "RegistryCodeSaver"),
				true);
	if ((infoRegistryCodeSaverPtr != NULL) && infoRegistryCodeSaverPtr->elementPtr.IsValid()){
		// create and set attribute value for 'RegistriesManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoRegistriesManagerPtr = infoRegistryCodeSaverPtr->elementPtr->InsertAttributeInfo("RegistriesManager", "icomp::CReferenceAttribute");
		if (attrInfoRegistriesManagerPtr != NULL){
			attrInfoRegistriesManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoRegistriesManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrRegistriesManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoRegistriesManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrRegistriesManagerPtr != NULL);
			attrRegistriesManagerPtr->SetValue("PackagesLoaderExt");
		}
	}

	// element 'RegistryConsistInfo' of type CmpstrPck::RegistryConsistInfo
	icomp::IRegistry::ElementInfo* infoRegistryConsistInfoPtr = InsertElementInfo(
				"RegistryConsistInfo",
				icomp::CComponentAddress("CmpstrPck", "RegistryConsistInfo"),
				true);
	if ((infoRegistryConsistInfoPtr != NULL) && infoRegistryConsistInfoPtr->elementPtr.IsValid()){
		// create and set attribute value for 'EnvironmentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoEnvironmentManagerPtr = infoRegistryConsistInfoPtr->elementPtr->InsertAttributeInfo("EnvironmentManager", "icomp::CReferenceAttribute");
		if (attrInfoEnvironmentManagerPtr != NULL){
			attrInfoEnvironmentManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoEnvironmentManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrEnvironmentManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoEnvironmentManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrEnvironmentManagerPtr != NULL);
			attrEnvironmentManagerPtr->SetValue("PackagesLoaderExt");
		}
	}

	// element 'RegistryLoader' of type CmpstrPck::RegistryLoader
	icomp::IRegistry::ElementInfo* infoRegistryLoaderPtr = InsertElementInfo(
				"RegistryLoader",
				icomp::CComponentAddress("CmpstrPck", "RegistryLoader"),
				true);
	if ((infoRegistryLoaderPtr != NULL) && infoRegistryLoaderPtr->elementPtr.IsValid()){
		// create and set attribute value for 'Log'
		icomp::IRegistryElement::AttributeInfo* attrInfoLogPtr = infoRegistryLoaderPtr->elementPtr->InsertAttributeInfo("Log", "icomp::CReferenceAttribute");
		if (attrInfoLogPtr != NULL){
			attrInfoLogPtr->exportId = "Log";
		}

		// create and set attribute value for 'VersionInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionInfoPtr = infoRegistryLoaderPtr->elementPtr->InsertAttributeInfo("VersionInfo", "icomp::CReferenceAttribute");
		if (attrInfoVersionInfoPtr != NULL){
			attrInfoVersionInfoPtr->exportId = "VersionInfo";
		}
	}

	// element 'VisualRegistry' of type CmpstrPck::VisualRegistry
	icomp::IRegistry::ElementInfo* infoVisualRegistryPtr = InsertElementInfo(
				"VisualRegistry",
				icomp::CComponentAddress("CmpstrPck", "VisualRegistry"),
				true);
	if ((infoVisualRegistryPtr != NULL) && infoVisualRegistryPtr->elementPtr.IsValid()){
		// create and set attribute value for 'Log'
		icomp::IRegistryElement::AttributeInfo* attrInfoLogPtr = infoVisualRegistryPtr->elementPtr->InsertAttributeInfo("Log", "icomp::CReferenceAttribute");
		if (attrInfoLogPtr != NULL){
			attrInfoLogPtr->exportId = "Log";
		}

		// create and set attribute value for 'MetaInfoManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoMetaInfoManagerPtr = infoVisualRegistryPtr->elementPtr->InsertAttributeInfo("MetaInfoManager", "icomp::CReferenceAttribute");
		if (attrInfoMetaInfoManagerPtr != NULL){
			attrInfoMetaInfoManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoMetaInfoManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrMetaInfoManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoMetaInfoManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrMetaInfoManagerPtr != NULL);
			attrMetaInfoManagerPtr->SetValue("PackagesLoaderExt");
		}
	}

	// element 'VisualRegistryView' of type CmpstrVoce::VisualRegistryView
	icomp::IRegistry::ElementInfo* infoVisualRegistryViewPtr = InsertElementInfo(
				"VisualRegistryView",
				icomp::CComponentAddress("CmpstrVoce", "VisualRegistryView"),
				true);
	if ((infoVisualRegistryViewPtr != NULL) && infoVisualRegistryViewPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ConsistencyInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoConsistencyInfoPtr = infoVisualRegistryViewPtr->elementPtr->InsertAttributeInfo("ConsistencyInfo", "icomp::CReferenceAttribute");
		if (attrInfoConsistencyInfoPtr != NULL){
			attrInfoConsistencyInfoPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoConsistencyInfoPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrConsistencyInfoPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoConsistencyInfoPtr->attributePtr.GetPtr());
			I_ASSERT(attrConsistencyInfoPtr != NULL);
			attrConsistencyInfoPtr->SetValue("RegistryConsistInfo");
		}

		// create and set attribute value for 'DocumentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentManagerPtr = infoVisualRegistryViewPtr->elementPtr->InsertAttributeInfo("DocumentManager", "icomp::CReferenceAttribute");
		if (attrInfoDocumentManagerPtr != NULL){
			attrInfoDocumentManagerPtr->exportId = "DocumentManager";
		}

		// create and set attribute value for 'MainWindow'
		icomp::IRegistryElement::AttributeInfo* attrInfoMainWindowPtr = infoVisualRegistryViewPtr->elementPtr->InsertAttributeInfo("MainWindow", "icomp::CReferenceAttribute");
		if (attrInfoMainWindowPtr != NULL){
			attrInfoMainWindowPtr->exportId = "MainWindow";
		}

		// create and set attribute value for 'MetaInfoManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoMetaInfoManagerPtr = infoVisualRegistryViewPtr->elementPtr->InsertAttributeInfo("MetaInfoManager", "icomp::CReferenceAttribute");
		if (attrInfoMetaInfoManagerPtr != NULL){
			attrInfoMetaInfoManagerPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoMetaInfoManagerPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrMetaInfoManagerPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoMetaInfoManagerPtr->attributePtr.GetPtr());
			I_ASSERT(attrMetaInfoManagerPtr != NULL);
			attrMetaInfoManagerPtr->SetValue("PackagesLoaderExt");
		}

		// create and set attribute value for 'QuickHelpViewer'
		icomp::IRegistryElement::AttributeInfo* attrInfoQuickHelpViewerPtr = infoVisualRegistryViewPtr->elementPtr->InsertAttributeInfo("QuickHelpViewer", "icomp::CReferenceAttribute");
		if (attrInfoQuickHelpViewerPtr != NULL){
			attrInfoQuickHelpViewerPtr->exportId = "QuickHelpViewer";
		}

		// create and set attribute value for 'RegistryCodeSaver'
		icomp::IRegistryElement::AttributeInfo* attrInfoRegistryCodeSaverPtr = infoVisualRegistryViewPtr->elementPtr->InsertAttributeInfo("RegistryCodeSaver", "icomp::CReferenceAttribute");
		if (attrInfoRegistryCodeSaverPtr != NULL){
			attrInfoRegistryCodeSaverPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoRegistryCodeSaverPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrRegistryCodeSaverPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoRegistryCodeSaverPtr->attributePtr.GetPtr());
			I_ASSERT(attrRegistryCodeSaverPtr != NULL);
			attrRegistryCodeSaverPtr->SetValue("RegistryCodeSaver");
		}

		// create and set attribute value for 'RegistryPreview'
		icomp::IRegistryElement::AttributeInfo* attrInfoRegistryPreviewPtr = infoVisualRegistryViewPtr->elementPtr->InsertAttributeInfo("RegistryPreview", "icomp::CReferenceAttribute");
		if (attrInfoRegistryPreviewPtr != NULL){
			attrInfoRegistryPreviewPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoRegistryPreviewPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrRegistryPreviewPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoRegistryPreviewPtr->attributePtr.GetPtr());
			I_ASSERT(attrRegistryPreviewPtr != NULL);
			attrRegistryPreviewPtr->SetValue("Preview");
		}

		// create and set attribute value for 'RegistrySelectionObservers'
		icomp::IRegistryElement::AttributeInfo* attrInfoRegistrySelectionObserversPtr = infoVisualRegistryViewPtr->elementPtr->InsertAttributeInfo("RegistrySelectionObservers", "icomp::CMultiReferenceAttribute");
		if (attrInfoRegistrySelectionObserversPtr != NULL){
			attrInfoRegistrySelectionObserversPtr->exportId = "RegistrySelectionObservers";
		}
	}

	// interface export
	SetElementInterfaceExported(
				"DocumentTemplate",
				"ibase::ICommandsProvider",
				true);
	SetElementInterfaceExported(
				"PackagesLoaderExt",
				"icmpstr::IExternalMetaInfoManager",
				true);
	SetElementInterfaceExported(
				"RegistryConsistInfo",
				"icmpstr::IRegistryConsistInfo",
				true);
	SetElementInterfaceExported(
				"PackagesLoaderExt",
				"icomp::IComponentEnvironmentManager",
				true);
	SetElementInterfaceExported(
				"PackagesLoaderExt",
				"icomp::IComponentStaticInfo",
				true);
	SetElementInterfaceExported(
				"PackagesLoaderExt",
				"icomp::IMetaInfoManager",
				true);
	SetElementInterfaceExported(
				"PackagesLoaderExt",
				"icomp::IRegistriesManager",
				true);
	SetElementInterfaceExported(
				"PackagesLoaderExt",
				"icomp::IRegistryLoader",
				true);
	SetElementInterfaceExported(
				"DocumentTemplate",
				"idoc::IDocumentTemplate",
				true);
}


// Embedded class CPackageOverviewDockRegistry

CCompositor::CCmpstrVocePck::CPackageOverviewDockRegistry::CPackageOverviewDockRegistry()
{
	// element 'PackageOverview' of type CmpstrPck::PackageOverview
	icomp::IRegistry::ElementInfo* infoPackageOverviewPtr = InsertElementInfo(
				"PackageOverview",
				icomp::CComponentAddress("CmpstrPck", "PackageOverview"),
				true);
	if ((infoPackageOverviewPtr != NULL) && infoPackageOverviewPtr->elementPtr.IsValid()){
		// create and set attribute value for 'ConsistencyInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoConsistencyInfoPtr = infoPackageOverviewPtr->elementPtr->InsertAttributeInfo("ConsistencyInfo", "icomp::CReferenceAttribute");
		if (attrInfoConsistencyInfoPtr != NULL){
			attrInfoConsistencyInfoPtr->exportId = "ConsistencyInfo";
		}

		// create and set attribute value for 'DocumentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentManagerPtr = infoPackageOverviewPtr->elementPtr->InsertAttributeInfo("DocumentManager", "icomp::CReferenceAttribute");
		if (attrInfoDocumentManagerPtr != NULL){
			attrInfoDocumentManagerPtr->exportId = "DocumentManager";
		}

		// create and set attribute value for 'EnvironmentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoEnvironmentManagerPtr = infoPackageOverviewPtr->elementPtr->InsertAttributeInfo("EnvironmentManager", "icomp::CReferenceAttribute");
		if (attrInfoEnvironmentManagerPtr != NULL){
			attrInfoEnvironmentManagerPtr->exportId = "EnvironmentManager";
		}

		// create and set attribute value for 'QuickHelpViewer'
		icomp::IRegistryElement::AttributeInfo* attrInfoQuickHelpViewerPtr = infoPackageOverviewPtr->elementPtr->InsertAttributeInfo("QuickHelpViewer", "icomp::CReferenceAttribute");
		if (attrInfoQuickHelpViewerPtr != NULL){
			attrInfoQuickHelpViewerPtr->exportId = "QuickHelpViewer";
		}
	}

	// element 'PackageOverviewDock' of type QtGuiPck::DockWidgetGui
	icomp::IRegistry::ElementInfo* infoPackageOverviewDockPtr = InsertElementInfo(
				"PackageOverviewDock",
				icomp::CComponentAddress("QtGuiPck", "DockWidgetGui"),
				true);
	if ((infoPackageOverviewDockPtr != NULL) && infoPackageOverviewDockPtr->elementPtr.IsValid()){
		// create and set attribute value for 'DockTitle'
		icomp::IRegistryElement::AttributeInfo* attrInfoDockTitlePtr = infoPackageOverviewDockPtr->elementPtr->InsertAttributeInfo("DockTitle", "icomp::TAttribute<istd::CString>");
		if (attrInfoDockTitlePtr != NULL){
			attrInfoDockTitlePtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoDockTitlePtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrDockTitlePtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoDockTitlePtr->attributePtr.GetPtr());
			I_ASSERT(attrDockTitlePtr != NULL);
			attrDockTitlePtr->SetValue(L"Packages");
		}

		// create and set attribute value for 'SlaveGui'
		icomp::IRegistryElement::AttributeInfo* attrInfoSlaveGuiPtr = infoPackageOverviewDockPtr->elementPtr->InsertAttributeInfo("SlaveGui", "icomp::CReferenceAttribute");
		if (attrInfoSlaveGuiPtr != NULL){
			attrInfoSlaveGuiPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSlaveGuiPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSlaveGuiPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSlaveGuiPtr->attributePtr.GetPtr());
			I_ASSERT(attrSlaveGuiPtr != NULL);
			attrSlaveGuiPtr->SetValue("PackageOverview");
		}
	}

	// interface export
	SetElementInterfaceExported(
				"PackageOverview",
				"ibase::ICommandsProvider",
				true);
	SetElementInterfaceExported(
				"PackageOverview",
				"icmpstr::IAttributeSelectionObserver",
				true);
	SetElementInterfaceExported(
				"PackageOverview",
				"imod::IModelEditor",
				true);
	SetElementInterfaceExported(
				"PackageOverview",
				"imod::IObserver",
				true);
	SetElementInterfaceExported(
				"PackageOverview",
				"iqtgui::IGuiObject",
				true);
	SetElementInterfaceExported(
				"PackageOverviewDock",
				"iqtgui::IMainWindowComponent",
				true);
}


// Embedded class CVisualRegistryViewRegistry

CCompositor::CCmpstrVocePck::CVisualRegistryViewRegistry::CVisualRegistryViewRegistry()
{
	// element 'CommandsBinder' of type QtGuiPck::CommandsBinder
	icomp::IRegistry::ElementInfo* infoCommandsBinderPtr = InsertElementInfo(
				"CommandsBinder",
				icomp::CComponentAddress("QtGuiPck", "CommandsBinder"),
				true);
	if ((infoCommandsBinderPtr != NULL) && infoCommandsBinderPtr->elementPtr.IsValid()){
		// create and set attribute value for 'CommandProviders'
		icomp::IRegistryElement::AttributeInfo* attrInfoCommandProvidersPtr = infoCommandsBinderPtr->elementPtr->InsertAttributeInfo("CommandProviders", "icomp::CMultiReferenceAttribute");
		if (attrInfoCommandProvidersPtr != NULL){
			attrInfoCommandProvidersPtr->attributePtr.SetPtr(new icomp::CMultiReferenceAttribute);
			I_ASSERT(attrInfoCommandProvidersPtr->attributePtr.IsValid());

			icomp::TMultiAttribute<std::string>* nattrInfoCommandProvidersPtr = dynamic_cast<icomp::TMultiAttribute<std::string>*>(attrInfoCommandProvidersPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoCommandProvidersPtr != NULL);

			nattrInfoCommandProvidersPtr->Reset();
			nattrInfoCommandProvidersPtr->InsertValue("VisualRegistryScenographer");
			nattrInfoCommandProvidersPtr->InsertValue("SceneProvider");
		}
	}

	// element 'SceneProvider' of type QtViewPck::SceneProvider
	icomp::IRegistry::ElementInfo* infoSceneProviderPtr = InsertElementInfo(
				"SceneProvider",
				icomp::CComponentAddress("QtViewPck", "SceneProvider"),
				true);
	if ((infoSceneProviderPtr != NULL) && infoSceneProviderPtr->elementPtr.IsValid()){
		// create and set attribute value for 'BackgroundMode'
		icomp::IRegistryElement::AttributeInfo* attrInfoBackgroundModePtr = infoSceneProviderPtr->elementPtr->InsertAttributeInfo("BackgroundMode", "icomp::TAttribute<int>");
		if (attrInfoBackgroundModePtr != NULL){
			attrInfoBackgroundModePtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoBackgroundModePtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrBackgroundModePtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoBackgroundModePtr->attributePtr.GetPtr());
			I_ASSERT(attrBackgroundModePtr != NULL);
			attrBackgroundModePtr->SetValue(2);
		}

		// create and set attribute value for 'DropConsumers'
		icomp::IRegistryElement::AttributeInfo* attrInfoDropConsumersPtr = infoSceneProviderPtr->elementPtr->InsertAttributeInfo("DropConsumers", "icomp::CMultiReferenceAttribute");
		if (attrInfoDropConsumersPtr != NULL){
			attrInfoDropConsumersPtr->attributePtr.SetPtr(new icomp::CMultiReferenceAttribute);
			I_ASSERT(attrInfoDropConsumersPtr->attributePtr.IsValid());

			icomp::TMultiAttribute<std::string>* nattrInfoDropConsumersPtr = dynamic_cast<icomp::TMultiAttribute<std::string>*>(attrInfoDropConsumersPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoDropConsumersPtr != NULL);

			nattrInfoDropConsumersPtr->Reset();
			nattrInfoDropConsumersPtr->InsertValue("VisualRegistryScenographer");
		}

		// create and set attribute value for 'GridSize'
		icomp::IRegistryElement::AttributeInfo* attrInfoGridSizePtr = infoSceneProviderPtr->elementPtr->InsertAttributeInfo("GridSize", "icomp::TAttribute<double>");
		if (attrInfoGridSizePtr != NULL){
			attrInfoGridSizePtr->attributePtr.SetPtr(new icomp::TAttribute<double>);
			I_ASSERT(attrInfoGridSizePtr->attributePtr.IsValid());

			icomp::CDoubleAttribute* attrGridSizePtr = dynamic_cast<icomp::CDoubleAttribute*>(attrInfoGridSizePtr->attributePtr.GetPtr());
			I_ASSERT(attrGridSizePtr != NULL);
			attrGridSizePtr->SetValue(25);
		}

		// create and set attribute value for 'IsAlignmentEnabled'
		icomp::IRegistryElement::AttributeInfo* attrInfoIsAlignmentEnabledPtr = infoSceneProviderPtr->elementPtr->InsertAttributeInfo("IsAlignmentEnabled", "icomp::TAttribute<bool>");
		if (attrInfoIsAlignmentEnabledPtr != NULL){
			attrInfoIsAlignmentEnabledPtr->attributePtr.SetPtr(new icomp::TAttribute<bool>);
			I_ASSERT(attrInfoIsAlignmentEnabledPtr->attributePtr.IsValid());

			icomp::CBoolAttribute* attrIsAlignmentEnabledPtr = dynamic_cast<icomp::CBoolAttribute*>(attrInfoIsAlignmentEnabledPtr->attributePtr.GetPtr());
			I_ASSERT(attrIsAlignmentEnabledPtr != NULL);
			attrIsAlignmentEnabledPtr->SetValue(true);
		}

		// create and set attribute value for 'SceneHeight'
		icomp::IRegistryElement::AttributeInfo* attrInfoSceneHeightPtr = infoSceneProviderPtr->elementPtr->InsertAttributeInfo("SceneHeight", "icomp::TAttribute<double>");
		if (attrInfoSceneHeightPtr != NULL){
			attrInfoSceneHeightPtr->attributePtr.SetPtr(new icomp::TAttribute<double>);
			I_ASSERT(attrInfoSceneHeightPtr->attributePtr.IsValid());

			icomp::CDoubleAttribute* attrSceneHeightPtr = dynamic_cast<icomp::CDoubleAttribute*>(attrInfoSceneHeightPtr->attributePtr.GetPtr());
			I_ASSERT(attrSceneHeightPtr != NULL);
			attrSceneHeightPtr->SetValue(841);
		}

		// create and set attribute value for 'SceneWidth'
		icomp::IRegistryElement::AttributeInfo* attrInfoSceneWidthPtr = infoSceneProviderPtr->elementPtr->InsertAttributeInfo("SceneWidth", "icomp::TAttribute<double>");
		if (attrInfoSceneWidthPtr != NULL){
			attrInfoSceneWidthPtr->attributePtr.SetPtr(new icomp::TAttribute<double>);
			I_ASSERT(attrInfoSceneWidthPtr->attributePtr.IsValid());

			icomp::CDoubleAttribute* attrSceneWidthPtr = dynamic_cast<icomp::CDoubleAttribute*>(attrInfoSceneWidthPtr->attributePtr.GetPtr());
			I_ASSERT(attrSceneWidthPtr != NULL);
			attrSceneWidthPtr->SetValue(1189);
		}
	}

	// element 'SelectedDocModelBinder' of type BasePck::SelectedDocModelBinder
	icomp::IRegistry::ElementInfo* infoSelectedDocModelBinderPtr = InsertElementInfo(
				"SelectedDocModelBinder",
				icomp::CComponentAddress("BasePck", "SelectedDocModelBinder"),
				true);
	if ((infoSelectedDocModelBinderPtr != NULL) && infoSelectedDocModelBinderPtr->elementPtr.IsValid()){
		infoSelectedDocModelBinderPtr->elementPtr->SetElementFlags(1);

		// create and set attribute value for 'ActivationObject'
		icomp::IRegistryElement::AttributeInfo* attrInfoActivationObjectPtr = infoSelectedDocModelBinderPtr->elementPtr->InsertAttributeInfo("ActivationObject", "icomp::CReferenceAttribute");
		if (attrInfoActivationObjectPtr != NULL){
			attrInfoActivationObjectPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoActivationObjectPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrActivationObjectPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoActivationObjectPtr->attributePtr.GetPtr());
			I_ASSERT(attrActivationObjectPtr != NULL);
			attrActivationObjectPtr->SetValue("SceneProvider");
		}

		// create and set attribute value for 'DocumentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentManagerPtr = infoSelectedDocModelBinderPtr->elementPtr->InsertAttributeInfo("DocumentManager", "icomp::CReferenceAttribute");
		if (attrInfoDocumentManagerPtr != NULL){
			attrInfoDocumentManagerPtr->exportId = "DocumentManager";
		}

		// create and set attribute value for 'Model'
		icomp::IRegistryElement::AttributeInfo* attrInfoModelPtr = infoSelectedDocModelBinderPtr->elementPtr->InsertAttributeInfo("Model", "icomp::CReferenceAttribute");
		if (attrInfoModelPtr != NULL){
			attrInfoModelPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoModelPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrModelPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoModelPtr->attributePtr.GetPtr());
			I_ASSERT(attrModelPtr != NULL);
			attrModelPtr->SetValue("VisualRegistryScenographer");
		}

		// create and set attribute value for 'Observers'
		icomp::IRegistryElement::AttributeInfo* attrInfoObserversPtr = infoSelectedDocModelBinderPtr->elementPtr->InsertAttributeInfo("Observers", "icomp::CMultiReferenceAttribute");
		if (attrInfoObserversPtr != NULL){
			attrInfoObserversPtr->exportId = "RegistrySelectionObservers";
		}
	}

	// element 'VisualRegistryScenographer' of type CmpstrPck::VisualRegistryScenographer
	icomp::IRegistry::ElementInfo* infoVisualRegistryScenographerPtr = InsertElementInfo(
				"VisualRegistryScenographer",
				icomp::CComponentAddress("CmpstrPck", "VisualRegistryScenographer"),
				true);
	if ((infoVisualRegistryScenographerPtr != NULL) && infoVisualRegistryScenographerPtr->elementPtr.IsValid()){
		infoVisualRegistryScenographerPtr->elementPtr->SetElementFlags(1);

		// create and set attribute value for 'ConsistencyInfo'
		icomp::IRegistryElement::AttributeInfo* attrInfoConsistencyInfoPtr = infoVisualRegistryScenographerPtr->elementPtr->InsertAttributeInfo("ConsistencyInfo", "icomp::CReferenceAttribute");
		if (attrInfoConsistencyInfoPtr != NULL){
			attrInfoConsistencyInfoPtr->exportId = "ConsistencyInfo";
		}

		// create and set attribute value for 'DocumentManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoDocumentManagerPtr = infoVisualRegistryScenographerPtr->elementPtr->InsertAttributeInfo("DocumentManager", "icomp::CReferenceAttribute");
		if (attrInfoDocumentManagerPtr != NULL){
			attrInfoDocumentManagerPtr->exportId = "DocumentManager";
		}

		// create and set attribute value for 'MainWindow'
		icomp::IRegistryElement::AttributeInfo* attrInfoMainWindowPtr = infoVisualRegistryScenographerPtr->elementPtr->InsertAttributeInfo("MainWindow", "icomp::CReferenceAttribute");
		if (attrInfoMainWindowPtr != NULL){
			attrInfoMainWindowPtr->exportId = "MainWindow";
		}

		// create and set attribute value for 'MetaInfoManager'
		icomp::IRegistryElement::AttributeInfo* attrInfoMetaInfoManagerPtr = infoVisualRegistryScenographerPtr->elementPtr->InsertAttributeInfo("MetaInfoManager", "icomp::CReferenceAttribute");
		if (attrInfoMetaInfoManagerPtr != NULL){
			attrInfoMetaInfoManagerPtr->exportId = "MetaInfoManager";
		}

		// create and set attribute value for 'QuickHelpViewer'
		icomp::IRegistryElement::AttributeInfo* attrInfoQuickHelpViewerPtr = infoVisualRegistryScenographerPtr->elementPtr->InsertAttributeInfo("QuickHelpViewer", "icomp::CReferenceAttribute");
		if (attrInfoQuickHelpViewerPtr != NULL){
			attrInfoQuickHelpViewerPtr->exportId = "QuickHelpViewer";
		}

		// create and set attribute value for 'RegistryCodeSaver'
		icomp::IRegistryElement::AttributeInfo* attrInfoRegistryCodeSaverPtr = infoVisualRegistryScenographerPtr->elementPtr->InsertAttributeInfo("RegistryCodeSaver", "icomp::CReferenceAttribute");
		if (attrInfoRegistryCodeSaverPtr != NULL){
			attrInfoRegistryCodeSaverPtr->exportId = "RegistryCodeSaver";
		}

		// create and set attribute value for 'RegistryPreview'
		icomp::IRegistryElement::AttributeInfo* attrInfoRegistryPreviewPtr = infoVisualRegistryScenographerPtr->elementPtr->InsertAttributeInfo("RegistryPreview", "icomp::CReferenceAttribute");
		if (attrInfoRegistryPreviewPtr != NULL){
			attrInfoRegistryPreviewPtr->exportId = "RegistryPreview";
		}

		// create and set attribute value for 'SceneProvider'
		icomp::IRegistryElement::AttributeInfo* attrInfoSceneProviderPtr = infoVisualRegistryScenographerPtr->elementPtr->InsertAttributeInfo("SceneProvider", "icomp::CReferenceAttribute");
		if (attrInfoSceneProviderPtr != NULL){
			attrInfoSceneProviderPtr->attributePtr.SetPtr(new icomp::CReferenceAttribute);
			I_ASSERT(attrInfoSceneProviderPtr->attributePtr.IsValid());

			icomp::TAttribute<std::string>* attrSceneProviderPtr = dynamic_cast<icomp::TAttribute<std::string>*>(attrInfoSceneProviderPtr->attributePtr.GetPtr());
			I_ASSERT(attrSceneProviderPtr != NULL);
			attrSceneProviderPtr->SetValue("SceneProvider");
		}
	}

	// interface export
	SetElementInterfaceExported(
				"SceneProvider",
				"i2d::ISceneController",
				true);
	SetElementInterfaceExported(
				"CommandsBinder",
				"ibase::ICommandsProvider",
				true);
	SetElementInterfaceExported(
				"VisualRegistryScenographer",
				"imod::IModel",
				true);
	SetElementInterfaceExported(
				"VisualRegistryScenographer",
				"imod::IObserver",
				true);
	SetElementInterfaceExported(
				"SceneProvider",
				"iqt2d::ISceneProvider",
				true);
	SetElementInterfaceExported(
				"SceneProvider",
				"iqtdoc::IPrintable",
				true);
	SetElementInterfaceExported(
				"SceneProvider",
				"iqtgui::IGuiObject",
				true);
}


// Embedded class CBasePck

CCompositor::CBasePck::CBasePck()
{
	const icomp::IComponentStaticInfo& infoApplicationInfo = BasePck::ApplicationInfo::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("ApplicationInfo", &infoApplicationInfo);
	const icomp::IComponentStaticInfo& infoAutoPersistence = BasePck::AutoPersistence::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("AutoPersistence", &infoAutoPersistence);
	const icomp::IComponentStaticInfo& infoComposedParamsSet = BasePck::ComposedParamsSet::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("ComposedParamsSet", &infoComposedParamsSet);
	const icomp::IComponentStaticInfo& infoCompositeDocumentTemplate = BasePck::CompositeDocumentTemplate::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("CompositeDocumentTemplate", &infoCompositeDocumentTemplate);
	const icomp::IComponentStaticInfo& infoFileNameParam = BasePck::FileNameParam::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("FileNameParam", &infoFileNameParam);
	const icomp::IComponentStaticInfo& infoFileTypeInfo = BasePck::FileTypeInfo::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("FileTypeInfo", &infoFileTypeInfo);
	const icomp::IComponentStaticInfo& infoLog = BasePck::Log::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("Log", &infoLog);
	const icomp::IComponentStaticInfo& infoRegistryCodeSaver = BasePck::RegistryCodeSaver::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("RegistryCodeSaver", &infoRegistryCodeSaver);
	const icomp::IComponentStaticInfo& infoSelectedDocModelBinder = BasePck::SelectedDocModelBinder::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("SelectedDocModelBinder", &infoSelectedDocModelBinder);
	const icomp::IComponentStaticInfo& infoVersionInfo = BasePck::VersionInfo::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("VersionInfo", &infoVersionInfo);
	const icomp::IComponentStaticInfo& infoXmlFileSerializer = BasePck::XmlFileSerializer::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("XmlFileSerializer", &infoXmlFileSerializer);
}


// Embedded class CCmpstrPck

CCompositor::CCmpstrPck::CCmpstrPck()
{
	const icomp::IComponentStaticInfo& infoAttributeEditor = CmpstrPck::AttributeEditor::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("AttributeEditor", &infoAttributeEditor);
	const icomp::IComponentStaticInfo& infoComponentHelpFileProvider = CmpstrPck::ComponentHelpFileProvider::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("ComponentHelpFileProvider", &infoComponentHelpFileProvider);
	const icomp::IComponentStaticInfo& infoPackageOverview = CmpstrPck::PackageOverview::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("PackageOverview", &infoPackageOverview);
	const icomp::IComponentStaticInfo& infoPackagesLoaderExt = CmpstrPck::PackagesLoaderExt::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("PackagesLoaderExt", &infoPackagesLoaderExt);
	const icomp::IComponentStaticInfo& infoQuickHelpViewer = CmpstrPck::QuickHelpViewer::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("QuickHelpViewer", &infoQuickHelpViewer);
	const icomp::IComponentStaticInfo& infoRegistryConsistInfo = CmpstrPck::RegistryConsistInfo::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("RegistryConsistInfo", &infoRegistryConsistInfo);
	const icomp::IComponentStaticInfo& infoRegistryLoader = CmpstrPck::RegistryLoader::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("RegistryLoader", &infoRegistryLoader);
	const icomp::IComponentStaticInfo& infoRegistryPreview = CmpstrPck::RegistryPreview::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("RegistryPreview", &infoRegistryPreview);
	const icomp::IComponentStaticInfo& infoRegistryPropEditor = CmpstrPck::RegistryPropEditor::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("RegistryPropEditor", &infoRegistryPropEditor);
	const icomp::IComponentStaticInfo& infoVisualRegistry = CmpstrPck::VisualRegistry::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("VisualRegistry", &infoVisualRegistry);
	const icomp::IComponentStaticInfo& infoVisualRegistryScenographer = CmpstrPck::VisualRegistryScenographer::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("VisualRegistryScenographer", &infoVisualRegistryScenographer);
}


// Embedded class CQtGuiPck

CCompositor::CQtGuiPck::CQtGuiPck()
{
	const icomp::IComponentStaticInfo& infoAboutGui = QtGuiPck::AboutGui::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("AboutGui", &infoAboutGui);
	const icomp::IComponentStaticInfo& infoCommandsBinder = QtGuiPck::CommandsBinder::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("CommandsBinder", &infoCommandsBinder);
	const icomp::IComponentStaticInfo& infoComposedParamsSetGui = QtGuiPck::ComposedParamsSetGui::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("ComposedParamsSetGui", &infoComposedParamsSetGui);
	const icomp::IComponentStaticInfo& infoDockWidgetGui = QtGuiPck::DockWidgetGui::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("DockWidgetGui", &infoDockWidgetGui);
	const icomp::IComponentStaticInfo& infoFileDialogLoader = QtGuiPck::FileDialogLoader::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("FileDialogLoader", &infoFileDialogLoader);
	const icomp::IComponentStaticInfo& infoFileNameParamGui = QtGuiPck::FileNameParamGui::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("FileNameParamGui", &infoFileNameParamGui);
	const icomp::IComponentStaticInfo& infoGuiApplication = QtGuiPck::GuiApplication::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("GuiApplication", &infoGuiApplication);
	const icomp::IComponentStaticInfo& infoLogGui = QtGuiPck::LogGui::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("LogGui", &infoLogGui);
	const icomp::IComponentStaticInfo& infoMainWindowGui = QtGuiPck::MainWindowGui::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("MainWindowGui", &infoMainWindowGui);
	const icomp::IComponentStaticInfo& infoModelDialogGui = QtGuiPck::ModelDialogGui::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("ModelDialogGui", &infoModelDialogGui);
	const icomp::IComponentStaticInfo& infoModelEditorGui = QtGuiPck::ModelEditorGui::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("ModelEditorGui", &infoModelEditorGui);
	const icomp::IComponentStaticInfo& infoMultiDocWorkspaceGui = QtGuiPck::MultiDocWorkspaceGui::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("MultiDocWorkspaceGui", &infoMultiDocWorkspaceGui);
	const icomp::IComponentStaticInfo& infoSplashScreen = QtGuiPck::SplashScreen::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("SplashScreen", &infoSplashScreen);
}


// Embedded class CQtPck

CCompositor::CQtPck::CQtPck()
{
	const icomp::IComponentStaticInfo& infoApplicationSettingsProvider = QtPck::ApplicationSettingsProvider::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("ApplicationSettingsProvider", &infoApplicationSettingsProvider);
	const icomp::IComponentStaticInfo& infoExtendedDocumentTemplate = QtPck::ExtendedDocumentTemplate::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("ExtendedDocumentTemplate", &infoExtendedDocumentTemplate);
	const icomp::IComponentStaticInfo& infoSettingsSerializer = QtPck::SettingsSerializer::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("SettingsSerializer", &infoSettingsSerializer);
}


// Embedded class CQtViewPck

CCompositor::CQtViewPck::CQtViewPck()
{
	const icomp::IComponentStaticInfo& infoSceneProvider = QtViewPck::SceneProvider::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("SceneProvider", &infoSceneProvider);
}


// Embedded class CLocalEnvironmentManager

CCompositor::CLocalEnvironmentManager::CLocalEnvironmentManager()
{
	// register real components
	RegisterEmbeddedComponentInfo("BasePck", &m_subBasePck);
	RegisterEmbeddedComponentInfo("CmpstrPck", &m_subCmpstrPck);
	RegisterEmbeddedComponentInfo("QtGuiPck", &m_subQtGuiPck);
	RegisterEmbeddedComponentInfo("QtPck", &m_subQtPck);
	RegisterEmbeddedComponentInfo("QtViewPck", &m_subQtViewPck);

	// create map for all known registries
	m_registriesMap[icomp::CComponentAddress("AcfGuiVoce", "Log")].SetPtr(new CAcfGuiVocePck::CLogRegistry());
	m_registriesMap[icomp::CComponentAddress("AcfGuiVoce", "LogDock")].SetPtr(new CAcfGuiVocePck::CLogDockRegistry());
	m_registriesMap[icomp::CComponentAddress("AcfGuiVoce", "MultiDocApp")].SetPtr(new CAcfGuiVocePck::CMultiDocAppRegistry());
	m_registriesMap[icomp::CComponentAddress("AcfGuiVoce", "SettingsPersistence")].SetPtr(new CAcfGuiVocePck::CSettingsPersistenceRegistry());
	m_registriesMap[icomp::CComponentAddress("AcfSlnVoce", "VersionInfo")].SetPtr(new CAcfSlnVocePck::CVersionInfoRegistry());
	m_registriesMap[icomp::CComponentAddress("AcfVoce", "VersionInfo")].SetPtr(new CAcfVocePck::CVersionInfoRegistry());
	m_registriesMap[icomp::CComponentAddress("CmpstrVoce", "AttributeEditorDock")].SetPtr(new CCmpstrVocePck::CAttributeEditorDockRegistry());
	m_registriesMap[icomp::CComponentAddress("CmpstrVoce", "ClassHelpDock")].SetPtr(new CCmpstrVocePck::CClassHelpDockRegistry());
	m_registriesMap[icomp::CComponentAddress("CmpstrVoce", "CompositorApplication")].SetPtr(new CCmpstrVocePck::CCompositorApplicationRegistry());
	m_registriesMap[icomp::CComponentAddress("CmpstrVoce", "CompositorDockWidgets")].SetPtr(new CCmpstrVocePck::CCompositorDockWidgetsRegistry());
	m_registriesMap[icomp::CComponentAddress("CmpstrVoce", "CompositorSettings")].SetPtr(new CCmpstrVocePck::CCompositorSettingsRegistry());
	m_registriesMap[icomp::CComponentAddress("CmpstrVoce", "CompositorSettingsDialog")].SetPtr(new CCmpstrVocePck::CCompositorSettingsDialogRegistry());
	m_registriesMap[icomp::CComponentAddress("CmpstrVoce", "CompositorTemplate")].SetPtr(new CCmpstrVocePck::CCompositorTemplateRegistry());
	m_registriesMap[icomp::CComponentAddress("CmpstrVoce", "PackageOverviewDock")].SetPtr(new CCmpstrVocePck::CPackageOverviewDockRegistry());
	m_registriesMap[icomp::CComponentAddress("CmpstrVoce", "VisualRegistryView")].SetPtr(new CCmpstrVocePck::CVisualRegistryViewRegistry());

	// register composed packages
	m_packageAcfGuiVoceInfoPtr.SetPtr(new CAcfGuiVocePck(this));
	if (m_packageAcfGuiVoceInfoPtr.IsValid()){
		RegisterEmbeddedComponentInfo("AcfGuiVoce", m_packageAcfGuiVoceInfoPtr.GetPtr());
	}

	m_packageAcfSlnVoceInfoPtr.SetPtr(new CAcfSlnVocePck(this));
	if (m_packageAcfSlnVoceInfoPtr.IsValid()){
		RegisterEmbeddedComponentInfo("AcfSlnVoce", m_packageAcfSlnVoceInfoPtr.GetPtr());
	}

	m_packageAcfVoceInfoPtr.SetPtr(new CAcfVocePck(this));
	if (m_packageAcfVoceInfoPtr.IsValid()){
		RegisterEmbeddedComponentInfo("AcfVoce", m_packageAcfVoceInfoPtr.GetPtr());
	}

	m_packageCmpstrVoceInfoPtr.SetPtr(new CCmpstrVocePck(this));
	if (m_packageCmpstrVoceInfoPtr.IsValid()){
		RegisterEmbeddedComponentInfo("CmpstrVoce", m_packageCmpstrVoceInfoPtr.GetPtr());
	}
}


// reimplemented (icomp::IRegistriesManager)

const icomp::IRegistry* CCompositor::CLocalEnvironmentManager::GetRegistry(const icomp::CComponentAddress& address, const icomp::IRegistry* contextRegistryPtr) const
{
	RegistriesMap::const_iterator findIter = m_registriesMap.find(address);
	if (findIter != m_registriesMap.end()){
		return findIter->second.GetPtr();
	}
	return BaseClass::GetRegistry(address, contextRegistryPtr);
}

