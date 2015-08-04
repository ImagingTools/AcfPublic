/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#ifndef iipr_CImageInterpolationParamsComp_included
#define iipr_CImageInterpolationParamsComp_included


// ACF includes
#include "icomp/CComponentBase.h"

// ACF-Solutions includes
#include "iipr/CImageInterpolationParams.h"


namespace iipr
{


class CImageInterpolationParamsComp: public icomp::CComponentBase, public CImageInterpolationParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CImageInterpolationParamsComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(IImageInterpolationParams);
		I_ASSIGN(m_interpolationModeAttrPtr, "InterpolationMode", "Interpolation mode:\n0 - no interpolation\n1 - bilinear\n2 - bicubic", true, 0);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(int, m_interpolationModeAttrPtr);
};


} // namespace iipr


#endif // !iipr_CImageInterpolationParamsComp_included


