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


#ifndef imath_CFixedPointManip_included
#define imath_CFixedPointManip_included


#include "imath/CDoubleManip.h"


namespace imath
{


/**
	Implementation of \c imath::IDoubleManip interface for fixed point arithmentic.
*/
class CFixedPointManip: public CDoubleManip
{
public:
	typedef CDoubleManip BaseClass;

	enum RoundingType
	{
		/**
			Normal mathematical rounding to the nearest value.
		*/
		RT_NORMAL,
		/**
			Rounding down.
		*/
		RT_FLOOR,
		/**
			Rounding up.
		*/
		RT_CEIL,
		RT_LAST = RT_CEIL + 1
	};

	CFixedPointManip(int precision = 1, RoundingType roundingType = RT_NORMAL);

	/**
		Set fixed point precision.
	 */
	void SetPrecision(int precision);

	/**	Get type of rounding.
	 */
	RoundingType GetRoundingType() const;

	/**	Set type of rounding.
	 */
	void SetRoundingType(RoundingType roundingType);

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
	typedef int (*RoundingFuntionPtr)(qreal value);

	virtual qint32 GetInternalValue(double value) const;
	virtual double GetNormalValue(qint32 intValue) const;

	QString GetString(const double& value, int precision) const;

private:
	int m_precision;
	RoundingType m_roundingType;

	static RoundingFuntionPtr m_roundingFuntionsPtr[RT_LAST + 1];

	double m_scaleToIntFactor;
};


// inline methods

inline CFixedPointManip::RoundingType CFixedPointManip::GetRoundingType() const
{
	return m_roundingType;
}


// reimplemented (imath::TIValueManip)

inline double CFixedPointManip::GetRounded(const double& value) const
{
	return GetNormalValue(GetInternalValue(value));
}


inline bool CFixedPointManip::IsEqual(const double& value1, const double& value2) const
{
	return GetInternalValue(value1) == GetInternalValue(value2);
}


inline bool CFixedPointManip::IsSmaller(const double& value1, const double& value2) const
{
	return GetInternalValue(value1) < GetInternalValue(value2);
}


inline bool CFixedPointManip::IsSmallerEqual(const double& value1, const double& value2) const
{
	return GetInternalValue(value1) <= GetInternalValue(value2);
}


inline double CFixedPointManip::GetSmallerValue(const double& value) const
{
	return GetNormalValue(GetInternalValue(value) - 1);
}


inline double CFixedPointManip::GetBiggerValue(const double& value) const
{
	return GetNormalValue(GetInternalValue(value) + 1);
}


// protected methods

inline qint32 CFixedPointManip::GetInternalValue(double value) const
{
	RoundingFuntionPtr function = m_roundingFuntionsPtr[m_roundingType];

	return qint32(function(value * m_scaleToIntFactor));
}


inline double CFixedPointManip::GetNormalValue(qint32 intValue) const
{
	return intValue / m_scaleToIntFactor;
}


} // namespace imath


#endif // !imath_CFixedPointManip_included


