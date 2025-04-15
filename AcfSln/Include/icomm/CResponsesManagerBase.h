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
#include <QtCore/QMap>

// ACF includes
#include <iser/IArchive.h>
#include <icomm/IResponsesManager.h>
#include <icomm/IResponse.h>


namespace icomm
{


/**
	This is base implementation of icomm::IResponsesManager interface.
	This is abstract class, to use it you have to implement abstract methods.
*/
class CResponsesManagerBase: public IResponsesManager
{
public:
	~CResponsesManagerBase();

	/**
		Remove all providers from this manager.
	*/
	virtual void Reset();

	/**
		This method should be called from end implementation when new message is received.
	*/
	virtual bool OnReceived(iser::IArchive& request, iser::IArchive& answer);

	// reimplemented (icomm::IResponsesManager)
	virtual void ConnectProvider(IResponse* providerPtr) override;
	virtual void DisconnectProvider(IResponse* providerPtr) override;

protected:
	typedef QMap<QByteArray, IResponse*> ProvidersMap;

	// abstract methods
	/**
		Send answer and clear archive to be ready for next operation.
	*/
	virtual bool SendAndClear(iser::IArchive& answer) = 0;

private:
	ProvidersMap m_providersMap;
};


} // namespace icomm


