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
#include <QtCore/QByteArray>

// ACF includes
#include <istd/IPolymorphic.h>
#include <iser/IArchive.h>


namespace icomm
{


class IResponsesManager;


/**
	This is common interface for all response objects.
	Response objects you can connect to response container,
	to provide response for associated request.
	\sa icomm::IRequest and icomm::IResponseContainer.
*/
class IResponse: virtual public istd::IPolymorphic
{
public:
	/**
		Identify the command which is provided through this response provider.
		All requests with this command will be serialized using this object.
	*/
	virtual QByteArray GetCommand() const = 0;

	/**
		Get response for specified input stream.
	*/
	virtual bool DoResponse(iser::IArchive& request, iser::IArchive& response) = 0;

	//	internal methods
	/**
		Internal method used to synchronize connection between IResponse and IResponsesManager.
		It called after manager method ConnectProvider is called.
		\sa	icomm::IResponsesManager.
		\return	true, if connection was successfull.
	*/
	virtual bool OnAttached(IResponsesManager* managerPtr) = 0;
	/**
		Internal method used to synchronize connection between IResponse and IResponsesManager.
		It called after manager method DisconnectProvider is called.
		\sa	icomm::IResponsesManager.
		\return	true, if disconnection was successfull.
	*/
	virtual bool OnDetached(IResponsesManager* managerPtr) = 0;
};


} // namespace icomm


