/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "ifpf/CHotfolderLoaderComp.h"


// Qt includes
#include <QtCore/QFileInfo>
#include <QtCore/QDir>

// ACF includes
#include "istd/TChangeNotifier.h"


// AcfSln includes
#include "ifpf/IHotfolderProcessingInfo.h"


namespace ifpf
{


// reimplemented (iser::IFileLoader)

int CHotfolderLoaderComp::LoadFromFile(istd::IChangeable& data, const QString& filePath) const
{
	if (!IsOperationSupported(&data, &filePath, QF_LOAD | QF_FILE, false)){
		return StateFailed;
	}

	istd::CChangeNotifier notifier(&data);
	iprm::IParamsSet* hotfolderParamsSet = dynamic_cast<iprm::IParamsSet*>(&data);
	if (hotfolderParamsSet == NULL){
		return StateFailed;
	}

	if (m_monitorSessionsParamIdAttrPtr.IsValid()){
		const iser::ISerializable* monitoringSessionsPtr = hotfolderParamsSet->GetParameter(*m_monitorSessionsParamIdAttrPtr);
		if (monitoringSessionsPtr != NULL){
			ReadArchiveEx staticParamsArchive(GetStaticParamsPath(filePath), this);

			(const_cast<iser::ISerializable*>(monitoringSessionsPtr))->Serialize(staticParamsArchive);
		}
	}
	
	return BaseClass::LoadFromFile(data, filePath);
}


int CHotfolderLoaderComp::SaveToFile(const istd::IChangeable& data, const QString& filePath) const
{
	if (!IsOperationSupported(&data, &filePath, QF_SAVE | QF_FILE, false)){
		return StateFailed;
	}

	const iprm::IParamsSet* hotfolderParamsSet = dynamic_cast<const iprm::IParamsSet*>(&data);
	if (hotfolderParamsSet == NULL){
		return StateFailed;
	}

	int retVal = BaseClass::SaveToFile(data, filePath);
	if (retVal != StateFailed){
		if (m_monitorSessionsParamIdAttrPtr.IsValid()){
			const iser::ISerializable* monitoringSessionsPtr = dynamic_cast<const iser::ISerializable*>(hotfolderParamsSet->GetParameter(*m_monitorSessionsParamIdAttrPtr));
			if (monitoringSessionsPtr != NULL){
				WriteArchiveEx staticParamsArchive(GetStaticParamsPath(filePath), GetVersionInfo(), this);

				if ((const_cast<iser::ISerializable*>(monitoringSessionsPtr))->Serialize(staticParamsArchive)){
					return retVal;
				}
			}
		}
	}

	return retVal;
}


// reimplemented (iser::IFileTypeInfo)

bool CHotfolderLoaderComp::GetFileExtensions(QStringList& result, int flags, bool doAppend) const
{
	if (!BaseClass::GetFileExtensions(result, flags, doAppend)){
		if (!doAppend){
			result.clear();
		}

		result.push_back("hot");
	}

	return true;
}


QString CHotfolderLoaderComp::GetTypeDescription(const QString* extensionPtr) const
{
	if ((extensionPtr == NULL) || (extensionPtr->compare("hot", Qt::CaseInsensitive) == 0)){
		return QString("Hotfolder Data File");
	}

	return "";
}


// protected methods

QString CHotfolderLoaderComp::GetStaticParamsPath(const QString& objectPath) const
{
	QFileInfo fileInfo(objectPath);

	return fileInfo.dir().absoluteFilePath(fileInfo.baseName() + ".dms");
}


// reimplemented (ibase::TFileSerializerComp)

void CHotfolderLoaderComp::OnReadError(
			const iser::CXmlFileReadArchive& /*archive*/,
			const istd::IChangeable& /*data*/,
			const QString& /*filePath*/) const
{
}


} // namespace ifpf


