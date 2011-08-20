/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iipr_CDelegatedBitmapSupplierComp_included
#define iipr_CDelegatedBitmapSupplierComp_included


// STL includes
#include <utility>

// ACF includes
#include "imod/IModel.h"
#include "imod/CMultiModelObserverBase.h"
#include "i2d/ITransformation2d.h"
#include "iproc/TSupplierCompWrap.h"

// IACF includes
#include "iipr/IBitmapSupplier.h"


namespace iipr
{


/**
	Image supplier delegating the calls to another one or accessing some bitmap object directly.
*/
class CDelegatedBitmapSupplierComp:
			public iproc::TSupplierCompWrap<iipr::IBitmapSupplier, std::pair<const i2d::ITransformation2d*, const iimg::IBitmap*> >,
			protected imod::CMultiModelObserverBase
{
public:
	typedef iproc::TSupplierCompWrap<iipr::IBitmapSupplier, std::pair<const i2d::ITransformation2d*, const iimg::IBitmap*> > BaseClass;

	I_BEGIN_COMPONENT(CDelegatedBitmapSupplierComp);
		I_ASSIGN(m_inputBitmapSupplierCompPtr, "SlaveSupplier", "Slave supplier where all calls will be delegated", false, "SlaveSupplier");
		I_ASSIGN(m_bitmapCompPtr, "BitmapObject", "Bitmap object used if no slave supplier is provided", false, "BitmapObject");
		I_ASSIGN_TO(m_bitmapModelCompPtr, m_bitmapCompPtr, false);
		I_ASSIGN(m_calibrationCompPtr, "CalibrationObject", "Calibration object used as image to log transformation, if no slave supplier is provided", false, "CalibrationObject");
		I_ASSIGN_TO(m_calibrationModelCompPtr, m_calibrationCompPtr, false);
	I_END_COMPONENT;

protected:
	// reimplemented (iipr::IBitmapSupplier)
	virtual const iimg::IBitmap* GetBitmap() const;
	virtual const i2d::ITransformation2d* GetLogTransform() const;

	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

protected:
	// reimplemented (imod::CMultiModelObserverBase)
	virtual void OnUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

private:
	I_REF(iipr::IBitmapSupplier, m_inputBitmapSupplierCompPtr);
	I_REF(iimg::IBitmap, m_bitmapCompPtr);
	I_REF(imod::IModel, m_bitmapModelCompPtr);
	I_REF(i2d::ITransformation2d, m_calibrationCompPtr);
	I_REF(imod::IModel, m_calibrationModelCompPtr);
};


} // namespace iipr


#endif // !iipr_CDelegatedBitmapSupplierComp_included


