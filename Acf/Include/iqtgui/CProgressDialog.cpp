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


#include <iqtgui/CProgressDialog.h>


namespace iqtgui
{


// public methods

CProgressDialog::CProgressDialog(const QString& description, const QString& defaultText, QWidget* parentWidget)
:	BaseClass(parentWidget),
	m_lastTaskText(defaultText),
	m_lastProgressValue(0)
{
	setAutoClose(true);
	setMaximum(100);
	setMinimum(0);
	setWindowModality(Qt::WindowModal);
	setWindowTitle(description);
	setLabelText(defaultText);

	connect(this, SIGNAL(TaskTextChanged(QString)), this, SLOT(setLabelText(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(ProgressChanged(int)), this, SLOT(setValue(int)), Qt::QueuedConnection);
}


// protected methods

// reimplemented (ibase::CCumulatedProgressManagerBase)

void CProgressDialog::OnProgressChanged(double cumulatedValue)
{
	int progressValue = int(cumulatedValue * 100);
	if (progressValue != m_lastProgressValue){
		m_lastProgressValue = progressValue;

		Q_EMIT ProgressChanged(progressValue);
	}
}


void CProgressDialog::OnTasksChanged()
{
	QString taskName;
	auto tasksInfo = GetProcessedTasks(true, 1);
	if (!tasksInfo.empty()){
		taskName = tasksInfo[0].description;
	}

	if (taskName != m_lastTaskText){
		m_lastTaskText = taskName;

		Q_EMIT TaskTextChanged(taskName);
	}
}


} // namespace iqtgui


