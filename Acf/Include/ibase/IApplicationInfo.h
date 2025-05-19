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


#pragma once


// Qt includes
#include <QtCore/QString>

// ACF includes
#include <istd/IPolymorphic.h>
#include <iser/IVersionInfo.h>
#include <ibase/ibase.h>


namespace ibase
{


/**
	This interface provides some information about the application.

	\ingroup Main
*/
class IApplicationInfo: virtual public istd::IPolymorphic
{
public:
	enum ApplicationAttribute
	{
		AA_COMPANY_NAME,
		AA_PRODUCT_NAME,
		AA_PRODUCT_EDITION,
		AA_APPLICATION_ID,
		AA_APPLICATION_NAME,
		AA_APPLICATION_SUBNAME,
		AA_APPLICATION_TYPE,
		AA_APPLICATION_PATH,
		AA_LEGAL_COPYRIGHT,
		AA_MAIN_VERSION,
		AA_USER = 100
	};

	/**
		Get value of application attribute.
		\param	attributeId	ID of application attribute \sa ApplicationAttribute.
	*/
	virtual QString GetApplicationAttribute(int attributeId, bool allowTranslation = true) const = 0;

	/**
		Get ID of main module version ID for \c iser::IVersionInfo.
		This ID is used to identify which module is main application module.
		The meaning is the same as meaning of \c versionId parameters in interface \c iser::IVersionInfo.
		\return	ID of main module, or negative value if it is undefined.
	*/
	virtual int GetMainVersionId() const = 0;

	/**
		Get access to application version info.
	*/
	virtual const iser::IVersionInfo& GetVersionInfo() const = 0;
};


} // namespace ibase


