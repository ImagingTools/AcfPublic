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

#include "generated/ui_CwrapperAcf.h"
#include "CwrapperAcf.h"

//QT 
#include <QtCore/QFileInfo>
#include <QtGui/QMessageBox>



int main(int argc, char *argv[])
{		

	QApplication::setStyle("plastique");
	QApplication app(argc, argv);
	
	
	wrapper::CwrapperAcf *wrapperPtr;	
	
	if (argc > 1){
		QFileInfo confFile = QString(argv[1]);

		if(!confFile.exists()){
			QMessageBox::warning(0, "ACF Wrapper",
								  "File not exist",
								  QMessageBox::Ok);		
			return 1;
		}

		if (confFile.suffix() == "xpc"){	
			wrapperPtr = new wrapper::CwrapperAcf(argv);
			wrapperPtr->RunACF(1000);
			wrapperPtr->show();				
			return app.exec();			
		
		}else{			
			QMessageBox::warning(0, "ACF Wrapper",
								  "Invalid file format",
								  QMessageBox::Ok);			
			return 1;
		}	

	} else {
		wrapperPtr = new wrapper::CwrapperAcf();
		wrapperPtr->show();
		return app.exec();
	}


}

