/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iqtprm/CNameParamGuiComp.h"


// Qt includes
#include <QtCore/QtGlobal>
#include <QtGui/QRegExpValidator>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QLabel>
#else
#include <QtGui/QLabel>
#endif

// ACF includes
#include "istd/TChangeNotifier.h"


namespace iqtprm
{


// public methods

// reimplemented (imod::IModelEditor)

void CNameParamGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	iprm::INameParam* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		objectPtr->SetName(NameEdit->text());
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CNameParamGuiComp::UpdateGui(int /*updateFlags*/)
{
	iprm::INameParam* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		NameEdit->setText(objectPtr->GetName());
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CNameParamGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	int labelPosition = LP_LEFT;

	if (m_labelPositionAttrPtr.IsValid()){
		labelPosition = *m_labelPositionAttrPtr;
	}

	QLayout* selectorLayoutPtr = NULL;
	Q_ASSERT(NameFrame->layout() == NULL);

	if (labelPosition == LP_LEFT){
		selectorLayoutPtr = new QHBoxLayout(NameFrame);

	}
	else{
		selectorLayoutPtr = new QVBoxLayout(NameFrame);
	}

	selectorLayoutPtr->setContentsMargins(0, 0, 0, 0);

	if (m_labelAttrPtr.IsValid()){
		QLabel* selectorLabelPtr = new QLabel(NameFrame);
		selectorLabelPtr->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
		selectorLabelPtr->setText(*m_labelAttrPtr);

		selectorLayoutPtr->addWidget(selectorLabelPtr);
	}

	selectorLayoutPtr->addWidget(NameEdit);


	connect(NameEdit, SIGNAL(textChanged(const QString&)), this, SLOT(OnNameChanged(const QString&)));
	if (m_regularExpressionAttrPtr.IsValid()){
		QRegExp expression(*m_regularExpressionAttrPtr);

		QRegExpValidator* validatorPtr = new QRegExpValidator(expression, NameEdit);

		NameEdit->setValidator(validatorPtr);
	}
}


// private slots

void CNameParamGuiComp::OnNameChanged(const QString& /*text*/)
{
	DoUpdateModel();
}


} // namespace iqtprm


