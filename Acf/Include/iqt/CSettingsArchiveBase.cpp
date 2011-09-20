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


#include "iqt/CSettingsArchiveBase.h"


// ACF includes
#include "iqt/iqt.h"


namespace iqt
{


// public methods

CSettingsArchiveBase::CSettingsArchiveBase(	const QString& organizationName,
											const QString& applicationName)
	:BaseClass(organizationName, applicationName)
{
}


// protected methods

QString CSettingsArchiveBase::CreateKey(bool replaceMultiple) const
{
	QString registryKey;

	for (		OpenTagsList::iterator index = m_openTagsList.begin();
				index != m_openTagsList.end();
				index++){
		TagInfo& tagInfo = *index;
		if (tagInfo.count > 0 && replaceMultiple){
			tagInfo.tagId = QString::number(tagInfo.count).toStdString();
		}

		registryKey += iqt::GetQString(tagInfo.tagId);
	
		registryKey += "/";
	}

	return registryKey;
}


} // namespace iqt


