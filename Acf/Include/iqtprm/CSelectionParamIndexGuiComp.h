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


#ifndef iqtprm_CSelectionParamIndexGuiComp_included
#define iqtprm_CSelectionParamIndexGuiComp_included


#include "iprm/ISelectionParam.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtprm/Generated/ui_CSelectionParamIndexGuiComp.h"


namespace iqtprm
{


class CSelectionParamIndexGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CSelectionParamIndexGuiComp,
			iprm::ISelectionParam>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CSelectionParamIndexGuiComp,
				iprm::ISelectionParam> BaseClass;

	I_BEGIN_COMPONENT(CSelectionParamIndexGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

protected Q_SLOTS:
	void on_OptionIndexSlider_valueChanged(int value);
};


} // namespace iqtprm


#endif // !iqtprm_CSelectionParamIndexGuiComp_included


