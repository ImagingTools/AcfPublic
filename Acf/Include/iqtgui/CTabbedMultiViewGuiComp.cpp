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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtgui/CTabbedMultiViewGuiComp.h"


// ACF includes
#include "imod/IModel.h"


namespace iqtgui
{


// public methods

// reimplemented (imod::IObserver)

bool CTabbedMultiViewGuiComp::OnAttached(imod::IModel* modelPtr)
{
	if (BaseClass2::OnAttached(modelPtr)){
		if (m_observersCompPtr.IsValid()){
			for (int index = 0; index < m_observersCompPtr.GetCount(); index++){
				modelPtr->AttachObserver(m_observersCompPtr[index]);
			}
		}

		return true;
	}

	return false;
}


bool CTabbedMultiViewGuiComp::OnDetached(imod::IModel* modelPtr)
{
	if (m_observersCompPtr.IsValid()){
		for (int index = 0; index < m_observersCompPtr.GetCount(); index++){
			if (modelPtr->IsAttached(m_observersCompPtr[index])){
				modelPtr->DetachObserver(m_observersCompPtr[index]);
			}
		}
	}

	return BaseClass2::OnDetached(modelPtr);
}


} // namespace iqtgui


