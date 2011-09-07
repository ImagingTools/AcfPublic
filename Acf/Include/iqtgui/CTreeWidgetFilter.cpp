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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtgui/CTreeWidgetFilter.h"


// Qt includes
#include <QEvent>
#include <QMouseEvent>


namespace iqtgui
{


CTreeWidgetFilter::CTreeWidgetFilter(QTreeWidget* slavePtr)
:	QObject(slavePtr),
	m_slave(*slavePtr)
{
	I_ASSERT(slavePtr != NULL);

	m_slave.viewport()->installEventFilter(this);
}



// protected methods

// reimplemented (QObject)

bool CTreeWidgetFilter::eventFilter(QObject* sourcePtr, QEvent* eventPtr)
{
	switch (eventPtr->type()){
	case QEvent::MouseButtonPress:
		{
			QMouseEvent* mouseEvent = dynamic_cast<QMouseEvent*>(eventPtr);
			if (mouseEvent != NULL){
				QTreeWidgetItem* foundPtr = m_slave.itemAt(mouseEvent->pos());
				if (foundPtr == NULL){
					m_slave.clearSelection();

					return true;
				}
			}
		}

		return false;

	default:
		return BaseClass::eventFilter(sourcePtr, eventPtr);
	}
}


} // namespace iqtgui


