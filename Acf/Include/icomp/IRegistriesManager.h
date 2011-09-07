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


#ifndef icomp_IRegistriesManager_included
#define icomp_IRegistriesManager_included


#include <string>

#include "istd/istd.h"
#include "istd/IChangeable.h"
#include "istd/CString.h"


namespace icomp
{


class IRegistry;
class CComponentAddress;


class IRegistriesManager: virtual public istd::IChangeable
{
public:
	/**
		Get access to stored registry.
		\param	address		adress of registry treated as composed component.
		\return				registry object or NULL if specified composite component is not registered.
	*/
	virtual const IRegistry* GetRegistry(const CComponentAddress& address, const IRegistry* contextRegistryPtr = NULL) const = 0;
	/**
		Get directory path of specified component package.
		\param	packageId	ID of component package.
		\return				package dir path or empty string if specified package is not registered.
	*/
	virtual istd::CString GetPackageDirPath(const std::string& packageId) const = 0;
};


}//namespace icomp


#endif // !icomp_IRegistriesManager_included


