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


#pragma once


// ACF includes
#include <icalib/CAffineCalibration2d.h>
#include <icalib/CPerspectiveCalibration2d.h>
#include <icalib/CLUTCalibration2d.h>
#include <icalib/CSimpleLensCorrection.h>


namespace icalib
{


// a simple header-only calibration factory for known classes
// to avoid cloning of whole compositums because of memory leaks and dangling pointers upon destruction

inline istd::IChangeable* FactorizeFrom(const istd::IChangeable* calibPtr)
{
	if (!calibPtr)
		return nullptr;

	istd::IChangeable* resultPtr = nullptr;

	if (auto affinePtr = dynamic_cast<const icalib::CAffineCalibration2d*>(calibPtr)) {
		resultPtr = new icalib::CAffineCalibration2d;
	}
	else if (auto perspPtr = dynamic_cast<const icalib::CPerspectiveCalibration2d*>(calibPtr)) {
		resultPtr = new icalib::CPerspectiveCalibration2d;
	}
	else if (auto lutPtr = dynamic_cast<const icalib::CLUTCalibration2d*>(calibPtr)) {
		resultPtr = new icalib::CLUTCalibration2d;
	}
	else if (auto lensPtr = dynamic_cast<const icalib::CSimpleLensCorrection*>(calibPtr)) {
		resultPtr = new icalib::CSimpleLensCorrection;
	}

	if (resultPtr) {
		resultPtr->CopyFrom(*calibPtr);
		return resultPtr;
	}

	// default clone
	return calibPtr->CloneMe();
}


}
