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


#ifndef iqt_CSettingsArchiveBase_included
#define iqt_CSettingsArchiveBase_included


#include <QSettings>

#include "istd/CString.h"


namespace iqt
{


class CSettingsArchiveBase: protected QSettings
{
public:
	typedef QSettings BaseClass;

	CSettingsArchiveBase(	const QString& organizationName,
							const QString& applicationName);

protected:
	QString CreateKey(bool replaceMultiple = true) const;

protected:
	struct TagInfo
	{
		TagInfo(const std::string& tagId, int count = 0, const std::string& subTagId = std::string())
		{
			this->tagId = tagId;
			this->count = count;
			this->subTagId = subTagId;
		}
	
		std::string tagId;
		std::string subTagId;
		int count;
	};

	typedef std::vector<TagInfo> OpenTagsList;
	mutable OpenTagsList m_openTagsList;
};


} // namespace iqt


#endif // !iqt_CSettingsArchiveBase_included

