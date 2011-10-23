/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "icomp/CComponentBase.h"


#include "icomp/IComponentContext.h"
#include "icomp/IRegistryElement.h"
#include "icomp/CBaseComponentStaticInfo.h"


namespace icomp
{


CComponentBase::CComponentBase()
:	m_contextPtr(NULL), m_parentPtr(NULL), m_isParentOwner(false)
{
}


// reimplemented (icomp::IComponent)

const IComponent* CComponentBase::GetParentComponent(bool ownerOnly) const
{
	if (!ownerOnly || m_isParentOwner){
		return m_parentPtr;
	}

	return NULL;
}


void* CComponentBase::GetInterface(const istd::CClassInfo& interfaceType, const std::string& /*subId*/)
{
	if (!interfaceType.IsValid()){
		return this;
	}

	static istd::CClassInfo compInterfaceType(typeid(icomp::IComponent));

	if (m_contextPtr != NULL){
		if (interfaceType.IsVoid() || (interfaceType == compInterfaceType)){
			return static_cast<icomp::IComponent*>(this);
		}

		const IRealComponentStaticInfo& staticInfo = GetComponentStaticInfo();

		return staticInfo.GetComponentInterface(interfaceType, *this);
	}

	return NULL;
}


const IComponentContext* CComponentBase::GetComponentContext() const
{
	return m_contextPtr;
}


void CComponentBase::SetComponentContext(
			const icomp::IComponentContext* contextPtr,
			const IComponent* parentPtr,
			bool isParentOwner)
{
	m_contextPtr = contextPtr;
	m_parentPtr = parentPtr;
	m_isParentOwner = isParentOwner;
}


IComponent* CComponentBase::GetSubcomponent(const std::string& /*componentId*/) const
{
	return NULL;	// normal component has no subcomponents
}


const IComponentContext* CComponentBase::GetSubcomponentContext(const std::string& /*componentId*/) const
{
	return NULL;	// normal component has no subcomponents and also their contexts
}


IComponent* CComponentBase::CreateSubcomponent(const std::string& /*componentId*/) const
{
	return NULL;	// normal component cannot create subcomponents
}


void CComponentBase::OnSubcomponentDeleted(const IComponent* /*subcomponentPtr*/)
{
	// do nothing, real components has no subcomponents
}


// protected methods

void CComponentBase::OnComponentCreated()
{
	I_ASSERT(m_contextPtr != NULL);
}


void CComponentBase::OnComponentDestroyed()
{
	I_ASSERT(m_contextPtr != NULL);
}


// static methods

const icomp::IRealComponentStaticInfo& CComponentBase::InitStaticInfo(IComponent* /*componentPtr*/)
{
	static CBaseComponentStaticInfo emptyInfo;

	return emptyInfo;
}


} // namespace icomp


