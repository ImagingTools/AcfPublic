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


#ifndef iqt2d_CSceneControllerGuiComp_included
#define iqt2d_CSceneControllerGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiCompBase.h"

#include "i2d/ISceneController.h"

#include "iqt2d/ISceneProvider.h"
#include "iqt2d/Generated/ui_CSceneControllerGuiComp.h"


namespace iqt2d
{


class CSceneControllerGuiComp:
			public iqtgui::TDesignerGuiCompBase<Ui::CSceneControllerGuiComp>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiCompBase<Ui::CSceneControllerGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CSceneControllerGuiComp);
		I_ASSIGN(m_sceneRestrictionsCompPtr, "SceneRestrictions", "Scene manipulation restrictions", false, "SceneRestrictions");
		I_ASSIGN(m_sceneProviderCompPtr, "SceneProvider", "Scene provider", true, "SceneProvider");
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

protected Q_SLOTS:
	void OnZoomIncrement();
	void OnZoomDecrement();
	void OnResetView();
	void OnRotateRight();
	void OnRotateLeft();

private:
	I_REF(i2d::ISceneController, m_sceneRestrictionsCompPtr);
	I_REF(iqt2d::ISceneProvider, m_sceneProviderCompPtr);
};


} // namespace iqt2d


#endif // !iqt2d_CSceneControllerGuiComp_included


