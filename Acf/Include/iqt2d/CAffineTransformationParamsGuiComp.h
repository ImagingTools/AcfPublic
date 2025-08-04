/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// ACF includes
#include <iview/CAffineTransformation2dShape.h>
#include <i2d/CAffineTransformation2d.h>
#include <iqt2d/TShapeParamsGuiCompBase.h>

#include <GeneratedFiles/iqt2d/ui_CAffineTransformationParamsGui.h>


namespace iqt2d
{


/**
	Gui Editor for shape affine transformation parameters
 */
class CAffineTransformationParamsGuiComp:
			public iqt2d::TShapeParamsGuiCompBase<
						Ui::CAffineTransformationParamsGui,
						iview::CAffineTransformation2dShape,
						i2d::CAffineTransformation2d>
{
	Q_OBJECT

public:
	typedef iqt2d::TShapeParamsGuiCompBase<
				Ui::CAffineTransformationParamsGui,
				iview::CAffineTransformation2dShape,
				i2d::CAffineTransformation2d> BaseClass;

	I_BEGIN_COMPONENT(CAffineTransformationParamsGuiComp);
	I_END_COMPONENT;

protected:
	// reimplemented (iqt2d::TViewExtenderCompBase)
	virtual void CreateShapes(int sceneId, Shapes& result);

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached() override;
	virtual void OnGuiModelDetached() override;
	virtual void UpdateModel() const override;
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet) override;

protected Q_SLOTS:
	void OnParamsChanged(double value);
	void on_ResetButton_clicked(bool = false);
};


} // namespace iqt2d


