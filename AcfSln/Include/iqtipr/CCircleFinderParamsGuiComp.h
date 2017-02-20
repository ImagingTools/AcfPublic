/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtipr_CCircleFinderParamsGuiComp_included
#define iqtipr_CCircleFinderParamsGuiComp_included


#include <iipr/ICircleFinderParams.h>

#include <iqtgui/TDesignerGuiObserverCompBase.h>

#include <GeneratedFiles/iqtipr/ui_CCircleFinderParamsGuiComp.h>


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

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateModel() const;
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

protected Q_SLOTS:
	void on_EnableOutliersElimination_toggled(bool value);
	void on_MinOutliersDistance_valueChanged(double value);
	void on_MaxRaysCount_valueChanged(int value);
	void on_CaliperMode_currentIndexChanged(int index);
};


} // namespace iqtipr


#endif // !iqtipr_CCircleFinderParamsGuiComp_included


