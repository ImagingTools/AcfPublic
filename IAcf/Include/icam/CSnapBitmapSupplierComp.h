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


#ifndef icam_CSnapBitmapSupplierComp_included
#define icam_CSnapBitmapSupplierComp_included


// ACF includes
#include "istd/TDelPtr.h"
#include "iimg/IBitmap.h"
#include "iprm/IParamsSet.h"
#include "iproc/TSupplierCompWrap.h"
#include "iproc/IBitmapAcquisition.h"

#include "iipr/IBitmapSupplier.h"


namespace icam
{


/**
	Implementation of bitmap supplier based on image acquisition.
*/
class CSnapBitmapSupplierComp: public iproc::TSupplierCompWrap<iipr::IBitmapSupplier, istd::TDelPtr<iimg::IBitmap> >
{
public:
	typedef iproc::TSupplierCompWrap<iipr::IBitmapSupplier, istd::TDelPtr<iimg::IBitmap> > BaseClass;

	I_BEGIN_COMPONENT(CSnapBitmapSupplierComp);
		I_ASSIGN(m_bitmapCompFact, "BitmapFactory", "Use to create bitmap object", true, "BitmapFactory");
		I_ASSIGN(m_bitmapAcquisitionCompPtr, "BitmapAcquisition", "Bitmap acquision object for image snap", true, "BitmapAcquisition");
	I_END_COMPONENT;

	// reimplemented (iipr::IBitmapSupplier)
	virtual const iimg::IBitmap* GetBitmap() const;

protected:
	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(istd::TDelPtr<iimg::IBitmap>& result) const;

private:
	I_FACT(iimg::IBitmap, m_bitmapCompFact);

	I_REF(iproc::IBitmapAcquisition, m_bitmapAcquisitionCompPtr);
};


} // namespace icam


#endif // !icam_CSnapBitmapSupplierComp_included


