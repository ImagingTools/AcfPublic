/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef icomp_TSimComponentsFactory_included
#define icomp_TSimComponentsFactory_included


#include "istd/TIFactory.h"
#include "istd/CClassInfo.h"

#include "icomp/IComponent.h"
#include "icomp/TComponentWrap.h"
#include "icomp/TSimComponentWrap.h"


namespace icomp
{


/**
	Simulation wrapper of component.
	It allows to use components directly from static linked libraries, without component framework.

	\ingroup ComponentConcept
*/
template <class Base>
class TSimComponentsFactory: public TSimComponentWrap<Base>, public istd::TIFactory<icomp::IComponent>
{
public:
	typedef TSimComponentWrap<Base> BaseClass;

	TSimComponentsFactory();

	// reimplemented (istd::IFactoryInfo)
	virtual istd::IFactoryInfo::KeyList GetFactoryKeys() const;

	// reimplemented (istd::TIFactory<icomp::IComponent>)
	virtual icomp::IComponent* CreateInstance(const std::string& keyId = "") const;

private:
	KeyList m_factoryKeys;
};


// public methods

template <class Base>
TSimComponentsFactory<Base>::TSimComponentsFactory()
{
	m_factoryKeys.push_back(istd::CClassInfo::GetName<Base>());
}


// reimplemented (istd::IFactoryInfo)

template <class Base>
istd::IFactoryInfo::KeyList TSimComponentsFactory<Base>::GetFactoryKeys() const
{
	return m_factoryKeys;
}


// reimplemented (istd::TIFactory<icomp::IComponent>)

template <class Base>
icomp::IComponent* TSimComponentsFactory<Base>::CreateInstance(const std::string& keyId) const
{
	if (keyId.empty() || (keyId == m_factoryKeys.back())){
		icomp::IComponent* retVal = new TComponentWrap<Base>();
		if (retVal != NULL){
			retVal->SetComponentContext(this, this, false);
			return retVal;
		}
	}

	return NULL;
}


}//namespace icomp


#endif // !icomp_TSimComponentsFactory_included


