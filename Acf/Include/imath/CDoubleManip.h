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


#ifndef imath_CDoubleManip_included
#define imath_CDoubleManip_included


#include "imath/IDoubleManip.h"


namespace imath
{


/**
	Simple implementation of \c imath::IDoubleManip interface for double values without rounding.
*/
class CDoubleManip: virtual public IDoubleManip
{
public:
	CDoubleManip();

	/**
		Get point character.
	 */
	char GetPointChar() const;

	/**
		Set point character.
	 */
	void SetPointChar(char pointChar);

	// reimplemented (imath::IDoubleManip)
	virtual int GetPrecision() const;

	// reimplemented (imath::TIValueManip)
	virtual double GetRounded(const double& value) const;
	virtual bool IsEqual(const double& value1, const double& value2) const;
	virtual bool IsSmaller(const double& value1, const double& value2) const;
	virtual bool IsSmallerEqual(const double& value1, const double& value2) const;
	virtual double GetSmallerValue(const double& value) const;
	virtual double GetBiggerValue(const double& value) const;
	virtual QString GetString(const double& value) const;
	virtual bool GetParsed(const QString& text, double& result) const;

protected:
	enum{
		PRECISION = 6
	};

private:
	char m_pointChar;
};


// inline methods

inline char CDoubleManip::GetPointChar() const
{
	return m_pointChar;
}


inline void CDoubleManip::SetPointChar(char pointChar)
{
	m_pointChar = pointChar;
}


// reimplemented (imath::TIValueManip)

inline double CDoubleManip::GetRounded(const double& value) const
{
	return value;
}


inline bool CDoubleManip::IsEqual(const double& value1, const double& value2) const
{
	return value1 == value2;
}


inline bool CDoubleManip::IsSmaller(const double& value1, const double& value2) const
{
	return value1 < value2;
}


inline bool CDoubleManip::IsSmallerEqual(const double& value1, const double& value2) const
{
	return value1 <= value2;
}


inline double CDoubleManip::GetSmallerValue(const double& value) const
{
	return value - 0.001;
}


inline double CDoubleManip::GetBiggerValue(const double& value) const
{
	return value + 0.001;
}


} // namespace imath


#endif // !imath_CDoubleManip_included


