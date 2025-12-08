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


#include <ilog/CStandardStreamBridge.h>


// ACF includes
#include <ilog/CMessage.h>


namespace ilog
{


// public methods

CStandardStreamBridge::CStandardStreamBridge(
			std::ostream &stream,
			ilog::IMessageConsumer& messageConsumer,
			istd::IInformationProvider::InformationCategory informationSeverity)
	:m_stream(stream),
	m_messageConsumer(messageConsumer),
	m_informationSeverity(informationSeverity)
{
	// Store original buffer:
	m_originalBufferPtr = stream.rdbuf();

	// Insert hook:
	stream.rdbuf(this);
}


CStandardStreamBridge::~CStandardStreamBridge()
{
	QMutexLocker lock(&m_bufferMutex);

	// Restore the original buffer:
	m_stream.rdbuf(m_originalBufferPtr);
}


// protected methods

// reimplemented (std::basic_streambuf)

std::streamsize CStandardStreamBridge::xsputn(const char* data, std::streamsize bufferSize)
{
	QMutexLocker lock(&m_bufferMutex);

	m_textBuffer += data;

	return bufferSize;
}


std::basic_streambuf<char>::int_type CStandardStreamBridge::overflow(int_type v)
{
	QMutexLocker lock(&m_bufferMutex);

	if (v == '\n'){
		m_messageConsumer.AddMessage(ilog::IMessageConsumer::MessagePtr(new ilog::CMessage(m_informationSeverity, 0, m_textBuffer, "")));

		m_textBuffer.clear();
	}
	else{
		m_textBuffer += QChar(v);
	}

	return v;
}


} // namespace ilog


