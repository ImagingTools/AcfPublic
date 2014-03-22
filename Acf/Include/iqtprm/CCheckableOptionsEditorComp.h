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


#ifndef iqtprm_CCheckableOptionsEditorComp_included
#define iqtprm_CCheckableOptionsEditorComp_included


// ACF includes
#include "iqtgui/TDesignerGuiObserverCompBase.h"
#include "iprm/IOptionsManager.h"

#include "GeneratedFiles/iqtprm/ui_CCheckableOptionsEditorComp.h"


namespace iqtprm
{


class CCheckableOptionsEditorComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CCheckableOptionsEditorComp,
						iprm::IOptionsManager>
{
	Q_OBJECT
public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CCheckableOptionsEditorComp,
				iprm::IOptionsManager> BaseClass;

	I_BEGIN_COMPONENT(CCheckableOptionsEditorComp);
		I_ASSIGN(m_useHorizontalLayoutAttrPtr, "UseHorizontalLayout", "Horizontal mode for GUI", true, true);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected Q_SLOTS:
	void OnParameterChanged();

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

private:
	I_ATTR(bool, m_useHorizontalLayoutAttrPtr);
};


} // namespace iqtprm


#endif // !iqtprm_CCheckableOptionsEditorComp_included


