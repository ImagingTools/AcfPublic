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


#ifndef icomp_CMultiFactoryAttribute_included
#define icomp_CMultiFactoryAttribute_included


// Qt includes
#include <QtCore/QByteArray>

// ACF includes
#include <icomp/CMultiReferenceAttribute.h>


namespace icomp
{


/**
	Special attribute used to store list of referenced component ID's.
*/
class CMultiFactoryAttribute: public CMultiReferenceAttribute
{
public:
	typedef CMultiReferenceAttribute BaseClass;

	enum DefaultAttributeFlags
	{
		DAF_OBLIGATORY = IAttributeStaticInfo::AF_OBLIGATORY | IAttributeStaticInfo::AF_MULTIPLE | IAttributeStaticInfo::AF_FACTORY,
		DAF_OPTIONAL = IAttributeStaticInfo::AF_NULLABLE | IAttributeStaticInfo::AF_MULTIPLE | IAttributeStaticInfo::AF_FACTORY
	};

	CMultiFactoryAttribute();
	CMultiFactoryAttribute(const CMultiFactoryAttribute& attribute);
	CMultiFactoryAttribute(int elementsCount, QByteArray* valuesPtr);

	// reimplemented (iser::IObject)
	virtual QByteArray GetFactoryId() const override;

	// static methods
	static QByteArray GetTypeName();
};


} // namespace icomp


#endif // icomp_CMultiFactoryAttribute_included


