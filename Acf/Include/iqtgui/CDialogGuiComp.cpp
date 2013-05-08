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


#include "iqtgui/CDialogGuiComp.h"


// Qt includes
#include <QtGui/QIcon>
#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>


namespace iqtgui
{


// public methods

// reimplemented (iqtgui::IDialog)

void CDialogGuiComp::ExecuteDialog(IGuiObject* parentPtr)
{
	istd::TDelPtr<iqtgui::CGuiComponentDialog> dialogPtr(CreateComponentDialog(QDialogButtonBox::Close, parentPtr));
	if (dialogPtr.IsValid()){
		dialogPtr->exec();
	}
}


// reimpemented (ibase::ICommandsProvider)

const ibase::IHierarchicalCommand* CDialogGuiComp::GetCommands() const
{
	return &m_rootCommand;
}


// protected methods

iqtgui::CGuiComponentDialog* CDialogGuiComp::CreateComponentDialog(int buttons, IGuiObject* parentPtr) const
{
	istd::TDelPtr<iqtgui::CGuiComponentDialog> dialogPtr;

	if (m_guiCompPtr.IsValid()){
		QWidget* parentWidgetPtr = (parentPtr != NULL)? parentPtr->GetWidget(): NULL;

		dialogPtr.SetPtr(
					new iqtgui::CGuiComponentDialog(
								m_guiCompPtr.GetPtr(),
								buttons,
								true,
								parentWidgetPtr));

		if (m_dialogTitleAttrPtr.IsValid()){
			dialogPtr->setWindowTitle((*m_dialogTitleAttrPtr));
		}
		else{
			dialogPtr->setWindowTitle(QCoreApplication::applicationName());
		}

		if (m_dialogIconPathAttrPtr.IsValid()){
			dialogPtr->setWindowIcon(QIcon(*m_dialogIconPathAttrPtr));
		}
		else{
			dialogPtr->setWindowIcon(QApplication::windowIcon());
		}

		SetInitialDialogSize(*dialogPtr);
	}

	return dialogPtr.PopPtr();
}


// reimplemented (icomp::CComponentBase)

void CDialogGuiComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	m_rootMenuCommand.SetName(*m_rootMenuNameAttrPtr);
	m_dialogCommand.SetVisuals(*m_menuNameAttrPtr, *m_menuNameAttrPtr, *m_menuDescriptionAttrPtr);

	m_rootMenuCommand.InsertChild(&m_dialogCommand);
	m_rootCommand.InsertChild(&m_rootMenuCommand);

	connect(&m_dialogCommand, SIGNAL(triggered()), this, SLOT(OnCommandActivated()));
}


// protected slots

void CDialogGuiComp::OnCommandActivated()
{
	ExecuteDialog(NULL);
}


// private methods

void CDialogGuiComp::SetInitialDialogSize(QDialog& dialog) const
{
	if (m_initialDialogSizeAttrPtr.IsValid()){
		const QDesktopWidget* desktopPtr = QApplication::desktop();
		Q_ASSERT(desktopPtr != NULL);

		QRect screenRect = desktopPtr->screenGeometry();

		double screenFactor = qMin(0.99, *m_initialDialogSizeAttrPtr);

		dialog.resize(int(screenRect.width() * screenFactor), int(screenRect.height() * screenFactor));
	}
}


} // namespace iqtgui


