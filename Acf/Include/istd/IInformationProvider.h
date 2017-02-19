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


#ifndef istd_IInformationProvider_included
#define istd_IInformationProvider_included


// Qt includes
#include <QtCore/QString>
#include <QtCore/QDateTime>

// ACF includes
#include <istd/IChangeable.h>


namespace istd
{


/**
	Common interface for class providing some basic information object.
*/
class IInformationProvider: virtual public IChangeable
{
public:
	/**
		Category of information.
	*/
	enum InformationCategory
	{
		/**
			Information is unimportant, for example can be used for diagnostic.
		*/
		IC_NONE,
		/**
			Normal information level.
		*/
		IC_INFO,
		/**
			Information about warning, processing could be done.
		*/
		IC_WARNING,
		/**
			Information about error, processing could not be done correctly.
		*/
		IC_ERROR,
		/**
			Information about critical error - unnormal state of system, should never be returned.
		*/
		IC_CRITICAL
	};

	/**
		Additionally information flags.
	*/
	enum InformationTypeFlags
	{
		ITF_DEBUG = 0x1,
		ITF_SYSTEM = 0x2,
		ITF_USER = 0x4
	};

	/**
		Get optional time stamp of the information.
		\return time stamp associated with this information, or null QDateTime object, if there is no associated time stamp.
	*/
	virtual QDateTime GetInformationTimeStamp() const = 0;

	/**
		Get category of the information.
		\sa InformationCategory
	*/
	virtual InformationCategory GetInformationCategory() const = 0;

	/**
		Get binary ID of the information using to automatical identification of this information type.
		If there is no information ID it returns negative value.
	*/
	virtual int GetInformationId() const = 0;

	/**
		Get the text description of the information.
		If there is no description provided it contains empty string.
	*/
	virtual QString GetInformationDescription() const = 0;

	/**
		Get the source of the information.
		If there is no source information provided it contains empty string.
	*/
	virtual QString GetInformationSource() const = 0;

	/**
		Get flags of the information.
		\sa InformationTypeFlags
	*/
	virtual int GetInformationFlags() const = 0;
};


} // namespace istd


#endif // !istd_IInformationProvider_included


