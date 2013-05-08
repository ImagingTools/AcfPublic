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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "imath/CFixedPointManip.h"


// Qt includes
#include <QtCore/QVector>
#include <QtCore/qmath.h>


namespace imath
{


CFixedPointManip::CFixedPointManip(int precision, RoundingType roundingType)
:	m_roundingType(roundingType)
{
	SetPrecision(precision);
}


void CFixedPointManip::SetPrecision(int precision)
{
	m_precision = precision;
	m_scaleToIntFactor = qPow(10.0, m_precision);
}


void CFixedPointManip::SetRoundingType(RoundingType roundingType)
{
	m_roundingType = roundingType;
}


// reimplemented (imath::IDoubleManip)

int CFixedPointManip::GetPrecision() const
{
	return m_precision;
}


// reimplemented (imath::TIValueManip)

QString CFixedPointManip::GetString(const double& value) const
{
	return GetString(value, m_precision);
}


bool CFixedPointManip::GetParsed(const QString& text, double& result) const
{
	bool retVal = BaseClass::GetParsed(text, result);

	if (retVal){
		result = GetRounded(result);
	}

	return retVal;
}


// protected methods

QString CFixedPointManip::GetString(const double& value, int /*precision*/) const
{
	typedef QVector<char> CharacterList;
	CharacterList rotatedString;

	qint32 intValue = GetInternalValue(value);
	quint32 intAbsValue = (intValue > 0)? quint32(intValue): quint32(-intValue);

	if (m_precision > 0){
		for (int i = 0; i < m_precision; ++i){
			rotatedString.push_back('0' + char(intAbsValue % 10));
			intAbsValue /= 10;
		}
		rotatedString.push_back(GetPointChar());
	}
	else{
		for (int i = 0; i < -m_precision; ++i){
			rotatedString.push_back('0');
		}
	}

	do{
		rotatedString.push_back('0' + char(intAbsValue % 10));
		intAbsValue /= 10;
	} while (intAbsValue != 0);

	if (intValue < 0){
		rotatedString.push_back('-');
	}

	int stringLength = int(rotatedString.size());

	QString retVal(int(rotatedString.size()), ' ');

	for (int i = 0; i < stringLength; ++i){
		retVal[i] = rotatedString[stringLength - i - 1];
	}

	return retVal;
}


// static attributes

CFixedPointManip::RoundingFuntionPtr CFixedPointManip::m_roundingFuntionsPtr[RT_LAST + 1] = {
			qRound,
			qFloor,
			qCeil};


} // namespace imath


