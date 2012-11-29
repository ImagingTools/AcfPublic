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


#include "iqtgui/CTabContainerGuiComp.h"


// Qt includes
#include <QtGui/QGridLayout>
#include <QtGui/QFrame>


namespace iqtgui
{


// protected methods

void CTabContainerGuiComp::UpdateVisualElements()
{
	QTabWidget* widgetPtr = GetQtWidget();
	I_ASSERT(widgetPtr != NULL);

	int visualProvidersCount = m_slaveWidgetsVisualCompPtr.GetCount();

	for (		TabToGuiIndexMap::ConstIterator iter = m_tabToGuiIndexMap.begin();
				iter != m_tabToGuiIndexMap.end();
				++iter){
		int tabIndex = iter.key();
		I_ASSERT(tabIndex >= 0);
		I_ASSERT(tabIndex < widgetPtr->count());

		int guiIndex = iter.value();
		I_ASSERT(guiIndex >= 0);
		I_ASSERT(guiIndex < m_slaveWidgetsCompPtr.GetCount());

		QIcon tabIcon;
		QString toolTip;

		if (guiIndex < visualProvidersCount){
			const IVisualStatusProvider* visualProviderPtr = m_slaveWidgetsVisualCompPtr[guiIndex];
			if (visualProviderPtr != NULL){
				tabIcon = visualProviderPtr->GetStatusIcon();
				toolTip = visualProviderPtr->GetStatusText();
			}
		}

		widgetPtr->setTabIcon(tabIndex, tabIcon);
		widgetPtr->setTabToolTip(tabIndex, toolTip);
	}
}


// reimplemented (iqtgui::CComponentBase)

void CTabContainerGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	I_ASSERT(IsGuiCreated());

	QTabWidget* widgetPtr = GetQtWidget();
	I_ASSERT(widgetPtr != NULL);
	if (widgetPtr == NULL){
		return;
	}

	if (*m_useTriangularTabsAttrPtr){
		widgetPtr->setTabShape(QTabWidget::Triangular);
	}

	widgetPtr->setTabPosition(QTabWidget::TabPosition(*m_tabOrientationAttrPtr));

	if (m_iconSizeAttrPtr.IsValid()){
		QSize iconSize = QSize(m_iconSizeAttrPtr->GetValue(), m_iconSizeAttrPtr->GetValue());
		if (!iconSize.isNull() && iconSize.isValid() && !iconSize.isEmpty()){
			widgetPtr->setIconSize(iconSize);
		}
	}

	int tabsCount = m_tabModel.GetOptionsCount();

	for (int guiIndex = 0; guiIndex < tabsCount; guiIndex++){
		QString tabName = m_tabNamesAttrPtr[guiIndex];

		iqtgui::IGuiObject* guiPtr = m_slaveWidgetsCompPtr[guiIndex];
		if ((guiPtr == NULL) || !guiPtr->CreateGui(widgetPtr)){
			m_tabModel.SetOptionEnabled(guiIndex, false);

			continue;
		}

		QWidget* pageWidget = new QWidget(widgetPtr);
		QVBoxLayout* pageLayout = new QVBoxLayout(pageWidget);

		pageLayout->addWidget(guiPtr->GetWidget());

		int tabIndex = widgetPtr->addTab(pageWidget, tabName);
		m_tabToGuiIndexMap[tabIndex] = guiIndex;

		if (		(guiIndex < m_slaveWidgetsVisualCompPtr.GetCount()) &&
					(guiIndex < m_slaveWidgetsModelCompPtr.GetCount())){
			imod::IModel* modelPtr = m_slaveWidgetsModelCompPtr[guiIndex];
			if ((m_slaveWidgetsVisualCompPtr[guiIndex] != NULL) && (modelPtr != NULL)){
				RegisterModel(modelPtr, guiIndex);
			}
		}
	}

	widgetPtr->setCurrentIndex(m_tabModel.GetSelectedOptionIndex());

