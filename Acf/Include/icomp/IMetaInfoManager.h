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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef icomp_IMetaInfoManager_included
#define icomp_IMetaInfoManager_included


#include "istd/IChangeable.h"

#include "icomp/IComponentStaticInfo.h"
#include "icomp/CComponentAddress.h"


namespace icomp
{


class IMetaInfoManager: virtual public istd::IChangeable
{
public:
	enum ComponentTypeFlag
	{
		CTF_REAL = 1 << IComponentStaticInfo::CT_REAL,
		CTF_COMPOSITE = 1 << IComponentStaticInfo::CT_COMPOSITE,
		CTF_ALL = CTF_REAL | CTF_COMPOSITE
	};

	typedef QSet<CComponentAddress> ComponentAddresses;

	/**
		Get addresses of known components.
	*/
	virtual ComponentAddresses GetComponentAddresses(int typeFlag = CTF_ALL) const = 0;

	/**
		Get access to static info of some component.
		\param	address	component address.
		\return	static info of component or NULL, if no component type for specified address was found.
	*/
	virtual const IComponentStaticInfo* GetComponentMetaInfo(const CComponentAddress& address) const = 0;
	
	/**
		Get access to static info of a package.
		\param	package ID.
		\return	static info of the package or NULL, if no package for specified ID was found.
	*/
	virtual const IComponentStaticInfo* GetPackageMetaInfo(const QByteArray& packageId) const = 0;

};


} // namespace icomp


#endif // !icomp_IMetaInfoManager_included


