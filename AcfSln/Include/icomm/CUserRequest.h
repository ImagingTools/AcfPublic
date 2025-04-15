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
#include <icomm/IRequest.h>


namespace icomm
{


/**
	This is simple implementation of icomm::IRequest interface.
	This implementation serialize slave object and is associated with icomm::CUserResponse class.
	Note: On both sides the same object type als slave must be connected!
	You can use it as base class for your own requsts implementation.
*/
class CUserRequest: public IRequest
{
public:
	/**
		Contructs request object with specified command and slave object.
		\param	command		command string. It is used to identify the request type on server side.
		\param	slavePtr	slave object will be serializated using request data.
							It cannot be NULL.
		\param	timeout		timeout of this request.
	*/
	CUserRequest(const QByteArray& command, ISerializable* slavePtr, double timeout = 3);

	// reimplemented (icomm::IRequest)
	virtual double GetTimeOut() const override;
	virtual QByteArray GetCommand() const override;
	virtual QString ExtractMessage(const CResponseHeader& header) const override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

private:
	QByteArray m_command;
	double m_timeOut;
	ISerializable* m_slavePtr;
};


} // namespace icomm


