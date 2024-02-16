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


#ifndef istd_ILogger_included
#define istd_ILogger_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include <istd/IInformationProvider.h>


namespace istd
{


/**
	Common interface for classes sending some log info.
	Default implementation is provided for convinience and it does nothing.

	\ingroup Logging
*/
class ILogger: virtual public IPolymorphic
{
public:
	/**
		Check if any log message is consumed.
		Default implementation retuns false.
	*/
	virtual bool IsLogConsumed(
				const IInformationProvider::InformationCategory* categoryPtr = NULL,
				const int* flagsPtr = NULL) const;

	/**
		Send any message to log.
		Default implementation do nothing.
		\param	category		message category.
		\param	id				binary id identifying this message type for automatical processing.
		\param	message			message text will be send.
		\param	messageSource	source of the message.
		\return	true, if it was possible to send this message and it is 'consumed'.
	*/
	virtual bool SendLogMessage(
				IInformationProvider::InformationCategory category,
				int id,
				const QString& message,
				const QString& messageSource,
				int flags = 0) const;

protected:
	/**
		Decorate message parts before outputting.
	*/
	virtual void DecorateMessage(
				IInformationProvider::InformationCategory category,
				int id,
				int flags,
				QString& message,
				QString& messageSource) const;
};


// inline methods

inline bool ILogger::IsLogConsumed(
			const IInformationProvider::InformationCategory* /*categoryPtr*/,
			const int* /*flagsPtr*/) const
{
	return false;
}


inline bool ILogger::SendLogMessage(
			IInformationProvider::InformationCategory /*category*/,
			int /*id*/,
			const QString& /*message*/,
			const QString& /*messageSource*/,
			int /*flags*/) const
{
	return false;
}


// protected methods

inline void ILogger::DecorateMessage(
			IInformationProvider::InformationCategory /*category*/,
			int /*id*/,
			int /*flags*/,
			QString& /*message*/,
			QString& /*messageSource*/) const
{
}


} // namespace istd


#endif // !istd_ILogger_included


