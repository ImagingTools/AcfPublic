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

void CModelDialogGuiComp::ExecuteDialog(IGuiObject* parentPtr)
{
	if (!m_workingDataFactoryCompPtr.IsValid() || !m_workingModelFactoryCompPtr.IsValid()){
		return;
	}

	istd::IChangeable* sourceDataPtr = m_dataCompPtr.GetPtr();
	istd::IChangeable* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		sourceDataPtr = objectPtr;
	}

	if (sourceDataPtr == NULL){
		return;
	}

	istd::TDelPtr<iqtgui::CGuiComponentDialog> dialogPtr(CreateComponentDialog(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, parentPtr));
	if (!dialogPtr.IsValid()){
		return;
	}

	m_workingObjectPtr.SetPtr(m_workingDataFactoryCompPtr.CreateComponent());

	istd::IChangeable* workingDataPtr = m_workingDataFactoryCompPtr.ExtractInterface(m_workingObjectPtr.GetPtr());
	if (workingDataPtr != NULL){
		if (workingDataPtr->CopyFrom(*sourceDataPtr)){
			imod::IModel* workingModelPtr = m_workingModelFactoryCompPtr.ExtractInterface(m_workingObjectPtr.GetPtr());
			I_ASSERT(workingModelPtr != NULL);
			if (workingModelPtr != NULL){
				bool isAttached = workingModelPtr->AttachObserver(m_editorCompPtr.GetPtr());
				if (isAttached){
					int retVal = dialogPtr->exec();

					if (retVal == QDialog::Accepted){
						sourceDataPtr->CopyFrom(*workingDataPtr);
					}

					// re-attach the original data model to the editor:
					workingModelPtr->DetachObserver(m_editorCompPtr.GetPtr());
				}
			}
		}
	}

	m_workingObjectPtr.Reset();
}


} // namespace iqtgui


