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


#ifndef icmm_CVarColor_included
#define icmm_CVarColor_included


// ACF includes
#include "iser/ISerializable.h"

#include "imath/IDoubleManip.h"
#include "imath/CVarVector.h"

#include "icmm/icmm.h"


namespace icmm
{


/**
	Generic color implementation with variable number of color components.

	The dimension of used colorspace can be set at the construction time of CVarColor object,
*/
class CVarColor: public imath::CVarVector, public iser::ISerializable
{
public:
	typedef imath::CVarVector BaseClass;

	/**
		Default constructor.
		It set number of elements to 0.
	*/
	CVarColor();

	/**
		Constructor with explicit initialization of number of elements.
	*/
	explicit CVarColor(int componentsCount, double value = 0);

	/**
		Copy constructor.
	*/
	CVarColor(const CVarColor& color);

	/**
		Template conversion constructor.
	*/
	template <int Size>
	CVarColor(const imath::TVector<Size>& vector)
	:	BaseClass(vector)
	{
	}

	/**
		Get color after components value rounding with specified precision.
		\param	manipulator	manipulator object used to round single components.
		\param	result		result object.
	*/
	void GetRounded(const imath::IDoubleManip& manipulator, CVarColor& result);

	/**
		Check if two values are equal after rounding.
		\param	color		second color to comparision.
		\param	manipulator	value manipulator used to round single components.
	*/
	bool IsRoundedEqual(const CVarColor& color, const imath::IDoubleManip& manipulator) const;

	/**
		Allows to compare two colors with tolerance.
	*/
	bool IsSimilar(const CVarColor& color, double tolerance = I_BIG_EPSILON) const;

	/**
		Check if this color value is normalized.
		Normalized values have all components in the range [0, 1].
	*/
	bool IsNormalized() const;

	/**
		Make this color to be normalized.
		Normalized values have all components in the range [0, 1].
	*/
	void Normalize();

	/**
		Get normalized color.
		Normalized values have all components in the range [0, 1].
	*/
	void GetNormalized(CVarColor& result) const;

	CVarColor operator+(const CVarColor& color) const;
	CVarColor operator-(const CVarColor& color) const;
	CVarColor operator*(const CVarColor& color) const;
	CVarColor operator/(const CVarColor& color) const;

	CVarColor operator*(double value) const;
	CVarColor operator/(double value) const;

	const CVarColor& operator=(const CVarColor& color);

	const CVarColor& operator+=(const CVarColor& color);
	const CVarColor& operator-=(const CVarColor& color);
	const CVarColor& operator*=(const CVarColor& color);
	const CVarColor& operator/=(const CVarColor& color);

	const CVarColor& operator*=(double value);
	const CVarColor& operator/=(double value);

	// reimplemented (iser::ISerializable)
	bool Serialize(iser::IArchive& archive);
};


// inline methods

inline bool CVarColor::IsSimilar(const CVarColor& color, double tolerance) const
{
	return GetDistance(color) <= tolerance;
}


inline bool CVarColor::IsNormalized() const
{
	int elementsCount = GetElementsCount();

	for (int i = 0; i < elementsCount; ++i){
		double component = GetElement(i);

		if ((component < 0) && (component > 1)){
			return false;
		}
	}

	return true;
}


inline CVarColor CVarColor::operator+(const CVarColor& color) const
{
	CVarColor retVal(*this);

	retVal += color;

	return retVal;
}


inline CVarColor CVarColor::operator-(const CVarColor& color) const
{
	CVarColor retVal(*this);

	retVal -= color;

	return retVal;
}


inline CVarColor CVarColor::operator*(const CVarColor& color) const
{
	CVarColor retVal(*this);

	retVal *= color;

	return retVal;
}


inline CVarColor CVarColor::operator/(const CVarColor& color) const
{
	CVarColor retVal(*this);

	retVal /= color;

	return retVal;
}


inline CVarColor CVarColor::operator*(double value) const
{
	int elementsCount = GetElementsCount();

	CVarColor retVal(elementsCount);

	for (int i = 0; i < elementsCount; ++i){
		retVal.SetElement(i, GetElement(i) * value);
	}

	return retVal;
}


inline CVarColor CVarColor::operator/(double value) const
{
	int elementsCount = GetElementsCount();

	CVarColor retVal(elementsCount);

	for (int i = 0; i < elementsCount; ++i){
		retVal.SetElement(i, GetElement(i) / value);
	}

	return retVal;
}


inline const CVarColor& CVarColor::operator*=(double value)
{
	BaseClass::operator*=(value);

	return *this;
}


inline const CVarColor& CVarColor::operator/=(double value)
{
	BaseClass::operator/=(value);

	return *this;
}


} // namespace icmm


#endif // !icmm_CVarColor_included


