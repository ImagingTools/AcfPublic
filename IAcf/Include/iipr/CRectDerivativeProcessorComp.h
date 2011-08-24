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


#ifndef iipr_CRectDerivativeProcessorComp_included
#define iipr_CRectDerivativeProcessorComp_included


#include "istd/CString.h"

#include "icomp/CComponentBase.h"

#include "iipr/CRectDerivativeProcessor.h"


namespace iipr
{


/**
	Component implemnetation of derivative processor using rectangular filter kernel.
*/
class CRectDerivativeProcessorComp: public icomp::CComponentBase, public CRectDerivativeProcessor
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef CRectDerivativeProcessor BaseClass2;

	I_BEGIN_COMPONENT(CRectDerivativeProcessorComp);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_REGISTER_INTERFACE(INumericConstraints);
		I_ASSIGN(m_filterParamsIdAttrPtr, "FilterParamsId", "ID of filter parameters in parameter set", true, "FilterParams");
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(istd::CString, m_filterParamsIdAttrPtr);
};


} // namespace iipr


#endif // !iipr_CRectDerivativeProcessorComp_included


