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


#ifndef iwiz_IWizardNavigationController_included
#define iwiz_IWizardNavigationController_included


#include "istd/IPolymorphic.h"


namespace iwiz
{


/**
	Interface for wizard navigation.
*/
class IWizardNavigationController: virtual public istd::IPolymorphic
{
public:

	/**
		Get the ID of the next wizard page for the current page.
		\param currentPageId	ID of the current wizard page.
	*/
	virtual int GetNextPageId(int currentPageId) = 0;
};


} // namespace iwiz


#endif // !iwiz_IWizardNavigationController_included


