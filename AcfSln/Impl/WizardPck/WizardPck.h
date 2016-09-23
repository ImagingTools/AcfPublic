/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef WizardPck_included
#define WizardPck_included


#include <icomp/TModelCompWrap.h>


#include <iwiz/CWizardDocumentComp.h>
#include <iwiz/CComposedStateControllerComp.h>
#include <iwiz/CSelectionConsistencyControllerComp.h>


/**
	Wizard controller package.
*/
namespace WizardPck
{


typedef icomp::TModelCompWrap<iwiz::CWizardDocumentComp> WizardDocument;
typedef icomp::TModelCompWrap<iwiz::CComposedStateControllerComp> ComposedStateController;
typedef icomp::TModelCompWrap<iwiz::CSelectionConsistencyControllerComp> SelectionConsistencyController;


} // namespace WizardPck


#endif // !WizardPck_included


