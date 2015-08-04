/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include "iqt2d/CExtendedConsoleGuiComp.h"


namespace iqt2d
{


// protected methods

// reimplemented (CGuiComponentBase)

void CExtendedConsoleGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	if (m_viewProviderGuiCompPtr.IsValid()){
		m_viewProviderGuiCompPtr->CreateGui(ViewFrame);
	}

	if (m_toolBarCompPtr.IsValid()){
		m_toolBarCompPtr->CreateGui(CommandsFrame);

		if (*m_isFloatingToolbarAttr){
			CommandsFrame->setParent(ViewFrame);
			CommandsFrame->setFrameShape(QFrame::StyledPanel);
			CommandsFrame->setAutoFillBackground(true);
			CommandsFrame->setWindowFlags(Qt::FramelessWindowHint);
			CommandsFrame->setWindowOpacity(0.5);
		}
	}
	else
		CommandsFrame->hide();

	if (m_statusInfoGuiCompPtr.IsValid()){
		m_statusInfoGuiCompPtr->CreateGui(InfoFrame);
	}
	else
		InfoFrame->hide();
}


void CExtendedConsoleGuiComp::OnGuiDestroyed()
{
	if (m_viewProviderGuiCompPtr.IsValid()){
		m_viewProviderGuiCompPtr->DestroyGui();
	}

	if (m_toolBarCompPtr.IsValid()){
		m_toolBarCompPtr->DestroyGui();
	}

	if (m_statusInfoGuiCompPtr.IsValid()){
		m_statusInfoGuiCompPtr->DestroyGui();
	}

	BaseClass::OnGuiDestroyed();
}


// reimplemented (QObject)

bool CExtendedConsoleGuiComp::eventFilter(QObject* sourcePtr, QEvent* eventPtr)
{
	if (eventPtr->type() == QEvent::Resize || eventPtr->type() == QEvent::Show){
		if (CommandsFrame->isVisible() && *m_isFloatingToolbarAttr){
			CommandsFrame->adjustSize();
			CommandsFrame->setMaximumWidth(ViewFrame->width());
		}
	}

	return BaseClass::eventFilter(sourcePtr, eventPtr);
}


} // namespace iqt2d


