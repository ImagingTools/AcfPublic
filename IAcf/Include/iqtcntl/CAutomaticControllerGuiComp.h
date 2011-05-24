/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
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
	virtual void UpdateEditor(int updateFlags = 0);

protected slots:
	void on_AutomaticButton_toggled(bool checked);
};


} // namespace iqtcntl


#endif // !iqtcntl_CAutomaticControllerGuiComp_included


