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


enum ColorantType
{
	CT_NONE,
	CT_PROCESS,
	CT_SPOT
};

I_DECLARE_ENUM(ColorantType, CT_NONE, CT_PROCESS, CT_SPOT);


/**
	Usage of a process colorant.
*/
enum ProcessColorantUsage
{
	/**
		No special usage of the process colorant.
	*/
	PCU_NONE,

	/**
		Colorant is used as a darker version of another process colorant.
	*/
	PCU_DARK,

	/**
		Colorant is used as a lighter version of another process colorant.
	*/
	PCU_LIGHT,

	/**
		Colorant is used for expanding the gamut of the printing device.
	*/
	PCU_ECG
};

I_DECLARE_ENUM(ProcessColorantUsage, PCU_NONE, PCU_DARK, PCU_LIGHT, PCU_ECG);



} // namespace icmm


