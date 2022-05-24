/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_CPerspCalibFinder_included
#define iipr_CPerspCalibFinder_included


// ACF includes
#include <istd/IPolymorphic.h>
#include <i2d/CVector2d.h>

// ACF-Solutions includes
#include <icalib/CPerspectiveCalibration2d.h>


namespace iipr
{


/**
	Helper class allowing to find perspective calibration using list of nominal and found positions.
*/
class CPerspCalibFinder: public istd::IPolymorphic
{
public:
	/**
		It allows to find perspective calibration factors.
	*/
	virtual bool FindPerspCalib(
				const i2d::CVector2d* nominalPositionsPtr,
				const i2d::CVector2d* foundPositionsPtr,
				int positionsCount,
				icalib::CPerspectiveCalibration2d& result,
				bool allowPerspective = true,
				bool allowRotation = true,
				bool allowScale = true,
				bool allowAnisotropic = true,
				bool allowTranslation = true) const;
	/**
		It allows to find perspective calibration factors with lens correction factor.
	*/
	virtual bool FindPerspCalibWithCorrection(
				const i2d::CVector2d* nominalPositionsPtr,
				const i2d::CVector2d* foundPositionsPtr,
				int positionsCount,
				const i2d::CVector2d& opticalCenter,
				icalib::CPerspectiveCalibration2d& result,
				double& lensCorrFactor,
				bool allowPerspective = true,
				bool allowRotation = true,
				bool allowScale = true,
				bool allowAnisotropic = true,
				bool allowTranslation = true) const;
};


} // namespace iipr


#endif // !iipr_CPerspCalibFinder_included


