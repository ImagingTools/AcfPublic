/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#ifndef iwiz_IParamsManagerWizard_included
#define iwiz_IParamsManagerWizard_included


#include <iprm/IParamsManager.h>

#include <iwiz/IWizardNavigationController.h>


namespace iwiz
{


/**
	Interface for wizard implementation based on parameter manager.
	In this concept each wizard page is stored as \c iprm::IParamsSet object.
	Pages are accessible using standard iprm::IParamsManager interface.
	Typically no inserting or deleting of page is supported.
*/
class IParamsManagerWizard:
			virtual public IWizardNavigationController,
			virtual public iprm::IParamsManager
{
public:
	/**
		Check, if selection of some wizard page is allowed.
		It is used to avoid trying switch to inactive pages.
		\param	pageIndex	index of page.
							It has the same interpretation as e.g. \c index in iprm::IParamsManager::GetParamsSet or
							\c index in iprm::IOptionsList::GetOptionName.
	*/
	virtual bool IsPageSelectionAllowed(int pageIndex) const = 0;
};


} // namespace iwiz


#endif // !iwiz_IParamsManagerWizard_included


