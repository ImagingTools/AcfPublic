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


#ifndef icomp_CCompositeComponentStaticInfo_included
#define icomp_CCompositeComponentStaticInfo_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include "istd/TDelPtr.h"

#include "icomp/IAttributeStaticInfo.h"
#include "icomp/IRegistry.h"
#include "icomp/CBaseComponentStaticInfo.h"


namespace icomp
{


class IComponentEnvironmentManager;
class IRegistriesManager;


class CCompositeComponentStaticInfo: public CBaseComponentStaticInfo
{
public:
	CCompositeComponentStaticInfo(
				const IRegistry& registry,
				const icomp::IComponentEnvironmentManager& manager,
				const IComponentStaticInfo* parentPtr = NULL);

	// reimplemented (icomp::IRealComponentStaticInfo)
	virtual IComponent* CreateComponent() const;

	//	reimplemented (icomp::IComponentStaticInfo)
	virtual int GetComponentType() const;
	virtual const IComponentStaticInfo* GetEmbeddedComponentInfo(const QByteArray& embeddedId) const;
	virtual const QString& GetDescription() const;
	virtual const QString& GetKeywords() const;

protected:
	/**
		Get the element info for the given element ID. Method works recurive for the complex ID's.
	*/
	const IRegistry::ElementInfo* GetElementInfoFromRegistry(
				const IRegistry& registry,
				const QByteArray& elementId,
				const icomp::IRegistriesManager& manager) const;

	class AttrAsOptionalDelegator: virtual public IAttributeStaticInfo
	{
	public:
		AttrAsOptionalDelegator(
					const IAttributeStaticInfo* slavePtr,
					const iser::IObject* defaultValuePtr);

		virtual const QByteArray& GetAttributeDescription() const;
		virtual const iser::IObject* GetAttributeDefaultValue() const;
		virtual QByteArray GetAttributeTypeName() const;
		virtual IElementStaticInfo::Ids GetRelatedMetaIds(int metaGroupId, int flags, int flagsMask) const;
		virtual int GetAttributeFlags() const;

	private:
		const IAttributeStaticInfo& m_slave;
		const iser::IObject* m_defaultValuePtr;
	};

private:
	typedef istd::TDelPtr<IAttributeStaticInfo> AttrMetaInfoPtr;
	typedef QMap<const IAttributeStaticInfo*, AttrMetaInfoPtr> AttrReplacers;
	AttrReplacers m_attrReplacers;

	typedef istd::TDelPtr<icomp::CCompositeComponentStaticInfo> ComponentInfoPtr;
	typedef QMap<QByteArray, ComponentInfoPtr> EmbeddedComponentInfos;
	mutable EmbeddedComponentInfos m_embeddedComponentInfos;

	QString m_description;
	QString m_keywords;
	int m_category;
};


} // namespace icomp


#endif // !icomp_CCompositeComponentStaticInfo_included


