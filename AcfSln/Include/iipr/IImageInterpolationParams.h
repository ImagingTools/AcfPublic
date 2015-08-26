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


#ifndef iipr_IImageInterpolationParams_included
#define iipr_IImageInterpolationParams_included


// ACF includes
#include "istd/istd.h"
#include "iser/ISerializable.h"


namespace iipr
{


/**
	Common interface for interpolation parameters
*/
class IImageInterpolationParams: virtual public iser::ISerializable
{
public:

	/**
		Interpolation mode
	*/
	enum InterpolationMode
	{
		IM_NO_INTERPOLATION,
		IM_BILINEAR,
		IM_BICUBIC,
		IM_NEAREST_NEIGHBOUR
	};

	I_DECLARE_ENUM(InterpolationMode, IM_NO_INTERPOLATION, IM_BILINEAR, IM_BICUBIC, IM_NEAREST_NEIGHBOUR);

	/**
		Get used interpolation mode.
		\sa InterpolationMode
	*/
	virtual int GetInterpolationMode() const = 0;

	/**
		Set interpolation mode.
		\sa InterpolationMode
	*/
	virtual void SetInterpolationMode(int interpolationMode) = 0;
};


} // namespace iipr


#endif // !iipr_IImageInterpolationParams_included


