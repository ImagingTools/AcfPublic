/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "icomp/export.h"

#include "MeasPck.h"


namespace MeasPck
{


I_EXPORT_DEFAULT_SERVICES;

I_EXPORT_PACKAGE(
			"AcfSln/Measure",
			"System-undependent package for sampling, measurement acquisition and related thema",
			"Measurement Acquisition Undependend" IM_TAG("Sampling") IM_PROJECT("ACF-Solutions") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			GeneralBitmap,
			"General, system undependent bitmap implementation",
			"Bitmap Picture Acquisition Simple General" IM_TAG("Image"));

I_EXPORT_COMPONENT(
			GeneralDataSequence,
			"General, system undependent sample sequence implementation",
			"Samples Sequence Acquisition" IM_TAG("Sampling"));

I_EXPORT_COMPONENT(
			SimpleSamplesSequence8,
			"Simple sample sequence storing 8-bit samples, system undependent",
			"Samples Sequence Measurement" IM_TAG("Sampling"));

I_EXPORT_COMPONENT(
			SimpleSamplesSequence16,
			"Simple sample sequence storing 16-bit samples, system undependent",
			"Samples Sequence Measurement" IM_TAG("Sampling"));

I_EXPORT_COMPONENT(
			SimpleSamplesSequence32,
			"Simple sample sequence storing 32-bit samples, system undependent",
			"Samples Sequence Measurement" IM_TAG("Sampling"));

I_EXPORT_COMPONENT(
			WavSamplesLoader,
			"Loader for loading and saving sample sequence as Audio WAV file",
			"Audio WAV Loder Serializer Persistence Samples Sequence Measurement" IM_TAG("Loader"));

I_EXPORT_COMPONENT(
			DataStatistics,
			"Basic statistics of a numerical data",
			"Data" IM_TAG("Statistics"));

I_EXPORT_COMPONENT(
			DataSequenceStatistics,
			"Data sequence statistics",
			"Sequence Data" IM_TAG("Statistics"));

I_EXPORT_COMPONENT(
			HistogramStatisticsProcessor,
			"Processor for calculation of statistics",
			"Histogram Statistics" IM_TAG("Processing"));

I_EXPORT_COMPONENT(
			NumericParams,
			"Rectangular filter parameter",
			"Filter Image Processing Parameter");


} // namespace MeasPck


