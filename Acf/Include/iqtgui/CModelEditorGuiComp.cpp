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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtgui/CModelEditorGuiComp.h"


namespace iqtgui
{


CModelEditorGuiComp::CModelEditorGuiComp()
:	m_isConnected(false)
{
}


// reimplemented (iqtgui::IGuiObject)

bool CModelEditorGuiComp::IsGuiCreated() const
{
	if (m_slaveGuiCompPtr.IsValid()){
		return m_slaveGuiCompPtr->IsGuiCreated();
	}

	return false;
}


bool CModelEditorGuiComp::CreateGui(QWidget* parentPtr)
{
	if (m_slaveGuiCompPtr.IsValid()){
		return m_slaveGuiCompPtr->CreateGui(parentPtr);
	}

	return false;
}


bool CModelEditorGuiComp::DestroyGui()
{
	if (m_slaveGuiCompPtr.IsValid()){
		return m_slaveGuiCompPtr->DestroyGui();
	}

	return false;
}


QWidget* CModelEditorGuiComp::GetWidget() const
{
	if (m_slaveGuiCompPtr.IsValid()){
		return m_slaveGuiCompPtr->GetWidget();
	}

	return NULL;
}


void CModelEditorGuiComp::OnTryClose(bool* ignoredPtr)
{
	if (m_slaveGuiCompPtr.IsValid()){
		return m_slaveGuiCompPtr->OnTryClose(ignoredPtr);
	}
}


// reimplemented (imod::IModelEditor)

void CModelEditorGuiComp::UpdateEditor(int updateFlags)
{
	I_ASSERT(IsGuiCreated());

	if (m_slaveEditorCompPtr.IsValid()){
		m_slaveEditorCompPtr->UpdateEditor(updateFlags);
	}
}


void CModelEditorGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());

	if (m_slaveEditorCompPtr.IsValid()){
		m_slaveEditorCompPtr->UpdateModel();
	}
}


bool CModelEditorGuiComp::IsReadOnly() const
{
	if (m_slaveEditorCompPtr.IsValid()){
		return m_slaveEditorCompPtr->IsReadOnly();
	}

	return true;
}


void CModelEditorGuiComp::SetReadOnly(bool state)
{
	if (m_slaveEditorCompPtr.IsValid()){
		m_slaveEditorCompPtr->SetReadOnly(state);
	}
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CModelEditorGuiComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	I_ASSERT(!m_isConnected);

	if (m_slaveObserverCompPtr.IsValid() && m_modelCompPtr.IsValid()){
		m_isConnected = m_modelCompPtr->AttachObserver(m_slaveObserverCompPtr.GetPtr());
	}
}


void CModelEditorGuiComp::OnComponentDestroyed()
{
	if (m_isConnected){
		I_ASSERT(m_slaveObserverCompPtr.IsValid());
		I_ASSERT(m_modelCompPtr.IsValid());

		m_modelCompPtr->DetachObserver(m_slaveObserverCompPtr.GetPtr());
	}

	BaseClass::OnComponentDestroyed();
}


} // namespace iqtgui


