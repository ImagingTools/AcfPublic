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


#ifndef iqtsig_CSamplingParamsGuiComp_included
#define iqtsig_CSamplingParamsGuiComp_included


#include "isig/ISamplingParams.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtsig/iqtsig.h"

#include "iqtsig/Generated/ui_CSamplingParamsGuiComp.h"


namespace iqtsig
{


class CSamplingParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CSamplingParamsGuiComp,
			isig::ISamplingParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CSamplingParamsGuiComp,
				isig::ISamplingParams> BaseClass;

	I_BEGIN_COMPONENT(CSamplingParamsGuiComp)
	I_END_COMPONENT

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void UpdateGui(int updateFlags = 0);

protected Q_SLOTS:
	void on_IntervalSB_valueChanged(double value);
	void on_ModeCB_currentIndexChanged(int index);
};


} // namespace iqtsig


#endif // !iqtsig_CSamplingParamsGuiComp_included


