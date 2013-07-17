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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iipr/CColorPatternControllerComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

// ACF-Solutions includes
#include "iipr/CBitmapOperations.h"


namespace iipr
{

	
// reimplemented (IPatternController)

bool CColorPatternControllerComp::TeachPattern(const istd::IChangeable* /*sourceObjectPtr*/)
{
	if (!m_patternBitmapProviderCompPtr.IsValid()){
		SendCriticalMessage(0, "Bad component configuration. Pattern bitmap provider 'PatternBitmapProvider' not set!");

		return false;
	}

	if (!m_bitmapRegionCompPtr.IsValid()){
		SendCriticalMessage(0, "Bad component configuration. Bitmap region 'BitmapRegion' not set!");

		return false;
	}

	if (!m_histogramProgressorCompPtr.IsValid()){
		SendCriticalMessage(0, "Bad component configuration. Histogram processor 'HistogramProgressor' not set!");

		return false;
	}


	const iimg::IBitmap* bitmapPtr = m_patternBitmapProviderCompPtr->GetBitmap();
	if (bitmapPtr == NULL){
		SendErrorMessage(0, "Empty bitmap cannot be used for color pattern teaching");

		return false;
	}

	iimg::CGeneralBitmap patternBitmap;

	i2d::CRectangle patternBoundingBox = m_bitmapRegionCompPtr->GetBoundingBox();
	const i2d::ICalibration2d* aoiCalibrationPtr = m_bitmapRegionCompPtr->GetCalibration();
	if (aoiCalibrationPtr != NULL){
		if (!patternBoundingBox.Transform(*aoiCalibrationPtr)){
			SendErrorMessage(0, "Teaching region could not be defined");

			return false;
		}
	}

	if (!iipr::CBitmapOperations::ReduceBitmapToRegion(*bitmapPtr, patternBoundingBox, patternBitmap)){
		SendErrorMessage(0, "Teaching region could not be extracted from the bitmap");

		return false;
	}

	imeas::CSimpleSamplesSequence32 histogram;

	if (!m_histogramProgressorCompPtr->DoProcessing(NULL, &patternBitmap, &histogram)){
		SendErrorMessage(0, "Histogram calculation failed");

		return false;
	}

	istd::CChangeNotifier updatePtr(this);

	return m_patternBitmap.CopyFrom(patternBitmap) && m_histogram.CopyFrom(histogram);
}


void CColorPatternControllerComp::ResetPattern()
{
	istd::CChangeNotifier updatePtr(this);

	m_patternBitmap.ResetImage();
	m_histogram.ResetSequence();
}


bool CColorPatternControllerComp::IsPatternValid() const
{
	return !m_patternBitmap.IsEmpty();
}


const iser::ISerializable* CColorPatternControllerComp::GetPatternObject() const
{
	return &m_histogram;
}


// reimplemented (iimg::IBitmapProvider)

const iimg::IBitmap* CColorPatternControllerComp::GetBitmap() const
{
	return &m_patternBitmap;
}


// reimplemented (imeas::IDataSequenceProvider)

const imeas::IDataSequence* CColorPatternControllerComp::GetDataSequence() const
{
	return &m_histogram;
}


// reimplemented (iser::ISerializable)

bool CColorPatternControllerComp::Serialize(iser::IArchive& archive)
{
	istd::CChangeNotifier notifier(archive.IsStoring() ? NULL : this);

	static iser::CArchiveTag patternBitmapTag("PatternBitmap", "Bitmap used as pattern");
	static iser::CArchiveTag histogramTag("Histogram", "Histogram of the pattern bitmap");

	bool retVal = true;

	retVal = retVal && archive.BeginTag(patternBitmapTag);		
	retVal = retVal && m_patternBitmap.Serialize(archive);
	retVal = retVal && archive.EndTag(patternBitmapTag);		

	retVal = retVal && archive.BeginTag(histogramTag);		
	retVal = retVal && m_histogram.Serialize(archive);
	retVal = retVal && archive.EndTag(histogramTag);		

	return retVal;
}


// reimplemented (istd::IChangeable)

bool CColorPatternControllerComp::CopyFrom(const IChangeable& object, CompatibilityMode mode)
{
	const CColorPatternControllerComp* sourcePtr = dynamic_cast<const CColorPatternControllerComp*>(&object);
	if (sourcePtr != NULL){
		istd::CChangeNotifier notifier(this);

		bool retVal = m_patternBitmap.CopyFrom(sourcePtr->m_patternBitmap, mode);
		retVal = m_histogram.CopyFrom(sourcePtr->m_histogram, mode) && retVal;

		return retVal;
	}

	return false;
}


} // namespace iipr


