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


#include "ifile/CAutoPersistenceComp.h"


// Qt includes
#include <QtCore/QtGlobal>
#include <QtCore/QCoreApplication>
#if QT_VERSION >= 0x050000
#include <QtConcurrent/QtConcurrent>
#else
#include <QtCore>
#endif


namespace ifile
{


// public methods

CAutoPersistenceComp::CAutoPersistenceComp()
	:m_isDataWasChanged(false)
{
}


// protected methods

void CAutoPersistenceComp::SaveObjectSnapshot()
{
	bool skipStoring = false;

	if (!m_objectShadowPtr.IsValid()){
		return;
	}

	iser::ISerializable* serializablePtr = dynamic_cast<iser::ISerializable*>(m_objectShadowPtr.GetPtr());

	// For the serializable objects memory comparison can be done:
	if (serializablePtr != NULL){
		iser::CMemoryWriteArchive currentState;

		if (serializablePtr->Serialize(currentState)){
			if (currentState != m_lastStoredObjectState){
				m_lastStoredObjectState = currentState;
			}
			else{
				skipStoring = true;
			}
		}
	}

	if (!skipStoring){
		StoreObject(*m_objectShadowPtr.GetPtr());
	}
}


void CAutoPersistenceComp::StoreObject(const istd::IChangeable& object) const
{
	if (m_fileLoaderCompPtr.IsValid()){
		QString filePath;
		if (m_filePathCompPtr.IsValid()){
			filePath = m_filePathCompPtr->GetPath();
		}

		m_fileLoaderCompPtr->SaveToFile(object, filePath);
	}
}


// reimplemented (imod::CSingleModelObserverBase)

void CAutoPersistenceComp::OnUpdate(int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	bool storeByTimer = m_storeIntervalAttrPtr.IsValid() ? *m_storeIntervalAttrPtr : false;
	if (storeByTimer){
		EnsureTimerConnected();
	}
	else{
		if (*m_storeOnChangeAttrPtr && m_objectCompPtr.IsValid()){
			StoreObject(*m_objectCompPtr.GetPtr());
		}
	}

	m_isDataWasChanged = true;
}


// reimplemented (icomp::CComponentBase)

void CAutoPersistenceComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (*m_restoreOnBeginAttrPtr){
		if (m_fileLoaderCompPtr.IsValid() && m_objectCompPtr.IsValid()){
			QString filePath;
			if (m_filePathCompPtr.IsValid()){
				filePath = m_filePathCompPtr->GetPath();
			}

			m_fileLoaderCompPtr->LoadFromFile(*m_objectCompPtr, filePath);
		}
	}

	if (m_objectModelCompPtr.IsValid())
	{
		m_objectModelCompPtr->AttachObserver(this);
	}

	EnsureTimerConnected();
}


void CAutoPersistenceComp::OnComponentDestroyed()
{
	disconnect(&m_storingTimer, SIGNAL(timeout()), this, SLOT(OnTimeout()));

	m_storingFuture.waitForFinished();

	EnsureModelDetached();

	if (*m_storeOnEndAttrPtr && m_objectCompPtr.IsValid()){
		StoreObject(*m_objectCompPtr.GetPtr());
	}

	BaseClass::OnComponentDestroyed();
}


// private slots

void CAutoPersistenceComp::OnTimeout()
{
	if (!m_isDataWasChanged){
		return;
	}

	if (m_storingFuture.isRunning()){
		return;
	}

	if (!m_objectCompPtr.IsValid()){
		return;
	}

	m_objectShadowPtr.SetPtr(m_objectCompPtr->CloneMe());
	if (!m_objectShadowPtr.IsValid()){
		return;
	}

	m_storingFuture = QtConcurrent::run(this, &CAutoPersistenceComp::SaveObjectSnapshot);

	m_isDataWasChanged = false;
}


// private methods

void CAutoPersistenceComp::EnsureTimerConnected()
{
	if (m_storeIntervalAttrPtr.IsValid() && !QCoreApplication::startingUp()){
		if (!m_storingTimer.isActive()){
			connect(&m_storingTimer, SIGNAL(timeout()), this, SLOT(OnTimeout()));

			m_storingTimer.start(*m_storeIntervalAttrPtr * 1000);
		}
	}
}


} // namespace ifile


