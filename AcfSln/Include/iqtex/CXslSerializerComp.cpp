/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iqtex/CXslSerializerComp.h>


// Qt includes
#include <QtCore/QObject>

// ACF includes
#include <istd/CChangeNotifier.h>

// ACF-Solutions includes
#include <iqtex/CXslTransformationReadArchive.h>
#include <iqtex/CXslTransformationWriteArchive.h>


namespace iqtex
{


int CXslSerializerComp::LoadFromFile(
			istd::IChangeable& data,
			const QString& filePath,
			ibase::IProgressManager* /*progressManagerPtr*/) const
{
	if (IsOperationSupported(&data, &filePath, QF_LOAD | QF_FILE, false)){
		CXslTransformationReadArchive archive(filePath, m_xslReadFilePath->GetPath());

		Q_ASSERT(!archive.IsStoring());

		iser::ISerializable* serializablePtr = CompCastPtr<iser::ISerializable>(&data);
		Q_ASSERT(serializablePtr != NULL);

		if (serializablePtr->Serialize(archive)){
			return OS_OK;
		}
		else{
			OnReadError(archive, data, filePath);
		}
	}
	return OS_FAILED;
}


int CXslSerializerComp::SaveToFile(
			const istd::IChangeable& data,
			const QString& filePath,
			ibase::IProgressManager* /*progressManagerPtr*/) const
{
	if (IsOperationSupported(&data, &filePath, QF_SAVE | QF_FILE, false)){
		CXslTransformationWriteArchive archive(filePath, m_xslWriteFilePath->GetPath(), GetVersionInfo(), true);
		Q_ASSERT(archive.IsStoring());

		const iser::ISerializable* serializablePtr = CompCastPtr<iser::ISerializable>(&data);
		Q_ASSERT(serializablePtr != NULL);

		if (!CheckMinimalVersion(*serializablePtr, archive.GetVersionInfo())){
			SendWarningMessage(MI_UNSUPPORTED_VERSION, QObject::tr("Archive version is not supported, possible lost of data"));
		}

		if ((const_cast<iser::ISerializable*>(serializablePtr))->Serialize(archive)){
			return OS_OK;
		}
		else{
			SendInfoMessage(MI_CANNOT_SAVE, QObject::tr("Cannot serialize object to file"));
		}
	}

	return OS_FAILED;
}


// protected methods


void CXslSerializerComp::OnReadError(const iser::IArchive& /*archive*/, const istd::IChangeable& /*data*/, const QString& filePath) const
{
	SendWarningMessage(MI_CANNOT_LOAD, QObject::tr("Cannot load object from file ") + filePath);
}


} // namespace iqtex


