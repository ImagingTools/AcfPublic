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


#ifndef iqt2d_CRectangleParamsGuiComp_included
#define iqt2d_CRectangleParamsGuiComp_included


#include <i2d/CRectangle.h>

#include <iview/CRectangleShape.h>

#include <iqt2d/TShapeParamsGuiCompBase.h>
#include <GeneratedFiles/iqt2d/ui_CRectangleParamsGuiComp.h>


namespace iqt2d
{


class CRectangleParamsGuiComp:
			public iqt2d::TShapeParamsGuiCompBase<
						Ui::CRectangleParamsGuiComp,
						iview::CRectangleShape,
						i2d::CRectangle>
{
	Q_OBJECT

public:
	typedef iqt2d::TShapeParamsGuiCompBase<
				Ui::CRectangleParamsGuiComp,
				iview::CRectangleShape,
				i2d::CRectangle> BaseClass;

	I_BEGIN_COMPONENT(CRectangleParamsGuiComp);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached() override;
	virtual void OnGuiModelDetached() override;
	virtual void UpdateModel() const override;
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet) override;

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiRetranslate() override;

protected Q_SLOTS:
	void OnParamsChanged(double value);
};


} // namespace iqt2d


#endif // !iqt2d_CRectangleParamsGuiComp_included


