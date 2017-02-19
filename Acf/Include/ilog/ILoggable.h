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


#ifndef ilog_ILoggable_included
#define ilog_ILoggable_included


#include <ilog/IMessageConsumer.h>

#include <istd/IPolymorphic.h>


namespace ilog
{


/**
	Inteface for object, which support the 
*/
class ILoggable: virtual public istd::IPolymorphic
{
public:
	/**
		Install log.
	*/
	virtual void SetLogPtr(IMessageConsumer* logPtr) = 0;
	
	/**
		Get log.
	*/
	virtual IMessageConsumer* GetLogPtr() const = 0;

	/**
		Enable/disable tracing.
	*/
	virtual void SetTracingEnabled(bool trace) = 0;

	/**
		Returns true if tracing enabled.
	*/
	virtual bool IsTracingEnabled() const = 0;
};


} // namespace ilog


#endif // !ilog_ILoggable_included


