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


#ifndef icomp_CMultiReferenceAttribute_included
#define icomp_CMultiReferenceAttribute_included


// Qt includes
#include <QtCore/QByteArray>

// ACF includes
#include "iattr/TMultiAttribute.h"
#include "icomp/IAttributeStaticInfo.h"


namespace icomp
{


/**
	Special attribute used to store list of referenced component ID's.
*/
class CMultiReferenceAttribute: public iattr::CIdListAttribute
{
public:
	typedef iattr::CIdListAttribute BaseClass;

	enum DefaultAttributeFlags
	{
		DAF_OBLIGATORY = iattr::IAttributeMetaInfo::AF_OBLIGATORY | iattr::IAttributeMetaInfo::AF_MULTIPLE | IAttributeStaticInfo::AF_REFERENCE,
		DAF_OPTIONAL = iattr::IAttributeMetaInfo::AF_NULLABLE | iattr::IAttributeMetaInfo::AF_MULTIPLE | IAttributeStaticInfo::AF_REFERENCE
	};

	CMultiReferenceAttribute();
	CMultiReferenceAttribute(const CMultiReferenceAttribute& attribute);
	CMultiReferenceAttribute(int elementsCount, QByteArray* valuesPtr);

	// reimplemented (iser::IObject)
	QByteArray GetFactoryId() const;

	// static methods
	static QByteArray GetTypeName();
};


} // namespace icomp


#endif // icomp_CMultiReferenceAttribute_included


