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


#ifndef iipr_CProcessedBitmapSupplierComp_included
#define iipr_CProcessedBitmapSupplierComp_included


// STL includes
#include <utility>

// ACF includes
#include "iproc/IProcessor.h"
#include "iproc/TSupplierCompWrap.h"

// IACF includes
#include "iipr/IBitmapSupplier.h"


namespace iipr
{


/**
	Image supplier providing processed image from some other input image supplier.
*/
class CProcessedBitmapSupplierComp: public iproc::TSupplierCompWrap<iipr::IBitmapSupplier, std::pair<istd::TDelPtr<i2d::ITransformation2d>,  istd::TDelPtr<iimg::IBitmap> > >
{
public:
	typedef iproc::TSupplierCompWrap<iipr::IBitmapSupplier, std::pair<istd::TDelPtr<i2d::ITransformation2d>,  istd::TDelPtr<iimg::IBitmap> > > BaseClass;

	I_BEGIN_COMPONENT(CProcessedBitmapSupplierComp);
		I_ASSIGN(m_bitmapCompFact, "BitmapFactory", "Use to create bitmap object", true, "BitmapFactory");
		I_ASSIGN(m_inputBitmapSupplierCompPtr, "BitmapSupplier", "Provide input image", true, "BitmapSupplier");
		I_ASSIGN(m_imageProcessorCompPtr, "BitmapProcessor", "Bitmap conversion processor (takes bitmap as input and output)", true, "BitmapProcessor");
	I_END_COMPONENT;

protected:
	bool EnsureBitmapCreated(ProductType& result) const;

	// reimplemented (iipr::IBitmapSupplier)
	virtual const iimg::IBitmap* GetBitmap() const;
	virtual const i2d::ITransformation2d* GetLogTransform() const;

	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_FACT(iimg::IBitmap, m_bitmapCompFact);

	I_REF(iipr::IBitmapSupplier, m_inputBitmapSupplierCompPtr);
	I_REF(iproc::IProcessor, m_imageProcessorCompPtr);
};


} // namespace iipr


#endif // !iipr_CProcessedBitmapSupplierComp_included


