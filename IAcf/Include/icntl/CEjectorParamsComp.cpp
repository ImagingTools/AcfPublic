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


#include "icntl/CEjectorParamsComp.h"


namespace icntl
{


CEjectorParamsComp::CEjectorParamsComp()
:	m_ejectorPosition(1000),
	m_ejectionDistance(50)
{
}


// reimplemented (icntl::IEjectorParams)

double CEjectorParamsComp::GetEjectorPosition() const
{
	return m_ejectorPosition;
}


void CEjectorParamsComp::SetEjectorPosition(double position)
{
	if (position != m_ejectorPosition){
		istd::CChangeNotifier notifier(this);

		m_ejectorPosition = position;
	}
}


double CEjectorParamsComp::GetEjectionDistance() const
{
	return m_ejectionDistance;
}


void CEjectorParamsComp::SetEjectionDistance(double distance)
{
	if (distance != m_ejectionDistance){
		istd::CChangeNotifier notifier(this);

		m_ejectionDistance = distance;
	}
}


// reimplemented (iser::ISerializable)

bool CEjectorParamsComp::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	retVal = retVal && SerializeName(archive);
	retVal = retVal && SerializeEnabled(archive);

	static iser::CArchiveTag ejectorPositionTag("EjectorPosition", "Position of ejector in logical units");
	retVal = retVal && archive.BeginTag(ejectorPositionTag);
	retVal = retVal && archive.Process(m_ejectorPosition);
	retVal = retVal && archive.EndTag(ejectorPositionTag);

	static iser::CArchiveTag ejectionDistanceTag("EjectionDistance", "Distance ejector is on in logical units");
	retVal = retVal && archive.BeginTag(ejectionDistanceTag);
	retVal = retVal && archive.Process(m_ejectionDistance);
	retVal = retVal && archive.EndTag(ejectionDistanceTag);

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CEjectorParamsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	SetName(*m_nameAttrPtr);
	SetEnabled(*m_isEnabledAttrPtr);

	m_ejectorPosition = *m_ejectorPositionAttrPtr;
	m_ejectionDistance = *m_ejectionDistanceAttrPtr;
}


} // namespace icntl


