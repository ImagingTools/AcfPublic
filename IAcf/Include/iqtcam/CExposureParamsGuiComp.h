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


#ifndef iqtcam_CExposureParamsGuiComp_included
#define iqtcam_CExposureParamsGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "icam/IExposureParams.h"

#include "iqtcam/Generated/ui_CExposureParamsGuiComp.h"


namespace iqtcam
{


class CExposureParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CExposureParamsGuiComp,
			icam::IExposureParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CExposureParamsGuiComp,
				icam::IExposureParams> BaseClass;

	I_BEGIN_COMPONENT(CExposureParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void OnGuiModelDetached();
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected Q_SLOTS:
	void OnParamsChanged(double value);
};


} // namespace iqtcam


#endif // !iqtcam_CExposureParamsGuiComp_included


