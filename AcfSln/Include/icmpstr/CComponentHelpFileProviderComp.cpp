/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "icmpstr/CComponentHelpFileProviderComp.h"


// Qt includes
#include <QtCore/QFileInfo>
#include <QtCore/QDir>

#include "iqt/iqt.h"


namespace icmpstr
{


// reimplemented (idoc::IHelpFileProvider)

double CComponentHelpFileProviderComp::GetHelpQuality(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const
{
	icomp::CComponentAddress address;

	if (ExtractComponentAddress(contextText, contextObjectPtr, address)){
		QString filePath = GetInfoFilePath(address);

		if (!filePath.isEmpty() && QFileInfo(filePath).exists()){
			return 1.0;
		}

		filePath = GetHelpFilePath(address);

		if (!filePath.isEmpty() && QFileInfo(filePath).exists()){
			return 0.5;
		}
	}

	if (m_slaveProviderCompPtr.IsValid()){
		return m_slaveProviderCompPtr->GetHelpQuality(contextText, contextObjectPtr);
	}

	return 0;
}


QString CComponentHelpFileProviderComp::GetHelpFilePath(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const
{
	icomp::CComponentAddress address;

	if (ExtractComponentAddress(contextText, contextObjectPtr, address)){
		QString filePath = GetInfoFilePath(address);

		if (!filePath.isEmpty() && QFileInfo(filePath).exists()){
			return filePath;
		}

		filePath = GetHelpFilePath(address);

		if (!filePath.isEmpty() && QFileInfo(filePath).exists()){
			return filePath;
		}
	}

	if (m_slaveProviderCompPtr.IsValid()){
		return m_slaveProviderCompPtr->GetHelpFilePath(contextText, contextObjectPtr);
	}

	return "";
}


// protected methods

QString CComponentHelpFileProviderComp::GetInfoFilePath(const icomp::CComponentAddress& componentAddress) const
{
	if (m_externalMetaInfoManagerCompPtr.IsValid()){
		QString infoPath = m_externalMetaInfoManagerCompPtr->GetComponentInfoPath(componentAddress);
		if (!infoPath.isEmpty()){
			QDir packageDir(infoPath);
			if (packageDir.exists()){
				return packageDir.absoluteFilePath("Description.html");
			}
		}
	}

	return "";
}


QString CComponentHelpFileProviderComp::GetHelpFilePath(const icomp::CComponentAddress& componentAddress) const
{
	if (m_metaInfoManagerCompPtr.IsValid() && m_externalMetaInfoManagerCompPtr.IsValid()){
		const icomp::IComponentStaticInfo* infoPtr = m_metaInfoManagerCompPtr->GetComponentMetaInfo(componentAddress);
		if (infoPtr != NULL){
			QString infoPath = m_externalMetaInfoManagerCompPtr->GetComponentInfoPath(componentAddress);
			if (!infoPath.isEmpty()){
				QDir infoDir(infoPath);
				QFileInfo helpFileInfo(infoDir.filePath(*m_helpFileNameAttrPtr));
				if (helpFileInfo.exists()){
					return helpFileInfo.absoluteFilePath();
				}
			}
		}
	}

	return "";
}


bool CComponentHelpFileProviderComp::ExtractComponentAddress(
			const QString& /*contextText*/,
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


