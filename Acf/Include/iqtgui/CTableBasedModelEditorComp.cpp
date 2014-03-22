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


#include "iqtgui/CTableBasedModelEditorComp.h"


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QHeaderView>
#else
#include <QtGui/QHeaderView>
#endif


namespace iqtgui
{


// protected methods

// reimplemented (iqtgui::CGuiComponentBase)

void CTableBasedModelEditorComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	Q_ASSERT(m_showHorizontalHeaderAttrPtr.IsValid());

	QTableView* viewPtr = GetQtWidget();
	Q_ASSERT(viewPtr != NULL);

	QHeaderView* horizontalHeaderPtr = viewPtr->horizontalHeader();
	Q_ASSERT(horizontalHeaderPtr != NULL);

#if QT_VERSION >= 0x050000
	horizontalHeaderPtr->setSectionResizeMode(QHeaderView::Stretch);
#else
	horizontalHeaderPtr->setResizeMode(QHeaderView::Stretch);
#endif

	if (!*m_showHorizontalHeaderAttrPtr){
		horizontalHeaderPtr->hide();
	}

	QHeaderView* verticalHeaderPtr = viewPtr->verticalHeader();
	Q_ASSERT(verticalHeaderPtr != NULL);
	if (!*m_showVerticalHeaderAttrPtr){
		verticalHeaderPtr->hide();
	}
}


} // namespace iqtgui


