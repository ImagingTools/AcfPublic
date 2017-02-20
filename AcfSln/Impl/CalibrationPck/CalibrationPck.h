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


#ifndef CalibrationPck_included
#define CalibrationPck_included


// ACF includes
#include <imod/IObserver.h>
#include <icomp/TModelCompWrap.h>
#include <icomp/TMakeComponentWrap.h>

// ACF-Solutions includes
#include <icalib/CAffineCalibration2dComp.h>
#include <icalib/CPerspectiveCalibration2dComp.h>
#include <icalib/CSimpleLensCorrectionComp.h>
#include <icalib/CStaticCalibrationProviderComp.h>
#include <icalib/CCalibration2dProxyComp.h>


/**
	Base system-independent general package.
*/
namespace CalibrationPck
{


typedef icomp::TModelCompWrap<icalib::CAffineCalibration2dComp> AffineCalibration2d;
typedef icomp::TModelCompWrap<icalib::CPerspectiveCalibration2dComp> PerspectiveCalibration2d;
typedef icomp::TModelCompWrap<icalib::CSimpleLensCorrectionComp> SimpleLensCorrection;
typedef icomp::TModelCompWrap<icalib::CStaticCalibrationProviderComp> StaticCalibrationProvider;
typedef icomp::TModelCompWrap<icalib::CCalibration2dProxyComp> Calibration2dProxy;


} // namespace CalibrationPck


#endif // !CalibrationPck_included


