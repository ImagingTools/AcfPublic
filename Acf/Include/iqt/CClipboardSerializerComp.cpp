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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CClipboardSerializerComp.h"


// Qt includes
#include <QtCore/QByteArray>
#include <QtCore/QMimeData>
#include <QtGui/QApplication>
#include <QtGui/QClipboard>

// ACF includes
#include "istd/TChangeNotifier.h"

#include "iser/CMemoryReadArchive.h"
#include "iser/CMemoryWriteArchive.h"


namespace iqt
{


// reimplemented (iser::IFileLoader)

bool CClipboardSerializerComp::IsOperationSupported(
			const istd::IChangeable* dataObjectPtr,
			const QString* filePathPtr,
			int flags,
			bool beQuiet) const
{
	if ((dataObjectPtr != NULL) && (dynamic_cast<const iser::ISerializable*>(dataObjectPtr) == NULL)){
		if (!beQuiet){
			SendInfoMessage(MI_BAD_OBJECT_TYPE, "Object is not serializable");
		}

		return false;
	}

	if ((flags & QF_ANONYMOUS) == 0){
		return false;
	}

	if ((flags & (QF_LOAD | QF_SAVE)) == 0){
		return false;
	}

	return (filePathPtr == NULL) || filePathPtr->isEmpty();
}


int CClipboardSerializerComp::LoadFromFile(istd::IChangeable& data, const QString& /*filePath*/) const
{
	if (IsOperationSupported(&data, NULL, QF_LOAD | QF_ANONYMOUS, false)){
		iser::ISerializable* serializablePtr = CompCastPtr<iser::ISerializable>(const_cast<istd::IChangeable*>(&data));
		Q_ASSERT(serializablePtr != NULL);	// it was checked in IsOperationSupported

		const QClipboard* clipboardPtr = QApplication::clipboard();
		const QMimeData* mimeDataPtr = clipboardPtr->mimeData();

		QString mimeType = *m_mimeTypeAttrPtr;
		if (mimeDataPtr->hasFormat(mimeType)){
			QByteArray mimeData = mimeDataPtr->data(mimeType);
			if (!mimeData.isEmpty()){
				iser::CMemoryReadArchive archive(mimeData.constData(), mimeData.size());

				istd::CChangeNotifier changePtr(NULL, istd::IChangeable::CF_MODEL);

				if (serializablePtr->Serialize(archive)){
					changePtr.SetPtr(&data);
					
					return StateOk;
				}
				else{
					SendErrorMessage(MI_CANNOT_LOAD, "Cannot read data from clipboard archive (data corrupted)");
				}
			}
		}
		else{
			SendInfoMessage(MI_BAD_OBJECT_TYPE, "No MIME format in archive");
		}
	}

	return StateFailed;
}


int CClipboardSerializerComp::SaveToFile(const istd::IChangeable& data, const QString& /*filePath*/) const
{
	if (IsOperationSupported(&data, NULL, QF_SAVE | QF_ANONYMOUS, false)){
		QClipboard* clipboardPtr = QApplication::clipboard();
		if (clipboardPtr == NULL){
			return StateAborted;
		}

		istd::TDelPtr<QMimeData> mimeDataPtr(new QMimeData);
		if (mimeDataPtr.IsValid()){
			iser::ISerializable* serializablePtr = CompCastPtr<iser::ISerializable>(const_cast<istd::IChangeable*>(&data));
			Q_ASSERT(serializablePtr != NULL);	// it was checked in IsOperationSupported

			iser::CMemoryWriteArchive archive(m_versionInfoCompPtr.GetPtr());
			if (serializablePtr->Serialize(archive)){
				QString mimeType = *m_mimeTypeAttrPtr;
				mimeDataPtr->setData(mimeType, QByteArray((const char*)archive.GetBuffer(), archive.GetBufferSize()));

				clipboardPtr->setMimeData(mimeDataPtr.PopPtr());

				return StateOk;
			}
			else{
				SendErrorMessage(MI_CANNOT_LOAD, "Cannot store data to archive");
			}
		}
	}

	return StateFailed;
}


// reimplemented (iser::IFileTypeInfo)

bool CClipboardSerializerComp::GetFileExtensions(QStringList& /*result*/, int /*flags*/, bool /*doAppend*/) const
{
	return false;
}


QString CClipboardSerializerComp::GetTypeDescription(const QString* /*extensionPtr*/) const
{
	return QString();
}


} // namespace iqt


