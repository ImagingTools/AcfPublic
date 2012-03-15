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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef istd_IInformation_included
#define istd_IInformation_included


// Qt includes
#include <QtCore/QString>
#include <QtCore/QDateTime>

// ACF includes
#include "istd/IPolymorphic.h"


namespace istd
{


/**
	Common interface for class providing some basic information object.
*/
class IInformation: virtual public IPolymorphic
{
public:
	/**
		Category of message.
	*/
	enum InformationCategory
	{
		IC_INFO,
		IC_WARNING,
		IC_ERROR,
		IC_CRITICAL
	};

	/**
		Additionaly message flags.
	*/
	enum InformationTypeFlags
	{
		ITF_DEBUG = 0x1,
		ITF_SYSTEM = 0x2,
		ITF_USER = 0x4
	};

	/**
		Get optional time stamp of the message.
	*/
	virtual QDateTime GetTimeStamp() const = 0;

	/**
		Get category of the message.
		\sa InformationCategory
	*/
	virtual istd::IInformation::InformationCategory GetInformationCategory() const = 0;

	/**
		Get binary ID of the message using to automatical identification of this message type.
	*/
	virtual int GetInformationId() const = 0;

	/**
		Get the text of the message.
	*/
	virtual QString GetInformationDescription() const = 0;

	/**
		Get the source of the message.
	*/
	virtual QString GetSource() const = 0;

	/**
		Get flags of the message.
		\sa InformationFlags
	*/
	virtual int GetFlags() const = 0;
};


} // namespace istd


#endif // !istd_IInformation_included


