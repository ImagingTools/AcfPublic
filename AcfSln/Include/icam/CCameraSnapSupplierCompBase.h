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


// Qt includes
#include <QtCore/QPair>

// ACF includes
#include <istd/TDelPtr.h>
#include <i2d/ICalibration2d.h>
#include <i2d/ICalibrationProvider.h>
#include <iimg/IBitmap.h>
#include <iinsp/TSupplierCompWrap.h>

// ACF-Solutions includes
#include <icam/IBitmapAcquisition.h>
#include <icam/CSnapBitmapSupplierCompBase.h>


namespace icam
{


/**
	Basic implementation of bitmap supplier based on the camera snap.
*/
class CCameraSnapSupplierCompBase: public CSnapBitmapSupplierCompBase
{
public:
	typedef CSnapBitmapSupplierCompBase BaseClass;

	I_BEGIN_BASE_COMPONENT(CCameraSnapSupplierCompBase);
		I_REGISTER_INTERFACE(i2d::ICalibrationProvider);
		I_ASSIGN(m_bitmapAcquisitionCompPtr, "BitmapAcquisition", "Bitmap acquisition object for image snap", true, "BitmapAcquisition");
	I_END_COMPONENT;

protected:
	// reimplemented (CSnapBitmapSupplierCompBase)
	virtual int DoSnap(const iprm::IParamsSet* snapParamsPtr, iimg::IBitmap& snapBitmap) const;

	// reimplemented (iinsp::TSupplierCompWrap)
	virtual bool InitializeWork();

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(IBitmapAcquisition, m_bitmapAcquisitionCompPtr);
};


} // namespace icam


