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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef icam_CMemoryAcquisitionComp_included
#define icam_CMemoryAcquisitionComp_included


// ACF includes
#include "iser/IFileLoader.h"
#include "icomp/CComponentBase.h"
#include "ifile/IFileNameParam.h"
#include "iimg/CGeneralBitmap.h"
#include "iproc/TSyncProcessorWrap.h"

// ACF-Solutions includes
#include "icam/IBitmapAcquisition.h"


namespace icam
{


/**
	Bitmap loader component implementing interfaces \c iser::IFileLoader and \c icam::IBitmapAcquisition.
*/
class CMemoryAcquisitionComp:
			public icomp::CComponentBase,
			public iimg::CGeneralBitmap,
			virtual public iproc::TSyncProcessorWrap<IBitmapAcquisition>
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef iimg::CGeneralBitmap BaseClass2;

	I_BEGIN_COMPONENT(CMemoryAcquisitionComp);
		I_REGISTER_INTERFACE(IBitmapAcquisition);
		I_REGISTER_INTERFACE(iimg::IBitmap);
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (icam::IBitmapAcquisition)
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const;
};


} // namespace icam


#endif // !icam_CMemoryAcquisitionComp_included


