/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CSettingsSerializerComp.h"


// ACF includes
#include "iqt/CSettingsReadArchive.h"
#include "iqt/CSettingsWriteArchive.h"


namespace iqt
{


// reimplemented (iser::IFileLoader)

bool CSettingsSerializerComp::IsOperationSupported(
			const istd::IChangeable* dataObjectPtr,
			const QString* /*filePathPtr*/,
			int flags,
			bool beQuiet) const
{
	if ((dataObjectPtr != NULL) && (dynamic_cast<const iser::ISerializable*>(dataObjectPtr) == NULL)){
		if (!beQuiet){
			SendInfoMessage(MI_BAD_OBJECT_TYPE, "Object is not serializable");
		}

		return false;
	}

	if ((flags & (QF_LOAD | QF_SAVE)) == 0){
		return false;
	}

	return ((flags & QF_ANONYMOUS) != 0);
}


int CSettingsSerializerComp::LoadFromFile(istd::IChangeable& data, const QString& /*filePath*/) const
{
	if (IsOperationSupported(&data, NULL, QF_LOAD | QF_ANONYMOUS, false)){
		iser::ISerializable* serializeblePtr = dynamic_cast<iser::ISerializable*>(&data);
		if (m_applicationInfoCompPtr.IsValid() && (serializeblePtr != NULL)){ 
			QString applicationName = m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_NAME);
			QString companyName = m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_COMPANY_NAME);

			QSettings::Scope scope = m_scopeAttrPtr.IsValid() ? QSettings::Scope(*m_scopeAttrPtr) : QSettings::UserScope; 

			CSettingsReadArchive archive(companyName, applicationName, *m_rootKeyAttrPtr, scope);

			if (serializeblePtr->Serialize(archive)){
				return StateOk;
			}
			else{
				SendInfoMessage(MI_CANNOT_LOAD, "Cannot serialize object from file");
			}
		}
		else{
			SendInfoMessage(MI_CANNOT_LOAD, "No application info found, it is needed to save to settings");
		}
	}

	return StateFailed;
}


int CSettingsSerializerComp::SaveToFile(const istd::IChangeable& data, const QString& /*filePath*/) const
{
	if (IsOperationSupported(&data, NULL, QF_SAVE | QF_ANONYMOUS, false)){
		iser::ISerializable* serializeblePtr = dynamic_cast<iser::ISerializable*>(const_cast<istd::IChangeable*>(&data));
		if (m_applicationInfoCompPtr.IsValid() && (serializeblePtr != NULL)){ 
			QString companyName = m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_COMPANY_NAME);
			QString applicationName = m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_NAME);

			QSettings::Scope scope = m_scopeAttrPtr.IsValid() ? QSettings::Scope(*m_scopeAttrPtr) : QSettings::UserScope; 

			CSettingsWriteArchive archive(
						companyName,
						applicationName,
						*m_rootKeyAttrPtr,
						scope,
						&m_applicationInfoCompPtr->GetVersionInfo());
		
			if (serializeblePtr->Serialize(archive)){
				return StateOk;
			}
			else{
				SendInfoMessage(MI_CANNOT_SAVE, "Cannot serialize object to file");
			}
		}
		else{
			SendInfoMessage(MI_CANNOT_LOAD, "No application info found, it is needed to save to settings");
		}
	}

	return StateFailed;
}


// reimplemented (iser::IFileTypeInfo)

bool CSettingsSerializerComp::GetFileExtensions(QStringList& /*result*/, int /*flags*/, bool /*doAppend*/) const
{
	return false;
}


QString CSettingsSerializerComp::GetTypeDescription(const QString* /*extensionPtr*/) const
{
	return "";
}


} // namespace iqt


