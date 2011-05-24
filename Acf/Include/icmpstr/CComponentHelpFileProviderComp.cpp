/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "icmpstr/CComponentHelpFileProviderComp.h"


// Qt includes
#include <QFileInfo>
#include <QDir>

#include "iqt/iqt.h"


namespace icmpstr
{


// reimplemented (idoc::IHelpFileProvider)

double CComponentHelpFileProviderComp::GetHelpQuality(const istd::CString& contextText, const istd::IPolymorphic* contextObjectPtr) const
{
	icomp::CComponentAddress address;

	if (ExtractComponentAddress(contextText, contextObjectPtr, address)){
		istd::CString filePath = GetInfoFilePath(address);

		if (!filePath.IsEmpty() && QFileInfo(iqt::GetQString(filePath)).exists()){
			return 1.0;
		}

		filePath = GetHelpFilePath(address);

		if (!filePath.IsEmpty() && QFileInfo(iqt::GetQString(filePath)).exists()){
			return 0.5;
		}
	}

	if (m_slaveProviderCompPtr.IsValid()){
		return m_slaveProviderCompPtr->GetHelpQuality(contextText, contextObjectPtr);
	}

	return 0;
}


istd::CString CComponentHelpFileProviderComp::GetHelpFilePath(const istd::CString& contextText, const istd::IPolymorphic* contextObjectPtr) const
{
	icomp::CComponentAddress address;

	if (ExtractComponentAddress(contextText, contextObjectPtr, address)){
		istd::CString filePath = GetInfoFilePath(address);

		if (!filePath.IsEmpty() && QFileInfo(iqt::GetQString(filePath)).exists()){
			return filePath;
		}

		filePath = GetHelpFilePath(address);

		if (!filePath.IsEmpty() && QFileInfo(iqt::GetQString(filePath)).exists()){
			return filePath;
		}
	}

	if (m_slaveProviderCompPtr.IsValid()){
		return m_slaveProviderCompPtr->GetHelpFilePath(contextText, contextObjectPtr);
	}

	return "";
}


// protected methods

istd::CString CComponentHelpFileProviderComp::GetInfoFilePath(const icomp::CComponentAddress& componentAddress) const
{
	if (m_externalMetaInfoManagerCompPtr.IsValid()){
		QString infoPath = iqt::GetQString(m_externalMetaInfoManagerCompPtr->GetComponentInfoPath(componentAddress));
		if (!infoPath.isEmpty()){
			QDir packageDir(infoPath);
			if (packageDir.exists()){
				return iqt::GetCString(packageDir.absoluteFilePath("Description.html"));
			}
		}
	}

	return "";
}


istd::CString CComponentHelpFileProviderComp::GetHelpFilePath(const icomp::CComponentAddress& componentAddress) const
{
	if (m_metaInfoManagerCompPtr.IsValid() && m_externalMetaInfoManagerCompPtr.IsValid()){
		const icomp::IComponentStaticInfo* infoPtr = m_metaInfoManagerCompPtr->GetComponentMetaInfo(componentAddress);
		if (infoPtr != NULL){
			istd::CString infoPath = m_externalMetaInfoManagerCompPtr->GetComponentInfoPath(componentAddress);
			if (!infoPath.IsEmpty()){
				QDir infoDir(iqt::GetQString(infoPath));
				QFileInfo helpFileInfo(infoDir.filePath(iqt::GetQString(*m_helpFileNameAttrPtr)));
				if (helpFileInfo.exists()){
					return iqt::GetCString(helpFileInfo.absoluteFilePath());
				}
			}
		}
	}

	return "";
}


bool CComponentHelpFileProviderComp::ExtractComponentAddress(
			const istd::CString& /*contextText*/,
			const istd::IPolymorphic* contextObjectPtr,
			icomp::CComponentAddress& result) const
{
	const icomp::CComponentAddress* addressPtr = dynamic_cast<const icomp::CComponentAddress*>(contextObjectPtr);
	if (addressPtr != NULL){
		result = *addressPtr;

		return true;
	}

	return false;
}


} // namespace icmpstr


