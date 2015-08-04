/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include "iipr/CCaliperFeature.h"


// ACF includes
#include "istd/CChangeNotifier.h"
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iipr
{


CCaliperFeature::CCaliperFeature(
			double weight,
			double position,
			int edgeMode)
	:m_position(position),
	m_weight(weight),
	m_edgeMode(edgeMode)
{
	imath::CVarVector values;
	values.SetElementsCount(2);

	values.SetElement(0, weight);
	values.SetElement(1, position);

	SetValues(values);
}


double CCaliperFeature::GetPosition() const
{
	return m_position;
}


double CCaliperFeature::GetWeight() const
{
	return m_weight;
}


int CCaliperFeature::GetEdgeMode() const
{
	return m_edgeMode;
}


// reimplemented (imeas::INumericValue)

bool CCaliperFeature::IsValueTypeSupported(ValueTypeId valueTypeId) const
{
	switch (valueTypeId){
		case VTI_AUTO:
		case VTI_ALPHA:
		case VTI_WEIGHT:
			return true;
		default:
			break;
	}

	return false;
}


imath::CVarVector CCaliperFeature::GetComponentValue(ValueTypeId valueTypeId) const
{
	imath::CVarVector retVal;

	switch (valueTypeId){
	case VTI_AUTO:
		return GetValues();

	case VTI_ALPHA:
		retVal.SetElementsCount(1);
		retVal.SetElement(0, m_position);
		break;

	case VTI_WEIGHT:
		retVal.SetElementsCount(1);
		retVal.SetElement(0, m_weight);
		break;

	default:
		break;
	}

	return retVal;
}


// reimplemented (iser::ISerializable)

bool CCaliperFeature::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag valueTag("Position", "Position on projection", iser::CArchiveTag::TT_LEAF);
	static iser::CArchiveTag edgeModeTag("EdgeMode", "Edge mode", iser::CArchiveTag::TT_LEAF);
	static iser::CArchiveTag weightModeTag("Weight", "Caliper weight", iser::CArchiveTag::TT_LEAF);

	bool retVal = true;

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);
	Q_UNUSED(notifier);

	retVal = retVal && BaseClass::Serialize(archive);

	retVal = retVal && archive.BeginTag(valueTag);
	retVal = retVal && archive.Process(m_position);
	retVal = retVal && archive.EndTag(valueTag);

	retVal = retVal && archive.BeginTag(edgeModeTag);
	retVal = retVal && archive.Process(m_edgeMode);
	retVal = retVal && archive.EndTag(edgeModeTag);

	retVal = retVal && archive.BeginTag(weightModeTag);
	retVal = retVal && archive.Process(m_weight);
	retVal = retVal && archive.EndTag(weightModeTag);

	return retVal;
}


} // namespace iipr


