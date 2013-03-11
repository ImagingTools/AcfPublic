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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_CMessageContainer_included
#define ibase_CMessageContainer_included


// Qt includes
#include <QtCore/QList>
#include <QtCore/QMutex>

// ACF includes
#include "istd/IInformationProvider.h"

#include "ibase/IMessageContainer.h"
#include "ibase/IMessageConsumer.h"
#include "ibase/THierarchicalBase.h"


namespace ibase
{		


/**
	Basic implementation of a message container.
*/
class CMessageContainer:
			public ibase::THierarchicalBase<IHierarchicalMessageContainer>,
			virtual public IMessageConsumer
{
public:
	CMessageContainer();
	CMessageContainer(const CMessageContainer& container);

	virtual void AddChildContainer(IHierarchicalMessageContainer* childContainerPtr);

	void SetSlaveConsumer(ibase::IMessageConsumer* consumerPtr);

	/**
		Set maximal number of messages in the container. 
		If the container is full and a new message is added, the oldest message will be removed.
		\param maxMessageCount maximal number of messages in the container. If the value equals -1,
		no limit is set for.
	*/
	void SetMaxMessageCount(int maxMessageCount = -1);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (ibase::IMessageContainer)
	virtual int GetWorstCategory() const;
	virtual Messages GetMessages() const;
	virtual void ClearMessages();

	// reimplemented (ibase::IMessageConsumer)
	virtual bool IsMessageSupported(
				int messageCategory = -1,
				int messageId = -1,
				const istd::IInformationProvider* messagePtr = NULL) const;
	virtual void AddMessage(const IMessageConsumer::MessagePtr& messagePtr);

	// reimplemented (ibase::IHierarchicalMessageContainer)
	virtual int GetChildsCount() const;
	virtual IHierarchicalMessageContainer* GetChild(int index) const;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const istd::IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);

private:
	typedef QList<IMessageConsumer::MessagePtr> MessageList;
	MessageList m_messages;

	typedef QVector<IHierarchicalMessageContainer*> Childs;
	Childs m_childContainers;

	ibase::IMessageConsumer* m_slaveConsumerPtr;

	int m_maxMessagesCount;

	int m_worstCategory;
};


} // namespace ibase


#endif // !ibase_CMessageContainer_included


