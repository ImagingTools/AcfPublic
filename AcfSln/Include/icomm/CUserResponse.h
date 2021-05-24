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
#include <iser/IArchive.h>
#include <iser/ISerializable.h>
#include <icomm/IResponse.h>


namespace icomm
{


class IResponsesManager;


/**
	This is simple implementation of icomm::IResponse interface.
	This implementation serialize slave object and is associated with icomm::CUserRequest class.
	Note: On both sides the same object type als slave must be connected!
	You can use it as base class for your own response implementation.
*/
class CUserResponse: public IResponse
{
public:
	/**
		Contructs response object with specified command and slave object.
		\param	command		command string. It is used to identify the request type on server side.
		\param	slavePtr	slave object will be serializated using request data.
							It cannot be NULL.
	*/
	CUserResponse(const QByteArray& command, iser::ISerializable* slavePtr);

	// reimplemented (icomm::IResponse)
	virtual QByteArray GetCommand() const;
	virtual bool DoResponse(iser::IArchive& request, iser::IArchive& response);
	virtual bool OnAttached(IResponsesManager* managerPtr);
	virtual bool OnDetached(IResponsesManager* managerPtr);

private:
	QByteArray m_command;
	iser::ISerializable* m_slavePtr;
	IResponsesManager* m_managerPtr;
};


} // namespace icomm


