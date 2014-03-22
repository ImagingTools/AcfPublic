/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "ibase/CApplicationInfoComp.h"


namespace ibase
{


// public methods

// reimplemented (ibase::IApplicationInfo)

QString CApplicationInfoComp::GetApplicationAttribute(int attributeId, bool allowTranslation) const
{
	switch (attributeId){
	case AA_COMPANY_NAME:
		if (m_companyNameAttrPtr.IsValid()){
			return allowTranslation? *m_companyNameAttrPtr: m_companyNameAttrPtr.GetOriginalValue();
		}
		break;

	case AA_PRODUCT_NAME:
		if (m_productNameAttrPtr.IsValid()){
			return allowTranslation? *m_productNameAttrPtr: m_productNameAttrPtr.GetOriginalValue();
		}
		break;

	case AA_APPLICATION_NAME:
		if (m_applicationNameAttrPtr.IsValid()){
			return allowTranslation? *m_applicationNameAttrPtr: m_applicationNameAttrPtr.GetOriginalValue();
		}
		break;

	case AA_APPLICATION_SUBNAME:
		if (m_applicationSubnameAttrPtr.IsValid()){
			return allowTranslation? *m_applicationSubnameAttrPtr: m_applicationSubnameAttrPtr.GetOriginalValue();
		}
		break;

	case AA_APPLICATION_TYPE:
		if (m_applicationTypeAttrPtr.IsValid()){
			return allowTranslation? *m_applicationTypeAttrPtr: m_applicationTypeAttrPtr.GetOriginalValue();
		}
		break;

	case AA_APPLICATION_PATH:
		return QString(".");
		break;

	case AA_LEGAL_COPYRIGHT:
		if (m_legalCopyrightAttrPtr.IsValid()){
			return allowTranslation? *m_legalCopyrightAttrPtr: m_legalCopyrightAttrPtr.GetOriginalValue();
		}
		break;

	case AA_MAIN_VERSION:
		if (m_mainVersionIdAttrPtr.IsValid() && m_versionInfoCompPtr.IsValid()){
			quint32 versionNumber;
			if (m_versionInfoCompPtr->GetVersionNumber(*m_mainVersionIdAttrPtr, versionNumber)){
				return m_versionInfoCompPtr->GetEncodedVersionName(*m_mainVersionIdAttrPtr, versionNumber);
			}
		}
		break;

	default:
		break;
	}

	return "";
}


int CApplicationInfoComp::GetMainVersionId() const
{
	int retVal = -1;

	if (m_mainVersionIdAttrPtr.IsValid()){
		retVal = *m_mainVersionIdAttrPtr;
	}

	return retVal;
}


const iser::IVersionInfo& CApplicationInfoComp::GetVersionInfo() const
{
	if (m_versionInfoCompPtr.IsValid()){
		return *m_versionInfoCompPtr;
	}

	return *this;	// empty version info
}


// public methods

// reimplemented (iser::IVersionInfo)

bool CApplicationInfoComp::GetVersionNumber(int /*versionId*/, quint32& result) const
{
	result = 0xffffffff;

	return false;
}


QString CApplicationInfoComp::GetVersionIdDescription(int /*versionId*/) const
{
	return "";
}


iser::IVersionInfo::VersionIds CApplicationInfoComp::GetVersionIds() const
{
	return iser::IVersionInfo::VersionIds();
}


QString CApplicationInfoComp::GetEncodedVersionName(int /*versionId*/, quint32 /*versionNumber*/) const
{
	return "";
}


} // namespace ibase


