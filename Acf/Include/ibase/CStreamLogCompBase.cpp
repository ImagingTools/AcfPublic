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


#include "ibase/CStreamLogCompBase.h"


// Qt includes
#include <QtCore/QDateTime>

// ACF includes
#include "istd/IInformationProvider.h"


namespace ibase
{


// public methods

CStreamLogCompBase::CStreamLogCompBase()
:	m_isLastDotShown(false)
{
}


// reimplemented (ibase::IMessageConsumer)

bool CStreamLogCompBase::IsMessageSupported(
			int /*messageCategory*/,
			int /*messageId*/,
			const istd::IInformationProvider* /*messagePtr*/) const
{
	return true;
}


void CStreamLogCompBase::AddMessage(const MessagePtr& messagePtr)
{
	if (messagePtr.IsValid()){
		if (messagePtr->GetInformationCategory() >= *m_minPriorityAttrPtr){
			if (m_isLastDotShown){
				NewLine();

				m_isLastDotShown = false;
			}

			WriteMessageToStream(*messagePtr);
		}
		else if (*m_isDotEnabledAttrPtr){
			WriteText(".");

			m_isLastDotShown = true;
		}
	}
}


// protected methods

void CStreamLogCompBase::WriteMessageToStream(const istd::IInformationProvider& message)
{
	QString messageText = GenerateMessageText(message);
	
	WriteText(messageText);

	NewLine();
}


QString CStreamLogCompBase::GenerateMessageText(const istd::IInformationProvider& message) const
{
	QString messageText = message.GetInformationDescription();

	if (m_useTimeStampAttrPtr.IsValid() && *m_useTimeStampAttrPtr){
		QString messageTimeStamp = message.GetInformationTimeStamp().toString();

		messageText = QString("[%1] %2").arg(messageTimeStamp).arg(messageText);
	}

	return messageText;
}


// reimplemented (icomp::CComponentBase)

void CStreamLogCompBase::OnComponentDestroyed()
{
	BaseClass::OnComponentDestroyed();

	if (m_isLastDotShown){
		NewLine();

		m_isLastDotShown = false;
	}
}


} // namespace ibase


