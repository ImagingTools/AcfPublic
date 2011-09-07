/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef MeasPck_included
#define MeasPck_included


// ACF includes
#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"
#include "iimg/CGeneralBitmap.h"

// ACF-Solutions includes
#include "imeas/TDiscrDataSequence.h"
#include "imeas/CGeneralDataSequence.h"
#include "imeas/CWavSamplesLoaderComp.h"
#include "imeas/CDataStatistics.h"
#include "imeas/CDataSequenceStatistics.h"
#include "imeas/CHistogramStatisticsProcessorComp.h"
#include "imeas/CNumericParamsComp.h"


/**
	System-undependent package for sampling, measurement acquisition and related thema.
*/
namespace MeasPck
{


typedef icomp::TModelCompWrap< icomp::TMakeComponentWrap<
			iimg::CGeneralBitmap,
			iimg::IBitmap,
			iimg::IRasterImage,
			iser::ISerializable,
			istd::IChangeable> > GeneralBitmap;
typedef icomp::TModelCompWrap< icomp::TMakeComponentWrap<
			imeas::CGeneralDataSequence,
			imeas::IDataSequence,
			imath::ISampledFunction2d,
			iser::ISerializable,
			istd::IChangeable> > GeneralDataSequence;
typedef icomp::TModelCompWrap< icomp::TMakeComponentWrap<
			imeas::CSimpleSamplesSequence8,
			imeas::IDiscrDataSequence,
			imeas::IDataSequence,
			iser::ISerializable,
			istd::IChangeable> > SimpleSamplesSequence8;
typedef icomp::TModelCompWrap< icomp::TMakeComponentWrap<
			imeas::CSimpleSamplesSequence16,
			imeas::IDiscrDataSequence,
			imeas::IDataSequence,
			iser::ISerializable,
			istd::IChangeable> > SimpleSamplesSequence16;
typedef icomp::TModelCompWrap< icomp::TMakeComponentWrap<
			imeas::CSimpleSamplesSequence32,
			imeas::IDiscrDataSequence,
			imeas::IDataSequence,
			iser::ISerializable,
			istd::IChangeable> > SimpleSamplesSequence32;
typedef imeas::CWavSamplesLoaderComp WavSamplesLoader;
typedef icomp::TModelCompWrap< icomp::TMakeComponentWrap<
			imeas::CDataStatistics,
			imeas::IDataStatistics,
			iser::ISerializable> > DataStatistics;
typedef icomp::TModelCompWrap< icomp::TMakeComponentWrap<
			imeas::CDataSequenceStatistics,
			imeas::IDataSequenceStatistics,
			iser::ISerializable> > DataSequenceStatistics;
typedef imeas::CHistogramStatisticsProcessorComp HistogramStatisticsProcessor;
typedef icomp::TModelCompWrap<imeas::CNumericParamsComp> NumericParams;


} // namespace MeasPck


#endif // !MeasPck_included


