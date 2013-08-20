/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef TutorialPck_included
#define TutorialPck_included


#include "icomp/TModelCompWrap.h"

#include "DocView/CTextEditorComp.h"

#include "ModelObserver/CAbComp.h"
#include "ModelObserver/CAbGuiComp.h"

#include "itutacf/CInterpolationTestComp.h"
#include "Juri/CHelloJuriGuiComp.h"
#include "TestProject/CTest1Comp.h"
#include "TestProject/CTest1GuiComp.h"
 
/**
	Base system-undependent general package.
*/
namespace TutorialPck
{


typedef CTextEditorComp TextEditor;

typedef icomp::TModelCompWrap<CAbComp> AB;
typedef CAbGuiComp AbGui;
typedef CHelloJuriGuiComp HelloJuri;
typedef icomp::TModelCompWrap<CTest1Comp> Test1;
typedef CTest1GuiComp Test1Gui;

typedef itutacf::CInterpolationTestComp InterpolationTest;


} // namespace TutorialPck


#endif // !TutorialPck_included


