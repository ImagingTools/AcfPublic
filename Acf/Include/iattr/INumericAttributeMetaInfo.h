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


#ifndef iattr_INumericAttributeMetaInfo_included
#define iattr_INumericAttributeMetaInfo_included


#include <iattr/IAttributeMetaInfo.h>


namespace iattr
{


/**
	Represents constraints of properties allowing values from enumerated set.
*/
class INumericAttributeMetaInfo: virtual public IAttributeMetaInfo
{
public:
	/**
		Get minimal allowed value for some attribute.
	*/
	virtual bool GetMinimalValue(iser::IObject& result) const = 0;
	/**
		Get maximal allowed value for some attribute.
	*/
	virtual bool GetMaximalValue(iser::IObject& result) const = 0;
};


} // namespace iattr


#endif // !iattr_INumericAttributeMetaInfo_included


