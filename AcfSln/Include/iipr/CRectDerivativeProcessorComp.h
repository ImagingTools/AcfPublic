/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_CRectDerivativeProcessorComp_included
#define iipr_CRectDerivativeProcessorComp_included


#include <QtCore/QString>

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
	I_ATTR(QByteArray, m_filterParamsIdAttrPtr);
};


} // namespace iipr


#endif // !iipr_CRectDerivativeProcessorComp_included


