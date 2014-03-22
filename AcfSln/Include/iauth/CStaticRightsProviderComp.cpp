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


#include "iauth/CStaticRightsProviderComp.h"


namespace iauth
{


// reimeplemented (IRightsProvider)

bool CStaticRightsProviderComp::HasRight(
			const QByteArray& operationId,
			bool beQuiet) const
{
	if (m_rightsOn.find(operationId) != m_rightsOn.end()){
		return true;
	}

	if (m_rightsOff.find(operationId) != m_rightsOff.end()){
		return false;
	}

	if (m_slaveProviderIfPtr.IsValid()){
		return m_slaveProviderIfPtr->HasRight(operationId, beQuiet);
	}

	return m_defaultRightAttrPtr.IsValid() && *m_defaultRightAttrPtr;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CStaticRightsProviderComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	m_rightsOn.clear();
	m_rightsOff.clear();

	if (m_rightsOnAttrPtr.IsValid()){
		int attrCount = int(m_rightsOnAttrPtr.GetCount());
		for (int i = 0; i < attrCount; ++i){
			m_rightsOn.insert(m_rightsOnAttrPtr[i].toLocal8Bit());
		}
	}

	if (m_rightsOffAttrPtr.IsValid()){
		int attrCount = int(m_rightsOffAttrPtr.GetCount());
		for (int i = 0; i < attrCount; ++i){
			m_rightsOff.insert(m_rightsOffAttrPtr[i].toLocal8Bit());
		}
	}
}


} // namespace iauth


