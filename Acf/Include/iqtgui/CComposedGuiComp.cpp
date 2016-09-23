/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <iqtgui/CComposedGuiComp.h>


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

QWidget* CComposedGuiComp::GetPageContainerWidget() const
{
	iwidgets::CMultiPageWidget* widgetPtr = dynamic_cast<iwidgets::CMultiPageWidget*>(GetWidget());

	return widgetPtr->GetContainerWidgetPtr();
}


// reimplemented (TRestorableGuiWrap)

void CComposedGuiComp::OnRestoreSettings(const QSettings& settings)
{
	Q_ASSERT(IsGuiCreated());

	QSplitter* splitterPtr = dynamic_cast<QSplitter*>(GetPageContainerWidget());
	if (splitterPtr != NULL){
		// preserve overriding of splitter orientation:
		Qt::Orientation splitterOrientation = splitterPtr->orientation();

		QByteArray splitterState = settings.value(GetSettingsKey()).toByteArray();

		splitterPtr->restoreState(splitterState);

		splitterPtr->setOrientation(splitterOrientation);
	}
}


void CComposedGuiComp::OnSaveSettings(QSettings& settings) const
{
	Q_ASSERT(IsGuiCreated());

	QSplitter* splitterPtr = dynamic_cast<QSplitter*>(GetPageContainerWidget());
	if (splitterPtr != NULL){
		QByteArray splitterState = splitterPtr->saveState();

		settings.setValue(GetSettingsKey(), splitterState);
	}
}


// protected methods

// reimplemented (iqtgui::CMultiPageGuiCompBase)

int CComposedGuiComp::GetPagesCount() const
{
	return m_guisCompPtr.GetCount();
}


iqtgui::IGuiObject* CComposedGuiComp::GetPageGuiComponent(int pageIndex) const
{
	Q_ASSERT(pageIndex >= 0);
	Q_ASSERT(pageIndex < m_guisCompPtr.GetCount());

	return m_guisCompPtr[pageIndex];
}


int CComposedGuiComp::GetDesignType() const
{
	return *m_designTypeAttrPtr;
}


// reimplemented (iqtgui::CGuiComponentBase)

void CComposedGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	bool isFlat = *m_flatViewAttrPtr;

	QTabWidget* tabWidgetPtr = dynamic_cast<QTabWidget*>(GetPageContainerWidget());
	if (tabWidgetPtr != NULL){
		if (isFlat){
			tabWidgetPtr->setDocumentMode(true);
		}

		tabWidgetPtr->setTabPosition(QTabWidget::TabPosition(*m_tabOrientationAttrPtr));
	}

	// TODO: possible remove it!
	QToolBox* toolBoxPtr = dynamic_cast<QToolBox*>(GetPageContainerWidget());
	if (toolBoxPtr != NULL){
		toolBoxPtr->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
	}

	QSplitter* splitterPtr = dynamic_cast<QSplitter*>(GetPageContainerWidget());
	if (splitterPtr != NULL){
		if (isFlat){
			splitterPtr->setOpaqueResize(false);
		}
	}
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


