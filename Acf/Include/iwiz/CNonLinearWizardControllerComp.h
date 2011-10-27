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


#ifndef iwiz_CNonLinearWizardControllerComp_included
#define iwiz_CNonLinearWizardControllerComp_included


#include "icomp/CComponentBase.h"

#include "iprm/IParamsManager.h"

#include "iwiz/IWizardNavigationController.h"
#include "iwiz/IWizardPageController.h"


namespace iwiz
{


/**
	Component implementation of a wizard controller.
*/
class CNonLinearWizardControllerComp:
			public icomp::CComponentBase,
			virtual public iwiz::IWizardNavigationController,
			virtual public iwiz::IWizardPageController
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CNonLinearWizardControllerComp);
		I_REGISTER_INTERFACE(iwiz::IWizardNavigationController);
		I_REGISTER_INTERFACE(iwiz::IWizardPageController);
		I_ASSIGN(m_wizardPagesCompPtr, "WizardPages", "Container of wizard page data", true, "WizardPages");
	I_END_COMPONENT;

	int GetPagesCount() const;

	// reimplemented (iwiz::IWizardNavigationController)
	virtual int GetNextPageId(int currentPage);

	// reimplemented (iwiz::IWizardPageController)
	virtual bool UpdateWizardPage(iwiz::IWizardPageInfo& page, imod::IModel& pageDataModel);

private:
	I_REF(iprm::IParamsManager, m_wizardPagesCompPtr);
};


} // namespace iwiz


#endif // !iwiz_CNonLinearWizardControllerComp_included


