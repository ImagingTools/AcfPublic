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


#include "iwiz/CNonLinearWizardControllerComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iwiz
{


// public methods

int CNonLinearWizardControllerComp::GetPagesCount() const
{
	if (m_wizardPagesCompPtr.IsValid()){
		return m_wizardPagesCompPtr->GetParamsSetsCount();
	}

	return 0;
}


// reimplemented (iwiz::IWizardNavigationController)

int CNonLinearWizardControllerComp::GetNextPageId(int currentPageId)
{
	if (m_wizardPagesCompPtr.IsValid()){
		int nextIndex = currentPageId + 1;

		if (nextIndex < GetPagesCount()){
			return nextIndex;
		}
	}

	return -1;
}


// reimplemented (iwiz::IWizardPageController)

bool CNonLinearWizardControllerComp::UpdateWizardPage(iwiz::IWizardPageInfo& page, imod::IModel& pageDataModel)
{
	return true;
}


} // namespace iwiz


