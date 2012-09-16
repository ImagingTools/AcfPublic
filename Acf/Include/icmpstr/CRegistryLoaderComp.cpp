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


#include "icmpstr/CRegistryLoaderComp.h"


// Qt includes
#include <QtCore/QString>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QtGui/QMessageBox>


// ACF includes
#include "istd/TChangeNotifier.h"

#include "icmpstr/CVisualRegistry.h"


namespace icmpstr
{


// reimplemented (iser::IFileLoader)

int CRegistryLoaderComp::LoadFromFile(istd::IChangeable& data, const QString& filePath) const
{
	istd::CChangeNotifier notifier(&data);

	if (!IsOperationSupported(&data, &filePath, QF_LOAD | QF_FILE, false)){
		return StateFailed;
	}

	CVisualRegistry* geometricalRegistryPtr = dynamic_cast<CVisualRegistry*>(&data);
	if (geometricalRegistryPtr != NULL){
		ReadArchiveEx registryArchive(filePath, this);
		I_ASSERT(!registryArchive.IsStoring());

		if (!geometricalRegistryPtr->SerializeRegistry(registryArchive)){
			OnReadError(registryArchive, data, filePath);

			return StateFailed;
		}

		ReadArchiveEx layoutArchive(GetLayoutPath(filePath), this);
		I_ASSERT(!layoutArchive.IsStoring());

		if (!geometricalRegistryPtr->SerializeUserData(layoutArchive)){
			SendInfoMessage(
						MI_CANNOT_READ_LAYOUT,
						tr("Layout information cannot be loaded (%1)").arg(filePath));
		}

		return StateOk;
	}
	else{
		return BaseClass::LoadFromFile(data, filePath);
	}

	return StateFailed;
}


int CRegistryLoaderComp::SaveToFile(const istd::IChangeable& data, const QString& filePath) const
{
	if (!IsOperationSupported(&data, &filePath, QF_SAVE | QF_FILE, false)){
		return StateFailed;
	}

	const CVisualRegistry* geometricalRegistryPtr = dynamic_cast<const CVisualRegistry*>(&data);
	if (geometricalRegistryPtr != NULL){
		WriteArchiveEx registryArchive(filePath, GetVersionInfo(), this);
		I_ASSERT(registryArchive.IsStoring());

		if (!const_cast<CVisualRegistry*>(geometricalRegistryPtr)->SerializeRegistry(registryArchive)){
			SendErrorMessage(
						MI_LOAD_ERROR,
						tr("Cannot store to file %1").arg(filePath));

			return StateFailed;
		}

		WriteArchiveEx layoutArchive(GetLayoutPath(filePath), GetVersionInfo(), this);
		I_ASSERT(layoutArchive.IsStoring());

		if (!const_cast<CVisualRegistry*>(geometricalRegistryPtr)->SerializeUserData(layoutArchive)){
			SendInfoMessage(
						MI_CANNOT_READ_LAYOUT,
						tr("Layout information cannot be stored (%1)").arg(filePath));
		}

		return StateOk;
	}

	return StateFailed;
}


// reimplemented (iser::IFileTypeInfo)

bool CRegistryLoaderComp::GetFileExtensions(QStringList& result, int flags, bool doAppend) const
{
	if (!BaseClass::GetFileExtensions(result, flags, doAppend)){
		if (!doAppend){
			result.clear();
		}

		result.push_back("arx");
	}

	return true;
}


QString CRegistryLoaderComp::GetTypeDescription(const QString* extensionPtr) const
{
	if ((extensionPtr == NULL) || (extensionPtr->compare("arx", Qt::CaseInsensitive) == 0)){
		return tr("ACF registry file");
	}

	return "";
}


// protected methods

QString CRegistryLoaderComp::GetLayoutPath(const QString& registryPath) const
{
	QFileInfo fileInfo(registryPath);
	QString layoutPath = fileInfo.dir().absoluteFilePath(fileInfo.completeBaseName() + ".alx");

	return layoutPath;
}


// reimplemented (ibase::TFileSerializerComp)

void CRegistryLoaderComp::OnReadError(
			const iser::CXmlFileReadArchive& archive,
			const istd::IChangeable& /*data*/,
			const QString& filePath) const
{
	int lastReadLine = archive.GetLastReadLine();

	QString message = tr("%1(%2) : Cannot load file").arg(filePath).arg(lastReadLine);

	SendErrorMessage(MI_CANNOT_LOAD, message);
}


} // namespace icmpstr


