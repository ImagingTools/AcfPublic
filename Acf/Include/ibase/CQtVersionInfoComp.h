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


#ifndef ibase_CQtVersionInfo_included
#define ibase_CQtVersionInfo_included


// ACF includes
#include "ibase/TVersionInfoBase.h"


namespace ibase
{


/**
	Component representation of the Qt module version.
*/
class CQtVersionInfoComp: public ibase::CVersionInfoCompBase
{
public:
	typedef ibase::CVersionInfoCompBase BaseClass;

	I_BEGIN_COMPONENT(CQtVersionInfoComp);
	I_END_COMPONENT;

	enum QtVersionIds
	{
		/**
			Version of Qt framework against the actual module was compiled.
		*/
		QVI_COMPILED = IVersionInfo::UserVersionId + 1,

		/**
			Version of Qt framework registered in the current runtime system.
		*/
		QVI_RUNTIME
	};

	// reimplemented (iser::IVersionInfo)
	virtual VersionIds GetVersionIds() const;
	virtual bool GetVersionNumber(int versionId, quint32& result) const;
	virtual QString GetVersionIdDescription(int versionId) const;
	virtual QString GetEncodedVersionName(int versionId, quint32 versionNumber) const;
};


} // namespace ibase


#endif // !ibase_CQtVersionInfo_included


