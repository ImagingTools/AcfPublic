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


#ifndef iipr_CPositionFromImageSupplierComp_included
#define iipr_CPositionFromImageSupplierComp_included


// ACF includes
#include "i2d/ICalibrationProvider.h"
#include "i2d/CVector2d.h"
#include "iproc/IProcessor.h"
#include "iproc/TSupplierCompWrap.h"
#include "iproc/IValueProvider.h"

// ACF-Solutions includes
#include "iipr/IBitmapProvider.h"


namespace iipr
{


/**
	Implementation of value supplier returning position on the image.
	To calculate this position is some processor used.
	This processor must accept image object as input and produce some set of features containing position into feature consumer.
	This supplier takes the feature with the higher weight value and output it as found position value.
*/
class CPositionFromImageSupplierComp:
			public iproc::TSupplierCompWrap<imath::CVarVector>,
			virtual public iproc::IValueProvider
{
public:
	typedef iproc::TSupplierCompWrap<imath::CVarVector> BaseClass;

	I_BEGIN_COMPONENT(CPositionFromImageSupplierComp);
		I_REGISTER_INTERFACE(iproc::IValueProvider);
		I_ASSIGN(m_bitmapProviderCompPtr, "BitmapSupplier", "Provide image to analyse", true, "BitmapSupplier");
		I_ASSIGN(m_calibrationProviderCompPtr, "CalibrationSupplier", "Provide 2D-calibration object", false, "CalibrationSupplier");
		I_ASSIGN_TO(m_bitmapProviderModelCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN(m_processorCompPtr, "Processor", "Processor calculating set of positions from image", true, "Processor");
	I_END_COMPONENT;

	// reimplemented (iproc::IValueProvider)
	virtual imath::CVarVector GetValue(int index = -1, int valueTypeId = VTI_AUTO) const;

protected:
	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(imath::CVarVector& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iipr::IBitmapProvider, m_bitmapProviderCompPtr);
	I_REF(i2d::ICalibrationProvider, m_calibrationProviderCompPtr);
	I_REF(imod::IModel, m_bitmapProviderModelCompPtr);
	I_REF(iproc::IProcessor, m_processorCompPtr);
};


} // namespace iipr


#endif // !iipr_CPositionFromImageSupplierComp_included


