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


#ifndef AuthorizationPckPck_included
#define AuthorizationPckPck_included


// ACF includes
#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

// ACF-Solutions includes
#include "iauth/CStaticRightsProviderComp.h"
#include "iauth/CUserLoginComp.h"
#include "iauth/CSimpleLoginComp.h"
#include "iauth/CUsersManagerComp.h"


/**
	Package for security and authorization components.
*/
namespace AuthorizationPck
{


typedef iauth::CStaticRightsProviderComp StaticRightsProvider;
typedef icomp::TModelCompWrap<iauth::CUserLoginComp> UserLogin;
typedef icomp::TModelCompWrap<iauth::CSimpleLoginComp> SimpleLogin;
typedef icomp::TModelCompWrap<iauth::CUsersManagerComp> UsersManager;


} // namespace AuthorizationPck


#endif // !AuthorizationPckPck_included


