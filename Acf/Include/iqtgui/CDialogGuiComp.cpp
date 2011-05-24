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


#include "iqtgui/CDialogGuiComp.h"


// Qt includes
#include <QIcon>


namespace iqtgui
{


// public methods

// reimplemented (iqtgui::IDialog)

void CDialogGuiComp::Execute()
{
	istd::TDelPtr<iqtgui::CGuiComponentDialog> dialogPtr(CreateComponentDialog(QDialogButtonBox::Close));
	if (dialogPtr.IsValid()){
		dialogPtr->exec();
	}
}


// protected methods

iqtgui::CGuiComponentDialog* CDialogGuiComp::CreateComponentDialog(int buttons) const
{
	istd::TDelPtr<iqtgui::CGuiComponentDialog> dialogPtr;

	if (m_guiCompPtr.IsValid()){
		dialogPtr.SetPtr(
					new iqtgui::CGuiComponentDialog(
								m_guiCompPtr.GetPtr(),
								buttons,
								true));

		if (m_dialogTitleAttrPtr.IsValid()){
			dialogPtr->setWindowTitle(iqt::GetQString(*m_dialogTitleAttrPtr));
		}

		if (m_dialogIconPathAttrPtr.IsValid()){
			dialogPtr->setWindowIcon(QIcon(iqt::GetQString(*m_dialogIconPathAttrPtr)));
		}
	}

	return dialogPtr.PopPtr();
}


} // namespace iqtgui


