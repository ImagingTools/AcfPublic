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


#ifndef icmm_CLab_included
#define icmm_CLab_included


#include "iser/IArchive.h"

#include "icmm/TComposedColor.h"


namespace icmm
{


/**
	Primitive for representation of LAB color value.
	Please note, that normal components values are in range [0, 1].
*/
class CLab: public TComposedColor<3>
{
public:
	typedef TComposedColor<3> BaseClass;

	enum ComponentIndex
	{
		CI_L,
		CI_A,
		CI_B
	};

	CLab(double l = 0.0, double a = 0.0, double b = 0.0);
	CLab(const CLab& color);

	// access to component values
	double GetL() const;
	void SetL(double value);
	double GetA() const;
	void SetA(double value);
	double GetB() const;
	void SetB(double value);

	// operators
	CLab operator+(const CLab& color) const;
	CLab operator-(const CLab& color) const;
	CLab operator*(const CLab& color) const;
	CLab operator/(const CLab& color) const;

	CLab operator*(double value) const;
	CLab operator/(double value) const;

	const CLab& operator=(const CLab& color);

	const CLab& operator+=(const CLab& color);
	const CLab& operator-=(const CLab& color);
	const CLab& operator*=(const CLab& color);
	const CLab& operator/=(const CLab& color);

	const CLab& operator*=(double value);
	const CLab& operator/=(double value);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);
};


// inline methods

inline CLab::CLab(double l, double a, double b)
:	BaseClass()
{
	SetElement(CI_L, l);
	SetElement(CI_A, a);
	SetElement(CI_B, b);
}


inline CLab::CLab(const CLab& color)
:	istd::IPolymorphic(), istd::IChangeable(), iser::ISerializable(), BaseClass(color)
{
}


// access to components

inline double CLab::GetL() const
{
	return GetElement(CI_L);
}


inline void CLab::SetL(double value)
{
	SetElement(CI_L, value);
}


inline double CLab::GetA() const
{
	return GetElement(CI_A);
}


inline void CLab::SetA(double value)
{
	SetElement(CI_A, value);
}


inline double CLab::GetB() const
{
	return GetElement(CI_B);
}


inline void CLab::SetB(double value)
{
	SetElement(CI_B, value);
}


// operators

inline CLab CLab::operator+(const CLab& color) const
{
	CLab retVal = *this;

	retVal += color;

	return retVal;
}


inline CLab CLab::operator-(const CLab& color) const
{
	CLab retVal = *this;

	retVal -= color;

	return retVal;
}


inline CLab CLab::operator*(const CLab& color) const
{
	CLab retVal = *this;

	retVal *= color;

	return retVal;
}


inline CLab CLab::operator/(const CLab& color) const
{
	CLab retVal = *this;

	retVal /= color;

	return retVal;
}


inline CLab CLab::operator*(double value) const
{
	CLab retVal = *this;

	retVal *= value;

	return retVal;
}


inline CLab CLab::operator/(double value) const
{
	CLab retVal = *this;

	retVal /= value;

	return retVal;
}


inline const CLab& CLab::operator=(const CLab& color)
{
	BaseClass::operator=(color);

	return *this;
}


inline const CLab& CLab::operator+=(const CLab& color)
{
	BaseClass::operator+=(color);

	return *this;
}


inline const CLab& CLab::operator-=(const CLab& color)
{
	BaseClass::operator-=(color);

	return *this;
}


inline const CLab& CLab::operator*=(const CLab& color)
{
	BaseClass::operator*=(color);

	return *this;
}


inline const CLab& CLab::operator/=(const CLab& color)
{
	BaseClass::operator/=(color);

	return *this;
}


inline const CLab& CLab::operator*=(double value)
{
	BaseClass::operator*=(value);

	return *this;
}


inline const CLab& CLab::operator/=(double value)
{
	BaseClass::operator/=(value);

	return *this;
}


} // namespace icmm


#endif // !icmm_CLab_included


