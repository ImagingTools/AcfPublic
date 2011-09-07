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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtproc/CProgressManagerGuiComp.h"


// Qt includes
#include <QCoreApplication>


namespace iqtproc
{


CProgressManagerGuiComp::CProgressManagerGuiComp()
:	m_isCanceled(false),
	m_isCancelable(false)
{
}


// protected methods

void CProgressManagerGuiComp::UpdateVisibleComponents()
{
	QWidget* widgetPtr = GetWidget();
	if (widgetPtr != NULL){
		if (*m_automaticHideAttrPtr){
			widgetPtr->setVisible(GetOpenSessionsCount() > 0);
		}

		m_isCancelable = m_isCancelable && !m_isCanceled;
		CancelButton->setEnabled(m_isCancelable);

		UpdateProgressBar();
	}
}


void CProgressManagerGuiComp::UpdateProgressBar()
{
	if (GetOpenSessionsCount() == 0){
		ProgressBar->setValue(0);
		ProgressBar->setEnabled(false);
	}
	else{
		ProgressBar->setValue(1000 * GetCumulatedProgress());
		ProgressBar->setEnabled(true);
	}
}


// reimplemented (iproc::CDelegatedProgressManager)

void CProgressManagerGuiComp::OnCancelable(bool cancelState)
{
	m_isCancelable = cancelState && *m_showCancelAttrPtr;

	CancelButton->setVisible(m_isCancelable);
}


// reimplemented (iproc::IProgressManager)

int CProgressManagerGuiComp::BeginProgressSession(
			const std::string& progressId,
			const istd::CString& description,
			bool isCancelable)
{
	if (GetOpenSessionsCount() <= 0){
		m_isCanceled = false;
	}
	else if (m_isCanceled){
		return -1;
	}

	return BaseClass2::BeginProgressSession(progressId, description, isCancelable);
}


bool CProgressManagerGuiComp::IsCanceled(int sessionId) const
{
	if (m_isCanceled){
		return true;
	}

	if (m_isCancelable){
		QCoreApplication::processEvents();
	}

	return BaseClass2::IsCanceled(sessionId);
}


// reimplemented (istd::IChangeable)

void CProgressManagerGuiComp::OnEndChanges(int changeFlags, istd::IPolymorphic* /*changeParamsPtr*/)
{
	if ((changeFlags & CF_SESSIONS_NUMBER) != 0){
		UpdateVisibleComponents();
	}

	if ((changeFlags & CF_PROGRESS_CHANGED) != 0){
		UpdateProgressBar();
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CProgressManagerGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	if (m_descriptionAttrPtr.IsValid()){
		DescriptionLabel->setText(tr((*m_descriptionAttrPtr).ToString().c_str()));
		DescriptionLabel->setVisible(true);
	}
	else{
		DescriptionLabel->setVisible(false);
	}

	CancelButton->setVisible(false);

	UpdateVisibleComponents();
}


// protected slots

void CProgressManagerGuiComp::on_CancelButton_clicked()
{
	m_isCanceled = true;

	UpdateVisibleComponents();
}


} // namespace iqtproc


