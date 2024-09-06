/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <icmm/CIlluminant.h>


// ACF includes
#include <istd/CChangeNotifier.h>


namespace icmm
{


CIlluminant::CIlluminant(
			StandardIlluminant illuminantType,
			const QString& illuminantName,
			const icmm::CVarColor& whitePoint)
	:m_illuminantType(illuminantType),
	m_illuminantName(illuminantName),
	m_whitePoint(whitePoint)
{
}


CIlluminant::CIlluminant(const CIlluminant & other)
	:m_whitePoint(other.m_whitePoint),
	m_illuminantName(other.m_illuminantName),
	m_illuminantType(other.m_illuminantType)
{
}


// reimplemented (IWhitePointProvider)

icmm::CVarColor icmm::CIlluminant::GetWhitePoint() const
{
	return m_whitePoint;
}


// reimplemented (IIluminant)

void CIlluminant::SetWhitePoint(const icmm::CVarColor& whitePoint)
{
	if (m_whitePoint != whitePoint){
		istd::CChangeNotifier changeNotifier(this);

		m_whitePoint = whitePoint;
	}
}


QString CIlluminant::GetIllumninantName() const
{
	return m_illuminantName;
}


void CIlluminant::SetIllumninantName(const QString& illuminantName)
{
	if (m_illuminantName != illuminantName){
		istd::CChangeNotifier changeNotifier(this);

		m_illuminantName = illuminantName;
	}
}


StandardIlluminant CIlluminant::GetIllumninantType() const
{
	return m_illuminantType;
}


void CIlluminant::SetIllumninantType(const StandardIlluminant& illuminantType)
{
	if (m_illuminantType != illuminantType){
		istd::CChangeNotifier changeNotifier(this);

		m_illuminantType = illuminantType;
	}
}

bool CIlluminant::IsEqual(const IChangeable& other) const
{
	const IIlluminant* objectPtr = dynamic_cast<const IIlluminant*>(&other);

	if (objectPtr == nullptr) {
		return false;
	}

	return m_illuminantType == objectPtr->GetIllumninantType() &&
		   m_illuminantName == objectPtr->GetIllumninantName() &&
		   m_whitePoint == objectPtr->GetWhitePoint();
}

} // namespace icmm


