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


#include "MeasPck.h"


#include <icomp/export.h>


namespace MeasPck
{


I_EXPORT_PACKAGE(
			"AcfSln/Measure",
			"System-undependent package for sampling, measurement acquisition and related thema",
			"Measurement Acquisition Undependend" IM_TAG("Sampling") IM_PROJECT("ACF-Solutions") IM_COMPANY("ImagingTools"));

I_EXPORT_COMPONENT(
			GeneralBitmap,
			"General, system undependent bitmap implementation",
			"Bitmap Picture Acquisition Simple General" IM_TAG("Image") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			GeneralDataSequence,
			"General, system undependent sample sequence implementation",
			"Samples Sequence Acquisition" IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			SimpleSamplesSequence8,
			"Simple sample sequence storing 8-bit samples, system undependent",
			"Samples Sequence Measurement" IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			SimpleSamplesSequence16,
			"Simple sample sequence storing 16-bit samples, system undependent",
			"Samples Sequence Measurement" IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			SimpleSamplesSequence32,
			"Simple sample sequence storing 32-bit samples, system undependent",
			"Samples Sequence Measurement" IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			WavSamplesLoader,
			"Loader for loading and saving sample sequence as Audio WAV file",
			"Audio WAV Loder Serializer Persistence Samples Sequence Measurement" IM_TAG("Loader") IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			SimpleDataStatistics,
			"Basic statistics of a numerical data",
			"Data" IM_TAG("Statistics") IM_AUTHOR("\"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			DataSequenceStatistics,
			"Data sequence statistics",
			"Sequence Data" IM_TAG("Statistics") IM_AUTHOR("\"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			HistogramStatisticsProcessor,
			"Processor for calculation of statistics",
			"Histogram Statistics" IM_TAG("Processing") IM_AUTHOR("\"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			NumericParams,
			"Set of numeric values used for filter values, channel values etc.",
			"Numeric Values Parameter" IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			NumericConstraints,
			"Defines simple constraints for numeric parameters with the same units and ranges for all values",
			"Numeric Values Parameter Constraints" IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			LinearAdjustParams,
			"Parameter with scale and offset for simple linear transformations",
			"Parameter Scale Offset Shift Contrast Brightness Linear Power" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Model Parameter") IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			CrossCorrelationProcessor,
			"Calculate the cross correlation of two data sequences",
			"Correlation Processor Comparison" IM_AUTHOR("\"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			RelativeUnitSelector,
			"Selector of unit info for relative values",
			"Correlation Processor Comparison" IM_AUTHOR("\"Kirill Lepskiy\""));


} // namespace MeasPck


