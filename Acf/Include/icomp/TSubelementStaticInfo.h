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


#ifndef icomp_TSubelementStaticInfo_included
#define icomp_TSubelementStaticInfo_included


// Qt includes
#include <QtCore/QByteArray>
#include <QtCore/QMap>

// ACF includes
#include "icomp/IElementStaticInfo.h"
#include "icomp/CBaseComponentStaticInfo.h"


namespace icomp
{


template <class ComponentType>
class TSubelementStaticInfo:
			virtual public IElementStaticInfo,
			virtual public IComponentInterfaceExtractor
{
public:
	typedef void* (*InterfaceExtractorPtr)(ComponentType& component);

	/**
		Constructor attaching this subelement info to the component.
	*/
	TSubelementStaticInfo(const QByteArray& name, CBaseComponentStaticInfo& owner);

	/**
		Register interface ID for this static component info.
		This interface ID is used for static check
		if this component can be used to resolve reference dependecy of second one.
	*/
	virtual void RegisterInterfaceExtractor(const QByteArray& interfaceName, InterfaceExtractorPtr extractorPtr);

	//	reimplemented (icomp::IElementStaticInfo)
	virtual const IElementStaticInfo* GetSubelementInfo(const QByteArray& subcomponentId) const;
	virtual Ids GetMetaIds(int metaGroupId) const;

	//	reimplemented (icomp::IComponentInterfaceExtractor)
	virtual void* GetComponentInterface(
				const istd::CClassInfo& interfaceType,
				IComponent& component,
				const QByteArray& subId) const;

	template <class InterfaceType>
	class Registrator
	{
	public:
		typedef InterfaceType* (*ExtractorPtr)(ComponentType& component);

		Registrator(TSubelementStaticInfo& staticInfo,
					const QByteArray& interfaceName,
					ExtractorPtr extractorPtr)
		{
			staticInfo.RegisterInterfaceExtractor(interfaceName, reinterpret_cast<InterfaceExtractorPtr>(extractorPtr));
		}
	};

private:
	typedef QMap<QByteArray, InterfaceExtractorPtr> InterfaceExtractors;
	InterfaceExtractors m_interfaceExtractors;
};


// public methods

template <class ComponentType>
TSubelementStaticInfo<ComponentType>::TSubelementStaticInfo(const QByteArray& name, CBaseComponentStaticInfo& owner)
{
	owner.RegisterSubelementInfo(name, this);
}


template <class ComponentType>
void TSubelementStaticInfo<ComponentType>::RegisterInterfaceExtractor(const QByteArray& interfaceName, InterfaceExtractorPtr extractorPtr)
{
	m_interfaceExtractors[interfaceName] = extractorPtr;
}


//	reimplemented (icomp::IElementStaticInfo)

template <class ComponentType>
const IElementStaticInfo* TSubelementStaticInfo<ComponentType>::GetSubelementInfo(const QByteArray& /*subcomponentId*/) const
{
	return NULL;
}


template <class ComponentType>
IElementStaticInfo::Ids TSubelementStaticInfo<ComponentType>::GetMetaIds(int metaGroupId) const
{
	Ids retVal;

	if (metaGroupId == MGI_INTERFACES){
		for (		typename InterfaceExtractors::const_iterator iter = m_interfaceExtractors.begin();
					iter != m_interfaceExtractors.end();
					++iter){
			retVal.insert(iter.key());
		}
	}

	return retVal;
}


//	reimplemented (icomp::IComponentInterfaceExtractor)

template <class ComponentType>
void* TSubelementStaticInfo<ComponentType>::GetComponentInterface(
			const istd::CClassInfo& interfaceType,
			IComponent& component,
			const QByteArray& subId) const
{
	ComponentType* nativeTypePtr = dynamic_cast<ComponentType*>(&component);
	if ((nativeTypePtr != NULL) && subId.isEmpty()){
		static istd::CClassInfo compInterfaceType(typeid(icomp::IComponent));

		if (!interfaceType.IsValid() || interfaceType.IsVoid() || (interfaceType == compInterfaceType)){
			return &component;
		}

		typename InterfaceExtractors::const_iterator foundIter = m_interfaceExtractors.find(interfaceType.GetName());
		if (foundIter != m_interfaceExtractors.end()){
			InterfaceExtractorPtr extractorPtr = foundIter.value();

			return extractorPtr(*nativeTypePtr);
		}

		if (interfaceType.IsConst()){
			istd::CClassInfo nonConstType = interfaceType.GetConstCasted(false);

			typename InterfaceExtractors::const_iterator foundIter = m_interfaceExtractors.find(nonConstType.GetName());
			if (foundIter != m_interfaceExtractors.end()){
				InterfaceExtractorPtr extractorPtr = foundIter.value();

				return extractorPtr(*nativeTypePtr);
			}
		}
	}

	return NULL;
}


} // namespace icomp


#endif // !icomp_TSubelementStaticInfo_included


