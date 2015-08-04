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


#ifndef iwidgets_CTreeWidgetFilter_included
#define iwidgets_CTreeWidgetFilter_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QTreeWidget>
#else
#include <QtGui/QTreeWidget>
#endif

#include "iwidgets/iwidgets.h"


namespace iwidgets
{


/**
	Provide some corrections in \c QTreeWidget object.
	Objects of this class are automatically registered by slave objects and should not be deleted manually.
	Please create instance of this class on heap.
*/
class CTreeWidgetFilter: public QObject
{
public:
	typedef QObject BaseClass;

	/**
		Constructor.
		\param	slavePtr	pointer to filtered slave tree object.
							It cannot be NULL.
	*/
	CTreeWidgetFilter(QTreeWidget* slavePtr);

protected:
	// reimplemented (QObject)
	virtual bool eventFilter(QObject* sourcePtr, QEvent* eventPtr);

private:
	QTreeWidget& m_slave;
};


} // namespace iwidgets


#endif // !iwidgets_CTreeWidgetFilter_included


