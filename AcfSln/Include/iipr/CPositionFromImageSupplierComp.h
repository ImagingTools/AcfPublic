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


#ifndef iipr_CPositionFromImageSupplierComp_included
#define iipr_CPositionFromImageSupplierComp_included


// ACF includes
#include <i2d/ICalibration2d.h>
#include <i2d/ICalibrationProvider.h>
#include <i2d/CVector2d.h>

// ACF-Solutions includes
#include <iproc/IProcessor.h>
#include <iinsp/ISupplier.h>
#include <iinsp/TSupplierCompWrap.h>
#include <iipr/CFeaturesContainer.h>
#include <imeas/CSimpleNumericValue.h>
#include <iimg/IBitmapProvider.h>


namespace iipr
{


/**
	Implementation of value supplier returning position on the image.
	To calculate this position is some processor used.
	This processor must accept image object as input and produce some set of features containing position into feature consumer.
	This supplier takes the feature with the higher weight value and output it as found position value.
*/
class CPositionFromImageSupplierComp:
			public iinsp::TSupplierCompWrap<CFeaturesContainer>,
			virtual public IFeaturesProvider,
			virtual public i2d::ICalibrationProvider
{
public:
	typedef iinsp::TSupplierCompWrap<CFeaturesContainer> BaseClass;

	I_BEGIN_COMPONENT(CPositionFromImageSupplierComp);
		I_REGISTER_INTERFACE(IFeaturesProvider);
		I_REGISTER_INTERFACE(i2d::ICalibrationProvider);
		I_ASSIGN(m_bitmapProviderCompPtr, "BitmapProvider", "Provide image to analyse", true, "BitmapProvider");
		I_ASSIGN_TO(m_bitmapSupplierCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN_TO(m_bitmapProviderModelCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN(m_calibrationProviderCompPtr, "CalibrationProvider", "Provide 2D-calibration object", false, "CalibrationProvider");
		I_ASSIGN(m_processorCompPtr, "Processor", "Processor calculating set of positions from image", true, "Processor");
	I_END_COMPONENT;

	// reimplemented (iipr::IFeaturesProvider)
	virtual int GetFeaturesCount() const;
	virtual const imeas::INumericValue& GetFeature(int index) const;

	// reimplemented (i2d::ICalibrationProvider)
	virtual const i2d::ICalibration2d* GetCalibration() const;

protected:
	// reimplemented (iinsp::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

protected:
	mutable istd::TDelPtr<const i2d::ICalibration2d> m_outputCalibrationPtr;

private:
	I_REF(iimg::IBitmapProvider, m_bitmapProviderCompPtr);
	I_REF(iinsp::ISupplier, m_bitmapSupplierCompPtr);
	I_REF(imod::IModel, m_bitmapProviderModelCompPtr);
	I_REF(i2d::ICalibrationProvider, m_calibrationProviderCompPtr);
	I_REF(iproc::IProcessor, m_processorCompPtr);
};


} // namespace iipr


#endif // !iipr_CPositionFromImageSupplierComp_included


