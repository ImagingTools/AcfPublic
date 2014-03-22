/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_CInstantiatorComp_included
#define ibase_CInstantiatorComp_included


#include "icomp/CComponentBase.h"


namespace ibase
{


/**
	This help component simply instantiate a set of dependent components during its instantiation.
	\deprecated
*/
class CInstantiatorComp: public icomp::CComponentBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CInstantiatorComp);
		I_ASSIGN_MULTI_0(m_instancesAttrPtr, "Instances", "List of instances will be created during instantiator is created", false);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_MULTIREF(istd::IPolymorphic, m_instancesAttrPtr);
};


} // namespace ibase


#endif // !ibase_CInstantiatorComp_included


