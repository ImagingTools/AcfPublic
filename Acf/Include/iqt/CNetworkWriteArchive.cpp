/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CNetworkWriteArchive.h"


// Qt includes
#include <QAuthenticator>


namespace iqt
{


CNetworkWriteArchive::CNetworkWriteArchive(
			const QString& hostAddress,
			int port,
			const QString& userName,
			const QString& password,
			const iser::IVersionInfo* versionInfoPtr,
			bool serializeHeader)
	:BaseClass(versionInfoPtr, serializeHeader),
	m_userName(userName),
	m_password(password)
{
	m_socket.connectToHost(hostAddress, port);

	m_socket.waitForConnected();

	connect(
				&m_socket,
				SIGNAL(proxyAuthenticationRequired(const QNetworkProxy&, QAuthenticator*)),
				this,
				SLOT(OnAuthentificationtRequired(const QNetworkProxy&, QAuthenticator*)));
}


CNetworkWriteArchive::~CNetworkWriteArchive()
{
	Flush();

	m_socket.disconnectFromHost();
	
	m_socket.waitForDisconnected();
}


bool CNetworkWriteArchive::Flush()
{
	if (m_socket.state() != QAbstractSocket::ConnectedState){
		return false;
	}

	QDataStream dataStream(&m_socket);

	dataStream << int(GetBufferSize());

	int written = dataStream.writeRawData(reinterpret_cast<const char*>(GetBuffer()), GetBufferSize());
	if (written != GetBufferSize()){
		return false;
	}
	
	if (!m_socket.flush()){
		return false;
	}
	
	return m_socket.waitForBytesWritten();
}


// reimplemented (iser::IArchive)

bool CNetworkWriteArchive::ProcessData(void* dataPtr, int size)
{
	if (m_socket.state() != QAbstractSocket::ConnectedState){
		return false;
	}

	return BaseClass::ProcessData(dataPtr, size);
}


// private slots

void CNetworkWriteArchive::OnAuthentificationtRequired(const QNetworkProxy&/* proxy*/, QAuthenticator* authenticator) const
{
	if (authenticator != NULL){
		authenticator->setUser(m_userName);
		authenticator->setPassword(m_password);
	}
}


} // namespace iqt


