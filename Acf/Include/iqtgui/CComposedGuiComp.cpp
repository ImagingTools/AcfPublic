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


#include "iqtgui/CComposedGuiComp.h"


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QGroupBox>
#else
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolBox>
#include <QtGui/QTabWidget>
#include <QtGui/QGroupBox>
#endif


namespace iqtgui
{


// public methods

CComposedGuiComp::CComposedGuiComp()
	:m_splitterPtr(NULL)
{
}


// reimplemented (TRestorableGuiWrap)

void CComposedGuiComp::OnRestoreSettings(const QSettings& settings)
{
	Q_ASSERT(IsGuiCreated());

	if (m_splitterPtr != NULL){
		// preserve overriding of splitter orientation:
		Qt::Orientation splitterOrientation = m_splitterPtr->orientation();

		QByteArray splitterState = settings.value(GetSettingsKey()).toByteArray();

		m_splitterPtr->restoreState(splitterState);

		m_splitterPtr->setOrientation(splitterOrientation);
	}
}


void CComposedGuiComp::OnSaveSettings(QSettings& settings) const
{
	Q_ASSERT(IsGuiCreated());

	if (m_splitterPtr != NULL){
		QByteArray splitterState = m_splitterPtr->saveState();

		settings.setValue(GetSettingsKey(), splitterState);
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CComposedGuiComp::OnGuiCreated()
{
	QWidget* widgetPtr = GetWidget();
	Q_ASSERT(widgetPtr != NULL);	// GUI was created, main widget must be present

	QBoxLayout* layoutPtr = NULL;
	if (*m_useHorizontalLayoutAttrPtr){
		layoutPtr = new QHBoxLayout(widgetPtr);
	}
	else{
		layoutPtr = new QVBoxLayout(widgetPtr);
	}

	layoutPtr->setMargin(0);

	bool isFlat = *m_flatViewAttrPtr;

	if (*m_designTypeAttrPtr == 1){		// Tool Box
		widgetPtr->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);

		QToolBox* toolBoxPtr = new QToolBox(widgetPtr);
		toolBoxPtr->setBackgroundRole(QPalette::Window);

		int elementsCount = m_guisCompPtr.GetCount();
		for (int i = 0; i < elementsCount; ++i){
			iqtgui::IGuiObject* guiPtr = m_guisCompPtr[i];

			if (guiPtr != NULL){
				QWidget* panelPtr = new QWidget(widgetPtr);
				QBoxLayout* panelLayoutPtr = new QVBoxLayout(panelPtr);
				panelLayoutPtr->setContentsMargins(6, 0, 6, 0);
				QString name;
				if (i < m_namesAttrPtr.GetCount()){
					name = m_namesAttrPtr[i];
				}

				guiPtr->CreateGui(panelPtr);

				toolBoxPtr->addItem(panelPtr, name);

				// TODO: candidate to remove
				QSpacerItem* spacerPtr = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

				panelLayoutPtr->addItem(spacerPtr);

				if (*m_insertSpacerAttrPtr){
					panelLayoutPtr->insertStretch(-1);
				}
			}
		}

		layoutPtr->addWidget(toolBoxPtr);
	}
	else if (*m_designTypeAttrPtr == 2){	// Tab Widget
		widgetPtr->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

		QTabWidget* tabWidgetPtr = new QTabWidget(widgetPtr);
		tabWidgetPtr->setTabPosition(QTabWidget::TabPosition(*m_tabOrientationAttrPtr));

		if (isFlat){
			tabWidgetPtr->setTabShape(QTabWidget::Triangular);
		}

		int elementsCount = m_guisCompPtr.GetCount();
		for (int i = 0; i < elementsCount; ++i){
			iqtgui::IGuiObject* guiPtr = m_guisCompPtr[i];

			if (guiPtr != NULL){
				QWidget* panelPtr = new QWidget(tabWidgetPtr);
				QBoxLayout* panelLayoutPtr = new QVBoxLayout(panelPtr);
				QString name;
				if (i < m_namesAttrPtr.GetCount()){
					name = m_namesAttrPtr[i];
				}

				guiPtr->CreateGui(panelPtr);

				tabWidgetPtr->addTab(panelPtr, name);

				if (*m_insertSpacerAttrPtr){
					panelLayoutPtr->insertStretch(-1);
				}
			}
		}

		layoutPtr->addWidget(tabWidgetPtr);
	}
	else if (*m_designTypeAttrPtr == 3){	// Splitter
		int elementsCount = m_guisCompPtr.GetCount();
		m_splitterPtr = new QSplitter(widgetPtr);

		if (isFlat){
			m_splitterPtr->setOpaqueResize(false);
		}

		if (*m_useHorizontalLayoutAttrPtr){
			m_splitterPtr->setOrientation(Qt::Horizontal);
		}
		else{
			m_splitterPtr->setOrientation(Qt::Vertical);
		}

		for (int i = 0; i < elementsCount; ++i){
			iqtgui::IGuiObject* guiPtr = m_guisCompPtr[i];
			if (guiPtr != NULL){
				guiPtr->CreateGui(widgetPtr);

				m_splitterPtr->addWidget(guiPtr->GetWidget());
			}
		}

		layoutPtr->addWidget(m_splitterPtr);
	}
	else{	// Group Box
		int elementsCount = m_guisCompPtr.GetCount();
		for (int i = 0; i < elementsCount; ++i){
			iqtgui::IGuiObject* guiPtr = m_guisCompPtr[i];

			QWidget* elementParentPtr = widgetPtr;

			if (i < m_namesAttrPtr.GetCount()){
				QLayout* parentLayoutPtr = elementParentPtr->layout();

				elementParentPtr = new QGroupBox(m_namesAttrPtr[i], elementParentPtr);
				new QVBoxLayout(elementParentPtr);

				if (parentLayoutPtr != NULL){
					parentLayoutPtr->addWidget(elementParentPtr);

					Q_ASSERT(layoutPtr != NULL);
					if (m_useSameStretchingFactorAttrPtr.IsValid() && *m_useSameStretchingFactorAttrPtr){
						layoutPtr->setStretchFactor(elementParentPtr, 1);
					}
				}

				if (isFlat){
					((QGroupBox*)elementParentPtr)->setFlat(true);
					elementParentPtr->layout()->setContentsMargins(0, 4, 0, 0);
				}
			}

			if (guiPtr != NULL){
				guiPtr->CreateGui(elementParentPtr);
			}
		}

		if (*m_insertSpacerAttrPtr){
			layoutPtr->insertStretch(-1);
		}
	}

	BaseClass::OnGuiCreated();
}


void CComposedGuiComp::OnGuiDestroyed()
{
	if (m_guisCompPtr.IsValid()){
		int guisCount = m_guisCompPtr.GetCount();
		for (int guiIndex = 0; guiIndex < guisCount; ++guiIndex){
			iqtgui::IGuiObject* guiPtr = m_guisCompPtr[guiIndex];
			if (guiPtr != NULL && guiPtr->IsGuiCreated()){
				guiPtr->DestroyGui();
			}
		}
	}

	BaseClass::OnGuiDestroyed();
}


// private methods

QString CComposedGuiComp::GetSettingsKey() const
{
	QString settingsKey = "Splitter";
	if (m_settingsKeyAttrPtr.IsValid()){
		settingsKey = *m_settingsKeyAttrPtr + QString("/") + settingsKey;
	}

	return settingsKey;
}


} // namespace iqtgui


