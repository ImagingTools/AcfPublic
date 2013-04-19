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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iloggui/CTextLogGuiComp.h"


namespace iloggui
{


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CTextLogGuiComp::UpdateGui()
{
	QString document;

	ilog::IMessageContainer* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		const ilog::IMessageContainer::Messages messages = objectPtr->GetMessages();
		for (int i = 0; i < messages.count(); i++){
			const ilog::IMessageConsumer::MessagePtr messagePtr = messages.at(i);

			QString entry = QString("[%1] <%2> %3 %4")
				.arg(messagePtr->GetInformationTimeStamp().toString())
				.arg(messagePtr->GetInformationSource())
				.arg(messagePtr->GetInformationCategory())
				.arg(messagePtr->GetInformationDescription());

			document += entry;
			document += "\n";
		}
	}	

	LogEditor->setPlainText(document);
}


// reimplemented (CGuiComponentBase)

void CTextLogGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();
}


void CTextLogGuiComp::OnGuiDestroyed()
{
	BaseClass::OnGuiDestroyed();
}


} // namespace iloggui


