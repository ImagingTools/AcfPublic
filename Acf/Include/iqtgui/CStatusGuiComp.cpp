/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iqtgui/CStatusGuiComp.h>


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QGroupBox>
#else
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QStatusBar>
#include <QtGui/QGroupBox>
#endif


namespace iqtgui
{


// reimplemented (iqtgui::TGuiObserverWrap)

void CStatusGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	QIcon icon;

	istd::IInformationProvider* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		icon = GetCategoryIcon(objectPtr->GetInformationCategory());
	}
	else{
		icon = GetCategoryIcon(istd::IInformationProvider::IC_NONE);
	}

	QLabel* labelPtr = GetQtWidget();
	Q_ASSERT(labelPtr != NULL);

	labelPtr->setPixmap(icon.pixmap(*m_iconSizeAttrPtr));
}


// reimplemented (iqtgui::CGuiComponentBase)

void CStatusGuiComp::OnGuiCreated()
{
	QLabel* labelPtr = GetQtWidget();
	Q_ASSERT(labelPtr != NULL);

	labelPtr->setMinimumSize(*m_iconSizeAttrPtr, *m_iconSizeAttrPtr);
	labelPtr->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	labelPtr->setScaledContents(false);
}


} // namespace iqtgui


