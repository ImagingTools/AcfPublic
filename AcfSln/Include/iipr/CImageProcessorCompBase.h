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


#ifndef iipr_CImageProcessorCompBase_included
#define iipr_CImageProcessorCompBase_included


// ACF includes
#include "istd/TSmartPtr.h"
#include "iproc/TSyncProcessorCompBase.h"
#include "iimg/IBitmap.h"


namespace iipr
{


/**
	Basic implementation for a simple bitmap processor.
*/
class CImageProcessorCompBase: public iproc::CSyncProcessorCompBase
{
public:
	typedef iproc::CSyncProcessorCompBase BaseClass;

	/**
		Describes modes of AOI interpretation.
		It is placed here to allow the same value interpretation for all image processors.
	*/
	enum AoiMode
	{
		/**
			AOI mask contains the input bitmap pixels.
		*/
		AM_INPUT_PIXELS,
		/**
			AOI mask contains the output bitmap pixels.
		*/
		AM_OUTPUT_PIXELS
	};

	I_BEGIN_BASE_COMPONENT(CImageProcessorCompBase);
	I_END_COMPONENT;

	CImageProcessorCompBase();

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

protected:
	// abstract methods
	virtual bool ProcessImage(
				const iprm::IParamsSet* paramsPtr, 
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage) = 0;
};


} // namespace iipr


#endif // !iipr_CImageProcessorCompBase_included

