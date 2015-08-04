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


#include "iipr/CBitmapProviderCacheComp.h"


namespace iipr
{


// reimplemented (iimg::IBitmapProvider)

const iimg::IBitmap* CBitmapProviderCacheComp::GetBitmap() const
{
	return m_bitmapPtr.GetPtr();
}


// reimplemented (i2d::ICalibrationProvider)

const i2d::ICalibration2d* CBitmapProviderCacheComp::GetCalibration() const
{
	return m_transformPtr.GetPtr();
}


// reimplemented (istd::IChangeable)

bool CBitmapProviderCacheComp::CopyFrom(const IChangeable& object, CompatibilityMode mode)
{
	const iimg::IBitmapProvider* providerPtr = dynamic_cast<const iimg::IBitmapProvider*>(&object);
	if (providerPtr != NULL){
		m_bitmapPtr.Reset();
		const iimg::IBitmap* bitmapPtr = providerPtr->GetBitmap();
		if (bitmapPtr != NULL){
			m_bitmapPtr.SetCastedOrRemove(bitmapPtr->CloneMe(mode));
		}

		m_transformPtr.Reset();

		const i2d::ICalibrationProvider* calibrationProviderPtr = dynamic_cast<const i2d::ICalibrationProvider*>(&object);
		if (calibrationProviderPtr != NULL){
			const i2d::ICalibration2d* transformPtr = calibrationProviderPtr->GetCalibration();
			if (transformPtr != NULL){
				m_transformPtr.SetCastedOrRemove(transformPtr->CloneMe(mode));
			}
		}

		return true;
	}

	return false;
}


} // namespace iipr


