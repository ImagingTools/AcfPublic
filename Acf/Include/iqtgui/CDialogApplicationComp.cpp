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


#include "iqtgui/CDialogApplicationComp.h"


// Qt includes
#include <QtGui/QApplication>


namespace iqtgui
{


// reimplemented (ibase::IApplication)

int CDialogApplicationComp::Execute(int argc, char** argv)
{
	if (InitializeApplication(argc, argv)){
		QByteArray appStyle;

		// parse arguments:
		for (int index = 1; index < argc; index++){
			QByteArray arg = argv[index];
			if (arg == "-style"){
				if (index+1 < argc){
					appStyle = argv[index+1];
				}
			}
		}
		QApplication::setStyle(QString::fromLocal8Bit(appStyle));

		TryShowSplashScreen();

		m_mainDialogCompPtr.IsValid();

		HideSplashScreen();

		if (m_mainDialogCompPtr.IsValid()){
			m_mainDialogCompPtr->ExecuteDialog(NULL);

			return 0;
		}
	}

	return -1;
}


QString CDialogApplicationComp::GetHelpText() const
{
	return "-style QtStyle\tname of Qt-specified style";
}


} // namespace iqtgui



