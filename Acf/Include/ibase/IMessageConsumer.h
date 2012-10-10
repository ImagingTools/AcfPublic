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


#ifndef ibase_IMessageConsumer_included
#define ibase_IMessageConsumer_included


#include "istd/IPolymorphic.h"
#include "istd/IInformationProvider.h"
#include "istd/TSmartPtr.h"


namespace ibase
{


/**
	Common interface for a message container consuming information objects (messages).

	\ingroup Main
*/
class IMessageConsumer: virtual public istd::IPolymorphic
{
public:
	typedef istd::TSmartPtr<const istd::IInformationProvider> MessagePtr;

	/**
		Check if some messge is supported.
		\param	messageCategory	category of message or -1 if undefined,
								\sa istd::IInformationProvider::InformationCategory.
		\param	messageId		ID of message as defined in istd::IInformationProvider or -1 if undefined.
		\param	messagePtr		optional message object, or NULL if undefined.
								Please note, this object will not be stored by receiver.
	*/
	virtual bool IsMessageSupported(
				int messageCategory = -1,
				int messageId = -1,
				const istd::IInformationProvider* messagePtr = NULL) const = 0;
	/**
		Adds a message item to the container. 
	*/
	virtual void AddMessage(const MessagePtr& messagePtr) = 0;
};


} // namespace ibase


#endif // !ibase_IMessageConsumer_included


