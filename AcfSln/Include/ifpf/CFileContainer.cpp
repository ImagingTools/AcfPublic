/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "ifpf/CFileContainer.h"


// Qt includes
#include <QtCore/QStringList>


// ACF includes
#include "istd/TChangeNotifier.h"


namespace ifpf
{


// public methods

void CFileContainer::ResetFiles()
{
	istd::CChangeNotifier changePtr(this);

	m_fileList.clear();
}

bool CFileContainer::InsertFile(const QString& file, int index)
{
	QFileInfo fileInfo(file);
	if (fileInfo.exists()){
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


// reimplemented (ibase::IFileListProvider)

QStringList CFileContainer::GetFileList() const
{
	QStringList fileList;

	for (		QFileInfoList::ConstIterator index = m_fileList.constBegin(); 
				index != m_fileList.constEnd();
				index++){
		fileList.push_back((*index).absoluteFilePath());
	}

	return fileList;
}


} // namespace ifpf


