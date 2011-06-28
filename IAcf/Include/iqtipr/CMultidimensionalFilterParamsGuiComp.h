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


#ifndef iqt_CMultidimensionalFilterParamsGuiComp_included
#define iqt_CMultidimensionalFilterParamsGuiComp_included


#include "iipr/IMultidimensionalFilterParams.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtipr/Generated/ui_CMultidimensionalFilterParamsGuiComp.h"


namespace iqtipr
{


class CMultidimensionalFilterParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CMultidimensionalFilterParamsGuiComp,
			iipr::IMultidimensionalFilterParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CMultidimensionalFilterParamsGuiComp,
				iipr::IMultidimensionalFilterParams> BaseClass;

	I_BEGIN_COMPONENT(CMultidimensionalFilterParamsGuiComp)
	I_END_COMPONENT

	CMultidimensionalFilterParamsGuiComp();

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	void UpdateLabel();

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void UpdateGui(int updateFlags = 0);

protected Q_SLOTS:
	void on_FilterWidthSlider_valueChanged(int value);
	void on_FilterHeightSlider_valueChanged(int value);

private:
	double m_widthScaleFactor;
	double m_heightScaleFactor;
};


} // namespace iqtipr


#endif // !iqt_CMultidimensionalFilterParamsGuiComp_included


