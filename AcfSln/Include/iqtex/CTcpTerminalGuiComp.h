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


#ifndef iqtex_CTcpTerminalGuiComp_included
#define iqtex_CTcpTerminalGuiComp_included


// Qt includes
#include <QtCore/QTimer>
#include <QtNetwork/QTcpSocket>

// ACF includes
#include <imod/IModel.h>
#include <imod/CSingleModelObserverBase.h>
#include <ifile/IFileNameParam.h>
#include <iqtgui/TDesignerGuiCompBase.h>

#include <GeneratedFiles/iqtex/ui_CTcpTerminalGuiComp.h>


namespace iqtex
{


/**
	Implementation of simple TCP terminal.
*/
class CTcpTerminalGuiComp:
			public iqtgui::TDesignerGuiCompBase<Ui::CTcpTerminalGuiComp>,
			protected imod::CSingleModelObserverBase
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiCompBase<Ui::CTcpTerminalGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CTcpTerminalGuiComp);
		I_ASSIGN(m_urlParamCompPtr, "UrlParam", "URL parameter used to find out address and socket for TCP connection", true, "UrlParam");
		I_ASSIGN_TO(m_urlParamModelCompPtr, m_urlParamCompPtr, false);
		I_ASSIGN_MULTI_0(m_presetTextsAttrPtr, "PresetTexts", "Set of preset texts", false);
	I_END_COMPONENT;

	CTcpTerminalGuiComp();

protected:
	void UpdateStateIcon();

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated() override;

	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed() override;

protected slots:
	void on_SendButton_clicked();
	void on_ClearSentListButton_clicked();
	void on_ClearReceivedListButton_clicked();
	void OnReadyRead();
	void OnConectTimer();
	void OnStateChanged(QAbstractSocket::SocketState socketState);

private:
	I_REF(ifile::IFileNameParam, m_urlParamCompPtr);
	I_REF(imod::IModel, m_urlParamModelCompPtr);
	I_MULTIATTR(QString, m_presetTextsAttrPtr);

	QTimer m_connectTimer;
	QTcpSocket m_socket;

	QIcon m_connectedIcon;
	QIcon m_disconnectedIcon;
};


} // namespace iqtex


#endif // !iqtex_CTcpTerminalGuiComp_included


