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


#ifndef ifpf_CFileSystemChangeStorage_included
#define ifpf_CFileSystemChangeStorage_included


// STL includes
#include <vector>


// ACF includes
#include "istd/TSmartPtr.h"

#include "isys/ICriticalSection.h"


// AcfSln includes
#include "ifpf/IFileSystemChangeStorage.h"


namespace ifpf
{


/**
	Implementation of the file storage.
	All public methods in this component are thread-safe immplemented.
*/
class CFileSystemChangeStorage: virtual public ifpf::IFileSystemChangeStorage
{
public:
	CFileSystemChangeStorage();

	// reimplemented (ifpf::IFileSystemChangeStorage)
	virtual int	 GetStorageItemsCount() const;
	virtual istd::CString GetItemPath(int fileIndex) const;
	virtual int GetItemState(int fileIndex) const;
	virtual void UpdateStorageItem(const istd::CString& path, int itemFlags);
	virtual void ResetStorage();

private:
	int GetFileIndexFromPath(const istd::CString& filePath) const;

private:
	struct FileItem
	{
		istd::CString path;
		int state;
	};

	typedef std::vector<FileItem> FileItems;
	FileItems m_storageItems;

	istd::TSmartPtr<isys::ICriticalSection> m_lockPtr;
};


} // namespace ifpf


#endif // !ifpf_CFileSystemChangeStorage_included

