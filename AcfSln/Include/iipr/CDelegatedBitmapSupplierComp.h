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


#ifndef iipr_CDelegatedBitmapSupplierComp_included
#define iipr_CDelegatedBitmapSupplierComp_included


// STL includes
#include <utility>

// ACF includes
#include "imod/IModel.h"
#include "imod/CMultiModelObserverBase.h"
#include "i2d/ICalibrationProvider.h"
#include "iproc/TSupplierCompWrap.h"

// ACF-Solutions includes
#include "iipr/IBitmapProvider.h"


namespace iipr
{


/**
	Image supplier delegating the calls to another one or accessing some bitmap object directly.
*/
class CDelegatedBitmapSupplierComp:
			public iproc::TSupplierCompWrap< std::pair<const i2d::ITransformation2d*, const iimg::IBitmap*> >,
			virtual public IBitmapProvider,
			virtual public i2d::ICalibrationProvider
{
public:
	typedef iproc::TSupplierCompWrap< std::pair<const i2d::ITransformation2d*, const iimg::IBitmap*> > BaseClass;

	I_BEGIN_COMPONENT(CDelegatedBitmapSupplierComp);
		I_REGISTER_INTERFACE(IBitmapProvider);
		I_REGISTER_INTERFACE(i2d::ICalibrationProvider);
		I_ASSIGN(m_inputBitmapProviderCompPtr, "SlaveSupplier", "Slave supplier where all calls will be delegated", false, "SlaveSupplier");
		I_ASSIGN_TO(m_inputBitmapProviderModelCompPtr, m_inputBitmapProviderCompPtr, false);
		I_ASSIGN_TO(m_calibrationProviderCompPtr, m_inputBitmapProviderCompPtr, false);
		I_ASSIGN(m_bitmapCompPtr, "BitmapObject", "Bitmap object used if no slave supplier is provided", false, "BitmapObject");
		I_ASSIGN_TO(m_bitmapModelCompPtr, m_bitmapCompPtr, false);
		I_ASSIGN(m_calibrationCompPtr, "CalibrationObject", "Calibration object used as image to log transformation, if no slave supplier is provided", false, "CalibrationObject");
		I_ASSIGN_TO(m_calibrationModelCompPtr, m_calibrationCompPtr, false);
	I_END_COMPONENT;

protected:
	// reimplemented (iipr::IBitmapProvider)
	virtual const iimg::IBitmap* GetBitmap() const;

	// reimplemented (i2d::ICalibrationProvider)
	virtual const i2d::ITransformation2d* GetCalibration() const;

	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iipr::IBitmapProvider, m_inputBitmapProviderCompPtr);
	I_REF(i2d::ICalibrationProvider, m_calibrationProviderCompPtr);
	I_REF(imod::IModel, m_inputBitmapProviderModelCompPtr);
	I_REF(iimg::IBitmap, m_bitmapCompPtr);
	I_REF(imod::IModel, m_bitmapModelCompPtr);
	I_REF(i2d::ITransformation2d, m_calibrationCompPtr);
	I_REF(imod::IModel, m_calibrationModelCompPtr);
};


} // namespace iipr


#endif // !iipr_CDelegatedBitmapSupplierComp_included


