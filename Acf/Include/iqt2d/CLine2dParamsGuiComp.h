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


#ifndef iqt2d_CLine2dParamsGuiComp_included
#define iqt2d_CLine2dParamsGuiComp_included


#include "i2d/CLine2d.h"

#include "iview/CInteractiveArrowShape.h"

#include "iqt2d/TShapeParamsGuiCompBase.h"
#include "iqt2d/Generated/ui_CLine2dParamsGuiComp.h"


namespace iqt2d
{


class CLine2dParamsGuiComp:
			public iqt2d::TShapeParamsGuiCompBase<
						Ui::CLine2dParamsGuiComp,
						iview::CInteractiveArrowShape,
						i2d::CLine2d>
{
	Q_OBJECT

public:
	typedef iqt2d::TShapeParamsGuiCompBase<
				Ui::CLine2dParamsGuiComp,
				iview::CInteractiveArrowShape,
				i2d::CLine2d> BaseClass;

	I_BEGIN_COMPONENT(CLine2dParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void OnGuiModelDetached();
	virtual void UpdateGui(int updateFlags = 0);

protected Q_SLOTS:
	void OnParamsChanged(double value);
};


} // namespace iqt2d


#endif // !iqt2d_CLine2dParamsGuiComp_included


