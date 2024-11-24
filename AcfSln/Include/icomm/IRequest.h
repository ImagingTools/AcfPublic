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
#include <QtCore/QString>

// ACF includes
#include <iser/ISerializable.h>


namespace icomm
{


class CResponseHeader;


/**
	Request object used in client-server communication.
	Request object can be added to request container (\sa icomm::IRequestContainer).
	Please note, that serialization has other meaning for reading and storing archive.
	For storing it is request serialization, for reading it is response serialization.
	Every request must specify its time out value and unique request command.
*/
class IRequest: virtual public iser::ISerializable
{
public:
	/**
		It describes how long this request would be stored in container.
		Additionally there is 'keep alive' mechanism.
	*/
	virtual double GetTimeOut() const = 0;
	/**
		Get string ID of request command.
		This string must correspond to command ID on server side.
		Standard implementation is, that pair of classes for client and server
		(implementing icomm::IRequest and icomm::IResponse, respectively)
		have hard coded the same ID.
	*/
	virtual QByteArray GetCommand() const = 0;
	/**
		Get error message of response.
	*/
	virtual QString ExtractMessage(const CResponseHeader& header) const = 0;
};


} // namespace icomm


