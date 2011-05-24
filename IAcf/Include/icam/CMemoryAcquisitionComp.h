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


#ifndef icam_CMemoryAcquisitionComp_included
#define icam_CMemoryAcquisitionComp_included


// ACF includes
#include "iser/IFileLoader.h"
#include "icomp/CComponentBase.h"
#include "iprm/IFileNameParam.h"
#include "iimg/CGeneralBitmap.h"

#include "iproc/TSyncProcessorWrap.h"

#include "iproc/IBitmapAcquisition.h"

#include "icam/icam.h"


namespace icam
{


/**
	Bitmap loader component implementing interfaces \c iser::IFileLoader and \c iproc::IBitmapAcquisition.
*/
class CMemoryAcquisitionComp:
			public icomp::CComponentBase,
			public iimg::CGeneralBitmap,
			virtual public iproc::TSyncProcessorWrap<iproc::IBitmapAcquisition>
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef iimg::CGeneralBitmap BaseClass2;

	I_BEGIN_COMPONENT(CMemoryAcquisitionComp);
		I_REGISTER_INTERFACE(iproc::IBitmapAcquisition);
		I_REGISTER_INTERFACE(iimg::IBitmap);
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (iproc::IBitmapAcquisition)
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const;
};


} // namespace icam


#endif // !icam_CMemoryAcquisitionComp_included


