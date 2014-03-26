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


// ACF includes
#include "icomp/TSimComponentWrap.h"
#include "icomp/TSimComponentsFactory.h"

// ACF package includes
#include "BasePck/BasePck.h"
#include "QtPck/QtPck.h"
#include "QtGuiPck/QtGuiPck.h"


int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(iqtgui);

	QApplication app(argc, argv);

	iqtgui::CMultiPageWidget emptyContainer;
	emptyContainer.setWindowTitle("Empty container");
	emptyContainer.showMaximized();

	iqtgui::CMultiPageWidget tabContainer(NULL, iqtgui::CMultiPageWidget::DT_TAB_WIDGET);
	tabContainer.setWindowTitle("Tab container");

	QLabel page1("Page 1");
	tabContainer.InsertPage(&page1, "Page 1");
	tabContainer.SetPageIcon(0, QIcon(":/Icons/StateOk"));

	QLabel page2("Page 2");
	tabContainer.InsertPage(&page2, "Page 2");
	tabContainer.SetPageIcon(1, QIcon(":/Icons/StateWarning"));

	QLabel page3("Page 3");
	tabContainer.InsertPage(&page3, "Page 3");
	tabContainer.SetPageIcon(2, QIcon(":/Icons/StateInvalid"));

	tabContainer.showMaximized();

	return app.exec();
}

