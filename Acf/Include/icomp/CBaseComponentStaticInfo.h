/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef icomp_CBaseComponentStaticInfo_included
#define icomp_CBaseComponentStaticInfo_included


#include "icomp/IRealComponentStaticInfo.h"
#include "icomp/CComponentStaticInfoBase.h"


namespace icomp
{


/**
	Standard implementation of static info for base component classes.
	The main difference to 'normal' component static info is, that instances of such components cannot be created.
*/
class CBaseComponentStaticInfo:
			public CComponentStaticInfoBase,
			virtual public IRealComponentStaticInfo
{
public:
	typedef CComponentStaticInfoBase BaseClass;

	typedef void* (*InterfaceExtractorPtr)(IComponent& component);

	CBaseComponentStaticInfo(const IRealComponentStaticInfo* baseComponentPtr = NULL);

	/**
		Register interface ID for this static component info.
		This interface ID is used for static check
		if this component can be used to resolve reference dependecy of second one.
	*/
	virtual void RegisterInterfaceExtractor(const QByteArray& interfaceName, InterfaceExtractorPtr extractorPtr);
	/**
		Register static attribute info.
		\param	attributeId			ID of attribute.
		\param	attributeInfoPtr	static attribute info object used to describe attribute type and as factory.
									It cannot be NULL.
	*/
	virtual void RegisterAttributeInfo(const QByteArray& attributeId, const IAttributeStaticInfo* attributeInfoPtr);
	/**
		Register static subcomponent info.
		\param	subcomponentId		ID of this subcomponent.
		\param	componentInfoPtr	static subcomponent info object used to describe subcomponent type and as factory.
									It cannot be NULL.
	*/
	virtual void RegisterSubelementInfo(const QByteArray& subcomponentId, const IElementStaticInfo* staticInfoPtr);

	//	reimplemented (icomp::IRealComponentStaticInfo)
	virtual IComponent* CreateComponent() const;

	//	reimplemented (icomp::IComponentInterfaceExtractor)
	virtual void* GetComponentInterface(
				const istd::CClassInfo& interfaceType,
				IComponent& component,
				const QByteArray& subId) const;

	//	reimplemented (icomp::IComponentStaticInfo)
	virtual const IAttributeStaticInfo* GetAttributeInfo(const QByteArray& attributeId) const;

	//	reimplemented (icomp::IElementStaticInfo)
	virtual Ids GetMetaIds(int metaGroupId) const;
	virtual const IElementStaticInfo* GetSubelementInfo(const QByteArray& subcomponentId) const;

	//	reimplemented (iattr::IAttributesMetaInfoProvider)
	virtual iattr::IAttributesProvider::AttributeIds GetAttributeMetaIds() const;
	virtual const iattr::IAttributeMetaInfo* GetAttributeMetaInfo(const QByteArray& attributeId) const;

private:
	const IRealComponentStaticInfo* m_baseComponentPtr;

	typedef QMap<QByteArray, InterfaceExtractorPtr> InterfaceExtractors;
	InterfaceExtractors m_interfaceExtractors;

	typedef QMap<QByteArray, const IElementStaticInfo*> SubelementInfos;
	SubelementInfos m_subelementInfos;

	typedef QMap<QByteArray, const IAttributeStaticInfo*> AttributeInfos;
	AttributeInfos m_attributeInfos;
};


} // namespace icomp


#endif // !icomp_CBaseComponentStaticInfo_included


