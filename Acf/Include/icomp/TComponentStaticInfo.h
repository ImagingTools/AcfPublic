/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef icomp_TComponentStaticInfo_included
#define icomp_TComponentStaticInfo_included


// ACF includes
#include <icomp/TComponentWrap.h>
#include <icomp/CBaseComponentStaticInfo.h>


namespace icomp
{


template <class Component>
class TComponentStaticInfo: public CBaseComponentStaticInfo
{
public:
	typedef CBaseComponentStaticInfo BaseClass;

	explicit TComponentStaticInfo(const IRealComponentStaticInfo* baseComponentPtr = NULL);

	// reimplemented (icomp::IRealComponentStaticInfo)
	virtual IComponent* CreateComponent() const override;

	//	reimplemented (icomp::IComponentStaticInfo)
	virtual int GetComponentType() const override;
};


// public methods

template <class Component>
TComponentStaticInfo<Component>::TComponentStaticInfo(const IRealComponentStaticInfo* baseComponentPtr)
:	BaseClass(baseComponentPtr)
{
}


// reimplemented (icomp::IRealComponentStaticInfo)

template <class Component>
IComponent* TComponentStaticInfo<Component>::CreateComponent() const
{
	TComponentWrap<Component>* componentPtr = new TComponentWrap<Component>();

	return componentPtr;
}


//	reimplemented (icomp::IComponentStaticInfo)

template <class Component>
int TComponentStaticInfo<Component>::GetComponentType() const
{
	return CT_REAL;
}


} // namespace icomp


#endif // !icomp_TComponentStaticInfo_included


