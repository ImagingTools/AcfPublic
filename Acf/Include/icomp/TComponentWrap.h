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


#pragma once


// ACF includes
#include <icomp/IComponent.h>
#include <icomp/ICompositeComponent.h>
#include <icomp/IComponentContext.h>


namespace icomp
{


/**
	Wrapper of end component implementation used to correct control of component life-cycle.
*/
template <class Component>
class TComponentWrap: public Component
{
public:
	typedef Component BaseClass;

	TComponentWrap();
	virtual ~TComponentWrap();

	// pseudo-reimplemented (icomp::IComponent)
	virtual void SetComponentContext(
				const IComponentContextSharedPtr& contextPtr,
				const IComponent* parentPtr,
				bool isParentOwner) override;
};


// public methods

template <class Component>
TComponentWrap<Component>::TComponentWrap()
{
}


template <class Component>
TComponentWrap<Component>::~TComponentWrap()
{
	ICompositeComponent* parentPtr = const_cast<ICompositeComponent*>(dynamic_cast<const ICompositeComponent*>(BaseClass::GetParentComponent(true)));
	if (parentPtr != NULL){
		parentPtr->OnSubcomponentDeleted(this);
	}
	else {
		this->SetComponentContext(IComponentContextSharedPtr(), nullptr, false);
	}
}


// pseudo-reimplemented (icomp::IComponent)

template <class Component>
void TComponentWrap<Component>::SetComponentContext(
			const IComponentContextSharedPtr& contextPtr,
			const IComponent* parentPtr,
			bool isParentOwner)
{
	if (BaseClass::GetComponentContext() != nullptr){
		BaseClass::OnComponentDestroyed();

		BaseClass::InitStaticInfo(this);
	}

 	BaseClass::SetComponentContext(contextPtr, parentPtr, isParentOwner);

	if (contextPtr != nullptr){
		BaseClass::InitStaticInfo(this);

		BaseClass::OnComponentCreated();
	}
}


} // namespace icomp


