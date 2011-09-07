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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CFileList.h"
#include "iqt/CDirList.h"


// Qt includes
#include <QFileInfo>


namespace iqt
{


CFileList::CFileList(QObject* parent) 
:	QObject(parent)
{
}


bool CFileList::Create(
			const QDir& root,
			int minRecursionDepth,
			int maxRecursionDepth,
			const QStringList& nameFilters,
			QDir::SortFlags sortSpec)
{
	clear();

	CDirList dirList;
	if (!dirList.Create(root, minRecursionDepth, maxRecursionDepth)){
		return false;
	}

	for (QStringList::const_iterator dirIter = dirList.begin(); dirIter != dirList.end(); ++dirIter){
		QString dirPath = *dirIter;

		QDir dir(dirPath);
		dir.setFilter(QDir::Files);

		QStringList files = dir.entryList(nameFilters, QDir::Files, sortSpec);

		for (		QStringList::const_iterator fileIter = files.begin();
					fileIter != files.end();
					++fileIter){
			const QString& fileName = *fileIter;

			QString filePath = dir.absoluteFilePath(fileName);

			push_back(filePath);	

			Q_EMIT currentFile(filePath);
		}
	}

	return true;
}


} // namespace iqt


