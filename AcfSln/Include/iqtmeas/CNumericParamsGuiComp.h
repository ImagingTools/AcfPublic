/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtmeas_CNumericParamsGuiComp_included
#define iqtmeas_CNumericParamsGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiObserverCompBase.h"

// ACF-Solutions includes
#include "imeas/INumericParams.h"

#include "iqtmeas/Generated/ui_CNumericParamsGuiComp.h"


namespace iqtmeas
{


class CNumericParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CNumericParamsGuiComp,
			imeas::INumericParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CNumericParamsGuiComp,
				imeas::INumericParams> BaseClass;

	I_BEGIN_COMPONENT(CNumericParamsGuiComp)
	I_END_COMPONENT

	CNumericParamsGuiComp();

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


} // namespace iqtmeas


#endif // !iqtmeas_CNumericParamsGuiComp_included


