/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
#include <icomp/CComponentBase.h>
#include <imod/CMultiModelDispatcherBase.h>
#include <iauth/ILogin.h>


namespace iauth
{


/**
	Help wrapper for handling login events.
*/
template<class BaseComponent>
class TLoginStatusHandlerCompWrap:
			public BaseComponent,
			protected imod::CMultiModelDispatcherBase
{
public:
	typedef BaseComponent BaseClass;

	I_BEGIN_BASE_COMPONENT(TLoginStatusHandlerCompWrap);
		I_ASSIGN(m_userLoginCompPtr, "UserLogin", "Currently logged user", false, "UserLogin");
		I_ASSIGN_TO(m_userLoginModelCompPtr, m_userLoginCompPtr, false);
	I_END_COMPONENT;

protected:
	enum ModelId
	{
		MI_LOGIN = 1000
	};

	/**
		Handler for the user-login event.
		The default implementation does nothing.
	*/
	virtual void OnLogin();

	/**
		Handler for the user-logout event.
		The default implementation does nothing.
	*/
	virtual void OnLogout();

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed() override;

	// reimplemented (imod::CMultiModelDispatcherBase)
	virtual void OnModelChanged(int modelId, const istd::IChangeable::ChangeSet& changeSet);

private:
	I_REF(iauth::ILogin, m_userLoginCompPtr);
	I_REF(imod::IModel, m_userLoginModelCompPtr);
};


// protected methods

template <class BaseComponent>
void TLoginStatusHandlerCompWrap<BaseComponent>::OnLogin()
{
}


template <class BaseComponent>
void TLoginStatusHandlerCompWrap<BaseComponent>::OnLogout()
{
}


// reimplemented (icomp::CComponentBase)

template <class BaseComponent>
void TLoginStatusHandlerCompWrap<BaseComponent>::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_userLoginCompPtr.IsValid() && m_userLoginModelCompPtr.IsValid()){
		static const istd::IChangeable::ChangeSet relevantFlags(iauth::ILogin::CF_LOGIN, iauth::ILogin::CF_LOGOUT);

		RegisterModel(m_userLoginModelCompPtr.GetPtr(), MI_LOGIN, relevantFlags);
	}
}


template <class BaseComponent>
void TLoginStatusHandlerCompWrap<BaseComponent>::OnComponentDestroyed()
{
	UnregisterAllModels();

	BaseClass::OnComponentDestroyed();
}


// reimplemented (imod::CMultiModelDispatcherBase)

template <class BaseComponent>
void TLoginStatusHandlerCompWrap<BaseComponent>::OnModelChanged(int modelId, const istd::IChangeable::ChangeSet& changeSet)
{
	if (modelId == MI_LOGIN){
		if (changeSet.Contains(iauth::ILogin::CF_LOGIN)){
			OnLogin();
		}

		if (changeSet.Contains(iauth::ILogin::CF_LOGOUT)){
			OnLogout();
		}
	}
}


} // namespace iauth


