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


#ifndef icomp_ICompositeComponent_included
#define icomp_ICompositeComponent_included


// ACF includes
#include <icomp/IComponent.h>


namespace icomp
{


/**
	Composite component interface.
	Composite component extends component funtionality providing manangement and access to subcomponents.
	Please note, that \c subId for icomp::IComponent::GetInterface will be associated with subcomponent for composed components.
	\ingroup ComponentConcept
*/
class ICompositeComponent: virtual public IComponent
{
public:
	/**
		Get access to subcomponent using its ID.
	*/
	virtual IComponent* GetSubcomponent(const QByteArray& componentId) const = 0;

	/**
		Get access to context of subcomponent using its ID.
		Please note, that this does'n create component instance.
	*/
	virtual const IComponentContext* GetSubcomponentContext(const QByteArray& componentId) const = 0;

	/**
		Create instance of subcomponent using its ID.
	*/
	virtual IComponent* CreateSubcomponent(const QByteArray& componentId) const = 0;

	/**
		Called if subcomponent is removed from memory.
		\param	subcomponentPtr	pointer to component beeing removed. It cannot be NULL.
	*/
	virtual void OnSubcomponentDeleted(const IComponent* subcomponentPtr) = 0;
};


} // namespace icomp


#endif // !icomp_ICompositeComponent_included


