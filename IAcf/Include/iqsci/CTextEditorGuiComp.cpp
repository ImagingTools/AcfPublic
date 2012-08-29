/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iqsci/CTextEditorGuiComp.h"


namespace iqsci
{


// reimplemented (imod::IModelEditor)

void CTextEditorGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());

	ibase::ITextDocument* objectPtr = GetObjectPtr();
	I_ASSERT(objectPtr != NULL);

	CTextEditor* textEditPtr = GetQtWidget();
	I_ASSERT(textEditPtr != NULL);

	objectPtr->SetText(textEditPtr->GetText());
}


// reimplemented (iqtgui::TGuiObserverWrap)

void CTextEditorGuiComp::UpdateGui(int /*updateFlags*/)
{
	CTextEditor* textEditPtr = GetQtWidget();
	I_ASSERT(textEditPtr != NULL);

	ibase::ITextDocument* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		textEditPtr->SetText(objectPtr->GetText());
	}
}


void CTextEditorGuiComp::OnGuiModelDetached()
{
	CTextEditor* textEditPtr = GetQtWidget();
	I_ASSERT(textEditPtr != NULL);

	textEditPtr->SetText(QString());

	BaseClass::OnGuiModelDetached();
}


// reimplemented (ibase::ICommandsProvider)

const ibase::IHierarchicalCommand* CTextEditorGuiComp::GetCommands() const
{
	if (IsGuiCreated()){
		CTextEditor* textEditPtr = GetQtWidget();
		I_ASSERT(textEditPtr != NULL);
		
		return textEditPtr->GetCommands();
	}

	return NULL;
}


// protected methods

// reimplemented (iqtgui::CGuiComponentBase)

void CTextEditorGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	CTextEditor* textEditorPtr = GetQtWidget();
	I_ASSERT(textEditorPtr != NULL);
	if (textEditorPtr != NULL){
		connect(textEditorPtr, SIGNAL(DataChanged()), this, SLOT(OnTextChanged()));

		if (m_useFoldingAttrPtr.IsValid()){
			textEditorPtr->SetFoldingEnabled(*m_useFoldingAttrPtr);
		}

		if (m_languageAttrPtr.IsValid()){
			textEditorPtr->SetLanguage(*m_languageAttrPtr);
		}

		if (m_readOnlyAttrPtr.IsValid() && *m_readOnlyAttrPtr){
			textEditorPtr->SetReadOnly();
		}
	}
}


void CTextEditorGuiComp::OnGuiRetranslate()
{
	BaseClass::OnGuiRetranslate();

	if (IsGuiCreated()){
		CTextEditor* textEditPtr = GetQtWidget();
		I_ASSERT(textEditPtr != NULL);
	
		textEditPtr->OnRetranslate();
	}
}


// protected slots

void CTextEditorGuiComp::OnTextChanged()
{
	UpdateBlocker updateBlocker(this);

	UpdateModel();
}


} // namespace iqsci


