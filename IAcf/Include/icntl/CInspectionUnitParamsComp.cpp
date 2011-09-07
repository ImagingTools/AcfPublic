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


#include "icntl/CInspectionUnitParamsComp.h"


namespace icntl
{


CInspectionUnitParamsComp::CInspectionUnitParamsComp()
:	m_triggerOffset(0),
	m_triggerAlpha(0)
{
}


// reimplemented (icntl::IInspectionUnitParams)

double CInspectionUnitParamsComp::GetTriggerOffset() const
{
	return m_triggerOffset;
}


void CInspectionUnitParamsComp::SetTriggerOffset(double offset)
{
	if (offset != m_triggerOffset){
		istd::CChangeNotifier notifier(this);

		m_triggerOffset = offset;
	}
}


double CInspectionUnitParamsComp::GetTriggerAlpha() const
{
	return m_triggerAlpha;
}


void CInspectionUnitParamsComp::SetTriggerAlpha(double value)
{
	if (value != m_triggerAlpha){
		istd::CChangeNotifier notifier(this);

		m_triggerAlpha = value;
	}
}


// reimplemented (iser::ISerializable)

bool CInspectionUnitParamsComp::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	retVal = retVal && SerializeName(archive);
	retVal = retVal && SerializeEnabled(archive);

	static iser::CArchiveTag triggerOffsetTag("TriggerOffset", "Offset of trigger in logical units");
	retVal = retVal && archive.BeginTag(triggerOffsetTag);
	retVal = retVal && archive.Process(m_triggerOffset);
	retVal = retVal && archive.EndTag(triggerOffsetTag);

	static iser::CArchiveTag triggerAlphaTag("TriggerAlpha", "Describe used light barrier edge");
	retVal = retVal && archive.BeginTag(triggerAlphaTag);
	retVal = retVal && archive.Process(m_triggerAlpha);
	retVal = retVal && archive.EndTag(triggerAlphaTag);

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CInspectionUnitParamsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	SetName(*m_nameAttrPtr);
	SetEnabled(*m_isEnabledAttrPtr);

	m_triggerOffset = *m_triggerOffsetAttrPtr;
	m_triggerAlpha = *m_triggerAlphaAttrPtr;
}


} // namespace icntl


