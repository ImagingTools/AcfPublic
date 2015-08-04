/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqt_CSettingsArchiveBase_included
#define iqt_CSettingsArchiveBase_included


// Qt includes
#include <QtCore/QList>

// Qt includes
#include <QtCore/QSettings>
#include <QtCore/QString>


namespace iqt
{

	
/**
	Basic implementation for an archive used Qt settings implementation as persistence medium.

	\ingroup Persistence
*/
class CSettingsArchiveBase: protected QSettings
{
public:
	typedef QSettings BaseClass;

	/**
	Constructor.
		\param	organizationName	Name of the organization.
		\param	applicationName 	Name of the application.
		\param	rootKey				The root key.
		\param	settingsScope   	(Optional) the settings scope.
	*/
	CSettingsArchiveBase(
				const QString& organizationName,
				const QString& applicationName,
				const QString& rootKey,
				QSettings::Scope settingsScope = QSettings::UserScope);

protected:
	bool EnterTag(const QByteArray& tagId);
	bool LeaveTag(const QByteArray& tagId);
	QString GetCurrentCountKey() const;
	QString CreateNextValueKey();
	QString GetBaseKey() const;

	struct TagInfo
	{
		TagInfo(const QByteArray& tagId, int siblingsCount)
		{
			this->tagId = tagId;
			this->siblingsCount = siblingsCount;
		}
	
		QByteArray tagId;
		int siblingsCount;
	};

	typedef QList<TagInfo> OpenTagsList;
	OpenTagsList m_openTagsList;

	QString m_rootKey;

	int m_valuesCount;
};


} // namespace iqt


#endif // !iqt_CSettingsArchiveBase_included

