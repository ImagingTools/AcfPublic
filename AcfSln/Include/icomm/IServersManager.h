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
#include <iser/ISerializable.h>
#include <icomm/IServerInfo.h>


namespace icomm
{


/**
	Server manager on the client side.
*/
class IServersManager: virtual public iser::ISerializable
{
public:
	/**
		Gets number of servers data stored in this manager.
	*/
	virtual int GetServersCount() const = 0;

	/**
		Gets server information for specified server.
	*/
	virtual const IServerInfo& GetServerInfo(int index) const = 0;
};


} // namespace icomm


