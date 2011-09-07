/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef iqtcntl_CAutomaticControllerGuiComp_included
#define iqtcntl_CAutomaticControllerGuiComp_included


// ACF includes
#include "imod/IModel.h"
#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "icntl/IAutomaticController.h"

#include "iqtcntl/iqtcntl.h"

#include "iqtcntl/Generated/ui_CAutomaticControllerGuiComp.h"


namespace iqtcntl
{


class CAutomaticControllerGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<Ui::CAutomaticControllerGuiComp, icntl::IAutomaticController>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<Ui::CAutomaticControllerGuiComp, icntl::IAutomaticController> BaseClass;

	I_BEGIN_COMPONENT(CAutomaticControllerGuiComp)
	I_END_COMPONENT

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

protected Q_SLOTS:
	void on_AutomaticButton_toggled(bool checked);
};


} // namespace iqtcntl


#endif // !iqtcntl_CAutomaticControllerGuiComp_included


