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


#ifndef ihotf_CFileSystemChangeStorage_included
#define ihotf_CFileSystemChangeStorage_included


// Qt includes
#include <QtCore/QVector>
#include <QtCore/QMutex>

// ACF includes
#include "istd/TSmartPtr.h"

// AcfSln includes
#include "ihotf/IFileSystemChangeStorage.h"


namespace ihotf
{


/**
	Implementation of the file storage.
	All public methods in this component are thread-safe immplemented.
*/
class CFileSystemChangeStorage: virtual public ihotf::IFileSystemChangeStorage
{
public:
	// reimplemented (ihotf::IFileSystemChangeStorage)
	virtual int	 GetStorageItemsCount() const;
	virtual QString GetItemPath(int fileIndex) const;
	virtual int GetItemState(int fileIndex) const;
	virtual void UpdateStorageItem(const QString& path, int itemFlags);
	virtual void ResetStorage();

private:
	int GetFileIndexFromPath(const QString& filePath) const;

private:
	struct FileItem
	{
		QString path;
		int state;
	};

	typedef QVector<FileItem> FileItems;
	FileItems m_storageItems;

	mutable QMutex m_mutex;
};


} // namespace ihotf


#endif // !ihotf_CFileSystemChangeStorage_included

