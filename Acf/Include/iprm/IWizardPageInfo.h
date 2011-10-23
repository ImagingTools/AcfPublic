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


#ifndef iprm_IWizardPageInfo_included
#define iprm_IWizardPageInfo_included


#include "istd/IChangeable.h"


namespace iprm
{


/**
	Interface for a wizard page.
*/
class IWizardPageInfo: virtual public istd::IChangeable
{
public:
	enum ChangeFlags
	{
		CF_PAGE_FINISHED = 0x100000	
	};

	/**
		The page processing was finished, the page data is complete set. 
	*/
	virtual bool IsPageFinished() const = 0;

	/**
		Marks a wizard page as finished.

		\sa IsPageFinished
	*/
	virtual void SetPageFinished(bool isPageFinished = true) = 0;
};


} // namespace iprm


#endif // !iprm_IWizardPageInfo_included


