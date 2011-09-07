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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt2d/CSceneBinderComp.h"


namespace iqt2d
{


// protected methods

// reimplemented (icomp::CComponentBase)

void CSceneBinderComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_sceneProviderCompPtr.IsValid() && m_extenderCompPtr.IsValid()){
		m_extenderCompPtr->AddItemsToScene(m_sceneProviderCompPtr.GetPtr(), ISceneExtender::SF_DIRECT);
	}
}


void CSceneBinderComp::OnComponentDestroyed()
{
	if (m_sceneProviderCompPtr.IsValid() && m_extenderCompPtr.IsValid()){
		m_extenderCompPtr->RemoveItemsFromScene(m_sceneProviderCompPtr.GetPtr());
	}

	BaseClass::OnComponentDestroyed();
}


} // namespace iqt2d


