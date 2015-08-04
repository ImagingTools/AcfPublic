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


#include "QtIprPck.h"


// Qt includes
#include <QtCore/QDir>

// ACF includes
#include "icomp/export.h"


namespace QtIprPck
{


I_EXPORT_PACKAGE(
			"AcfSln/QtIpr",
			"Standard Qt image processing package",
			"Qt \"Image Processing\" Processing GUI" IM_PROJECT("ACF-Solutions") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));


I_EXPORT_COMPONENT(
			ValueSupplierGui,
			"GUI for supplier implementation returning position found using caliper tool",
			"Observer Caliper Position Supplier");

I_EXPORT_COMPONENT(
			CaliperParamsGui,
			"GUI to parametrize caliper",
			"Observer Caliper Parameters Direction Edge Mode Threshold");

I_EXPORT_COMPONENT(
			LineProjectionSupplierGui,
			"GUI for line projection supplier",
			"Observer Supplier Line Projection");

I_EXPORT_COMPONENT(
			CircleFinderParamsGui,
			"GUI to parametrize the circle finder",
			"Observer Caliper Circle Parameters");

I_EXPORT_COMPONENT(
			SearchBasedFeaturesSupplierGui,
			"GUI for search based position supplier",
			"Observer Supplier Search Image Processing");

I_EXPORT_COMPONENT(
			GeneralSearchParamsGui,
			"GUI for general search parameters",
			"Observer Search Parameters");

I_EXPORT_COMPONENT(
			Convolution2dParamsGui,
			"GUI for definition of convolution kernel",
			"Kernel Convolution Filter");

I_EXPORT_COMPONENT(
			MultiLineSupplierGui, 
			"Editor for multi-line provider",
			"Multi Line Supplier GUI")

I_EXPORT_COMPONENT(
			MultiLineProjectionSupplierGui, 
			"Editor for multi-line projection provider",
			"Multi Line Projection Supplier GUI");

I_EXPORT_COMPONENT(
			PatternTeachingControllerGui, 
			"UI for the pattern teaching controller",
			"Pattern Teaching Editor");

I_EXPORT_COMPONENT(
			ColorPatternComparatorGui, 
			"Editor for color pattern comparator",
			"Color Pattern Comparator Compare Match Matching");

I_EXPORT_COMPONENT(
			ImageInterpolationParamsGui, 
			"Editor for the image interpolation parameters",
			"Color Image Interpolation Parameters");


} // namespace QtIprPck


