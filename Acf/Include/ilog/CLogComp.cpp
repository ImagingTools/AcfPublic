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


#include "ilog/CLogComp.h"


namespace ilog
{


// public methods

// reimplemented (ilog::IMessageConsumer)

bool CLogComp::IsMessageSupported(
			int messageCategory,
			int messageId,
			const istd::IInformationProvider* messagePtr) const
{
	return BaseClass2::IsMessageSupported(messageCategory, messageId, messagePtr);
}


void CLogComp::AddMessage(const IMessageConsumer::MessagePtr& messagePtr)
{
	BaseClass2::AddMessage(messagePtr);

	BaseClass::AddMessage(messagePtr);
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CLogComp::OnComponentCreated()
{
	if (m_maxMessageCountAttrPtr.IsValid()){
		SetMaxMessageCount(m_maxMessageCountAttrPtr->GetValue());
	}
}


} // namespace ilog


