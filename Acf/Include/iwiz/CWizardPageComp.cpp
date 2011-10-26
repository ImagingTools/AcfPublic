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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iwiz/CWizardPageComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iwiz
{


// public methods

CWizardPageComp::CWizardPageComp()
	:m_isPageFinished(false)
{
}


// reimplemented (iwiz::IWizardPageInfo)

bool CWizardPageComp::IsPageFinished() const
{
	return m_isPageFinished;
}


void CWizardPageComp::SetPageFinished(bool isPageFinished)
{
	if (m_isPageFinished != isPageFinished){
		istd::CChangeNotifier changePtr(this, CF_PAGE_FINISHED);

		m_isPageFinished = isPageFinished;
	}
}


// protected methods

// reimplemented (imod::CMultiModelDispatcherBase)

void CWizardPageComp::OnModelChanged(int modelId, int /*changeFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	if (m_pageControllerCompPtr.IsValid()){
		imod::IModel* modelPtr = GetObjectAt<imod::IModel>(modelId);

		I_ASSERT(modelPtr != NULL);

		m_pageControllerCompPtr->UpdateWizardPage(*this, *modelPtr);		
	}
}


// reimplemented (icomp::CComponentBase)

void CWizardPageComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	// if no page controller was set, the page can be immediately marked as finished:
	if (!m_pageControllerCompPtr.IsValid()){
		m_isPageFinished = true;
	}

	const ParameterInfos& parameterInfos = GetParameterInfos();
	for (int parameterIndex = 0; parameterIndex < parameterInfos.GetCount(); parameterIndex++){
		imod::IModel* parameterModelPtr = dynamic_cast<imod::IModel*>(parameterInfos.GetAt(parameterIndex)->parameterPtr.GetPtr());
		if (parameterModelPtr != NULL){
			RegisterModel(parameterModelPtr, parameterIndex);
		}
	}
}


void CWizardPageComp::OnComponentDestroyed()
{
	BaseClass2::UnregisterAllModels();

	BaseClass::OnComponentDestroyed();
}


} // namespace iprm


