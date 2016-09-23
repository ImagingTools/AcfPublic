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


#include <ihotf/CFileSystemChangeStorage.h>


// Qt includes
#include <QtCore/QMutexLocker>

// ACF includes
#include <istd/CChangeNotifier.h>


namespace ihotf
{


// public methods

CFileSystemChangeStorage::CFileSystemChangeStorage()
	:m_mutex(QMutex::Recursive)
{
}


// reimplemented (ihotf::IFileSystemChangeStorage)

int CFileSystemChangeStorage::GetStorageItemsCount() const
{
	QMutexLocker locker(&m_mutex);

	int itemsCount = int(m_storageItems.size());

	return itemsCount;
}


QString CFileSystemChangeStorage::GetItemPath(int fileIndex) const
{
	QMutexLocker locker(&m_mutex);

	Q_ASSERT(fileIndex >= 0);
	Q_ASSERT(fileIndex < int(m_storageItems.size()));

	QString filePath = m_storageItems[fileIndex].path;

	return filePath;
}


int CFileSystemChangeStorage::GetItemState(int fileIndex) const
{
	QMutexLocker locker(&m_mutex);

	Q_ASSERT(fileIndex >= 0);
	Q_ASSERT(fileIndex < int(m_storageItems.size()));

	int fileState = m_storageItems[fileIndex].state;

	return fileState;
}


void CFileSystemChangeStorage::UpdateStorageItem(const QString& path, int changeFlag)
{
	QMutexLocker locker(&m_mutex);

	const istd::IChangeable::ChangeSet updateItemChangeSet(changeFlag);
	istd::CChangeNotifier notifier(this, &updateItemChangeSet);
	Q_UNUSED(notifier);

	int itemIndex = GetFileIndexFromPath(path);
	if (itemIndex < 0){
		m_storageItems.push_back(FileItem());

		m_storageItems.back().path = path;
		m_storageItems.back().state = changeFlag;
	}
	else{
		FileItem& item = m_storageItems[itemIndex];

		item.state = changeFlag;
	}
}



void CFileSystemChangeStorage::RemoveStorageItem(int itemIndex)
{
	QMutexLocker locker(&m_mutex);

	istd::CChangeNotifier changePtr(this);

	m_storageItems.removeAt(itemIndex);
}


void CFileSystemChangeStorage::ResetStorage()
{
	QMutexLocker locker(&m_mutex);

	const istd::IChangeable::ChangeSet updateItemChangeSet(CF_DATA_RESET);
	istd::CChangeNotifier notifier(this, &updateItemChangeSet);
	Q_UNUSED(notifier);

	m_storageItems.clear();
}


// private methods

int CFileSystemChangeStorage::GetFileIndexFromPath(const QString& filePath) const
{
	for (int index = 0; index < int(m_storageItems.size()); ++index){
		if (m_storageItems[index].path == filePath){
			return index;
		}
	}

	return -1;
}


} // namespace ihotf


