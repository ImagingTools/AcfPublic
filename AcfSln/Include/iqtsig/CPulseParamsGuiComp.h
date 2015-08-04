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


#ifndef iqtsig_CPulseParamsGuiComp_included
#define iqtsig_CPulseParamsGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiObserverCompBase.h"

// ACF-Solutions includes
#include "isig/IPulseParams.h"

#include "iqtsig/iqtsig.h"

#include "GeneratedFiles/iqtsig/ui_CPulseParamsGuiComp.h"


namespace iqtsig
{


class CPulseParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CPulseParamsGuiComp,
			isig::IPulseParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CPulseParamsGuiComp,
				isig::IPulseParams> BaseClass;

	I_BEGIN_COMPONENT(CPulseParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

protected Q_SLOTS:
	void on_DelayTimeSB_valueChanged(double value);
	void on_PulseTimeSB_valueChanged(double value);
	void on_RelaxingTimeSB_valueChanged(double value);
};


} // namespace iqtsig


#endif // !iqtsig_CPulseParamsGuiComp_included


