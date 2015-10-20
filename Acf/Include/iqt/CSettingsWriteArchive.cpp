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


#include "iqt/CSettingsWriteArchive.h"


// ACF includes
#include "iqt/iqt.h"


namespace iqt
{


// public methods

CSettingsWriteArchive::CSettingsWriteArchive(
			const QString& organizationName,
			const QString& productName,
			const QString& rootKey,
			QSettings::Scope settingsScope,
			const iser::IVersionInfo* versionInfoPtr)
:	BaseClass(versionInfoPtr),
	BaseClass2(organizationName, productName, rootKey, settingsScope)
{
	SerializeAcfHeader();
}


// reimplemented (iser::IArchive)

bool CSettingsWriteArchive::BeginTag(const iser::CArchiveTag& tag)
{
	return EnterTag(tag.GetId());
}


bool CSettingsWriteArchive::BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& /*subTag*/, int& count)
{
	if (EnterTag(tag.GetId())){
		QString countRegistryKey = GetCurrentCountKey();

		BaseClass2::setValue(countRegistryKey, count);

		return true;
	}

	return false;
}


bool CSettingsWriteArchive::EndTag(const iser::CArchiveTag& tag)
{
	return LeaveTag(tag.GetId());
}


bool CSettingsWriteArchive::Process(QString& value)
{
	QString registryKey = CreateNextValueKey();

	if (registryKey.isEmpty()){
		return false;
	}

	BaseClass2::setValue(registryKey, value);

	return true;
}


// protected methods

// reimplemented (iser::CTextWriteArchiveBase)

bool CSettingsWriteArchive::WriteTextNode(const QByteArray& text)
{
	QString registryKey = CreateNextValueKey();

	if (registryKey.isEmpty()){
		return false;
	}

	BaseClass2::setValue(registryKey, text);

	return true;
}


} // namespace iqt


