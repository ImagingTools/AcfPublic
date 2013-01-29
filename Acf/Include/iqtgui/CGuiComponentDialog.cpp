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


#include "iqtgui/CGuiComponentDialog.h"


// Qt includes
#include <QtGui/QVBoxLayout>
#include <QtGui/QCloseEvent>


namespace iqtgui
{


CGuiComponentDialog::CGuiComponentDialog(
			iqtgui::IGuiObject* guiObjectPtr,
			int buttons,
			bool isModal,
			QWidget* parentWidgetPtr)
:	BaseClass(parentWidgetPtr),
	m_buttonsBox(NULL),
	m_guiObjectPtr(NULL)
{
	// GUI pointer must be valid:
	I_ASSERT(guiObjectPtr != NULL);

	// GUI must not be created:
	I_ASSERT(!guiObjectPtr->IsGuiCreated());
	if (!guiObjectPtr->IsGuiCreated()){
		BaseClass::setModal(isModal);

		QVBoxLayout* dialogLayout = new QVBoxLayout(this);

		if (guiObjectPtr != NULL){
			if (guiObjectPtr->CreateGui(this)){
				m_guiObjectPtr = guiObjectPtr;

				dialogLayout->addWidget(m_guiObjectPtr->GetWidget());

				QWidget* slaveWidgetPtr = guiObjectPtr->GetWidget();
				I_ASSERT(slaveWidgetPtr != NULL);

				BaseClass::resize(slaveWidgetPtr->sizeHint().expandedTo(BaseClass::sizeHint()));
			}
		}

		if (isModal || (buttons != 0)){
			QDialogButtonBox::StandardButtons buttonFlags = (buttons != 0)?
						(QDialogButtonBox::StandardButtons)buttons:
						QDialogButtonBox::Close;

			m_buttonsBox = new QDialogButtonBox(buttonFlags, Qt::Horizontal, this);
			connect(m_buttonsBox, SIGNAL(accepted()), this, SLOT(accept()));
			connect(m_buttonsBox, SIGNAL(rejected()), this, SLOT(reject()));

			dialogLayout->addWidget(m_buttonsBox);
		}
	}
}


CGuiComponentDialog::~CGuiComponentDialog()
{
	if (m_guiObjectPtr != NULL){
		I_ASSERT(m_guiObjectPtr->IsGuiCreated());

		if (m_guiObjectPtr->IsGuiCreated()){
			m_guiObjectPtr->DestroyGui();
		}
	}
}


// protected methods

// reimplemented (QWidget)

void CGuiComponentDialog::closeEvent(QCloseEvent* eventPtr)
{
	Q_ASSERT(eventPtr != NULL);

	if (m_guiObjectPtr != NULL){
		bool ignoreClosing = false;
		m_guiObjectPtr->OnTryClose(&ignoreClosing);

		if (ignoreClosing){
			  eventPtr->ignore();

			  return;
		}
	}

	BaseClass::closeEvent(eventPtr);
}


void CGuiComponentDialog::keyPressEvent(QKeyEvent* eventPtr)
{
	Q_ASSERT(eventPtr != NULL);

	switch (eventPtr->key()){
        case Qt::Key_Escape:
		if (m_guiObjectPtr != NULL){
			bool ignoreClosing = false;
			m_guiObjectPtr->OnTryClose(&ignoreClosing);
			if (ignoreClosing){
				  return;
			}

			int currentResult = BaseClass::result();
			if (currentResult != 0){
				done(currentResult);

				return;
			}			
		}
		break;
	}

	BaseClass::keyPressEvent(eventPtr);
}


} // namespace iqtgui


