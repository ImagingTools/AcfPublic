/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iprop_CPropertyBase_included
#define iprop_CPropertyBase_included


#include "iser/TCopySerializedWrap.h"

#include "iprop/IProperty.h"


namespace iprop
{


class IPropertiesManager;


/**
	Basic implementation of an property.
*/
class CPropertyBase: public iser::TCopySerializedWrap<IProperty>
{
public:
	CPropertyBase();
	CPropertyBase(
				IPropertiesManager* propertyOwnerPtr,
				const std::string& propertyId,
				const std::string& propertyDescription,
				int propertyFlags,
				int changeFlags = 0);

	// reimplemented (iprop::IProperty)
	virtual const iser::IObject* GetDefaultPropertyValue() const;

protected:
	IPropertiesManager* m_propertyOwnerPtr;
	int m_changeFlags;
};


} // namespace iprop


#endif // !iprop_CPropertyBase_included


