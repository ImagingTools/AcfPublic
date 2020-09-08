/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iprm/CParamsSetDelegatorComp.h>


// ACF incldues
#include <iser/IArchive.h>


namespace iprm
{


// public methods

CParamsSetDelegatorComp::CParamsSetDelegatorComp()
	:BaseClass2(this, UF_SOURCE)
{
}


// reimplemented (iprm::IParamsSet)

CParamsSetDelegatorComp::Ids CParamsSetDelegatorComp::GetParamIds(bool editableOnly) const
{
	if (m_slaveParamsSetCompPtr.IsValid()){
		return m_slaveParamsSetCompPtr->GetParamIds(editableOnly);
	}

	return Ids();
}


const iser::ISerializable* CParamsSetDelegatorComp::GetParameter(const QByteArray& id) const
{
	if (m_slaveParamsSetCompPtr.IsValid()){
		return m_slaveParamsSetCompPtr->GetParameter(id);
	}

	return NULL;
}


iser::ISerializable* CParamsSetDelegatorComp::GetEditableParameter(const QByteArray& id)
{
	if (m_slaveParamsSetCompPtr.IsValid()){
		return m_slaveParamsSetCompPtr->GetEditableParameter(id);
	}

	return NULL;
}


// reimplemented (iser::IObject)

QByteArray CParamsSetDelegatorComp::GetFactoryId() const
{
	if (m_typeIdAttrPtr.IsValid()){
		return *m_typeIdAttrPtr;
	}
	else if (m_slaveParamsSetCompPtr.IsValid()){
		return m_slaveParamsSetCompPtr->GetFactoryId();
	}

	return QByteArray();
}


// reimplemented (iser::ISerializable)

bool CParamsSetDelegatorComp::Serialize(iser::IArchive& archive)
{
	if (m_slaveParamsSetCompPtr.IsValid()){
		return m_slaveParamsSetCompPtr->Serialize(archive);
	}

	return false;
}


// reimplemented (istd::IChangeable)

bool CParamsSetDelegatorComp::CopyFrom(const IChangeable& object, CompatibilityMode mode)
{
	if (m_slaveParamsSetCompPtr.IsValid()){
		return m_slaveParamsSetCompPtr->CopyFrom(object, mode);
	}

	return false;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CParamsSetDelegatorComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_modelCompPtr.IsValid()){
		m_modelCompPtr->AttachObserver(this);
	}
}


void CParamsSetDelegatorComp::OnComponentDestroyed()
{
	BaseClass2::EnsureModelsDetached();

	BaseClass::OnComponentDestroyed();
}


} // namespace iprm


