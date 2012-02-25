/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iqtex/CTcpTerminalGuiComp.h"


// QT includes
#include <QUrl>


namespace iqtex
{


CTcpTerminalGuiComp::CTcpTerminalGuiComp()
:	m_connectedIcon(":/Icons/StateOk.svg"),
	m_disconnectedIcon(":/Icons/StateInvalid.svg")
{
	QObject::connect(&m_connectTimer, SIGNAL(timeout()), this, SLOT(OnConectTimer()));
	QObject::connect(&m_socket, SIGNAL(readyRead()), this, SLOT(OnReadyRead()));
	QObject::connect(
				&m_socket,
				SIGNAL(stateChanged(QAbstractSocket::SocketState)),
				this,
				SLOT(OnStateChanged(QAbstractSocket::SocketState)));
}


// protected methods

void CTcpTerminalGuiComp::UpdateStateIcon()
{
	if (IsGuiCreated()){
		SendButton->setIcon(m_socket.state() == QAbstractSocket::ConnectedState? m_connectedIcon: m_disconnectedIcon);
	}
}

// reimplemented (iqtgui::CGuiComponentBase)

void CTcpTerminalGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	int presetsCount = m_presetTextsAttrPtr.GetCount();
	for (int i = 0; i < presetsCount; ++i){
		CommandCB->addItem(m_presetTextsAttrPtr[i]);
	}

	UpdateStateIcon();
}


// reimplemented (imod::CSingleModelObserverBase)

void CTcpTerminalGuiComp::OnUpdate(int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	m_socket.disconnectFromHost();
	m_socket.waitForDisconnected();

	OnConectTimer();

	m_connectTimer.start(1000);
}


// reimplemented (icomp::CComponentBase)

void CTcpTerminalGuiComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_urlParamModelCompPtr.IsValid()){
		m_urlParamModelCompPtr->AttachObserver(this);
	}
	else{
		OnUpdate(0, NULL);
	}
}


void CTcpTerminalGuiComp::OnComponentDestroyed()
{
	m_socket.disconnectFromHost();

	imod::CSingleModelObserverBase::EnsureModelDetached();

	BaseClass::OnComponentDestroyed();
}


// protected slots

void CTcpTerminalGuiComp::on_SendButton_clicked()
{
	QString command = CommandCB->currentText();

	m_socket.write((command + "\n").toAscii());

	QTreeWidgetItem* lineItemPtr = new QTreeWidgetItem(SentList);
	lineItemPtr->setText(0, command);
}


void CTcpTerminalGuiComp::on_ClearSentListButton_clicked()
{
	SentList->clear();
}


void CTcpTerminalGuiComp::on_ClearReceivedListButton_clicked()
{
	ReceivedList->clear();
}


void CTcpTerminalGuiComp::OnReadyRead()
{
	while (m_socket.canReadLine()){
		QString line = m_socket.readLine(1024);

		QTreeWidgetItem* lineItemPtr = new QTreeWidgetItem(ReceivedList);
		lineItemPtr->setText(0, line);
	}
}


void CTcpTerminalGuiComp::OnConectTimer()
{
	if (m_urlParamCompPtr.IsValid()){
		QString urlString = m_urlParamCompPtr->GetPath();
		QUrl url(urlString);

		m_socket.connectToHost(url.host(), url.port());
	}
}


void CTcpTerminalGuiComp::OnStateChanged(QAbstractSocket::SocketState socketState)
{
	if (socketState == QAbstractSocket::ConnectedState){
		m_connectTimer.stop();
	}

	if (socketState == QAbstractSocket::UnconnectedState){
		m_connectTimer.start(2000);
	}

	UpdateStateIcon();
}


} // namespace iqtex


