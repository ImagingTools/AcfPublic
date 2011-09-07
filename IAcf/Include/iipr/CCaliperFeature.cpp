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


#include "iipr/CCaliperFeature.h"


#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iipr
{


CCaliperFeature::CCaliperFeature(
			double weight,
			double position,
			int edgeMode)
:	BaseClass(weight),
	m_position(position),
	m_edgeMode(edgeMode)
{
}


double CCaliperFeature::GetPosition() const
{
	return m_position;
}


int CCaliperFeature::GetEdgeMode() const
{
	return m_edgeMode;
}


// reimplemented (iser::ISerializable)

bool CCaliperFeature::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	retVal = retVal && BaseClass::Serialize(archive);

	static iser::CArchiveTag valueTag("Position", "Position on projection");
	retVal = retVal && archive.BeginTag(valueTag);
	retVal = retVal && archive.Process(m_position);
	retVal = retVal && archive.EndTag(valueTag);

	static iser::CArchiveTag edgeModeTag("EdgeMode", "Edge mode");
	retVal = retVal && archive.BeginTag(edgeModeTag);
	retVal = retVal && archive.Process(m_edgeMode);
	retVal = retVal && archive.EndTag(edgeModeTag);

	return retVal;
}


} // namespace iipr

