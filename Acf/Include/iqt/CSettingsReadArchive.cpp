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


#include "iqt/CSettingsReadArchive.h"


// Qt includes
#include <QtCore/QStringList>



namespace iqt
{


// public methods

CSettingsReadArchive::CSettingsReadArchive(
			const QString& organizationName,
			const QString& applicationName,
			const QString& rootKey,
			QSettings::Scope settingsScope)
:	BaseClass2(organizationName, applicationName, rootKey, settingsScope)
{
	SerializeAcfHeader();
}


// reimplemented (iser::IArchive)

bool CSettingsReadArchive::BeginTag(const iser::CArchiveTag& tag)
{
	return EnterTag(tag.GetId());
}


bool CSettingsReadArchive::BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& /*subTag*/, int& count)
{
	if (EnterTag(tag.GetId())){
		QString countRegistryKey = GetCurrentCountKey();

		bool isOk = true;
		count = BaseClass2::value(countRegistryKey).toInt(&isOk);

		if (isOk){
			return true;
		}
	}

	return false;
}


bool CSettingsReadArchive::EndTag(const iser::CArchiveTag& tag)
{
	return LeaveTag(tag.GetId());
}


bool CSettingsReadArchive::Process(QByteArray& value)
{
	QString registryKey = CreateNextValueKey();

	if (registryKey.isEmpty()){
		return false;
	}

	value = BaseClass2::value(registryKey).toString().toLocal8Bit();

	return true;
}


bool CSettingsReadArchive::Process(QString& value)
{
	QString registryKey = CreateNextValueKey();

	if (registryKey.isEmpty()){
		return false;
	}

	value = BaseClass2::value(registryKey).toString();

	return true;
}


} // namespace iqt

