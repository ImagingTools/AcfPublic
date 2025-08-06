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


#include <iqtgui/CProgressGuiBridge.h>


namespace iqtgui
{


// public methods

CProgressGuiBridge::CProgressGuiBridge(QProgressBar* progressWidget, QAbstractButton* cancelButton)
:	m_progresBarPtr(progressWidget),
	m_cancelButtonPtr(cancelButton),
	m_lastProgressValue(0)
{
	if (m_cancelButtonPtr != NULL){
		connect(m_cancelButtonPtr, SIGNAL(clicked()), this, SLOT(OnCancelButtonClicked()));
	}

	if (m_progresBarPtr != NULL){
		m_progresBarPtr->setValue(0);

		connect(this, SIGNAL(ProgressChanged(int)), m_progresBarPtr, SLOT(setValue(int)), Qt::QueuedConnection);
	}
}


// protected methods

// reimplemented (ibase::CCumulatedProgressManagerBase)

void CProgressGuiBridge::OnProgressChanged(double cumulatedValue)
{
	int progressValue = int(cumulatedValue * 100);
	if (progressValue != m_lastProgressValue){
		m_lastProgressValue = progressValue;

		Q_EMIT ProgressChanged(progressValue);
	}
}


// protected slots

void CProgressGuiBridge::OnCancelButtonClicked()
{
	SetCanceled();
}


} // namespace iqtgui


