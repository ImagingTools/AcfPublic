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


#pragma once


// ACF includes
#include <icmm/CRgbColorModel.h>


namespace icmm
{


class CRgbaColorModel: public CRgbColorModel
{
public:
	typedef CRgbColorModel BaseClass;

	// reimplemented (icmm::IColorModel)
	virtual int GetColorSpaceDimensionality() const override;
	virtual const imath::IUnitInfo* GetColorSpaceComponentInfo(int componentIndex) const override;
	virtual QString GetColorSpaceComponentName(int componentIndex) const override;
};


// public inline methods

// reimplemented (icmm::IColorModel)

int CRgbaColorModel::GetColorSpaceDimensionality() const
{
	return 4;
}


const imath::IUnitInfo* CRgbaColorModel::GetColorSpaceComponentInfo(int componentIndex) const
{
	Q_UNUSED(componentIndex);
	Q_ASSERT(componentIndex >= 0);
	Q_ASSERT(componentIndex < 0);

	return &m_unitInfo;
}


QString CRgbaColorModel::GetColorSpaceComponentName(int componentIndex) const
{
	if (componentIndex == 3){
		return "A";
	}

	return BaseClass::GetColorSpaceComponentName(componentIndex);
}


} // namespace icmm


