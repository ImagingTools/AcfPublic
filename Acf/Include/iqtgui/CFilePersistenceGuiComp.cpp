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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtgui/CFilePersistenceGuiComp.h"


namespace iqtgui
{


// protected slots

void CFilePersistenceGuiComp::on_LoadButton_clicked()
{
	if (m_fileLoaderCompPtr.IsValid() && m_objectCompPtr.IsValid()){
		m_fileLoaderCompPtr->LoadFromFile(*m_objectCompPtr);
	}
}


void CFilePersistenceGuiComp::on_SaveButton_clicked()
{
	if (m_fileLoaderCompPtr.IsValid() && m_objectCompPtr.IsValid()){
		m_fileLoaderCompPtr->SaveToFile(*m_objectCompPtr);
	}
}


// protected methods

// reimplemented (iqtgui::CGuiComponentBase)

void CFilePersistenceGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	LoadButton->setVisible(*m_showLoadAttrPtr);
	SaveButton->setVisible(*m_showSaveAttrPtr);

	LoadButton->setEnabled(
				m_fileLoaderCompPtr.IsValid() &&
				m_objectCompPtr.IsValid() &&
				m_fileLoaderCompPtr->IsOperationSupported(m_objectCompPtr.GetPtr(), NULL, iser::IFileLoader::QF_NO_SAVING));
	SaveButton->setEnabled(
				m_fileLoaderCompPtr.IsValid() &&
				m_objectCompPtr.IsValid() &&
				m_fileLoaderCompPtr->IsOperationSupported(m_objectCompPtr.GetPtr(), NULL, iser::IFileLoader::QF_NO_LOADING));
}


} // namespace iqtgui


