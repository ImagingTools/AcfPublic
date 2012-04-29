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


#ifndef ibase_IMessageContainer_included
#define ibase_IMessageContainer_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include "istd/IInformationProvider.h"
#include "istd/TIHierarchical.h"

#include "iser/ISerializable.h"

#include "ibase/IMessageConsumer.h"


namespace ibase
{


/**
	Common interface for an message container.
*/
class IMessageContainer: virtual public IMessageConsumer, virtual public iser::ISerializable
{
public:
	typedef QVector<MessagePtr> Messages;

	enum ChangeFlags
	{
		CF_MESSAGE_ADDED = 1 << 6,
		CF_MESSAGE_REMOVED = 1 << 7,
		CF_RESET = 1 << 8
	};

	/**
		Set maximal number of messages in the container. 
		If a new message will be added to the full container, the oldest message will be removed.
		\param maxMessageCount maximal number of messages in the container. If the value equals -1,
		no limit is set for.
	*/
	virtual void SetMaxMessageCount(int maxMessageCount = -1) = 0;

	/**
		Set maximum time difference between the oldest and newest message. If calculated value is grated then this threshold,
		the oldest message will be removed if a new message will be added.
		\param maxLiveTime maximal time difference in seconds
	*/
	virtual void SetMaxLiveTime(int maxLiveTime = -1) = 0;

	/**
		Get worst message category.
		\sa IInformationProvider::InformationCategory
	*/
	virtual int GetWorstCategory() const = 0;

	/**
		This function returns messages in the container. 
	*/
	virtual Messages GetMessages() const = 0;

	/**
		Remove all message items from container.
	*/
	virtual void ClearMessages() = 0;
};


typedef istd::TIHierarchical<ibase::IMessageContainer> IHierarchicalMessageContainer;


} // namespace ibase


#endif // !ibase_IMessageContainer_included

