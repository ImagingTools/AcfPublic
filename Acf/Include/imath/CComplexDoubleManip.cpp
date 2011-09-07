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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "imath/CComplexDoubleManip.h"


namespace imath
{


// public methods

CComplexDoubleManip::CComplexDoubleManip(
			int precision,
			RoundingType roundingType,
			double scaleFactor,
			double offset,
			const istd::CRange& range)
:	BaseClass(precision, roundingType),
	m_scaleFactor(scaleFactor),
	m_offset(offset),
	m_range(range)
{
}


// reimplemented (imath::TIValueManip)

std::string CComplexDoubleManip::GetString(const double& value) const
{
	return BaseClass::GetString(GetRounded(value) * m_scaleFactor + m_offset, m_scaledPrecision);
}


bool CComplexDoubleManip::GetParsed(const std::string& text, double& result) const
{
	bool retVal = CDoubleManip::GetParsed(text, result);

	if (retVal){
		result = GetRounded(result / m_scaleFactor - m_offset);
	}

	return retVal;
}


// protected methods

// reimplemented (imath::TIValueManip)

I_SDWORD CComplexDoubleManip::GetInternalValue(double value) const
{
	value = m_range.GetNearestInside(value);

	return BaseClass::GetInternalValue(value);
}


} // namespace imath


