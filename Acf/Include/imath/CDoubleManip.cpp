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


#include "imath/CDoubleManip.h"


// STL includes
#include <cmath>
#include <sstream>


namespace imath{


CDoubleManip::CDoubleManip()
:	m_pointChar('.')
{
}


// reimplemented (imath::IDoubleManip)

int CDoubleManip::GetPrecision() const
{
	return 15;	// approximated precision of type double with the leading digit before the point
}


// reimplemented (imath::TIValueManip)

std::string CDoubleManip::GetString(const double& value) const
{
	std::ostringstream stream;

	stream << value;

	return stream.str();
}


bool CDoubleManip::GetParsed(const std::string& text, double& result) const
{
	double sign = 0.0;
	double divider = 0.0;
	I_SDWORD intValueResult = 0;

	int stringLength = int(text.size());
	for (int i = 0; i < stringLength; ++i){
		char c = text[i];
		if (::isdigit(c)){
			divider *= 10;

			intValueResult = intValueResult * 10 + c - '0';
		}
		else if (c == m_pointChar){
			if (divider != 0){
				return false;
			}

			divider = 1.0;
		}
		else if (c == '-'){
			if (sign != 0.0){
				return false;	// two minus or plus signs are not allowed
			}

			sign = -1.0;
		}
		else if (c == '+'){
			if (sign != 0.0){
				return false;	// two minus or plus signs are not allowed
			}

			sign = 1.0;
		}
	}

	if (sign == 0.0){
		sign = 1.0;
	}

	if (divider == 0.0){
		divider = 1.0;
	}

	result = intValueResult * sign / divider;

	return true;
}


} // namespace imath


