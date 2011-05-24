/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef istd_IServicesProvider_included
#define istd_IServicesProvider_included


#include "istd/IPolymorphic.h"
#include "istd/CClassInfo.h"


namespace istd
{


/**
	Allow access to service implementation.
	This interface is used to provide cascade of service implementation distributed in several modules.
*/
class IServicesProvider: virtual public istd::IPolymorphic
{
public:
	/**
		Get pointer to service implementation.
		If implementation for specified ID is not available, it returns NULL.
	*/
	virtual void* GetService(const istd::CClassInfo& serviceId) const = 0;
	/**
		Create new service instance.
	*/
	virtual void* CreateService(const istd::CClassInfo& info) const = 0;
};


} // namespace istd


#endif // !istd_IServicesProvider_included


