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


#include "iprm/CComposedParamsSetComp.h"


// ACF includes
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iprm
{


// reimplemented (iprm::IParamsSet)

IParamsSet::Ids CComposedParamsSetComp::GetParamIds(bool editableOnly) const
{
	Ids retVal = BaseClass2::GetParamIds(editableOnly);

	if (!editableOnly){
		int slavesCount = m_slaveParamsCompPtr.GetCount();
		for (int i = 0; i < slavesCount; ++i){
			const IParamsSet* slavePtr = m_slaveParamsCompPtr[i];
			if (slavePtr != NULL){
				retVal += slavePtr->GetParamIds(false);
			}
		}
	}

	return retVal;
}


const iser::ISerializable* CComposedParamsSetComp::GetParameter(const QByteArray& id) const
{
	const iser::ISerializable* paramPtr = BaseClass2::GetParameter(id);
	if (paramPtr != NULL){
		return paramPtr;
	}

	int slavesCount = m_slaveParamsCompPtr.GetCount();
	for (int i = 0; i < slavesCount; ++i){
		const IParamsSet* slavePtr = m_slaveParamsCompPtr[i];
		if (slavePtr != NULL){
			const iser::ISerializable* paramPtr = slavePtr->GetParameter(id);
			if (paramPtr != NULL){
				return paramPtr;
			}
		}
	}

	return NULL;
}


// reimplemented (istd::IHierarchical)

int CComposedParamsSetComp::GetHierarchicalFlags() const
{
	return HF_CHILDS_SUPPORTED;
}


int CComposedParamsSetComp::GetChildsCount() const
{
	return m_parametersCompPtr.GetCount();
}


istd::IPolymorphic* CComposedParamsSetComp::GetChild(int index) const
{
	Q_ASSERT(index >= 0);
	Q_ASSERT(index < m_parametersCompPtr.GetCount());

	return m_parametersCompPtr[index];
}


istd::IPolymorphic* CComposedParamsSetComp::GetParent() const
{
	return NULL;
}


// reimplemented (istd::IChangeable)

bool CComposedParamsSetComp::CopyFrom(const IChangeable& object)
{
	// Copy all fixed parameters from external parameter set
	const iprm::IParamsSet* objectParamsSetPtr = dynamic_cast<const iprm::IParamsSet*>(&object);

	if (objectParamsSetPtr == NULL){
		return false;
	}
	int setsCount = qMin(m_parametersCompPtr.GetCount(), m_parametersIdAttrPtr.GetCount());

	for (int i = 0; i < setsCount; ++i){
		const QByteArray& id = m_parametersIdAttrPtr[i];
		iser::ISerializable* paramPtr = m_parametersCompPtr[i];
		if (paramPtr != NULL){
			const iser::ISerializable* objectParamPtr = objectParamsSetPtr->GetParameter(id);
			if ((objectParamPtr == NULL) || !paramPtr->CopyFrom(*objectParamPtr)){
				return false;
			}
		}
	}

	return true;
}


// protected methods

iprm::IParamsSet* CComposedParamsSetComp::GetSlaveParamsSet(int index) const
{
	if (!m_slaveParamsCompPtr.IsValid()){
		return NULL;
	}

	Q_ASSERT(index >= 0);
	Q_ASSERT(index < GetSlaveParamsSetCount());

	return m_slaveParamsCompPtr[index];
}


int CComposedParamsSetComp::GetSlaveParamsSetCount() const
{
	if (!m_slaveParamsCompPtr.IsValid()){
		return 0;
	}

	return m_slaveParamsCompPtr.GetCount();
}


// reimplemented (icomp::CComponentBase)

void CComposedParamsSetComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	BaseClass2::SetParametersTypeId(*m_typeIdAttrPtr);

	int setsCount = qMin(m_parametersCompPtr.GetCount(), m_parametersIdAttrPtr.GetCount());

	for (int i = 0; i < setsCount; ++i){
		const QByteArray& id = m_parametersIdAttrPtr[i];
		iser::ISerializable* paramPtr = m_parametersCompPtr[i];
		if (paramPtr != NULL){
			BaseClass2::SetEditableParameter(id, paramPtr);
		}
		else{
			qDebug(		"Component '%s': Parameter '%s' is set to invalid pointer",
						icomp::CComponentContext::GetHierarchyAddress(GetComponentContext()).constData(),
						id.constData());
		}
	}
}


} // namespace iprm


