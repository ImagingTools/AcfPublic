/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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


#include "iqtgui/CModelDialogGuiComp.h"


// Qt includes
#include <QIcon>


namespace iqtgui
{


// public methods

// reimplemented (iqtgui::IDialog)

void CModelDialogGuiComp::Execute()
{
	I_ASSERT(m_dataCompPtr.IsValid());
	I_ASSERT(m_modelCompPtr.IsValid());
	I_ASSERT(m_workingDataFactoryCompPtr.IsValid());
	I_ASSERT(m_workingModelFactoryCompPtr.IsValid());

	// create working model:
	if (!m_workingDataFactoryCompPtr.IsValid()){
		return;
	}

	istd::TDelPtr<iqtgui::CGuiComponentDialog> dialogPtr(CreateComponentDialog(QDialogButtonBox::Ok | QDialogButtonBox::Cancel));
	if (!dialogPtr.IsValid()){
		return;
	}

	bool orignalModelAttached = m_modelCompPtr->IsAttached(m_editorCompPtr.GetPtr());
	if (orignalModelAttached){
		m_modelCompPtr->DetachObserver(m_editorCompPtr.GetPtr());
	}

	m_workingDataPtr.SetPtr(m_workingDataFactoryCompPtr.CreateInstance());

	if (m_workingDataPtr.IsValid()){
		if (m_workingDataPtr->CopyFrom(*m_dataCompPtr.GetPtr())){
			imod::IModel* workingModelPtr = dynamic_cast<imod::IModel*>(m_workingDataPtr.GetPtr());
			I_ASSERT(workingModelPtr != NULL);
			if (workingModelPtr != NULL){
				bool isAttached = workingModelPtr->AttachObserver(m_editorCompPtr.GetPtr());
				if (isAttached){
					int retVal = dialogPtr->exec();

					if (retVal == QDialog::Accepted){
						m_dataCompPtr->CopyFrom(*m_workingDataPtr.GetPtr());
					}

					// re-attach the original data model to the editor:
					workingModelPtr->DetachObserver(m_editorCompPtr.GetPtr());

					if (orignalModelAttached){
						m_modelCompPtr->AttachObserver(m_editorCompPtr.GetPtr());
					}
				}
			}
		}
	}

	m_workingDataPtr.Reset();
}


} // namespace iqtgui


