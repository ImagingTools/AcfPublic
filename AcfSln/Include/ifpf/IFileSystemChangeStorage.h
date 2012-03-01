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


#ifndef ifpf_IFileSystemChangeStorage_included
#define ifpf_IFileSystemChangeStorage_included


// ACF includes
#include "istd/IChangeable.h"
#include <QtCore/QString>


namespace ifpf
{


/**
	Common interface for a storage of files.
*/
class IFileSystemChangeStorage: virtual public istd::IChangeable
{
public:
	/**
		File system change flags.
	*/
	enum ChangeFlags
	{
		/**
			File(s) were added.
		*/
		CF_NEW = 0x1000000,

		/**
			File(s) were removed.
		*/
		CF_REMOVED = 0x2000000,

		/**
			File(s) were modified.
		*/
		CF_MODIFIED = 0x4000000,

		/**
			File's attributes were changed.
		*/
		CF_ATTRIBUTE_CHANGED = 0x8000000,

		/**
			All possible changes
		*/
		CF_SOME_CHANGES = CF_NEW | CF_REMOVED | CF_MODIFIED | CF_ATTRIBUTE_CHANGED
	};

	/**
		Get number of items in the storage.
	*/
	virtual int GetStorageItemsCount() const = 0;

	/**
		Get item path with the given index from the storage.
	*/
	virtual QString GetItemPath(int fileIndex) const = 0;

	/**
		Get item state with the given index from the storage.
	*/
	virtual int GetItemState(int fileIndex) const = 0;

	/**
		Update storage item. If the item not exists, new one will be created and added to the storage.
		If the item is marked as "removed" it will not deleted from the storage.
		Use RemoveItemStorage, if you want permanently remove the item from the storage.
	*/
	virtual void UpdateStorageItem(const QString& path, int itemFlags) = 0;

	/**
		Reset the storage.
	*/
	virtual void ResetStorage() = 0;
};


} // namespace ifpf


#endif // !ifpf_IFileSystemChangeStorage_included


