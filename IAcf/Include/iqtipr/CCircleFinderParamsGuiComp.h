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


#ifndef iqtipr_CCircleFinderParamsGuiComp_included
#define iqtipr_CCircleFinderParamsGuiComp_included


#include "iipr/ICircleFinderParams.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtipr/Generated/ui_CCircleFinderParamsGuiComp.h"


namespace iqtipr
{


class CCircleFinderParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CCircleFinderParamsGuiComp,
			iipr::ICircleFinderParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CCircleFinderParamsGuiComp,
				iipr::ICircleFinderParams> BaseClass;

	I_BEGIN_COMPONENT(CCircleFinderParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;
	virtual void UpdateEditor(int updateFlags = 0);

protected Q_SLOTS:
	void on_EnableOutliersElimination_toggled(bool value);
	void on_MinOutliersDistance_valueChanged(double value);
	void on_MaxRaysCount_valueChanged(int value);
	void on_CaliperMode_currentIndexChanged(int index);
};


} // namespace iqtipr


#endif // !iqtipr_CCircleFinderParamsGuiComp_included


