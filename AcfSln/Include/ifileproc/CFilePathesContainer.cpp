/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#include <ifileproc/CFilePathesContainer.h>


// Qt includes
#include <QtCore/QStringList>

// ACF includes
#include <istd/CChangeNotifier.h>


namespace ifileproc
{


// public methods

void CFilePathesContainer::ResetFiles()
{
	istd::CChangeNotifier changePtr(this);

	m_fileList.clear();
}

bool CFilePathesContainer::InsertFile(const QString& file, int index, bool ignoreNonExistingFiles)
{
	bool addFile = true;

	QFileInfo fileInfo(file);

	if (ignoreNonExistingFiles){
		addFile = fileInfo.exists();
	}
	
	if (addFile){
		istd::CChangeNotifier changePtr(this);
	
		if (index < 0){
			m_fileList.push_back(fileInfo);
		}
		else{
			m_fileList.insert(index, fileInfo);
		}

		return true;
	}

	return false;
}


// reimplemented (ifile::IFileListProvider)

const QFileInfoList& CFilePathesContainer::GetFileList() const
{
	return m_fileList;
}


} // namespace ifileproc


