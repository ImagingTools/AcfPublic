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


#ifndef iqtgui_CTabbedMultiViewGuiComp_included
#define iqtgui_CTabbedMultiViewGuiComp_included


// ACF includes
#include "imod/IModelEditor.h"
#include "imod/CSingleModelObserverBase.h"


#include "iqtgui/CHierarchicalCommand.h"
#include "iqtgui/CTabContainerGuiComp.h"


namespace iqtgui
{


/**
	A multi view observer implementation.
*/
class CTabbedMultiViewGuiComp:
			public iqtgui::CTabContainerGuiComp,
			public imod::CSingleModelObserverBase
{
	Q_OBJECT

public:
	typedef iqtgui::CTabContainerGuiComp BaseClass;
	typedef imod::CSingleModelObserverBase BaseClass2;

	I_BEGIN_COMPONENT(CTabbedMultiViewGuiComp);
		I_REGISTER_INTERFACE(imod::IObserver);
		I_ASSIGN_MULTI_0(m_observersCompPtr, "Editors", "Editors", true);
	I_END_COMPONENT;

protected:
	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);
	virtual bool OnDetached(imod::IModel* modelPtr);

private:
	I_MULTIREF(imod::IObserver, m_observersCompPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CTabbedMultiViewGuiComp_included


