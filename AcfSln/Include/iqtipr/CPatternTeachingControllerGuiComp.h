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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtipr_CPatternTeachingControllerGuiComp_included
#define iqtipr_CPatternTeachingControllerGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiObserverCompBase.h"

// ACF-Solutions includes
#include "iipr/IPatternController.h"

#include "Generated/ui_CPatternTeachingControllerGuiComp.h"


namespace iqtipr
{


class CPatternTeachingControllerGuiComp:
		public iqtgui::TDesignerGuiObserverCompBase<
				Ui::CPatternTeachingControllerGuiComp,
				iipr::IPatternController>
{
	Q_OBJECT
public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
			Ui::CPatternTeachingControllerGuiComp,
			iipr::IPatternController> BaseClass;

	I_BEGIN_COMPONENT(CPatternTeachingControllerGuiComp);
	I_END_COMPONENT;

protected Q_SLOTS:
	void on_LearnButton_clicked();

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (iqt::CGuiObjectBase)
	virtual void OnGuiCreated();
};


} // namespace iqtipr


#endif // !iqtipr_CPatternTeachingControllerGuiComp_included


