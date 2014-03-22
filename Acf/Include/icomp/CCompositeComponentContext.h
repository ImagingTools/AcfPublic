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


#ifndef icomp_CCompositeComponentContext_included
#define icomp_CCompositeComponentContext_included


#include "icomp/CComponentContext.h"


namespace icomp
{


class IRegistry;
class IRegistriesManager;
class IComponentEnvironmentManager;


class CCompositeComponentContext: public CComponentContext
{
public:
	typedef CComponentContext BaseClass;

	/**
		Constructor.
		\param	elementPtr				registry element object describing parameterisation of this composition treated as component.
										It can not be NULL.
		\param	registryPtr				data model object used by this composition.
										It can not be NULL.
		\param	registriesManagerPtr	registry manager allowing to access to registries if composite subelement is created.
		\param	parentPtr				pointer to parent object of this instance.
	*/
	CCompositeComponentContext(
				const IRegistryElement* elementPtr,
				const IComponentStaticInfo* staticInfoPtr,
				const IRegistry* registryPtr,
				const IComponentEnvironmentManager* environmentManagerPtr,
				const CCompositeComponentContext* parentPtr,
				const QByteArray& contextId);

	const IRegistry& GetRegistry() const;
	const IComponentEnvironmentManager& GetEnvironmentManager() const;

private:
	const IRegistry& m_registry;
	const IComponentEnvironmentManager& m_environmentManager;
};


// inline methods

inline const IRegistry& CCompositeComponentContext::GetRegistry() const
{
	return m_registry;
}


inline const IComponentEnvironmentManager& CCompositeComponentContext::GetEnvironmentManager() const
{
	return m_environmentManager;
}


} // namespace icomp


#endif // !icomp_CCompositeComponentContext_included


