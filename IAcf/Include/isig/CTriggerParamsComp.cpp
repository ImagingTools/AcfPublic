/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "isig/CTriggerParamsComp.h"


#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace isig
{


CTriggerParamsComp::CTriggerParamsComp()
:	m_triggerMode(TM_NONE)
{
}


// reimplemented (isig::ITriggerParams)

const ITriggerConstraints* CTriggerParamsComp::GetTriggerConstraints() const
{
	return m_triggerConstraintsCompPtr.GetPtr();
}


int CTriggerParamsComp::GetTriggerMode() const
{
	return m_triggerMode;
}


void CTriggerParamsComp::SetTriggerMode(int triggerMode)
{
	if (m_triggerMode!= triggerMode){
		istd::CChangeNotifier changePtr(this);

		m_triggerMode = triggerMode;
	}
}


// reimplemented (iser::ISerializable)

bool CTriggerParamsComp::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag bottomTag("TriggerMode", "Trigger mode");
	retVal = retVal && archive.BeginTag(bottomTag);
	retVal = retVal && archive.Process(m_triggerMode);
	retVal = retVal && archive.EndTag(bottomTag);

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CTriggerParamsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	m_triggerMode = *m_triggerModeAttrPtr;
}


} // namespace isig


