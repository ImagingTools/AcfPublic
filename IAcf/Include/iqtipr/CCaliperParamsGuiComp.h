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


#ifndef iqtipr_CCaliperParamsGuiComp_included
#define iqtipr_CCaliperParamsGuiComp_included


#include "iipr/ICaliperParams.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtipr/Generated/ui_CCaliperParamsGuiComp.h"


namespace iqtipr
{


class CCaliperParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CCaliperParamsGuiComp,
			iipr::ICaliperParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CCaliperParamsGuiComp,
				iipr::ICaliperParams> BaseClass;

	I_BEGIN_COMPONENT(CCaliperParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

protected Q_SLOTS:
	void on_ThresholdSB_valueChanged(int value);
	void on_EdgePolarityCB_currentIndexChanged(int index);
	void on_DirectionCB_currentIndexChanged(int index);
};


} // namespace iqtipr


#endif // !iqtipr_CCaliperParamsGuiComp_included


