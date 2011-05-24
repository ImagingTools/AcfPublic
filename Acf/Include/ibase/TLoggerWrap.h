/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_TLoggerWrap_included
#define ibase_TLoggerWrap_included


#include "istd/ILogger.h"

#include "ibase/IMessageConsumer.h"
#include "ibase/ILoggable.h"
#include "ibase/CMessage.h"


namespace ibase
{		


/**
	Class wrapper implementing interface istd::ILogger sending log messages over ibase::IMessageConsumer.
	Access to interface ibase::IMessageConsumer must be registered by user.
	To register it use interface ibase::ILoggable implemented by this wrapper.

	\ingroup Helpers
*/
template <class Base>
class TLoggerWrap: virtual public Base, virtual public ILoggable, virtual public istd::ILogger
{
public:
	TLoggerWrap();

	// reimplemented (ibase::ILoggable)
	virtual void SetLogPtr(ibase::IMessageConsumer* logPtr);
	virtual ibase::IMessageConsumer* GetLogPtr() const;

protected:
	/**
		Send info message to log.
		\sa ibase::IMessage for message meaning documentation.
		\param	id				binary id identifying this message type for automatical processing.
		\param	message			message text will be send.
		\param	messageSource	source of the message
	*/
	bool SendInfoMessage(
				int id,
				const istd::CString& message,
				const istd::CString& messageSource = istd::CString(),
				int flags = 0) const;

	/**
		Send warning message to log.
		\sa ibase::IMessage for message meaning documentation.
		\param	id				binary id identifying this message type for automatical processing.
		\param	message			message text will be send.
		\param	messageSource	source of the message
	*/
	bool SendWarningMessage(
				int id,
				const istd::CString& message,
				const istd::CString& messageSource = istd::CString(),
				int flags = 0) const;

	/**
		Send error message to log.
		\sa ibase::IMessage for message meaning documentation.
		\param	id				binary id identifying this message type for automatical processing.
		\param	message			message text will be send.
		\param	messageSource	source of the message
	*/
	bool SendErrorMessage(
				int id,
				const istd::CString& message,
				const istd::CString& messageSource = istd::CString(),
				int flags = 0) const;

	/**
		Send critical message to log.
		\sa ibase::IMessage for message meaning documentation.
		\param	id				binary id identifying this message type for automatical processing.
		\param	message			message text will be send.
		\param	messageSource	optional human readable description of message source.
	*/
	bool SendCriticalMessage(
				int id,
				const istd::CString& message,
				const istd::CString& messageSource = istd::CString(),
				int flags = 0) const;

	// reimplemented (istd::ILogger)
	virtual bool IsLogConsumed(
				const MessageCategory* categoryPtr = NULL,
				const int* flagsPtr = NULL) const;
	virtual bool SendLogMessage(
				MessageCategory category,
				int id,
				const istd::CString& message,
				const istd::CString& messageSource,
				int flags = 0) const;

private:
	ibase::IMessageConsumer* m_logPtr;
};


// public methods

template <class Base>
TLoggerWrap<Base>::TLoggerWrap()
:	m_logPtr(NULL)
{
}


// pseudo-reimplemented (ibase::ILoggable)

template <class Base>
inline void TLoggerWrap<Base>::SetLogPtr(ibase::IMessageConsumer* logPtr)
{
	m_logPtr = logPtr;
}


template <class Base>
inline ibase::IMessageConsumer* TLoggerWrap<Base>::GetLogPtr() const
{
	return m_logPtr;
}


// protected methods

template <class Base>
bool TLoggerWrap<Base>::SendInfoMessage(int id, const istd::CString& message, const istd::CString& messageSource, int flags) const
{
	return SendLogMessage(istd::ILogger::MC_INFO, id, message, messageSource, flags);
}


template <class Base>
bool TLoggerWrap<Base>::SendWarningMessage(int id, const istd::CString& message, const istd::CString& messageSource, int flags) const
{
	return SendLogMessage(istd::ILogger::MC_WARNING, id, message, messageSource, flags);
}


template <class Base>
bool TLoggerWrap<Base>::SendErrorMessage(int id, const istd::CString& message, const istd::CString& messageSource, int flags) const
{
	return SendLogMessage(istd::ILogger::MC_ERROR, id, message, messageSource, flags);
}


template <class Base>
bool TLoggerWrap<Base>::SendCriticalMessage(int id, const istd::CString& message, const istd::CString& messageSource, int flags) const
{
	return SendLogMessage(istd::ILogger::MC_CRITICAL, id, message, messageSource, flags);
}


// reimplemented (istd::ILogger)

template <class Base>
bool TLoggerWrap<Base>::IsLogConsumed(
			const MessageCategory* /*categoryPtr*/,
			const int* /*flagsPtr*/) const
{
	return (m_logPtr != NULL);
}


template <class Base>
bool TLoggerWrap<Base>::SendLogMessage(
			istd::ILogger::MessageCategory category,
			int id,
			const istd::CString& message,
			const istd::CString& messageSource,
			int flags) const
{
	if (m_logPtr != NULL){
		istd::CString correctedMessage = message;
		istd::CString correctedMessageSource = messageSource;

		DecorateMessage(category, id, flags, correctedMessage, correctedMessageSource);

		m_logPtr->AddMessage(new ibase::CMessage(category, id, correctedMessage, correctedMessageSource, flags));
	
		return true;
	}

	return false;
}


} // namespace ibase


#endif // !ibase_TLoggerWrap_included


