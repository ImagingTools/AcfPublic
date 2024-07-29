/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iqtgui/CProgressManagerGuiComp.h>


// Qt includes
#include <QtCore/QCoreApplication>


namespace iqtgui
{


// protected methods

// reimplemented (ibase::CCumulatedProgressManagerBase)

void CProgressManagerGuiComp::OnProgressChanged(double cumulatedValue)
{
	int pogressValue = 1000 * cumulatedValue;

	if (IsGuiCreated()) {
		ProgressBar->setValue(pogressValue);

		qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
	}
}


void CProgressManagerGuiComp::OnTasksChanged()
{
	QWidget* widgetPtr = GetWidget();
	if (widgetPtr != NULL) {
		if (*m_automaticHideAttrPtr) {
			auto openTasks = GetProcessedTasks();
			widgetPtr->setVisible(!openTasks.empty());
		}

		CancelButton->setEnabled(IsCancelable());

		qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CProgressManagerGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	int pogressValue = 1000 * GetCumulatedProgress();

	ProgressBar->setValue(pogressValue);

	if (m_descriptionAttrPtr.IsValid()){
		DescriptionLabel->setText(tr((*m_descriptionAttrPtr).toLocal8Bit()));
		DescriptionLabel->setVisible(true);
	}
	else{
		DescriptionLabel->setVisible(false);
	}

	CancelButton->setVisible(*m_showCancelAttrPtr);
}


// protected slots

void CProgressManagerGuiComp::on_CancelButton_clicked()
{
	SetCanceled();
}


} // namespace iqtgui


