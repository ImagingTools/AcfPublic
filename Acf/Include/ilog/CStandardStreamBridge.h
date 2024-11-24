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


#ifndef ilog_CStandardStreamBridge_included
#define ilog_CStandardStreamBridge_included


// STL includes
#include <iostream>
#include <streambuf>
#include <string>

// Qt includes
#include <QtCore/QString>
#include <QtCore/QMutex>

// ACF includes
#include <ilog/IMessageConsumer.h>


namespace ilog
{


class CStandardStreamBridge: protected std::basic_streambuf<char>
{
public:
	typedef std::basic_streambuf<char> BaseClass;

	CStandardStreamBridge(
				std::ostream &stream,
				ilog::IMessageConsumer& messageConsumer,
				istd::IInformationProvider::InformationCategory informationSeverity);
	virtual ~CStandardStreamBridge();

protected:
	// reimplemented (std::basic_streambuf)
	virtual std::streamsize xsputn(const char* data, std::streamsize bufferSize) override;
	virtual int_type overflow(int_type v) override;

private:
	std::ostream& m_stream;
	std::streambuf* m_originalBufferPtr;

	ilog::IMessageConsumer& m_messageConsumer;
	istd::IInformationProvider::InformationCategory m_informationSeverity;

	QString m_textBuffer;
	mutable QMutex m_bufferMutex;
};


} // namespace ilog


#endif // !ilog_CStandardStreamBridge_included


