/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <icmm/CVarColor.h>


// ACF includes
#include <istd/CChangeNotifier.h>

#include <iser/CArchiveTag.h>


namespace icmm
{


// static constants
static const iser::CArchiveTag s_colorComponentsTag("ColorComponents", "List of color components", iser::CArchiveTag::TT_MULTIPLE);
static const iser::CArchiveTag s_componentTag("Component", "Single component", iser::CArchiveTag::TT_LEAF, &s_colorComponentsTag);


CVarColor::CVarColor()
{
}


CVarColor::CVarColor(int componentsCount, double value)
:	BaseClass(componentsCount, value)
{
}


CVarColor::CVarColor(const CVarColor& color)
:	istd::IPolymorphic(),
	istd::IChangeable(),
	iser::ISerializable(),
	BaseClass(color)
{
}


void CVarColor::GetRounded(const imath::IDoubleManip& manipulator, CVarColor& result)
{
	int elementsCount = GetElementsCount();

	result.SetElementsCount(elementsCount);

	for (int i = 0; i < elementsCount; ++i){
		result[i] = manipulator.GetRounded(GetElement(i));
	}
}


bool CVarColor::IsRoundedEqual(const CVarColor& color, const imath::IDoubleManip& manipulator) const
{
	int elementsCount = GetElementsCount();
	for (int i = 0; i < elementsCount; ++i){
		if (!manipulator.IsEqual(GetElement(i), color[i])){
			return false;
		}
	}

	return true;
}


void CVarColor::Normalize()
{
	int elementsCount = GetElementsCount();
	for (int i = 0; i < elementsCount; ++i){
		if (GetElement(i) < 0.0){
			SetElement(i, 0.0);
		}

		if (GetElement(i) > 1.0){
			SetElement(i, 1.0);
		}
	}
}


void CVarColor::GetNormalized(CVarColor& result) const
{
	result = *this;

	result.Normalize();
}


const CVarColor& CVarColor::operator=(const CVarColor& color)
{
	int elementsCount = color.GetElementsCount();

	SetElementsCount(elementsCount);

	for (int i = 0; i < elementsCount; ++i){
		SetElement(i, color[i]);
	}

	return *this;
}


const CVarColor& CVarColor::operator+=(const CVarColor& color)
{
	Elements& elements = BaseClass::GetElementsRef();

	int elementsCount = qMin(GetElementsCount(), color.GetElementsCount());
	for (int i = 0; i < elementsCount; ++i){
		elements[i] += color.GetElement(i);
	}

	return *this;
}


const CVarColor& CVarColor::operator-=(const CVarColor& color)
{
	Elements& elements = BaseClass::GetElementsRef();

	int elementsCount = qMin(GetElementsCount(), color.GetElementsCount());
	for (int i = 0; i < elementsCount; ++i){
		elements[i] -= color.GetElement(i);
	}

	return *this;
}


const CVarColor& CVarColor::operator*=(const CVarColor& color)
{
	Elements& elements = BaseClass::GetElementsRef();

	int elementsCount = qMin(GetElementsCount(), color.GetElementsCount());
	for (int i = 0; i < elementsCount; ++i){
		elements[i] *= color.GetElement(i);
	}

	return *this;
}


const CVarColor& CVarColor::operator/=(const CVarColor& color)
{
	Elements& elements = BaseClass::GetElementsRef();

	int elementsCount = qMin(GetElementsCount(), color.GetElementsCount());
	for (int i = 0; i < elementsCount; ++i){
		elements[i] /= color.GetElement(i);
	}

	return *this;
}


// reimplemented (iser::ISerializable)

bool CVarColor::Serialize(iser::IArchive& archive)
{
	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this, &GetAllChanges());
	Q_UNUSED(notifier);

	bool retVal = true;

	int elementsCount = GetElementsCount();

	retVal = retVal && archive.BeginMultiTag(s_colorComponentsTag, s_componentTag, elementsCount);

	if (!retVal){
		return false;
	}

	if (!archive.IsStoring()){
		if (!SetElementsCount(elementsCount)){
			return false;
		}
	}

	for (int i = 0; i < elementsCount; ++i){
		retVal = retVal && archive.BeginTag(s_componentTag);
		retVal = retVal && archive.Process(operator[](i));
		retVal = retVal && archive.EndTag(s_componentTag);
	}

	retVal = retVal && archive.EndTag(s_colorComponentsTag);

	return retVal;
}


} // namespace icmm


