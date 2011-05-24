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


#ifndef icomp_TComponentRegistrator_included
#define icomp_TComponentRegistrator_included


#include <string>

#include "icomp/TComponentStaticInfo.h"
#include "icomp/CPackageStaticInfo.h"


namespace icomp
{


/**
	Simple helper class providing registration of template-specified component in package.
*/
template <class Component>
class TComponentRegistrator: public icomp::TComponentStaticInfo<Component>
{
public:
	typedef icomp::TComponentStaticInfo<Component> BaseClass;

	TComponentRegistrator(
				const std::string& componentId,
				icomp::CPackageStaticInfo& packageStaticInfo,
				const istd::CString& description,
				const istd::CString& keywords);

	//	reimplemented (icomp::IComponentStaticInfo)
	virtual const istd::CString& GetDescription() const;
	virtual const istd::CString& GetKeywords() const;

private:
	std::string m_logicalName;
	istd::CString m_description;
	istd::CString m_keywords;
};


// public methods

template <class Component>
TComponentRegistrator<Component>::TComponentRegistrator(
			const std::string& componentId,
			icomp::CPackageStaticInfo& packageStaticInfo,
			const istd::CString& description,
			const istd::CString& keywords)
:	BaseClass(&Component::InitStaticInfo(NULL)),
	m_description(description),
	m_keywords(keywords)
{
	packageStaticInfo.RegisterEmbeddedComponentInfo(componentId, this);

	m_keywords += " ";

	m_keywords += packageStaticInfo.GetKeywords();
}


//	reimplemented (icomp::IComponentStaticInfo)

template <class Component>
const istd::CString& TComponentRegistrator<Component>::GetDescription() const
{
	return m_description;
}


template <class Component>
const istd::CString& TComponentRegistrator<Component>::GetKeywords() const
{
	return m_keywords;
}


}//namespace icomp


#endif // !icomp_TComponentRegistrator_included


