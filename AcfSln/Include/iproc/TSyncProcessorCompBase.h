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


#ifndef iproc_TSyncProcessorCompBase_included
#define iproc_TSyncProcessorCompBase_included


#include "ilog/TLoggerCompWrap.h"

#include "iproc/TSyncProcessorWrap.h"

#include "icomp/CComponentBase.h"


namespace iproc
{


/**
	Simple definition macro for a synchronous processor.
*/
template <class Base, class Interface = Base>
class TSyncProcessorCompBase:
			public ilog::CLoggerComponentBase,
			public iproc::TSyncProcessorWrap<Base>
{
public:
	typedef ilog::CLoggerComponentBase BaseClass;
	typedef iproc::TSyncProcessorWrap<Base> BaseClass2;
	typedef Interface InterfaceType;

	I_BEGIN_BASE_COMPONENT(TSyncProcessorCompBase);
		I_REGISTER_INTERFACE(Interface);
		I_REGISTER_INTERFACE(iproc::IProcessor);
	I_END_COMPONENT;
};


// global typedefs

typedef TSyncProcessorCompBase<IProcessor> CSyncProcessorCompBase;


} // namespace iproc


#endif // !iproc_TSyncProcessorCompBase_included