	// setup the corner widget:
	if (m_cornerGuiCompPtr.IsValid()){
		if (m_cornerGuiCompPtr->CreateGui(NULL)){
			widgetPtr->setCornerWidget(m_cornerGuiCompPtr->GetWidget());
		}
	}

	UpdateVisualElements();
}


void CTabContainerGuiComp::OnGuiDestroyed()
{
	I_ASSERT(m_slaveWidgetsCompPtr.IsValid());

	m_tabToGuiIndexMap.clear();

	if (m_slaveWidgetsCompPtr.IsValid()){
		int slaveWidgetsCount = m_slaveWidgetsCompPtr.GetCount();
		for (int widgetIndex = 0; widgetIndex < slaveWidgetsCount; widgetIndex++){
			iqtgui::IGuiObject* guiPtr = m_slaveWidgetsCompPtr[widgetIndex];
			if (guiPtr != NULL){
				guiPtr->DestroyGui();
			}
		}
	}

	BaseClass::OnGuiDestroyed();
}


// reimplemented (imod::CMultiModelDispatcherBase)

void CTabContainerGuiComp::OnModelChanged(int /*modelId*/, int /*changeFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	if (IsGuiCreated()){
		UpdateVisualElements();
	}
}

// reimplemented (icomp::CComponentBase)

void CTabContainerGuiComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	m_tabModel.SetParent(this);
}


// public methods of the embedded class TabModel

CTabContainerGuiComp::TabModel::TabModel()
	:m_parentPtr(NULL)
{
	m_selectedOptionIndex = 0;

	BaseClass::SetSelectionConstraints(this);
}


void CTabContainerGuiComp::TabModel::SetParent(CTabContainerGuiComp* parentPtr)
{
	I_ASSERT(parentPtr != NULL);

	m_parentPtr = parentPtr;

	if ((m_parentPtr != NULL) && m_parentPtr->m_tabNamesAttrPtr.IsValid()){
		int tabsCount = qMin(m_parentPtr->m_tabNamesAttrPtr.GetCount(), m_parentPtr->m_slaveWidgetsCompPtr.GetCount());

		for(int tabIndex = 0; tabIndex < tabsCount; tabIndex++){
			QString tabName = m_parentPtr->m_tabNamesAttrPtr[tabIndex];

			BaseClass2::InsertOption(tabName, tabName.toLocal8Bit());
		}
	}
}


// reimplemented (iprm::ISelectionParam)

bool CTabContainerGuiComp::TabModel::SetSelectedOptionIndex(int index)
{
	if (BaseClass::SetSelectedOptionIndex(index)){
		if (m_parentPtr != NULL && m_parentPtr->IsGuiCreated()){
			QTabWidget* tabWidgetPtr = m_parentPtr->GetQtWidget();
			I_ASSERT(tabWidgetPtr != NULL);

			tabWidgetPtr->setCurrentIndex(index);
		}
	}

	return false;
}


// reimplemented (iser::ISerializable)

bool CTabContainerGuiComp::TabModel::Serialize(iser::IArchive& archive)
{
	return BaseClass::Serialize(archive) && BaseClass2::Serialize(archive);
}


// reimplemented (iprm::IOptionsManager)

void CTabContainerGuiComp::TabModel::SetOptionEnabled(int index, bool isEnabled)
{
	BaseClass2::SetOptionEnabled(index, isEnabled);
	
	if (m_parentPtr != NULL && m_parentPtr->IsGuiCreated()){
		QTabWidget* tabWidgetPtr = m_parentPtr->GetQtWidget();
		I_ASSERT(tabWidgetPtr != NULL);

		tabWidgetPtr->setTabEnabled(index, isEnabled);
	}
}


bool CTabContainerGuiComp::TabModel::RemoveOption(int /*index*/)
{
	return false;
}


bool CTabContainerGuiComp::TabModel::InsertOption(
			QString& /*optionName*/,
			const QByteArray& /*optionId*/,
			const QString& /*optionDescription*/, 
			int /*index*/)
{
	return false;
}


} // namespace iqtgui


