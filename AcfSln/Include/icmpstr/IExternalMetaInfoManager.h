/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#ifndef icmpstr_IExternalMetaInfoManager_included
#define icmpstr_IExternalMetaInfoManager_included


#include <istd/IPolymorphic.h>
#include <QtCore/QString>

#include <icomp/CComponentAddress.h>


namespace icmpstr
{


class IExternalMetaInfoManager: virtual public istd::IPolymorphic
{
public:
	/**
		Get path of package info directory.
	*/
	virtual QString GetPackageInfoPath(const QByteArray& packageId) const = 0;

	/**
		Get path of component info directory.
	*/
	virtual QString GetComponentInfoPath(const icomp::CComponentAddress& address) const = 0;
};


} // namespace icmpstr


#endif // !icmpstr_IExternalMetaInfoManager_included


