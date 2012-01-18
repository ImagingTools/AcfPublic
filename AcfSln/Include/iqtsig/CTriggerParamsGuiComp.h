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


#ifndef iqtsig_CTriggerParamsGuiComp_included
#define iqtsig_CTriggerParamsGuiComp_included


#include "isig/ITriggerParams.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtsig/iqtsig.h"

#include "iqtsig/Generated/ui_CTriggerParamsGuiComp.h"


namespace iqtsig
{


class CTriggerParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CTriggerParamsGuiComp,
			isig::ITriggerParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CTriggerParamsGuiComp,
				isig::ITriggerParams> BaseClass;

	I_BEGIN_COMPONENT(CTriggerParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void UpdateGui(int updateFlags = 0);

protected Q_SLOTS:
	void on_NoTriggerRB_toggled(bool state);
	void on_ContinuousRB_toggled(bool state);
	void on_RisingEdgeRB_toggled(bool state);
	void on_FallingEdgeRB_toggled(bool state);
	void on_PositiveLevelRB_toggled(bool state);
	void on_NegativeLevelRB_toggled(bool state);
	void on_SoftwareTriggerRB_toggled(bool state);
};


} // namespace iqtsig


#endif // !iqtsig_CTriggerParamsGuiComp_included


