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


#ifndef ilog_CLogRouterComp_included
#define ilog_CLogRouterComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <ilog/IMessageConsumer.h>
#include <ilog/IMessageContainer.h>
#include <imod/IModel.h>
#include <imod/CSingleModelObserverBase.h>

namespace ilog
{


class CLogRouterComp
	: public icomp::CComponentBase
	, public imod::CSingleModelObserverBase
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef imod::CSingleModelObserverBase BaseClass2;
	I_BEGIN_COMPONENT(CLogRouterComp);
		I_REGISTER_INTERFACE(imod::IObserver)
		I_ASSIGN(m_messageContainerPtr, "InputMessageContainer", "Message container to track", true, "InputMessageContainer");
		I_ASSIGN_TO(m_messageContainerModelPtr, m_messageContainerPtr, true);
		I_ASSIGN(m_outputMessageConsumerPtr, "OutputMessageConsumer", "The acceptor of the forwarded messages", false, "OutputMessageConsumer");
		I_ASSIGN(m_minimalCategoryAttr, "MinimalCategory", "Minimal category to forward to the output log, negative value means forwarding everything", true, -1);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed() override;

	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(const istd::IChangeable::ChangeSet& changeSet) override;

private:
	QDateTime m_lastMessageTimestamp;
	QList<const istd::IInformationProvider*> m_lastProcessed;

private:
	I_REF(ilog::IMessageContainer, m_messageContainerPtr);
	I_REF(imod::IModel, m_messageContainerModelPtr);
	I_REF(ilog::IMessageConsumer, m_outputMessageConsumerPtr);
	I_ATTR(int, m_minimalCategoryAttr);
};

} // namespace ilog


#endif // !ilog_CLogRouterComp_included
