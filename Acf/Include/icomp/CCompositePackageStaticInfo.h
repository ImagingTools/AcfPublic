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


#ifndef icomp_CCompositePackageStaticInfo_included
#define icomp_CCompositePackageStaticInfo_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include <istd/TDelPtr.h>

#include <icomp/CPackageStaticInfo.h>
#include <icomp/CCompositeComponentStaticInfo.h>


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
				const QByteArray& packageId,
				const icomp::IComponentEnvironmentManager* managerPtr);

	void RegisterEmbeddedComponent(const QByteArray& componentId);

	//	reimplemented (icomp::IComponentStaticInfo)
	virtual Ids GetMetaIds(int metaGroupId) const;
	virtual const IComponentStaticInfo* GetEmbeddedComponentInfo(const QByteArray& embeddedId) const;

private:
	struct ComponentInfo
	{
		ComponentInfo():isInitialized(false){}

		istd::TDelPtr<icomp::CCompositeComponentStaticInfo> componentInfoPtr;
		bool isInitialized;
	};

	typedef QMap<QByteArray, ComponentInfo> EmbeddedComponentInfos;
	mutable EmbeddedComponentInfos m_embeddedComponentInfos;

	QByteArray m_packageId;
	const icomp::IComponentEnvironmentManager& m_envManager;
};


} // namespace icomp


#endif // !icomp_CCompositePackageStaticInfo_included


