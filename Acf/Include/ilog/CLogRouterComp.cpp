/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <ilog/CLogRouterComp.h>


// ACF includes
#include <ilog/CMessage.h>


namespace
{


bool CompareByTimestamps(ilog::IMessageConsumer::MessagePtr& lhs, ilog::IMessageConsumer::MessagePtr& rhs)
{
	return lhs->GetInformationTimeStamp() < rhs->GetInformationTimeStamp();
}
}


namespace ilog
{


// protected methods

// reimplemented (icomp::CComponentBase)

void CLogRouterComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (!m_messageContainerModelPtr.IsValid() || !m_messageContainerPtr.IsValid() || !m_outputMessageConsumerPtr.IsValid()){
		return;
	}

	m_messageContainerModelPtr->AttachObserver(this);

	m_lastMessageTimestamp = QDateTime::currentDateTime();
}


void CLogRouterComp::OnComponentDestroyed()
{
	EnsureModelDetached();

	BaseClass::OnComponentDestroyed();
}


// reimplemented (imod::CSingleModelObserverBase)

void CLogRouterComp::OnUpdate(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	IMessageContainer::Messages messages = m_messageContainerPtr->GetMessages();
	if (m_messageContainerPtr->GetWorstCategory() < *m_minimalCategoryAttr)
		return;

	// Remove empty message pointers if there are any
	IMessageContainer::Messages::iterator iter = messages.begin();
	while (iter != messages.end()){
		ilog::IMessageConsumer::MessagePtr value = *iter;

        if (        !value.IsValid() ||
                    value->GetInformationCategory() < *m_minimalCategoryAttr ||
                    value->GetInformationTimeStamp() < m_lastMessageTimestamp ||
                    (m_lastProcessed.contains(value.GetPtr()) &&
                    value->GetInformationTimeStamp() <= m_lastMessageTimestamp)){
			iter = messages.erase(iter);
		}
	}

	// sort by timestamp

	std::vector<IMessageConsumer::MessagePtr> sortedMessages(messages.begin(), messages.end());

	std::sort(sortedMessages.begin(), sortedMessages.end(), CompareByTimestamps);
	for (size_t i = 0, size = sortedMessages.size(); i < size; ++i){
		const IMessageConsumer::MessagePtr message = sortedMessages[i];

		ilog::CMessage* messageCopy = new ilog::CMessage();
		if (!message.IsValid() || !messageCopy->CopyFrom(*message)) {
			delete messageCopy;
			continue;
		}

		ilog::IMessageConsumer::MessagePtr messagePtr;
		messagePtr.SetPtr(messageCopy);
		m_outputMessageConsumerPtr->AddMessage(messagePtr);

		if (m_lastMessageTimestamp < messagePtr->GetInformationTimeStamp()){
			m_lastMessageTimestamp = messagePtr->GetInformationTimeStamp();
			m_lastProcessed.clear();
		}
		m_lastProcessed.append(message.GetPtr());
	}
}


} // namespace ilog


