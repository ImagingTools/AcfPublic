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


#ifndef iauth_ILogin_included
#define iauth_ILogin_included


// ACF includes
#include "istd/IPolymorphic.h"
#include <QString>


namespace iauth
{


/*
	Interface supporting login operation.
*/
class ILogin: virtual public istd::IPolymorphic
{
public:
	/**
		Check, if any user is logged to the system.
	*/
	virtual bool IsUserLogged() const = 0;
	/**
		Log in user.
		\return	true, if user is accepted.
	*/
	virtual bool Login(const QString& userName, const QString& password) = 0;
	/**
		Log in user.
		\return	true, if logout successful.
	*/
	virtual bool Logout() = 0;
};


} // namespace iauth


#endif // !iauth_ILogin_included
