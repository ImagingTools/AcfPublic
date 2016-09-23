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


#ifndef ifileproc_CBitmapPreviewGeneratorComp_included
#define ifileproc_CBitmapPreviewGeneratorComp_included


// ACF includes
#include <istd/TSmartPtr.h>
#include <iproc/TSyncProcessorCompBase.h>
#include <iimg/IBitmap.h>


namespace ifileproc
{


/**
	Generator of the bitmap preview.
*/
class CBitmapPreviewGeneratorComp: public iproc::CSyncProcessorCompBase
{
public:
	typedef iproc::CSyncProcessorCompBase BaseClass;

	I_BEGIN_COMPONENT(CBitmapPreviewGeneratorComp);
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);
};


} // namespace ifileproc


#endif // !ifileproc_CBitmapPreviewGeneratorComp_included


