/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtgui_CFreeWidgetGuiComp_included
#define iqtgui_CFreeWidgetGuiComp_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif


// ACF includes
#include <icomp/CComponentBase.h>

#include <iqtgui/IGuiObject.h>


namespace iqtgui
{


class CFreeWidgetGuiComp: public icomp::CComponentBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CFreeWidgetGuiComp);
		I_ASSIGN(m_slaveGuiCompPtr, "SlaveGui", "Slave GUI for this window", true, "SlaveGui");
		I_ASSIGN(m_titleAttrPtr, "Title", "Specify the window title ", true, "Free Window");
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

	I_REF(iqtgui::IGuiObject, m_slaveGuiCompPtr);
	I_TEXTATTR(m_titleAttrPtr);

	istd::TDelPtr<QMainWindow> m_mainWindowPtr;
};


} // namespace iqtgui


#endif // !iqtgui_CFreeWidgetGuiComp_included

