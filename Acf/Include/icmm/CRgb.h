/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef icmm_CRgb_included
#define icmm_CRgb_included


#include "iser/IArchive.h"

#include "icmm/TComposedColor.h"


namespace icmm
{


/**
	Primitive for representation of RGB color value.
	Please note, that normal components values are in range [0, 1].
*/
class CRgb: public TComposedColor<3>
{
public:
	typedef TComposedColor<3> BaseClass;

	enum ComponentIndex
	{
		CI_RED,
		CI_GREEN,
		CI_BLUE,
		CI_LAST = CI_BLUE
	};

	CRgb(double r = 0.0, double g = 0.0, double b = 0.0);
	CRgb(const CRgb& color);

	// access to component values
	double GetRed() const;
	void SetRed(double value);
	double GetGreen() const;
	void SetGreen(double value);
	double GetBlue() const;
	void SetBlue(double value);

	bool Serialize(iser::IArchive& archive);

	// operators
	CRgb operator+(const CRgb& color) const;
	CRgb operator-(const CRgb& color) const;
	CRgb operator*(const CRgb& color) const;
	CRgb operator/(const CRgb& color) const;

	CRgb operator*(double value) const;
	CRgb operator/(double value) const;

	const CRgb& operator=(const CRgb& color);

	const CRgb& operator+=(const CRgb& color);
	const CRgb& operator-=(const CRgb& color);
	const CRgb& operator*=(const CRgb& color);
	const CRgb& operator/=(const CRgb& color);

	const CRgb& operator*=(double value);
	const CRgb& operator/=(double value);
};


// inline methods

inline CRgb::CRgb(double r, double g, double b)
{
	SetElement(CI_RED, r);
	SetElement(CI_GREEN, g);
	SetElement(CI_BLUE, b);
}


inline CRgb::CRgb(const CRgb& color)
:	istd::IPolymorphic(),
	istd::IChangeable(),
	iser::ISerializable(),
	BaseClass(color)
{
}


// access to components

inline double CRgb::GetRed() const
{
	return GetElement(CI_RED);
}


inline void CRgb::SetRed(double value)
{
	SetElement(CI_RED, value);
}


inline double CRgb::GetGreen() const
{
	return GetElement(CI_GREEN);
}


inline void CRgb::SetGreen(double value)
{
	SetElement(CI_GREEN, value);
}


inline double CRgb::GetBlue() const
{
	return GetElement(CI_BLUE);
}


inline void CRgb::SetBlue(double value)
{
	SetElement(CI_BLUE, value);
}


// operators

inline const CRgb& CRgb::operator=(const CRgb& color)
{
	BaseClass::operator=(color);

	return *this;
}


inline const CRgb& CRgb::operator+=(const CRgb& color)
{
	BaseClass::operator+=(color);

	return *this;
}


inline const CRgb& CRgb::operator-=(const CRgb& color)
{
	BaseClass::operator-=(color);

	return *this;
}


inline const CRgb& CRgb::operator*=(const CRgb& color)
{
	BaseClass::operator*=(color);

	return *this;
}


inline const CRgb& CRgb::operator/=(const CRgb& color)
{
	BaseClass::operator/=(color);

	return *this;
}


inline const CRgb& CRgb::operator*=(double value)
{
	BaseClass::operator*=(value);

	return *this;
}


inline const CRgb& CRgb::operator/=(double value)
{
	BaseClass::operator/=(value);

	return *this;
}


} // namespace icmm


#endif // !icmm_CRgb_included


