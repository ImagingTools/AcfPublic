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


#ifndef iauth_CUser_included
#define iauth_CUser_included


// ACF includes
#include "istd/CString.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iauth
{


class CUser
{
public:
	CUser(const istd::CString& userName = "", const istd::CString& password = "", int userGroup = 0);
	CUser(const CUser& user);

	/**
		Get name of user.
	*/
	const istd::CString& GetUserName() const;
	/**
		Set name of user.
		\return	true, if user name was accepted, or false if it is uncompatible with the user name guide lines.
	*/
	bool SetUserName(const istd::CString& name);
	/**
		Get group number this user belongs.
		\return number of group, or -1 if this user is disabled.
	*/
	int GetUserGroup() const;
	/**
		Set group number this user belongs.
		\param	group	group number, or -1 if this user is disabled.
	*/
	void SetUserGroup(int group);
	/**
		Get password of this user.
	*/
	const istd::CString& GetPassword() const;
	/**
		Set password of this user.
		\return	true, if password was accepted, or false if it is uncompatible with the password guide lines.
	*/
	bool SetPassword(const istd::CString& password);

	/**
		Check, if password is correct.
	*/
	bool CheckPassword(const istd::CString& password) const;
	/**
		Set password to be reset.
	*/
	void ResetPassword();

	bool Serialize(iser::IArchive& archive);

private:
	istd::CString m_userName;
	istd::CString m_password;
	int m_userGroup;
};


}	// namespace iauth


#endif //iauth_CUser_included



