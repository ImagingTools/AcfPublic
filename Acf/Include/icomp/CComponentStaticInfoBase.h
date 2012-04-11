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


#ifndef icomp_CComponentStaticInfoBase_included
#define icomp_CComponentStaticInfoBase_included


// STL incldues
#include <QtCore/QByteArray>
#include <QtCore/QMap>

// ACF includes
#include "icomp/IComponentStaticInfo.h"


namespace icomp
{


class CComponentStaticInfoBase: virtual public IComponentStaticInfo
{
public:
	// reimplemented (icomp::IComponentStaticInfo)
	virtual int GetComponentType() const;
	virtual const IAttributeStaticInfo* GetAttributeInfo(const QByteArray& attributeId) const;
	virtual const IComponentStaticInfo* GetEmbeddedComponentInfo(const QByteArray& embeddedId) const;
	virtual const QString& GetDescription() const;
	virtual const QString& GetKeywords() const;

	//	reimplemented (icomp::IElementStaticInfo)
	virtual const IElementStaticInfo* GetSubelementInfo(const QByteArray& subcomponentId) const;
	virtual Ids GetMetaIds(int metaGroupId) const;
};


// inline methods

// reimplemented (icomp::IComponentStaticInfo)

inline const QString& CComponentStaticInfoBase::GetDescription() const
{
	static QString emptyString;

	return emptyString;
}


inline const QString& CComponentStaticInfoBase::GetKeywords() const
{
	static QString emptyString;

	return emptyString;
}


} // namespace icomp


#endif // !icomp_CComponentStaticInfoBase_included


