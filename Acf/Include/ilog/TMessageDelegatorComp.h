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


#ifndef ilog_TMessageDelegatorComp_included
#define ilog_TMessageDelegatorComp_included


// ACF includes
#include "icomp/CComponentBase.h"
#include "ilog/IMessageConsumer.h"


namespace ilog
{		


/**
	Delegator component for a message consumer.

	\ingroup Logging
*/
template <class BaseComponent>
class TMessageDelegatorComp: public BaseComponent, virtual public ilog::IMessageConsumer
{
public:
	typedef BaseComponent BaseClass;

	I_BEGIN_COMPONENT(TMessageDelegatorComp);
		I_REGISTER_INTERFACE(ilog::IMessageConsumer);
		I_ASSIGN(m_slaveMessageConsumerCompPtr, "SlaveMessageConsumer", "Slave message consumer", false, "SlaveMessageConsumer");
	I_END_COMPONENT;

	// reimplemented (ilog::IMessageConsumer)
	virtual bool IsMessageSupported(
				int messageCategory = -1,
				int messageId = -1,
				const istd::IInformationProvider* messagePtr = NULL) const;
	virtual void AddMessage(const MessagePtr& messagePtr);

protected:
	I_REF(ilog::IMessageConsumer, m_slaveMessageConsumerCompPtr);
};


// public methods

// reimplemented (ilog::IMessageConsumer)

template <class BaseComponent>
bool TMessageDelegatorComp<BaseComponent>::IsMessageSupported(
			int messageCategory,
			int messageId,
			const istd::IInformationProvider* messagePtr) const
{
	if (m_slaveMessageConsumerCompPtr.IsValid()){
		return m_slaveMessageConsumerCompPtr->IsMessageSupported(messageCategory, messageId, messagePtr);
	}

	return true;
}


template <class BaseComponent>
void TMessageDelegatorComp<BaseComponent>::AddMessage(const MessagePtr& messagePtr)
{
	if (m_slaveMessageConsumerCompPtr.IsValid()){
		return m_slaveMessageConsumerCompPtr->AddMessage(messagePtr);
	}
}


} // namespace ilog


#endif // !ilog_TMessageDelegatorComp_included


