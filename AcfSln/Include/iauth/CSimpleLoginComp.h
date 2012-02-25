/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iauth_CSimpleLoginComp_included
#define iauth_CSimpleLoginComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "iser/ISerializable.h"
#include "iser/CArchiveTag.h"


// ACF-Solutions includes
#include "imod/TModelWrap.h"
#include "iauth/ILogin.h"
#include "iauth/IRightsProvider.h"


namespace iauth
{


class CSimpleLoginComp:
			public icomp::CComponentBase,
			public ILogin,
			public IRightsProvider,
			public iser::ISerializable
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSimpleLoginComp);
		I_REGISTER_INTERFACE(ILogin);
		I_REGISTER_INTERFACE(IRightsProvider);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN_MULTI_0(m_userLevelsIfPtr, "UserLevels", "User levels", true);
		I_ASSIGN_MULTI_0(m_defaultUsersAttrPtr, "DefaultUsers", "DefaultUsers", false);
		I_ASSIGN_MULTI_0(m_defaultUserPasswordsAttrPtr, "DefaultUserPasswords", "DefaultUserPasswords", false);
		I_ASSIGN_MULTI_0(m_defaultUserLevelsAttrPtr, "DefaultUserLevels", "DefaultUserLevels", false);
	I_END_COMPONENT;

	struct User
	{
		QString name;
		QString password;
		int group;
	};

	CSimpleLoginComp();

	virtual int GetUsersCount() const;
	virtual User& GetUser(int index) const;
	virtual int FindUserIndex(const QString& name) const;
	virtual bool AddUser(const User& user);

	// reimplemented (iauth::ILogin)
	virtual bool IsUserLogged() const;
	virtual bool Login(const QString& userName, const QString& password);
	virtual bool Logout();

	// reimplemented (iauth::IRightsProvider)
	virtual bool HasRight(
					const std::string& operationId,
					bool beQuiet = false) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_MULTIREF(IRightsProvider, m_userLevelsIfPtr);
	I_MULTIATTR(QString, m_defaultUsersAttrPtr);
	I_MULTIATTR(QString, m_defaultUserPasswordsAttrPtr);
	I_MULTIATTR(int, m_defaultUserLevelsAttrPtr);

	typedef std::vector<User> Users;
	Users m_users;

	int m_loggedUserIndex;
};


} // namespace iauth


#endif // !iauth_CSimpleLoginComp_included


