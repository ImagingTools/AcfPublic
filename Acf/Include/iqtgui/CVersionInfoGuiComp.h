/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtgui_CVersionInfoGuiComp_included
#define iqtgui_CVersionInfoGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiCompBase.h"
#include "iser/IVersionInfo.h"

#include "GeneratedFiles/iqtgui/ui_CVersionInfoGuiComp.h"


namespace iqtgui
{


/**
	GUI component for showing the list of module versions.
*/
class CVersionInfoGuiComp: public iqtgui::TDesignerGuiCompBase<Ui::CVersionInfoGuiComp>
{
public:
	typedef iqtgui::TDesignerGuiCompBase<Ui::CVersionInfoGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CVersionInfoGuiComp);
		I_ASSIGN_MULTI_0(m_versionInfosCompPtr, "VersionInfos", "List of version infos", true);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

private:
	I_MULTIREF(iser::IVersionInfo, m_versionInfosCompPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CVersionInfoGuiComp_included


