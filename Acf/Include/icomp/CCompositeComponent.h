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


#ifndef icomp_CCompositeComponent_included
#define icomp_CCompositeComponent_included


// Qt includes
#include <QtCore/QByteArray>
#include <QtCore/QMap>

// ACF includes
#include "istd/CClassInfo.h"

#include "icomp/ICompositeComponent.h"
#include "icomp/IRegistry.h"
#include "icomp/IComponentContext.h"
#include "icomp/CInterfaceManipBase.h"


namespace icomp
{


class IMetaInfoManager;


class CCompositeComponent:
			public CInterfaceManipBase,
			virtual public ICompositeComponent
{
public:
	CCompositeComponent();
	virtual ~CCompositeComponent();

	/**
		Get interface implemented by this composite component.
	*/
	template <class InterfaceType>
	InterfaceType* GetComponentInterface(const QByteArray& subId = "");

	/**
		Make sure, all components with flag 'AutoInit' are initialized.
		\return	true, if there were components needed to be initialized.
	*/
	bool EnsureAutoInitComponentsCreated() const;

	// reimplemented (icomp::ICompositeComponent)
	virtual IComponent* GetSubcomponent(const QByteArray& componentId) const;
	virtual const IComponentContext* GetSubcomponentContext(const QByteArray& componentId) const;
	virtual IComponent* CreateSubcomponent(const QByteArray& componentId) const;
	virtual void OnSubcomponentDeleted(const IComponent* subcomponentPtr);

	// reimplemented (icomp::IComponent)
	virtual const ICompositeComponent* GetParentComponent(bool ownerOnly = false) const;
	virtual void* GetInterface(const istd::CClassInfo& interfaceType, const QByteArray& subId = "");
	virtual const IComponentContext* GetComponentContext() const;
	virtual void SetComponentContext(
				const icomp::IComponentContext* contextPtr,
				const ICompositeComponent* parentPtr,
				bool isParentOwner);

protected:
	typedef istd::TDelPtr<icomp::IComponent> ComponentPtr;
	typedef istd::TDelPtr<icomp::IComponentContext> ContextPtr;

	/**
		Create information objects and subcomponent.
		\param	componentId		ID of subcomponent.
		\param	subContextPtr	pointer to subcomponent context will be set to new context object if needed.
		\param	subComponentPtr	optional pointer to subcomponent will be set to new component object.
		\param	isOwned			true, if created component will be owned by this component and should delegate its destroy event.
		\return					true if success.
	*/
	bool CreateSubcomponentInfo(
				const QByteArray& componentId,
				ContextPtr& subContextPtr,
				ComponentPtr* subComponentPtr,
				bool isOwned) const;

private:
	struct ComponentInfo
	{
		ComponentInfo(): isComponentInitialized(false), isContextInitialized(false){}
		/**
			Pointer to component context for some component type.
		*/
		ComponentPtr componentPtr;
		/**
			Flag signaling we tried to create context of this component.
			It is used to avoid multiple initialization of component context.
		*/
		bool isComponentInitialized;
		/**
			Pointer to static component for some component type.
		*/
		ContextPtr contextPtr;
		/**
			Flag signaling we tried to create static component.
			It is used to avoid multiple initialization of component.
		*/
		bool isContextInitialized;
	};

	typedef QMap< QByteArray, ComponentInfo > ComponentMap;

	mutable ComponentMap m_componentMap;

	const IComponentContext* m_contextPtr;
	const ICompositeComponent* m_parentPtr;
	bool m_isParentOwner;

	mutable bool m_autoInitialized;
	mutable IRegistry::Ids m_autoInitComponentIds;
};


// inline methods

template <class InterfaceType>
inline InterfaceType* CCompositeComponent::GetComponentInterface(const QByteArray& subId)
{
	static istd::CClassInfo info(typeid(InterfaceType));

	return static_cast<InterfaceType*>(GetInterface(info, subId));
}


} // namespace icomp


#endif // !icomp_CCompositeComponent_included


