/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iqtmeas/CNumericParamsGuiComp.h"


// ACF includes
#include "imeas/INumericConstraints.h"


namespace iqtmeas
{


// public methods

CNumericParamsGuiComp::~CNumericParamsGuiComp()
{
	Q_ASSERT(m_valueWidgets.IsEmpty());
}


// reimplemented (imod::IModelEditor)

void CNumericParamsGuiComp::UpdateModel() const
{
	imeas::INumericValue* objectPtr = GetObjectPtr();
	if (objectPtr != NULL && IsGuiCreated()){
		int valuesCount = int(m_valueWidgets.GetCount());
		imath::CVarVector values(valuesCount);

		for (int i = 0; i < valuesCount; i++){
			CNumericValueWidget* valueWidgetPtr = m_valueWidgets.GetAt(i);

			values.SetElement(i, valueWidgetPtr->GetValue());
		}

		objectPtr->SetValues(values);
	}
}


// protected methods

// reimplemented (iqtgui::CGuiComponentBase)

void CNumericParamsGuiComp::OnGuiDestroyed()
{
	m_valueWidgets.Reset();

	BaseClass::OnGuiDestroyed();
}


// reimplemented (iqtgui::TGuiObserverWrap)

void CNumericParamsGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	QWidget* panelPtr = GetQtWidget();
	Q_ASSERT(panelPtr != NULL);	// called inside UpdateGui(), widget must be defined.

	QLayout* layoutPtr = panelPtr->layout();
	if (layoutPtr == NULL){
		layoutPtr = new QVBoxLayout;
		layoutPtr->setMargin(0);
		panelPtr->setLayout(layoutPtr);
	}

	imeas::INumericValue* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		const imeas::INumericConstraints* constraintsPtr = objectPtr->GetNumericConstraints();

		imath::CVarVector values = objectPtr->GetValues();

		int widgetsCount = m_valueWidgets.GetCount();

		int valuesCount;
		if (constraintsPtr != NULL){
			valuesCount = constraintsPtr->GetNumericValuesCount();
		}
		else{
			valuesCount = values.GetElementsCount();
		}

		m_valueWidgets.SetCount(valuesCount);
		for (int i = widgetsCount; i < valuesCount; i++){
			CNumericValueWidget* valueWidgetPtr = new CNumericValueWidget(
						panelPtr, 
						*m_isSliderVisibleAttrPtr, 
						*m_isButtonsVisibleAttrPtr,
						*m_inputPolicyAttrPtr);
			
			connect(valueWidgetPtr, SIGNAL(ValueChanged()), this, SLOT(OnValueChanged()));

			m_valueWidgets.SetElementAt(i, valueWidgetPtr);

			layoutPtr->addWidget(valueWidgetPtr);
		}

		for (int i = 0; i < valuesCount; i++){
			CNumericValueWidget* valueWidgetPtr = m_valueWidgets.GetAt(i);
			Q_ASSERT(valueWidgetPtr != NULL);

			if (constraintsPtr != NULL){
				valueWidgetPtr->SetUnitInfo(
							constraintsPtr->GetNumericValueName(i),
							constraintsPtr->GetNumericValueUnitInfo(i));
			}

			if (i < values.GetElementsCount()){
				valueWidgetPtr->SetValue(values.GetElement(i));
			}
			else{
				valueWidgetPtr->SetValue(0);
			}
		}
	}
}


// protected slots

void CNumericParamsGuiComp::OnValueChanged()
{
	DoUpdateModel();
}


} // namespace iqtmeas


