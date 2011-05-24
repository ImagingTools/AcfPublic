/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef icomp_CRegistryElement_included
#define icomp_CRegistryElement_included


#include <map>
#include <string>

#include "icomp/IRegistryElement.h"


namespace icomp
{


class IAttributeStaticInfo;


class CRegistryElement: virtual public IRegistryElement
{
public:
	CRegistryElement();

	virtual AttributeInfo* GetAttributeInfo(const std::string& attributeId);

	// reimplemented (icomp::IRegistryElement)
	virtual I_DWORD GetElementFlags() const;
	virtual void SetElementFlags(I_DWORD flags);
	virtual Ids GetAttributeIds() const;
	virtual AttributeInfo* InsertAttributeInfo(const std::string& attributeId, const std::string& attributeType);
	virtual iser::IObject* CreateAttribute(const std::string& attributeType) const;
	virtual const AttributeInfo* GetAttributeInfo(const std::string& attributeId) const;
	virtual bool RemoveAttribute(const std::string& attributeId);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	I_DWORD m_elementFlags;

	typedef std::map< std::string, AttributeInfo> AttributeInfoMap;
	AttributeInfoMap m_attributeInfos;
};


}//namespace icomp


#endif // !icomp_CRegistryElement_included


