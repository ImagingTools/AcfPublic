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


#ifndef icomp_TInterfaceRegistrator_included
#define icomp_TInterfaceRegistrator_included


// ACF includes
#include "istd/CClassInfo.h"

#include "icomp/CBaseComponentStaticInfo.h"


namespace icomp
{


/**
	Simple helper class providing registration of template-specified interface.
*/
template <class Interface>
class TInterfaceRegistrator
{
public:
	TInterfaceRegistrator(CBaseComponentStaticInfo& staticInfo);

protected:
	static void* InterfaceExtractor(IComponent& component);
};


// public methods

template <class Interface>
TInterfaceRegistrator<Interface>::TInterfaceRegistrator(CBaseComponentStaticInfo& staticInfo)
{
	istd::CClassInfo info = istd::CClassInfo::GetInfo<Interface>();

	if (!info.IsVoid()){
		staticInfo.RegisterInterfaceExtractor(info.GetName(), TInterfaceRegistrator<Interface>::InterfaceExtractor);
	}
}


template <>
inline TInterfaceRegistrator<void>::TInterfaceRegistrator(CBaseComponentStaticInfo& /*staticInfo*/)
{
}


// protected methods

template <class Interface>
void* TInterfaceRegistrator<Interface>::InterfaceExtractor(IComponent& component)
{
	void* retVal = dynamic_cast<Interface*>(&component);

	return retVal;
}


template <>
inline void* TInterfaceRegistrator<void>::InterfaceExtractor(IComponent& /*component*/)
{
	return NULL;
}


} // namespace icomp


#endif // !icomp_TInterfaceRegistrator_included


