/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "idoc/CSerializedUndoManager.h"


// ACF includes
#include "istd/TChangeNotifier.h"
#include "iser/CMemoryReadArchive.h"
#include "icomp/CComponentBase.h"
#include "i2d/IObject2d.h"


namespace idoc
{


CSerializedUndoManager::CSerializedUndoManager()
:	m_hasStoredDocumentState(false)
{
}


// reimplemented (idoc::IUndoManager)

bool CSerializedUndoManager::IsUndoAvailable() const
{
	return !m_undoList.isEmpty();
}


bool CSerializedUndoManager::IsRedoAvailable() const
{
	return !m_redoList.isEmpty();
}


void CSerializedUndoManager::ResetUndo()
{
	istd::CChangeNotifier selfNotifierPtr(this);

	m_undoList.clear();
	m_redoList.clear();
}


bool CSerializedUndoManager::DoUndo()
{
	UndoArchivePtr redoArchivePtr(new iser::CMemoryWriteArchive());
	if (IsUndoAvailable() && redoArchivePtr.IsValid()){
		istd::CChangeNotifier notifier(this);

		istd::TChangeNotifier<iser::ISerializable> objectPtr(GetObjectPtr(), istd::IChangeable::CF_NO_UNDO);
		if (objectPtr.IsValid()){
			if (objectPtr->Serialize(*redoArchivePtr)){
				m_redoList.push_back(UndoArchivePtr());
				m_redoList.back().TakeOver(redoArchivePtr);
			}

			const UndoArchivePtr& writeArchivePtr = m_undoList.back();
			Q_ASSERT(writeArchivePtr.IsValid());

			iser::CMemoryReadArchive readArchive(*writeArchivePtr);

			if (objectPtr->Serialize(readArchive)){
				m_undoList.pop_back();

				return true;
			}
		}
	}

	return false;
}


bool CSerializedUndoManager::DoRedo()
{
	UndoArchivePtr undoArchivePtr(new iser::CMemoryWriteArchive());
	if (IsRedoAvailable() && undoArchivePtr.IsValid()){
		istd::CChangeNotifier notifier(this);

		istd::TChangeNotifier<iser::ISerializable> objectPtr(GetObjectPtr(), istd::IChangeable::CF_NO_UNDO);
		if (objectPtr.IsValid()){
			if (objectPtr->Serialize(*undoArchivePtr)){
				m_undoList.push_back(UndoArchivePtr());
				m_undoList.back().TakeOver(undoArchivePtr);
			}

			const UndoArchivePtr& writeArchivePtr = m_redoList.back();
			Q_ASSERT(writeArchivePtr.IsValid());

			iser::CMemoryReadArchive readArchive(*writeArchivePtr);

			if (objectPtr->Serialize(readArchive)){
				m_redoList.pop_back();

				return true;
			}
		}
	}

	return false;
}


// reimplemented (imod::IObserver)

bool CSerializedUndoManager::OnAttached(imod::IModel* modelPtr)
{
	if (BaseClass::OnAttached(modelPtr)){
		m_hasStoredDocumentState = false;
		m_storedStateArchive.Reset();

		m_stateChangedFlag = DCF_UNKNOWN;
		m_hasStoredDocumentState = false;

		return true;
	}

	return false;
}


bool CSerializedUndoManager::OnDetached(imod::IModel* modelPtr)
{
	if (BaseClass::OnDetached(modelPtr)){
		m_hasStoredDocumentState = false;
		m_storedStateArchive.Reset();

		m_stateChangedFlag = DCF_UNKNOWN;
		m_hasStoredDocumentState = false;

		return true;
	}

	return false;
}


// protected methods

// reimplemented (imod::TSingleModelObserverBase<iser::ISerializable>)

iser::ISerializable* CSerializedUndoManager::CastFromModel(imod::IModel* modelPtr) const
{
	return CompCastPtr<iser::ISerializable>(modelPtr);
}


// reimplemented (imod::IObserver)

void CSerializedUndoManager::BeforeUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr)
{
	BaseClass::BeforeUpdate(modelPtr, updateFlags, updateParamsPtr);

	if (	((updateFlags & istd::IChangeable::CF_NO_UNDO) == 0) 
			&& ((updateFlags & i2d::IObject2d::CF_OBJECT_END_TRANSFORM) == 0) 
			&& !m_beginStateArchivePtr.IsValid()){
		iser::ISerializable* objectPtr = GetObjectPtr();
		if (objectPtr != NULL){
			UndoArchivePtr archivePtr(new iser::CMemoryWriteArchive());

			if (		archivePtr.IsValid() &&
						objectPtr->Serialize(*archivePtr) &&
						(m_undoList.isEmpty() || *archivePtr != *m_undoList.back() || (updateFlags & i2d::IObject2d::CF_OBJECT_START_TRANSFORM))){
				m_beginStateArchivePtr.TakeOver(archivePtr);
			}
		}
	}
}


