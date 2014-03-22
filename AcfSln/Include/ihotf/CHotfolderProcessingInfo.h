/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef ihotf_CHotfolderProcessingInfo_included
#define ihotf_CHotfolderProcessingInfo_included


// Qt includes
#include <QtCore/QMap>

// Qt includes
#include <QtCore/QMutex>

// ACF includes
#include "istd/TOptPointerVector.h"
#include "istd/TDelPtr.h"
#include "istd/TSmartPtr.h"
#include "istd/TChangeDelegator.h"
#include "imod/TModelWrap.h"

// AcfSln includes
#include "ihotf/IHotfolderProcessingInfo.h"
#include "ihotf/CHotfolderProcessingItem.h"


namespace ihotf
{


/**
	Implementation of the processing data model of the hotfolder.
*/
class CHotfolderProcessingInfo: virtual public ihotf::IHotfolderProcessingInfo
{
public:
	CHotfolderProcessingInfo();

	/**
		Return \c true if the item for the given input and output path already exists.
		If foundItemPtr not equals \c NULL and an item was found, \c foundItemPtr will be set to the found item.
	*/
	virtual bool ItemExists(const QString& inputFilePath, ihotf::IHotfolderProcessingItem** foundItemPtr = NULL) const;
	virtual bool ItemExists(const ihotf::IHotfolderProcessingItem& processingItem) const;

	// reimplemented (ihotf::IHotfolderProcessingInfo)
	virtual const ihotf::IHotfolderProcessingItem* AddProcessingItem(
				const QString& inputFilePath,
				const QString& outputFilePath = QString());
	virtual void RemoveProcessingItem(ihotf::IHotfolderProcessingItem* fileItemPtr);
	virtual int GetProcessingItemsCount() const;
	virtual ihotf::IHotfolderProcessingItem* GetProcessingItem(int processingItemIndex) const;
	virtual bool IsWorking() const;
	virtual void SetWorking(bool working = true);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	typedef imod::TModelWrap<
				istd::TChangeDelegator<
						ihotf::CHotfolderProcessingItem> > ProcessingItem;
	typedef istd::TPointerVector<ihotf::IHotfolderProcessingItem> FileItems;

	FileItems m_processingItems;

	bool m_isWorking;

	mutable QMutex m_mutex;
};


} // namespace ihotf


#endif // !ihotf_CHotfolderProcessingInfo_included

