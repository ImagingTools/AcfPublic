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


#include "ibase/CVersionInfoComp.h"


namespace ibase
{


// public methods

// reimplemented (iser::IVersionInfo)

bool CVersionInfoComp::GetVersionNumber(int versionId, quint32& result) const
{
	if (m_versionIdAttrPtr.IsValid() && (versionId == *m_versionIdAttrPtr)){
		result = *m_versionNumberAttrPtr;

		return true;
	}

	return BaseClass::GetVersionNumber(versionId, result);
}


QString CVersionInfoComp::GetVersionIdDescription(int versionId) const
{
	if (m_versionIdAttrPtr.IsValid() && (versionId == *m_versionIdAttrPtr)){
		return *m_versionIdDescriptionAttrPtr;
	}
	
	return BaseClass::GetVersionIdDescription(versionId);
}


iser::IVersionInfo::VersionIds CVersionInfoComp::GetVersionIds() const
{
	VersionIds retVal = BaseClass::GetVersionIds();

	if (m_versionIdAttrPtr.IsValid()){
		retVal.insert(*m_versionIdAttrPtr);
	}

	return retVal;
}


QString CVersionInfoComp::GetEncodedVersionName(int versionId, quint32 versionNumber) const
{
	QString retVal;

	if (m_versionIdAttrPtr.IsValid() && (versionId == *m_versionIdAttrPtr)){
		quint32 lastBellowNumber = 0;
		int knownVersionsCount = qMin(m_knownVersionsAttrPtr.GetCount(), m_knownVersionNamesAttrPtr.GetCount());
		for (int i = 0; i < knownVersionsCount; ++i){
			quint32 knownNumber = quint32(m_knownVersionsAttrPtr[i]);

			if ((knownNumber <= versionNumber) && (knownNumber >= lastBellowNumber)){
				lastBellowNumber = knownNumber;
				retVal = m_knownVersionNamesAttrPtr[i];
			}
		}

		if (m_isExtensionUsedAttrPtr.IsValid() && *m_isExtensionUsedAttrPtr){
			retVal += QString(".") + QString("%1").arg(int(versionNumber - lastBellowNumber));
		}

		return retVal;
	}

	return BaseClass::GetEncodedVersionName(versionId, versionNumber);
}


} // namespace ibase


