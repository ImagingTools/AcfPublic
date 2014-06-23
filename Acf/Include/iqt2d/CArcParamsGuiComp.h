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


#ifndef iqt2d_CArcParamsGuiComp_included
#define iqt2d_CArcParamsGuiComp_included


#include "i2d/CArc.h"

#include "iview/CArcShape.h"

#include "iqt2d/TShapeParamsGuiCompBase.h"
#include "GeneratedFiles/iqt2d/ui_CArcParamsGuiComp.h"


namespace iqt2d
{


class CArcParamsGuiComp: 
			public iqt2d::TShapeParamsGuiCompBase<
						Ui::CArcParamsGuiComp,
						iview::CArcShape,
						i2d::CArc>
{
	Q_OBJECT

public:
	typedef iqt2d::TShapeParamsGuiCompBase<
				Ui::CArcParamsGuiComp,
				iview::CArcShape,
				i2d::CCircle> CArc;

	I_BEGIN_COMPONENT(CArcParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();
	virtual void OnGuiRetranslate();

protected Q_SLOTS:
	void OnParamsChanged(double value);
};


} // namespace iqt2d


#endif // !iqt2d_CArcParamsGuiComp_included


