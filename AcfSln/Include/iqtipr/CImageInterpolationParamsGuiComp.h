/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iqtipr_CImageInterpolationParamsGuiComp_included
#define iqtipr_CImageInterpolationParamsGuiComp_included


// ACF includes
#include <iqtgui/TDesignerGuiObserverCompBase.h>

// ACF-Solutions includes
#include <iipr/IImageInterpolationParams.h>
#include <GeneratedFiles/iqtipr/ui_CImageInterpolationParamsGuiComp.h>


namespace iqtipr
{


class CImageInterpolationParamsGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CImageInterpolationParamsGuiComp,
						iipr::IImageInterpolationParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CImageInterpolationParamsGuiComp,
				iipr::IImageInterpolationParams> BaseClass;

	I_BEGIN_COMPONENT(CImageInterpolationParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiRetranslate();

protected Q_SLOTS:
	void on_InterpolationModeCombo_currentIndexChanged(int index);
};


} // namespace iqtipr


#endif // !iqtipr_CImageInterpolationParamsGuiComp_included


