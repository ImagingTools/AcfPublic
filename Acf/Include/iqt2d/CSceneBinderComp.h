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


#ifndef iqt2d_CSceneBinderComp_included
#define iqt2d_CSceneBinderComp_included


// ACF includes
#include <icomp/CComponentBase.h>

#include <iqt2d/IViewProvider.h>
#include <iqt2d/IViewExtender.h>


namespace iqt2d
{


/**
	Binder between scene and shapes creator provider.
*/
class CSceneBinderComp: public icomp::CComponentBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSceneBinderComp);
		I_ASSIGN(m_sceneProviderCompPtr, "SceneProvider", "A graphical scene provider", true, "SceneProvider");
		I_ASSIGN(m_extenderCompPtr, "SceneExtender", "Shapes provider for the graphical scene", true, "SceneExtender");
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(IViewProvider, m_sceneProviderCompPtr);
	I_REF(IViewExtender, m_extenderCompPtr);
};


} // namespace iqt2d


#endif // !iqt2d_CSceneBinderComp_included


