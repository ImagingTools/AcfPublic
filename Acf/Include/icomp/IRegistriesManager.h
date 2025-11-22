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


#pragma once


// Qt includes
#include <QtCore/QByteArray>

// ACF includes
#include <icomp/IComponentListProvider.h>


namespace icomp
{


class IRegistry;


/**
	Allow access to registries defined by composed components.
*/
class IRegistriesManager: virtual public IComponentListProvider
{
public:
	/**
		Get access to stored registry.
		\param	address		adress of registry treated as composed component.
		\return				registry object or NULL if specified composite component is not registered.
	*/
	virtual const IRegistry* GetRegistry(const CComponentAddress& address, const IRegistry* contextRegistryPtr = NULL) const = 0;
};


} // namespace icomp


