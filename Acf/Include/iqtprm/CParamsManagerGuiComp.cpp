/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include "iqtprm/CParamsManagerGuiComp.h"


namespace iqtprm
{


// protected methods

// reimplemented (CParamsManagerGuiCompBase)

imod::IObserver* CParamsManagerGuiComp::GetObserverPtr(const iprm::IParamsSet* /*paramsSetPtr*/) const
{
	return m_paramsObserverCompPtr.GetPtr();
}


iqtgui::IGuiObject* CParamsManagerGuiComp::GetEditorGuiPtr(const iprm::IParamsSet* /*paramsSetPtr*/) const
{
	return m_paramsGuiCompPtr.GetPtr();
}


// reimplemented (iqtgui::CComponentBase)

void CParamsManagerGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	if (m_paramsGuiCompPtr.IsValid()){
		m_paramsGuiCompPtr->CreateGui(ParamsFrame);
	}
}


void CParamsManagerGuiComp::OnGuiDestroyed()
{
	if (m_paramsGuiCompPtr.IsValid()){
		m_paramsGuiCompPtr->DestroyGui();
	}

	BaseClass::OnGuiDestroyed();
}


} // namespace iqtprm


