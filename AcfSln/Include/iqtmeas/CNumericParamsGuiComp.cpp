/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <iqtmeas/CNumericParamsGuiComp.h>


// ACF includes
#include <imeas/INumericConstraints.h>


namespace iqtmeas
{


// public methods

CNumericParamsGuiComp::~CNumericParamsGuiComp()
{
	Q_ASSERT(m_valueWidgets.IsEmpty());
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CNumericParamsGuiComp::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	imeas::INumericValue* objectPtr = GetObservedObject();
	Q_ASSERT(objectPtr != NULL);

	imod::IModel* contraintsModelPtr = dynamic_cast<imod::IModel*>(const_cast<imeas::INumericConstraints*>(objectPtr->GetNumericConstraints()));
	if (contraintsModelPtr != NULL){
		BaseClass2::RegisterModel(contraintsModelPtr);
	}
}


void CNumericParamsGuiComp::OnGuiModelDetached()
{
	BaseClass2::UnregisterAllModels();

	BaseClass::OnGuiModelDetached();
}


void CNumericParamsGuiComp::UpdateModel() const
{
	imeas::INumericValue* objectPtr = GetObservedObject();
	if ((objectPtr != NULL) && IsGuiCreated()) {
		int valuesCount = int(m_valueWidgets.GetCount());
		imath::CVarVector values(valuesCount);

		for (int i = 0; i < valuesCount; i++){
			CNumericValueWidget* valueWidgetPtr = m_valueWidgets.GetAt(i);

			values.SetElement(i, valueWidgetPtr->GetValue());
		}

		objectPtr->SetValues(values);
	}
}


void CNumericParamsGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	QWidget* panelPtr = GetQtWidget();
	Q_ASSERT(panelPtr != NULL);	// called inside OnGuiCreated(), widget must be defined.

	QLayout* layoutPtr = panelPtr->layout();
	Q_ASSERT(layoutPtr != NULL); // layout is allways set in OnGuiCreated()

	QObjectList children = layoutPtr->children();
	for (		QObjectList::ConstIterator iter = children.constBegin();
				iter != children.constEnd();
				++iter){
		QObject* childPtr = *iter;

		delete childPtr;
	}

	imeas::INumericValue* objectPtr = GetObservedObject();
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

		int sliderFlags = 0;
		if (*m_isSliderVisibleAttrPtr){
			sliderFlags = CNumericValueWidget::SF_SLIDER_ONLY;

			if (*m_isButtonsVisibleAttrPtr){
				sliderFlags = CNumericValueWidget::SF_SLIDER_BUTTONS;
			}

			if (*m_isSingleRowAttrPtr){
				sliderFlags |= CNumericValueWidget::SF_SINGLE_ROW;
			}
		}

		for (int i = widgetsCount; i < valuesCount; i++){
			CNumericValueWidget* valueWidgetPtr = new CNumericValueWidget(
						panelPtr, 
						sliderFlags,
						m_inputPolicyAttrPtr.IsValid()? *m_inputPolicyAttrPtr: -1,
						*m_editorPrecisionAttrPtr);
			
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
							constraintsPtr->GetNumericValueDescription(i),
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


// reimplemented (iqtgui::CGuiComponentBase)

void CNumericParamsGuiComp::OnGuiCreated()
{
	QWidget* panelPtr = GetQtWidget();
	Q_ASSERT(panelPtr != NULL);	// called inside OnGuiCreated(), widget must be defined.

	QLayout* layoutPtr = NULL;
	if (*m_verticalLayoutAttrPtr){
		layoutPtr = new QVBoxLayout;
	}
	else{
		layoutPtr = new QHBoxLayout;
	}

	layoutPtr->setMargin(0);
	panelPtr->setLayout(layoutPtr);

	BaseClass::OnGuiCreated();
}


void CNumericParamsGuiComp::OnGuiDestroyed()
{
	BaseClass::OnGuiDestroyed();

	m_valueWidgets.Reset();

}


// reimplemented (imod::CMultiModelDispatcherBase)

void CNumericParamsGuiComp::OnModelChanged(int /*modelId*/, const istd::IChangeable::ChangeSet& changeSet)
{
	UpdateGui(changeSet);
}


// protected slots

void CNumericParamsGuiComp::OnValueChanged()
{
	DoUpdateModel();
}


} // namespace iqtmeas


