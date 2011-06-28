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


#ifndef iipr_CLineProjectionSupplierComp_included
#define iipr_CLineProjectionSupplierComp_included


// ACF includes
#include "i2d/CVector2d.h"
#include "iprm/IParamsSet.h"
#include "iproc/IProcessor.h"
#include "iproc/TSupplierCompWrap.h"

// ACF-Solutions includes
#include "imeas/CGeneralDataSequence.h"

#include "iipr/IBitmapSupplier.h"
#include "iipr/ILineProjectionSupplier.h"
#include "iipr/ILineProjectionProcessor.h"


namespace iipr
{


class CLineProjectionSupplierComp: public iproc::TSupplierCompWrap<iipr::ILineProjectionSupplier, imeas::CGeneralDataSequence>
{
public:
	typedef iproc::TSupplierCompWrap<iipr::ILineProjectionSupplier, imeas::CGeneralDataSequence> BaseClass;

	I_BEGIN_COMPONENT(CLineProjectionSupplierComp);
		I_REGISTER_INTERFACE(CLineProjectionSupplierComp);
		I_ASSIGN(m_bitmapSupplierCompPtr, "BitmapSupplier", "Provide image to analyse", true, "BitmapSupplier");
		I_ASSIGN(m_projectionProcessorCompPtr, "ProjectionProcessor", "Processor for projection data generation", true, "ProjectionProcessor");
	I_END_COMPONENT;

	// reimplemented (iipr::ILineProjectionSupplier)
	virtual const imeas::IDataSequence* GetLineProjection() const;

protected:
	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(imeas::CGeneralDataSequence& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iipr::IBitmapSupplier, m_bitmapSupplierCompPtr);
	I_REF(iipr::ILineProjectionProcessor, m_projectionProcessorCompPtr);
};


} // namespace iipr


#endif // !iipr_CLineProjectionSupplierComp_included


