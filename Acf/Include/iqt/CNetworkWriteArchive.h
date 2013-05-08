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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt_CNetworkWriteArchive_included
#define iqt_CNetworkWriteArchive_included


// Qt includes
#include <QtCore/QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>

// ACF includes
#include "iser/CMemoryWriteArchive.h"

#include "iqt/iqt.h"


namespace iqt
{


class CNetworkWriteArchive:
			public QObject,
			public iser::CMemoryWriteArchive
{
	Q_OBJECT

public:
	typedef iser::CMemoryWriteArchive BaseClass;

	CNetworkWriteArchive(
				const QString& hostAddress,
				int port,
				const QString& userName = QString(),
				const QString& password = QString(),
				const iser::IVersionInfo* versionInfoPtr = NULL,
				bool serializeHeader = true);

	~CNetworkWriteArchive();

	virtual bool Flush();

	// reimplemented (iser::IArchive)
	virtual bool ProcessData(void* dataPtr, int size);
	
private Q_SLOTS:
	void OnAuthentificationtRequired(const QNetworkProxy& proxy, QAuthenticator* authenticator) const;

private:
	QTcpSocket m_socket;
	QString m_userName;
	QString m_password;
};


} // namespace iqt


#endif // !iqt_CNetworkWriteArchive_included


