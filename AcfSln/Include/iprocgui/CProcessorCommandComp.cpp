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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iprocgui/CProcessorCommandComp.h"


// Qt includes
#include<QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMessageBox>
#else
#include <QtGui/QMessageBox>
#endif

// ACF includes
#include "iprm/IOptionsList.h"


namespace iprocgui
{


// public methods

CProcessorCommandComp::CProcessorCommandComp()
	:m_processingCommand("", 100, ibase::ICommand::CF_GLOBAL_MENU | ibase::ICommand::CF_TOOLBAR)
{
}


// reimpemented (ibase::ICommandsProvider)

const ibase::IHierarchicalCommand* CProcessorCommandComp::GetCommands() const
{
	return &m_rootMenuCommand;
}


// reimpemented (icomp::IComponent)

void CProcessorCommandComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	m_mainMenuCommand.SetName(*m_rootMenuNameAttrPtr);
	m_processingCommand.SetVisuals(*m_menuNameAttrPtr, *m_menuNameAttrPtr, *m_menuDescriptionAttrPtr, QIcon(*m_actionIconAttrPtr));

	m_rootMenuCommand.InsertChild(&m_mainMenuCommand);
	m_mainMenuCommand.InsertChild(&m_processingCommand);

	m_processingCommand.setVisible(m_processorCompPtr.IsValid());

	connect(&m_processingCommand, SIGNAL(triggered()), this, SLOT(OnCommandActivated()));
}


// protected methods

// private slots

void CProcessorCommandComp::OnCommandActivated()
{
	Q_ASSERT(m_processorCompPtr.IsValid());

	int processingState = m_processorCompPtr->DoProcessing(
				m_processorParamsCompPtr.GetPtr(),
				m_processorInputCompPtr.GetPtr(),
				m_processorOutputCompPtr.GetPtr(),
				m_progressManagerCompPtr.GetPtr());

	QString finishMessage;

	switch (processingState){
	case iproc::IProcessor::TS_OK:
		finishMessage = m_successMessageAttrPtr.IsValid()? *m_successMessageAttrPtr: QString();
		if (!finishMessage.isEmpty()){
			QMessageBox::information(NULL, "", finishMessage);
		}
		break;

	case iproc::IProcessor::TS_INVALID:
		finishMessage = m_errorMessageAttrPtr.IsValid() ? *m_errorMessageAttrPtr : QString();
		if (!finishMessage.isEmpty()){
			QMessageBox::critical(NULL, "", finishMessage);
		}
		break;

	case iproc::IProcessor::TS_CANCELED:
		finishMessage = m_cancelMessageAttrPtr.IsValid() ? *m_cancelMessageAttrPtr: QString();
		if (!finishMessage.isEmpty()){
			QMessageBox::information(NULL, "", finishMessage);
		}
		break;

	default:
		break;
	}
}


} // namespace iprocgui


