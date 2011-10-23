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


#ifndef icomp_TSimComponentWrap_included
#define icomp_TSimComponentWrap_included


// ACF includes
#include "icomp/TComponentWrap.h"
#include "icomp/CSimComponentContextBase.h"


namespace icomp
{


/**
	Simulation wrapper of component.
	It allows to use components directly from static linked libraries, without component framework.

	\ingroup ComponentConcept
*/
template <class Base>
class TSimComponentWrap: public TComponentWrap<Base>, public CSimComponentContextBase
{
public:
	typedef TComponentWrap<Base> BaseClass;
	typedef CSimComponentContextBase BaseClass2;

	TSimComponentWrap();

	/**
		Initialilze component after setting all its attributes and references.
	*/
	void InitComponent();

	// pseudo-reimplemented (icomp::IComponent)
	virtual const IComponent* GetParentComponent(bool ownerOnly = false) const;
	virtual IComponent* GetSubcomponent(const std::string& componentId) const;
	virtual IComponent* CreateSubcomponent(const std::string& componentId) const;
};


// public methods

template <class Base>
TSimComponentWrap<Base>::TSimComponentWrap()
:	BaseClass(),
	BaseClass2(&BaseClass::GetComponentStaticInfo())
{
}


template <class Base>
void TSimComponentWrap<Base>::InitComponent()
{
	SetComponentContext(this, NULL, false);
}


// pseudo-reimplemented (icomp::IComponent)

template <class Base>
const IComponent* TSimComponentWrap<Base>::GetParentComponent(bool ownerOnly) const
{
	if (ownerOnly){
		return NULL;
	}
	else{
		return const_cast<TSimComponentWrap<Base>* >(this);
	}
}


template <class Base>
IComponent* TSimComponentWrap<Base>::GetSubcomponent(const std::string& componentId) const
{
	BaseClass2::ComponentsMap::const_iterator iter = BaseClass2::m_componentsMap.find(componentId);

	if (iter != BaseClass2::m_componentsMap.end()){
		return iter->second;
	}

	return NULL;
}


template <class Base>
IComponent* TSimComponentWrap<Base>::CreateSubcomponent(const std::string& componentId) const
{
	FactoriesMap::const_iterator iter = m_factoriesMap.find(componentId);
	if (iter != m_factoriesMap.end()){
		I_ASSERT(iter->second != NULL);

		return iter->second->CreateInstance();
	}

	return NULL;
}


} // namespace icomp


#endif // !icomp_TSimComponentWrap_included


