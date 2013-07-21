/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "idoc/CDocumentManagerListenerComp.h"


#include "istd/TChangeNotifier.h"


namespace idoc
{		


// public methods

CDocumentManagerListenerComp::CDocumentManagerListenerComp()
	:m_currentDocumentModelPtr(NULL)
{
}


// reimplemented (imod::IModelSelection)

imod::IModel* CDocumentManagerListenerComp::GetSelectedModel() const
{
	return m_currentDocumentModelPtr;
}


void CDocumentManagerListenerComp::SetSelectedModel(imod::IModel* modelPtr)
{
	if (modelPtr != m_currentDocumentModelPtr){
		istd::CChangeNotifier changePtr(this);

		m_currentDocumentModelPtr = modelPtr;
	}
}


// reimplemented (imod::CSingleModelObserverBase)

void CDocumentManagerListenerComp::OnUpdate(int updateFlags, istd::IPolymorphic* /* updateParamsPtr*/)
{
	idoc::IDocumentManager* documentManagerPtr = GetObjectPtr();
	if (documentManagerPtr == NULL){
		m_currentDocumentModelPtr = NULL;
		return;
	}

	bool updateModel = 
				(updateFlags & IDocumentManager::CF_DOCUMENT_REMOVED) != 0 || 
				(updateFlags & IDocumentManager::CF_VIEW_ACTIVATION_CHANGED) != 0; 

	if (updateModel){
		istd::IChangeable* documentPtr = NULL;
		istd::IPolymorphic* activeViewPtr = documentManagerPtr->GetActiveView();

		if (activeViewPtr != NULL){
			documentPtr = documentManagerPtr->GetDocumentFromView(*activeViewPtr);
		}

		istd::IPolymorphic* modelSourcePtr = documentPtr;
		if (m_useModelFromViewAttrPtr.IsValid()  && *m_useModelFromViewAttrPtr){
			modelSourcePtr = activeViewPtr;
		}

		imod::IModel* newModelPtr = dynamic_cast<imod::IModel*>(modelSourcePtr);

		SetSelectedModel(newModelPtr);
	}
}


} // namespace idoc


