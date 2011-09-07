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


#include "iqt/CDirList.h"


// Qt includes
#include <QFileInfo>


namespace iqt
{


CDirList::CDirList(QObject* parent) 
:	QObject(parent)
{
}


CDirList::CDirList(
			QObject* parent,
			const QDir& root,
			int minRecursionDepth,
			int maxRecursionDepth) 
:	QObject(parent)
{
	Create(root, minRecursionDepth, maxRecursionDepth);
}



bool CDirList::Create(
			const QDir& root,
			int minRecursionDepth,
			int maxRecursionDepth,
			bool doAppend)
{
	I_ASSERT(minRecursionDepth >= 0);

	if (!doAppend){
		clear();
	}

	QString rootPath = root.absolutePath();

	if (rootPath.isEmpty()){
		return false;
	}

	QFileInfo fileInfo(rootPath);
	if (!fileInfo.isDir()){
		return false;
	}

	DoSearch(root, minRecursionDepth, maxRecursionDepth);

	return true;
}


// protected methods

void CDirList::DoSearch(
			const QDir& root,
			int minRecursionDepth,
			int maxRecursionDepth)
{
	if (minRecursionDepth <= 0){
		QString rootPath = root.absolutePath();

		push_back(rootPath);

		Q_EMIT currentDir(rootPath);
	}

	if (maxRecursionDepth == 0){
		return;
	}

	QStringList entries = root.entryList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
	for (		QStringList::const_iterator iter = entries.begin();
				iter != entries.end();
				++iter){
		const QString& subDirName = *iter;

		QDir subDir = root;
		subDir.setPath(root.absoluteFilePath(subDirName));

		DoSearch(subDir, minRecursionDepth - 1, maxRecursionDepth - 1);
	}
}


} // namespace iqt


