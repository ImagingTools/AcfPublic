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


#ifndef iqt_CSettingsReadArchive_included
#define iqt_CSettingsReadArchive_included


#include "iser/CTextReadArchiveBase.h"

#include "iqt/CSettingsArchiveBase.h"


namespace iqt
{


class CSettingsReadArchive: public iser::CTextReadArchiveBase, public iqt::CSettingsArchiveBase
{
public:
	typedef iser::CTextReadArchiveBase BaseClass;
	typedef CSettingsArchiveBase BaseClass2;

	CSettingsReadArchive(
				const QString& organizationName,
				const QString& applicationName,
				const QString& rootKey);

	// reimplemented (iser::IArchive)
	virtual bool BeginTag(const iser::CArchiveTag& tag);
	virtual bool BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count);
	virtual bool EndTag(const iser::CArchiveTag& tag);
	virtual bool Process(std::string& value);
	virtual bool Process(istd::CString& value);
};


} // namespace iqt


#endif // !iqt_CSettingsReadArchive_included

