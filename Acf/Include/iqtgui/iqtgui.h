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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtgui_included
#define iqtgui_included


// Qt includes
#include <QtCore/QFile>
#include <QtCore/QTextStream>

// ACF includes
#include "iqt/iqt.h"


/**
	Standard GUI specific interfaces and components based on Qt.
*/
namespace iqtgui
{


/**
	Set style sheet to any supported object.
*/
template <class StyleSheetConsumer>
static bool SetStyleSheet(StyleSheetConsumer& styleSheetConsumer, const QString& styleSheetFilePath)
{
	if (styleSheetFilePath.isEmpty()){
		styleSheetConsumer.setStyleSheet("");

		return true;
	}

	QFile styleSheetFile(styleSheetFilePath);
	if (styleSheetFile.open(QIODevice::ReadOnly | QIODevice::Text)){
		QTextStream stream(&styleSheetFile);
		QString styleSheetText;
		QString textLine;
		do{
			textLine = stream.readLine();
			styleSheetText += textLine;
		} while (!textLine.isNull());

		styleSheetConsumer.setStyleSheet(styleSheetText);

		return true;
	}

	return false;
}


} // namespace iqtgui


#endif // !iqtgui_included


