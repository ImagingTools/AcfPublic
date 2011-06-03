#include "CVersionInfo.h"


// ACF includes
#include "icomp/TAttribute.h"
#include "icomp/TMultiAttribute.h"
#include "icomp/CRegistryElement.h"
#include "icomp/CCompositePackageStaticInfo.h"

// ACF component includes
#include "BasePck/BasePck.h"



CVersionInfo::CVersionInfo()
{
	SetComponentContext(&s_mainComponentContext, NULL, false);
}


// static attributes
icomp::CRegistryElement CVersionInfo::s_mainElement;
CVersionInfo::CMainRegistry CVersionInfo::s_mainRegistry;
CVersionInfo::CLocalEnvironmentManager CVersionInfo::s_localEnvironmentManager;
icomp::CCompositeComponentContext CVersionInfo::s_mainComponentContext(&s_mainElement, &s_localEnvironmentManager, &s_mainRegistry, &s_localEnvironmentManager, NULL);


// Embedded class CMainRegistry

CVersionInfo::CMainRegistry::CMainRegistry()
{
	// element 'BaseInfo' of type AcfSlnVoce::VersionInfo
	icomp::IRegistry::ElementInfo* infoBaseInfoPtr = InsertElementInfo(
				"BaseInfo",
				icomp::CComponentAddress("AcfSlnVoce", "VersionInfo"),
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
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.1.0");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.1.1");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.1.2");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.1.3");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.2.0");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.3.0");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.3.1");
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.3.2");
		}

		// create and set attribute value for 'KnownVersions'
		icomp::IRegistryElement::AttributeInfo* attrInfoKnownVersionsPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("KnownVersions", "icomp::TMultiAttribute<int>");
		if (attrInfoKnownVersionsPtr != NULL){
			attrInfoKnownVersionsPtr->attributePtr.SetPtr(new icomp::TMultiAttribute<int>);
			I_ASSERT(attrInfoKnownVersionsPtr->attributePtr.IsValid());

			icomp::CMultiIntAttribute* nattrInfoKnownVersionsPtr = dynamic_cast<icomp::CMultiIntAttribute*>(attrInfoKnownVersionsPtr->attributePtr.GetPtr());
			I_ASSERT(nattrInfoKnownVersionsPtr != NULL);

			nattrInfoKnownVersionsPtr->Reset();
			nattrInfoKnownVersionsPtr->InsertValue(122);
			nattrInfoKnownVersionsPtr->InsertValue(152);
			nattrInfoKnownVersionsPtr->InsertValue(169);
			nattrInfoKnownVersionsPtr->InsertValue(200);
			nattrInfoKnownVersionsPtr->InsertValue(233);
			nattrInfoKnownVersionsPtr->InsertValue(299);
			nattrInfoKnownVersionsPtr->InsertValue(322);
			nattrInfoKnownVersionsPtr->InsertValue(348);
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
			attrVersionIdPtr->SetValue(10);
		}

		// create and set attribute value for 'VersionIdDesc'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionIdDescPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("VersionIdDesc", "icomp::TAttribute<istd::CString>");
		if (attrInfoVersionIdDescPtr != NULL){
			attrInfoVersionIdDescPtr->attributePtr.SetPtr(new icomp::TAttribute<istd::CString>);
			I_ASSERT(attrInfoVersionIdDescPtr->attributePtr.IsValid());

			icomp::CStringAttribute* attrVersionIdDescPtr = dynamic_cast<icomp::CStringAttribute*>(attrInfoVersionIdDescPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionIdDescPtr != NULL);
			attrVersionIdDescPtr->SetValue(L"IACF");
		}

		// create and set attribute value for 'VersionNumber'
		icomp::IRegistryElement::AttributeInfo* attrInfoVersionNumberPtr = infoBaseInfoPtr->elementPtr->InsertAttributeInfo("VersionNumber", "icomp::TAttribute<int>");
		if (attrInfoVersionNumberPtr != NULL){
			attrInfoVersionNumberPtr->attributePtr.SetPtr(new icomp::TAttribute<int>);
			I_ASSERT(attrInfoVersionNumberPtr->attributePtr.IsValid());

			icomp::CIntAttribute* attrVersionNumberPtr = dynamic_cast<icomp::CIntAttribute*>(attrInfoVersionNumberPtr->attributePtr.GetPtr());
			I_ASSERT(attrVersionNumberPtr != NULL);
			attrVersionNumberPtr->SetValue(350);
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


// Embedded class CAcfSlnVocePck

CVersionInfo::CAcfSlnVocePck::CAcfSlnVocePck(const icomp::IComponentEnvironmentManager* managerPtr)
:	icomp::CCompositePackageStaticInfo("AcfSlnVoce", managerPtr)

{
	RegisterEmbeddedComponent("VersionInfo");
}


// Embedded class CVersionInfoRegistry

CVersionInfo::CAcfSlnVocePck::CVersionInfoRegistry::CVersionInfoRegistry()
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
			nattrInfoKnownVersionNamesPtr->InsertValue(L"0.4.4");
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
			nattrInfoKnownVersionsPtr->InsertValue(341);
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
			attrVersionNumberPtr->SetValue(342);
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

CVersionInfo::CAcfVocePck::CAcfVocePck(const icomp::IComponentEnvironmentManager* managerPtr)
:	icomp::CCompositePackageStaticInfo("AcfVoce", managerPtr)

{
	RegisterEmbeddedComponent("VersionInfo");
}


// Embedded class CVersionInfoRegistry

CVersionInfo::CAcfVocePck::CVersionInfoRegistry::CVersionInfoRegistry()
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
			nattrInfoKnownVersionNamesPtr->InsertValue(L"1.4.0");
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
			nattrInfoKnownVersionsPtr->InsertValue(1779);
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
			attrVersionNumberPtr->SetValue(1781);
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


// Embedded class CBasePck

CVersionInfo::CBasePck::CBasePck()
{
	const icomp::IComponentStaticInfo& infoVersionInfo = BasePck::VersionInfo::InitStaticInfo(NULL);
	RegisterEmbeddedComponentInfo("VersionInfo", &infoVersionInfo);
}


// Embedded class CLocalEnvironmentManager

CVersionInfo::CLocalEnvironmentManager::CLocalEnvironmentManager()
{
	// register real components
	RegisterEmbeddedComponentInfo("BasePck", &m_subBasePck);

	// create map for all known registries
	m_registriesMap[icomp::CComponentAddress("AcfSlnVoce", "VersionInfo")].SetPtr(new CAcfSlnVocePck::CVersionInfoRegistry());
	m_registriesMap[icomp::CComponentAddress("AcfVoce", "VersionInfo")].SetPtr(new CAcfVocePck::CVersionInfoRegistry());

	// register composed packages
	m_packageAcfSlnVoceInfoPtr.SetPtr(new CAcfSlnVocePck(this));
	if (m_packageAcfSlnVoceInfoPtr.IsValid()){
		RegisterEmbeddedComponentInfo("AcfSlnVoce", m_packageAcfSlnVoceInfoPtr.GetPtr());
	}

	m_packageAcfVoceInfoPtr.SetPtr(new CAcfVocePck(this));
	if (m_packageAcfVoceInfoPtr.IsValid()){
		RegisterEmbeddedComponentInfo("AcfVoce", m_packageAcfVoceInfoPtr.GetPtr());
	}
}


// reimplemented (icomp::IRegistriesManager)

const icomp::IRegistry* CVersionInfo::CLocalEnvironmentManager::GetRegistry(const icomp::CComponentAddress& address, const icomp::IRegistry* contextRegistryPtr) const
{
	RegistriesMap::const_iterator findIter = m_registriesMap.find(address);
	if (findIter != m_registriesMap.end()){
		return findIter->second.GetPtr();
	}
	return BaseClass::GetRegistry(address, contextRegistryPtr);
}

