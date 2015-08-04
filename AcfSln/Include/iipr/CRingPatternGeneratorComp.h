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


#ifndef iipr_CRingPatternGeneratorComp_included
#define iipr_CRingPatternGeneratorComp_included


// ACF includes
#include "iimg/IBitmap.h"

#include "iproc/TSyncProcessorCompBase.h"


namespace iipr
{


class CRingPatternGeneratorComp: public iproc::CSyncProcessorCompBase
{
public:
	typedef iproc::CSyncProcessorCompBase BaseClass;
	
	I_BEGIN_COMPONENT(CRingPatternGeneratorComp);
		I_ASSIGN(m_paramsIdAttrPtr, "ParamsId", "ID of the processor parameter in the parameter set", false, "ParamsId");
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

private:
	I_ATTR(QByteArray, m_paramsIdAttrPtr);
};


} // namespace iipr


#endif // !iipr_CRingPatternGeneratorComp_included

