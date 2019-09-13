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
	:m_progresBarPtr(progressWidget),
	m_cancelButtonPtr(cancelButton),
	m_isCanceled(false)
{
	if (m_cancelButtonPtr != NULL){
		connect(m_cancelButtonPtr, SIGNAL(clicked()), this, SLOT(OnCancelButtonClicked()));
	}
}


// reimplemented (ibase::IProgressManager)

int CProgressGuiBridge::BeginProgressSession(
			const QByteArray& /*progressId*/,
			const QString& /*description*/,
			bool /*isCancelable*/)
{
	return 0;
}


void CProgressGuiBridge::EndProgressSession(int /*sessionId*/)
{
	if (m_progresBarPtr != NULL){
		m_progresBarPtr->setValue(0);
	}
}


void CProgressGuiBridge::OnProgress(int /*sessionId*/, double currentProgress)
{
	if (m_progresBarPtr != NULL){
		m_progresBarPtr->setValue(currentProgress * 100);
	}
}


bool CProgressGuiBridge::IsCanceled(int /*sessionId*/) const
{
	return m_isCanceled;
}


// protected slots

void CProgressGuiBridge::OnCancelButtonClicked()
{
	m_isCanceled = true;
}


} // namespace iqtgui


