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
#include <istd/IPolymorphic.h>


namespace icomm
{


class IResponse;


/**
	Server side component, which provide managment of answer to client requests.
	\sa icomm::IRequestManager, icomm::IResponse
*/
class IResponsesManager: virtual public istd::IPolymorphic
{
public:
	/**
		Connect response provider to manager.
		\param	providerPtr	a pointer to connected response provider. It cannot be NULL.
	*/
	virtual void ConnectProvider(IResponse* providerPtr) = 0;

	/**
		Disconnect response provider from manager.
		\param	providerPtr	a pointer to disconnected response provider.
		Disconnected response provider must be previous connected to this manager and this pointer cannot be NULL.
	*/
	virtual void DisconnectProvider(IResponse* providerPtr) = 0;
};


} // namespace icomm


