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


#ifndef icomp_CCompositePackageStaticInfo_included
#define icomp_CCompositePackageStaticInfo_included


#include <map>

#include "istd/TDelPtr.h"

#include "icomp/CPackageStaticInfo.h"
#include "icomp/CCompositeComponentStaticInfo.h"


namespace icomp
{


class IComponentEnvironmentManager;


/**
	Implementation of package static info designing to provide composite component information 'on demand'.
*/
class CCompositePackageStaticInfo: public CPackageStaticInfo
{
public:
	typedef CPackageStaticInfo BaseClass;

	CCompositePackageStaticInfo(
				const std::string& packageId,
				const icomp::IComponentEnvironmentManager* managerPtr);

	void RegisterEmbeddedComponent(const std::string& componentId);

	//	reimplemented (icomp::IComponentStaticInfo)
	virtual const IComponentStaticInfo* GetEmbeddedComponentInfo(const std::string& embeddedId) const;
	virtual Ids GetMetaIds(int metaGroupId) const;

private:
	struct ComponentInfo
	{
		ComponentInfo():isInitialized(false){}

		istd::TDelPtr<icomp::CCompositeComponentStaticInfo> componentInfoPtr;
		bool isInitialized;
	};

	typedef std::map<std::string, ComponentInfo> EmbeddedComponentInfos;
	mutable EmbeddedComponentInfos m_embeddedComponentInfos;

	std::string m_packageId;
	const icomp::IComponentEnvironmentManager& m_envManager;
};


}//namespace icomp


#endif // !icomp_CCompositePackageStaticInfo_included


