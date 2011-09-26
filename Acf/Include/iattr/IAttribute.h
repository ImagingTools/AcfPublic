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


#ifndef iattr_IAttribute_included
#define iattr_IAttribute_included


#include "iser/IObject.h"

#include "iattr/iattr.h"


namespace iattr
{


/**
	Common interface for an attribute.
*/
class IAttribute: virtual public iser::IObject
{
public:
	enum AttributeFlags
	{
		/**
			Attribute is persistent.
		*/
		AF_PERSISTENT = 0x1
	};

	/**
		Get default value for the attribute.
	*/
	virtual const iser::IObject* GetDefaultAttributeValue() const = 0;
};


} // namespace iattr


#endif // !iattr_IAttribute_included


