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


// Qt includes
#include <QtCore/QVector>


#include <icomm/IServersManager.h>
#include <icomm/CHeartbeatAnswer.h>


namespace icomm
{


class IHeartbeatServersManager: public icomm::IServersManager
{
public:
	typedef QVector<icomm::CHeartbeatAnswer> FoundServers;

	/**
		Starts search function to find all accessible servers.
		\param	result	list of found servers.
	*/
	virtual bool FindServers(FoundServers& result) = 0;

	/**
		Gets CHeatbeatAnswer object.
		\param	index	the same index like in icomm::IServersManager::GetServerInfo method.
						\sa icomm::IServersManager
	*/
	virtual CHeartbeatAnswer& GetServerInfoImpl(int index) const = 0;

	/**
		Creates new server info object.
		\param	index		position in servers list.
							Server will be added on the end if it's negative.
		\param	copyFromIndex	If it is positive value, specified info object
								will be used as template.
		\return	index of server, or negative value if error.
	*/
	virtual int CreateServerInfo(int index = -1, int copyFromIndex = -1) = 0;

	/**
		Removes specified server info object.
	*/
	virtual bool RemoveServerInfo(int index) = 0;
};


} // namespace icomm


