/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef ilog_CLogComp_included
#define ilog_CLogComp_included


// ACF includes
#include "ilog/CLogCompBase.h"
#include "ilog/CMessageContainer.h"


namespace ilog
{


/**
	Data model of logging component.

	\ingroup Logging
*/
class CLogComp:
			public ilog::CLogCompBase,
			public ilog::CMessageContainer
{
public:
	typedef CLogCompBase BaseClass;
	typedef ilog::CMessageContainer BaseClass2;

	I_BEGIN_COMPONENT(CLogComp);
		I_REGISTER_INTERFACE(ilog::IMessageContainer);
		I_ASSIGN(m_maxMessageCountAttrPtr, "MaxMessageCount", "Maximal number of messages", false, 1000);
	I_END_COMPONENT;

	// reimplemented (ilog::IMessageConsumer)
	virtual bool IsMessageSupported(
				int messageCategory = -1,
				int messageId = -1,
				const istd::IInformationProvider* messagePtr = NULL) const;
	virtual void AddMessage(const MessagePtr& messagePtr);

protected:
	// reimplemented (ilog::CLogCompBase)
	virtual void WriteMessageToLog(const MessagePtr& messagePtr);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(int, m_maxMessageCountAttrPtr);
};


} // namespace ilog


#endif // !ilog_CLogComp_included

