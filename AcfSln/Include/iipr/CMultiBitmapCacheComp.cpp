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


#include "iipr/CMultiBitmapCacheComp.h"


// ACF includes
#include "istd/TDelPtr.h"


namespace iipr
{


CMultiBitmapCacheComp::CMultiBitmapCacheComp()
{
}


// reimplemented (iipr::IMultiBitmapProvider)

const iprm::IOptionsList* CMultiBitmapCacheComp::GetBitmapSelectionContraints() const
{
	return NULL;
}


int CMultiBitmapCacheComp::GetBitmapsCount() const
{
	return m_bitmapsPtr.GetCount();
}


const iimg::IBitmap* CMultiBitmapCacheComp::GetBitmap(int bitmapIndex) const
{
	Q_ASSERT(bitmapIndex >= 0);
	Q_ASSERT(bitmapIndex < GetBitmapsCount());

	return m_bitmapsPtr.GetAt(bitmapIndex);
}


// reimplemented (i2d::IMultiCalibrationProvider)

const iprm::IOptionsList* CMultiBitmapCacheComp::GetCalibrationSelectionContraints() const
{
	return NULL;
}


int CMultiBitmapCacheComp::GetCalibrationsCount() const
{
	return m_transformsPtr.GetCount();
}


const i2d::ICalibration2d* CMultiBitmapCacheComp::GetCalibration(int calibrationIndex) const
{
	Q_ASSERT(calibrationIndex >= 0);
	Q_ASSERT(calibrationIndex < GetBitmapsCount());
	Q_ASSERT(m_bitmapsPtr.GetCount() == m_transformsPtr.GetCount());

	return m_transformsPtr.GetAt(calibrationIndex);
}


// reimplemented (istd::IChangeable)

bool CMultiBitmapCacheComp::CopyFrom(const IChangeable& object, CompatibilityMode mode)
{
	bool retVal = false;

	const IMultiBitmapProvider* providerPtr = CompCastPtr<const IMultiBitmapProvider>(&object);
	if (providerPtr != NULL){
		int bitmapsCount = providerPtr->GetBitmapsCount();

		m_bitmapsPtr.SetCount(bitmapsCount);

		for (int i = 0; i < bitmapsCount; ++i){
			istd::TDelPtr<iimg::IBitmap> clonedBitmapPtr;
			const iimg::IBitmap* bitmapPtr = providerPtr->GetBitmap(i);
			if (bitmapPtr != NULL){
				clonedBitmapPtr.SetCastedOrRemove(bitmapPtr->CloneMe(mode));
			}
			m_bitmapsPtr.SetElementAt(i, clonedBitmapPtr.PopPtr());
		}

		retVal = true;
	}

	const i2d::IMultiCalibrationProvider* calibrationProviderPtr = CompCastPtr<const i2d::IMultiCalibrationProvider>(&object);
	if (calibrationProviderPtr != NULL){
		int calibrationsCount = calibrationProviderPtr->GetCalibrationsCount();

		m_transformsPtr.SetCount(calibrationsCount);

		for (int i = 0; i < calibrationsCount; ++i){
			istd::TDelPtr<i2d::ICalibration2d> clonedTransformPtr;
			const i2d::ICalibration2d* calibrationPtr = calibrationProviderPtr->GetCalibration(i);
			if (calibrationPtr != NULL){
				clonedTransformPtr.SetCastedOrRemove(calibrationPtr->CloneMe(mode));
			}
			m_transformsPtr.SetElementAt(i, clonedTransformPtr.PopPtr());
		}

		retVal = true;
	}

	return retVal;
}


} // namespace iipr


