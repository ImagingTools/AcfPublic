/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtgui/CObjectPreviewGuiComp.h"


// Qt includes
#include <QFileInfo>


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iqtgui
{


// public methods

// reimplemented (imod::IModelEditor)

void CObjectPreviewGuiComp::UpdateEditor(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	iprm::IFileNameParam* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		QString qtFilePath = iqt::GetQString(objectPtr->GetPath());

		if (m_lastFilePath != qtFilePath){
			m_lastFilePath = qtFilePath;

			m_fileSystemObserver.removePaths(m_fileSystemObserver.files());

			if (QFile::exists(m_lastFilePath)){
				m_fileSystemObserver.addPath(m_lastFilePath);
			}
			else{
				m_lastFilePath = QString();
			}

			m_lastModificationTimeStamp = QDateTime();
		}

		UpdateObjectFromFile();
	}
}


void CObjectPreviewGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated() && (GetObjectPtr() != NULL));
}


// protected methods

// reimplemented (imod::TGuiObserverWrap)

void CObjectPreviewGuiComp::OnGuiModelDetached()
{
	if (m_objectObserverCompPtr.IsValid() && m_objectModelCompPtr.IsValid()){
		if (m_objectModelCompPtr->IsAttached(m_objectObserverCompPtr.GetPtr())){
			m_objectModelCompPtr->DetachObserver(m_objectObserverCompPtr.GetPtr());
		}
	}

	BaseClass::OnGuiModelDetached();
}


// reimplemented (iqtgui::CGuiComponentBase)

void CObjectPreviewGuiComp::OnGuiCreated()
{
	if (m_objectGuiCompPtr.IsValid()){
		m_objectGuiCompPtr->CreateGui(ObjectViewFrame);	
	}

	connect(&m_fileSystemObserver, SIGNAL(fileChanged(const QString&)), this, SLOT(OnFileChanged(const QString&)));

	BaseClass::OnGuiCreated();
}


void CObjectPreviewGuiComp::OnGuiDestroyed()
{
	if (m_objectGuiCompPtr.IsValid()){
		m_objectGuiCompPtr->DestroyGui();	
	}

	BaseClass::OnGuiDestroyed();
}


// private slots

void CObjectPreviewGuiComp::OnFileChanged(const QString&/* filePath*/)
{
	UpdateObjectFromFile();
}


// private methods

void CObjectPreviewGuiComp::UpdateObjectFromFile()
{
	QFileInfo fileInfo(m_lastFilePath);
	if (!fileInfo.exists()){
		if (m_objectModelCompPtr->IsAttached(m_objectObserverCompPtr.GetPtr())){
			m_objectModelCompPtr->DetachObserver(m_objectObserverCompPtr.GetPtr());
		}
	}
	else{
		if (!m_objectModelCompPtr->IsAttached(m_objectObserverCompPtr.GetPtr())){
			m_objectModelCompPtr->AttachObserver(m_objectObserverCompPtr.GetPtr());
		}
	}
	
	if (fileInfo.lastModified() != m_lastModificationTimeStamp){
		m_lastModificationTimeStamp = fileInfo.lastModified();

		istd::CChangeNotifier changePtr(m_objectCompPtr.GetPtr());

		if (m_fileLoaderCompPtr.IsValid()){
			int retVal = m_fileLoaderCompPtr->LoadFromFile(*m_objectCompPtr.GetPtr(), iqt::GetCString(m_lastFilePath));
			if (retVal != iser::IFileLoader::StateOk){
				if (m_objectModelCompPtr->IsAttached(m_objectObserverCompPtr.GetPtr())){
					m_objectModelCompPtr->DetachObserver(m_objectObserverCompPtr.GetPtr());
				}
			}
		}
	}
}


} // namespace iqtgui


