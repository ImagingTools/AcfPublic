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


#ifndef iprm_IWizardPageController_included
#define iprm_IWizardPageController_included


#include "istd/IPolymorphic.h"


namespace imod
{
	class IModel;
}


namespace iprm
{


class IWizardPageInfo;


/**
	Interface for a wizard page controller.
	Controller will be notified about changes in the wizard page and 
	can set page status and/or navigation flow to the page object via UpdatePage method.
*/
class IWizardPageController: virtual public istd::IPolymorphic
{
public:
	/**
		The method will be called on changes in the data model of the wizard page.
		\param pageDataModel data model of the wizard page
		\param page	wizard page, which has triggered this event
	*/
	virtual bool UpdateWizardPage(iprm::IWizardPageInfo& page, imod::IModel& pageDataModel) = 0;
};


} // namespace iprm


#endif // !iprm_IWizardPageController_included


