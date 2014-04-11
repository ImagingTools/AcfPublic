/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "ifilegui/CFilePreviewGuiComp.h"


// Qt includes
#include <QtCore/QFileInfo>
#include <QtCore/QTimer>

// ACF includes
#include "istd/TChangeNotifier.h"


namespace ifilegui
{


// protected methods

// reimplemented (imod::TGuiObserverWrap)

void CFilePreviewGuiComp::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	if (		m_objectModelCompPtr.IsValid() &&
				m_objectObserverCompPtr.IsValid() &&
				!m_objectModelCompPtr->IsAttached(m_objectObserverCompPtr.GetPtr())){
		m_objectModelCompPtr->AttachObserver(m_objectObserverCompPtr.GetPtr());
	}
}


void CFilePreviewGuiComp::OnGuiModelDetached()
{
	if (		m_objectModelCompPtr.IsValid() &&
				m_objectObserverCompPtr.IsValid() &&
				m_objectModelCompPtr->IsAttached(m_objectObserverCompPtr.GetPtr())){
		m_objectModelCompPtr->DetachObserver(m_objectObserverCompPtr.GetPtr());
	}

	BaseClass::OnGuiModelDetached();
}


void CFilePreviewGuiComp::UpdateGui(int /*updateFlags*/)
{
	Q_ASSERT(IsGuiCreated());

	if (!m_fileLoaderCompPtr.IsValid()){
		return;
	}

	UpdateFilePreview();


}


// reimplemented (iqtgui::CGuiComponentBase)

void CFilePreviewGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	if (m_objectGuiCompPtr.IsValid()){
		m_objectGuiCompPtr->CreateGui(ObjectViewFrame);	
	}

	connect(&m_fileSystemObserver, SIGNAL(fileChanged(const QString&)), this, SLOT(UpdateFilePreview()));
}


void CFilePreviewGuiComp::OnGuiDestroyed()
{
	if (m_objectGuiCompPtr.IsValid()){
		m_objectGuiCompPtr->DestroyGui();	
	}

	BaseClass::OnGuiDestroyed();
}


void CFilePreviewGuiComp::UpdateFilePreview()
{
	ifile::IFileNameParam* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		QString newFilePath = objectPtr->GetPath();

		int fileQueryFlags = ifile::IFilePersistence::QF_LOAD;

		QFileInfo newFileInfo(newFilePath);
		if (newFileInfo.isFile()){
			fileQueryFlags |= ifile::IFilePersistence::QF_FILE;
		}
		else if (newFileInfo.isDir()){
			fileQueryFlags |= ifile::IFilePersistence::QF_DIRECTORY;
		}

		if (m_fileLoaderCompPtr->IsOperationSupported(NULL, NULL, fileQueryFlags)){
			if (m_lastFilePath != newFilePath){
				m_lastFilePath = newFilePath;

				m_fileSystemObserver.removePaths(m_fileSystemObserver.files());
				m_fileSystemObserver.addPath(m_lastFilePath);

				m_lastModificationTimeStamp = QDateTime();

				UpdateObjectFromFile();
			}
		}
		else{
			m_lastFilePath = QString();

			if (m_objectCompPtr.IsValid()){
				m_objectCompPtr->ResetData();
			}

			if (!newFilePath.isEmpty()){
				 QTimer::singleShot(1000, this, SLOT(UpdateFilePreview()));
			}
		}
	}
	else{
		if (m_objectCompPtr.IsValid()){
			m_objectCompPtr->ResetData();
		}
	}
}


// private methods

void CFilePreviewGuiComp::UpdateObjectFromFile()
{
	if (!m_objectCompPtr.IsValid()){
		return;
	}

	QFileInfo fileInfo(m_lastFilePath);

	if (!fileInfo.exists()){
		m_objectCompPtr->ResetData();

		return;
	}

	if (fileInfo.lastModified() != m_lastModificationTimeStamp){
		m_lastModificationTimeStamp = fileInfo.lastModified();

		istd::CChangeNotifier changePtr(m_objectCompPtr.GetPtr());

		if (m_fileLoaderCompPtr.IsValid()){
			int retVal = m_fileLoaderCompPtr->LoadFromFile(*m_objectCompPtr.GetPtr(), m_lastFilePath);
			if (retVal != ifile::IFilePersistence::OS_OK){
				m_objectCompPtr->ResetData();
			}
		}
	}
}


} // namespace ifilegui


