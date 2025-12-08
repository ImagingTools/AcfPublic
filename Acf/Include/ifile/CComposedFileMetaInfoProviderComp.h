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


#pragma once


// ACF includes
#include <ifile/IFileMetaInfoProvider.h>
#include <icomp/CComponentBase.h>


namespace ifile
{


/**
	\ingroup Persistence
*/
class CComposedFileMetaInfoProviderComp:
			public icomp::CComponentBase,
			virtual public ifile::IFileMetaInfoProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CComposedFileMetaInfoProviderComp);
		I_REGISTER_INTERFACE(ifile::IFileMetaInfoProvider);
		I_ASSIGN_MULTI_0(m_slaveInfoProvidersCompPtr, "SlaveInfoProviders", "List of slave meta info providers", true);
	I_END_COMPONENT;

	// reimplemented (ifile::IFileMetaInfoProvider)
	virtual idoc::MetaInfoPtr GetFileMetaInfo(const QString& filePath, ibase::IProgressManager* progressManagerPtr = NULL) const override;
	
private:
	I_MULTIREF(ifile::IFileMetaInfoProvider, m_slaveInfoProvidersCompPtr);
};


} // namespace ifile


