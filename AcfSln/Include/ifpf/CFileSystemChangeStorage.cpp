/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "ifpf/CFileSystemChangeStorage.h"


// ACF includes
#include "istd/TChangeNotifier.h"
#include "istd/CStaticServicesProvider.h"

#include "isys/CSectionBlocker.h"


namespace ifpf
{


// public methods

CFileSystemChangeStorage::CFileSystemChangeStorage()
{
	m_lockPtr = istd::CreateService<isys::ICriticalSection>();

	I_ASSERT(m_lockPtr.IsValid());
}


// reimplemented (ifpf::IFileSystemChangeStorage)

int CFileSystemChangeStorage::GetStorageItemsCount() const
{
	isys::CSectionBlocker lock(const_cast<isys::ICriticalSection*>(m_lockPtr.GetPtr()));

	int itemsCount = int(m_storageItems.size());

	return itemsCount;
}


istd::CString CFileSystemChangeStorage::GetItemPath(int fileIndex) const
{
	isys::CSectionBlocker lock(const_cast<isys::ICriticalSection*>(m_lockPtr.GetPtr()));

	I_ASSERT(fileIndex >= 0);
	I_ASSERT(fileIndex < int(m_storageItems.size()));

	istd::CString filePath = m_storageItems[fileIndex].path;

	return filePath;
}


int CFileSystemChangeStorage::GetItemState(int fileIndex) const
{
	isys::CSectionBlocker lock(const_cast<isys::ICriticalSection*>(m_lockPtr.GetPtr()));

	I_ASSERT(fileIndex >= 0);
	I_ASSERT(fileIndex < int(m_storageItems.size()));

	int fileState = m_storageItems[fileIndex].state;

	return fileState;
}


void CFileSystemChangeStorage::UpdateStorageItem(const istd::CString& path, int itemFlags)
{
	isys::CSectionBlocker lock(const_cast<isys::ICriticalSection*>(m_lockPtr.GetPtr()));

	istd::CChangeNotifier changePtr(this, itemFlags);

	int itemIndex = GetFileIndexFromPath(path);
	if (itemIndex < 0){
		m_storageItems.push_back(FileItem());

		m_storageItems.back().path = path;
		m_storageItems.back().state = itemFlags;
	}
	else{
		FileItem& item = m_storageItems[itemIndex];

		item.state = itemFlags;
	}
}


void CFileSystemChangeStorage::ResetStorage()
{
	isys::CSectionBlocker lock(const_cast<isys::ICriticalSection*>(m_lockPtr.GetPtr()));

	istd::CChangeNotifier changePtr(this);

	m_storageItems.clear();
}


// private methods

int CFileSystemChangeStorage::GetFileIndexFromPath(const istd::CString& filePath) const
{
	for (int index = 0; index < int(m_storageItems.size()); ++index){
		if (m_storageItems[index].path == filePath){
			return index;
		}
	}

	return -1;
}


} // namespace ifpf


