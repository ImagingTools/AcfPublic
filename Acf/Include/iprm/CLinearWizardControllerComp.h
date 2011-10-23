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


#ifndef iprm_CLinearWizardControllerComp_included
#define iprm_CLinearWizardControllerComp_included


#include "iprm/IParamsManager.h"
#include "iprm/IWizardNavigationController.h"
#include "iprm/IWizardPageController.h"

#include "icomp/CComponentBase.h"


namespace iprm
{


/**
	Component implementation of a wizard controller.
*/
class CLinearWizardControllerComp:
			public icomp::CComponentBase,
			virtual public iprm::IWizardNavigationController
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CLinearWizardControllerComp);
		I_REGISTER_INTERFACE(iprm::IWizardNavigationController);
		I_ASSIGN(m_wizardPagesCompPtr, "WizardPages", "Container of wizard page data", true, "WizardPages");
	I_END_COMPONENT;

	int GetPagesCount() const;

	// reimplemented (iprm::IWizardNavigationController)
	virtual int GetNextPageId(int currentPage);

private:
	I_REF(iprm::IParamsManager, m_wizardPagesCompPtr);
};


} // namespace iprm


#endif // !iprm_CLinearWizardControllerComp_included