void CSerializedUndoManager::AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr)
{
	istd::CChangeNotifier selfNotifierPtr(NULL);

	if (	((updateFlags & istd::IChangeable::CF_NO_UNDO) == 0) 
			&& ((updateFlags & i2d::IObject2d::CF_OBJECT_START_TRANSFORM) == 0) 
			&& m_beginStateArchivePtr.IsValid()){
		iser::ISerializable* objectPtr = GetObjectPtr();
		if (objectPtr != NULL){
			UndoArchivePtr archivePtr(new iser::CMemoryWriteArchive());

			if (objectPtr->Serialize(*archivePtr)){
				if (*archivePtr != *m_beginStateArchivePtr){
					selfNotifierPtr.SetPtr(this);

					m_undoList.push_back(UndoArchivePtr());
					m_undoList.back().TakeOver(m_beginStateArchivePtr);
					m_redoList.clear();
				}
			}
		}

		m_beginStateArchivePtr.Reset();
	}

	m_isStateChangedFlagValid = false;

	BaseClass::AfterUpdate(modelPtr, updateFlags, updateParamsPtr);
}


// reimplemented (idoc::IDocumentStateComparator)

bool CSerializedUndoManager::HasStoredDocumentState() const
{
	return m_hasStoredDocumentState;
}


bool CSerializedUndoManager::StoreDocumentState()
{
	istd::CChangeNotifier selfNotifierPtr(this);

	m_storedStateArchive.Reset();

	iser::ISerializable* serializablePtr = GetObjectPtr();
	if ((serializablePtr != NULL) && serializablePtr->Serialize(m_storedStateArchive)){
		m_stateChangedFlag = DCF_EQUAL;
		m_hasStoredDocumentState = true;
	}
	else{
		m_stateChangedFlag = DCF_UNKNOWN;
		m_hasStoredDocumentState = false;
	}
	m_isStateChangedFlagValid = true;

	return false;
}


bool CSerializedUndoManager::RestoreDocumentState()
{
	iser::CMemoryReadArchive restoreArchive(m_storedStateArchive);

	if (m_hasStoredDocumentState){
		istd::CChangeNotifier selfNotifierPtr(this);

		istd::TChangeNotifier<iser::ISerializable> serializablePtr(GetObjectPtr(), istd::IChangeable::CF_NO_UNDO);
		if (serializablePtr.IsValid() && serializablePtr->Serialize(restoreArchive)){
			m_stateChangedFlag = DCF_EQUAL;
			m_isStateChangedFlagValid = true;

			return true;
		}

		m_stateChangedFlag = DCF_UNKNOWN;
		m_isStateChangedFlagValid = true;

		m_undoList.clear();
		m_redoList.clear();
	}

	return false;
}


IDocumentStateComparator::DocumentChangeFlag CSerializedUndoManager::GetDocumentChangeFlag() const
{
	if (!m_isStateChangedFlagValid){
		iser::CMemoryWriteArchive compareArchive;

		iser::ISerializable* serializablePtr = GetObjectPtr();
		if (serializablePtr != NULL){
			const_cast<iser::ISerializable*>(serializablePtr)->Serialize(compareArchive);
			m_stateChangedFlag = (compareArchive != m_storedStateArchive)? DCF_DIFFERENT: DCF_EQUAL;
		}
		else{
			m_stateChangedFlag = DCF_UNKNOWN;
		}

		m_isStateChangedFlagValid = true;
	}

	return m_stateChangedFlag;
}


} // namespace idoc


