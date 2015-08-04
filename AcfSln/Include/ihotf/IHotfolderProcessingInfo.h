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


#ifndef ihotf_IHotfolder_included
#define ihotf_IHotfolder_included


// ACF includes
#include "iser/ISerializable.h"

#include "iprm/IParamsSet.h"


// AcfSln includes
#include "ihotf/IHotfolderProcessingItem.h"


namespace ihotf
{


/**
	Interface for a hotfolder's processing data model.
*/
class IHotfolderProcessingInfo: virtual public iser::ISerializable
{
public:
	/**
		Data model change notification flags.
	*/
	enum ChangeFlags
	{
		CF_FILE_ADDED = 0xd729a03,
		CF_FILE_REMOVED,
		CF_WORKING_STATE_CHANGED,
		CF_CREATE
	};

	/**
		Add new processing item to hotfolder's state model.
		If the output file name is not set, the file name will be calculated automatically.
	*/
	virtual const ihotf::IHotfolderProcessingItem* AddProcessingItem(
				const QString& inputFilePath,
				const QString& outputFilePath = QString()) = 0;
	
	/**
		Remove existing processing item from the hotfolder's state model.
	*/
	virtual void RemoveProcessingItem(ihotf::IHotfolderProcessingItem* fileItemPtr) = 0;
		
	/**
		Get the count of processing items in the hotfolder.
	*/
	virtual int GetProcessingItemsCount() const = 0;

	/**
		Get the processing item with the index \c processingItemIndex.
	*/
	virtual ihotf::IHotfolderProcessingItem* GetProcessingItem(int processingItemIndex) const = 0;

	/**
		Get the working state of the hotfolder.
	*/
	virtual bool IsWorking() const = 0;

	/**
		If \c working is \c true, the hotfolder processing will be started or stopped otherwise.
	*/
	virtual void SetWorking(bool working = true) = 0;
};


} // namespace ihotf


#endif // !ihotf_IHotfolder_included


