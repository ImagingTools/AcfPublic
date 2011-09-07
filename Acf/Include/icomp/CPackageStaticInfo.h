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


#ifndef icomp_CPackageStaticInfo_included
#define icomp_CPackageStaticInfo_included


#include "icomp/CComponentStaticInfoBase.h"


namespace iser
{
	class IArchive;
};


namespace icomp
{


/**
	Static info for component package.
	Please note, that in composed component concept there is no distinguish between package and component.
*/
class CPackageStaticInfo: virtual public CComponentStaticInfoBase
{
public:
	CPackageStaticInfo();
	CPackageStaticInfo(
				const istd::CString& description,
				const istd::CString& keywords);

	void Reset();

	virtual bool SerializeMeta(iser::IArchive& archive);

	/**
		Register embedded component static info.
		\param	embeddedId			ID of this embedded component.
		\param	componentInfoPtr	embedded component static info object used to describe its type.
									It cannot be NULL.
	*/
	virtual void RegisterEmbeddedComponentInfo(const std::string& embeddedId, const IComponentStaticInfo* componentInfoPtr);

	// reimplemented (icomp::IComponentStaticInfo)
	virtual const IComponentStaticInfo* GetEmbeddedComponentInfo(const std::string& embeddedId) const;
	virtual Ids GetMetaIds(int metaGroupId) const;
	virtual const istd::CString& GetDescription() const;
	virtual const istd::CString& GetKeywords() const;

private:
	typedef std::map<std::string, const IComponentStaticInfo*> EmbeddedComponentInfos;
	EmbeddedComponentInfos m_embeddedComponentInfos;

	istd::CString m_description;
	istd::CString m_keywords;
};


}//namespace icomp


#endif // !icomp_CPackageStaticInfo_included


