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
#include <imath/imath.h>


/**
	Contains color management classes.
	This package is system undependent.
	This package use following ACF packages:
	\li	istd
	\li	iser
	\li	imath

	\ingroup Color
*/
namespace icmm
{


/**
	Usage of a colorant.
*/
enum ColorantUsage
{
	/**
		No special usage of the colorant.
	*/
	CU_NONE,
	CU_CYAN,
	CU_DARK_CYAN,
	CU_LIGHT_CYAN,
	CU_MAGENTA,
	CU_DARK_MAGENTA,
	CU_LIGHT_MAGENTA,
	CU_YELLOW,
	CU_DARK_YELLOW,
	CU_LIGHT_YELLOW,
	CU_BLACK,
	CU_LIGHT_BLACK,
	CU_LIGHT_LIGHT_BLACK,

	/**
		Colorant is used for expanding the gamut of the printing device.
	*/
	CU_ECG,

	/**
		Colorant is used as a spot color.
	*/
	CU_SPOT
};

I_DECLARE_ENUM(
			ColorantUsage,
			CU_NONE,
			CU_CYAN,
			CU_DARK_CYAN,
			CU_LIGHT_CYAN,
			CU_MAGENTA,
			CU_DARK_MAGENTA,
			CU_LIGHT_MAGENTA,
			CU_YELLOW,
			CU_DARK_YELLOW,
			CU_LIGHT_YELLOW,
			CU_BLACK,
			CU_LIGHT_BLACK,
			CU_LIGHT_LIGHT_BLACK,
			CU_ECG,
			CU_SPOT);



} // namespace icmm


