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


#ifndef icomp_CReferenceAttribute_included
#define icomp_CReferenceAttribute_included


// STL includes
#include <string>

#include "icomp/TAttribute.h"


namespace icomp{


/**
	Special attribute used to store referenced component ID.
*/
class CReferenceAttribute: public TAttribute<std::string>
{
public:
	typedef TAttribute<std::string> BaseClass;

	enum DefaultAttributeFlags
	{
		DAF_OBLIGATORY = IAttributeStaticInfo::AF_OBLIGATORY | IAttributeStaticInfo::AF_REFERENCE,
		DAF_OPTIONAL = IAttributeStaticInfo::AF_NULLABLE | IAttributeStaticInfo::AF_REFERENCE
	};

	CReferenceAttribute(){}
	CReferenceAttribute(const CReferenceAttribute& attribute):BaseClass(attribute){}
	explicit CReferenceAttribute(const std::string& value):BaseClass(value){}

	// reimplemented (iser::IObject)
	const std::string& GetFactoryId() const;

	// static methods
	static const std::string& GetTypeName();

private:
	static const std::string s_typeName;
};


} // namespace icomp


#endif // !icomp_CReferenceAttribute_included


