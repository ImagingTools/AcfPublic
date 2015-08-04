/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iattr_IEnumAttributeMetaInfo_included
#define iattr_IEnumAttributeMetaInfo_included


#include "iattr/IAttributeMetaInfo.h"


namespace iattr
{


/**
	Represents constraints of properties allowing values from enumerated set.
*/
class IEnumAttributeMetaInfo: virtual public IAttributeMetaInfo
{
public:
	/**
		Checks if other then enumerated values are allowed.
		If it is enabled option list represents presets only. In this case general constraints can be taken using \c GetOtherValueConstraints.
	*/
	virtual bool IsAnyValueAllowed() const = 0;
	/**
		Gets number of enumerations.
	*/
	virtual int GetEnumsCount() const = 0;
	/**
		Gets description of single enumeration.
		\param	index	index of enumeration.
	*/
	virtual QString GetValueDescription(const iser::IObject& value) const = 0;
	/**
		Gets single enumeration.
	*/
	virtual const iser::IObject& GetEnum(int index) const = 0;
};


} // namespace iattr


#endif // !iattr_IEnumAttributeMetaInfo_included


