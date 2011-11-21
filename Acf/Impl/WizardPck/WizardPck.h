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


#ifndef WizardPck_included
#define WizardPck_included


#include "icomp/TModelCompWrap.h"


#include "iwiz/CWizardDocumentComp.h"
#include "iwiz/CWizardPageComp.h"


/**
	Wizard controller package.
*/
namespace WizardPck
{


typedef icomp::TModelCompWrap<iwiz::CWizardDocumentComp> WizardDocument;
typedef icomp::TModelCompWrap<iwiz::CWizardPageComp> WizardPage;


} // namespace WizardPck


#endif // !WizardPck_included


