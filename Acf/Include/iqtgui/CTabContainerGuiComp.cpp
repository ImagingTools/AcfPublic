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


#include "iqtgui/CTabContainerGuiComp.h"


// Qt includes
#include <QtGui/QTabWidget>


namespace iqtgui
{


// protected methods

// reimplemented (iqtgui::CMultiPageGuiCompBase)

int CTabContainerGuiComp::GetPagesCount() const
{
	return m_slaveWidgetsCompPtr.GetCount();
}


iqtgui::IGuiObject* CTabContainerGuiComp::GetPageGuiComponent(int pageIndex) const
{
	Q_ASSERT(pageIndex >= 0);
	Q_ASSERT(pageIndex < m_slaveWidgetsCompPtr.GetCount());

	return m_slaveWidgetsCompPtr[pageIndex];
}


int CTabContainerGuiComp::GetDesignType() const
{
	return CMultiPageWidget::DT_TAB_WIDGET;
}


// reimplemented (iqtgui::CGuiComponentBase)

void CTabContainerGuiComp::OnGuiCreated()
{
	Q_ASSERT(IsGuiCreated());

	BaseClass::OnGuiCreated();

	CMultiPageWidget* widgetPtr = dynamic_cast<CMultiPageWidget*>(GetWidget());
	Q_ASSERT(widgetPtr != NULL);

	QTabWidget* tabWidgetPtr = dynamic_cast<QTabWidget*>(widgetPtr->GetContainerWidgetPtr());
	if (tabWidgetPtr != NULL){
		if (*m_useTriangularTabsAttrPtr){
			tabWidgetPtr->setTabShape(QTabWidget::Triangular);
		}

		tabWidgetPtr->setTabPosition(QTabWidget::TabPosition(*m_tabOrientationAttrPtr));

		// setup the corner widget:
		if (m_cornerGuiCompPtr.IsValid()){
			if (m_cornerGuiCompPtr->CreateGui(NULL)){
				tabWidgetPtr->setCornerWidget(m_cornerGuiCompPtr->GetWidget());
			}
		}
	}
}


} // namespace iqtgui


