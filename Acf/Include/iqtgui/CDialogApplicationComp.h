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


#ifndef iqtgui_CDialogApplicationComp_included
#define iqtgui_CDialogApplicationComp_included


// ACF includes
#include "iqtgui/IDialog.h"
#include "iqtgui/CApplicationCompBase.h"


namespace iqtgui
{


/**
	Standard component for a Qt based GUI application.
	You have several attributes to control the appearance and decoration of the application window,
	you can define the splash screen and set some information about your application.
*/
class CDialogApplicationComp: public CApplicationCompBase
{
public:
	typedef CApplicationCompBase BaseClass;

	I_BEGIN_COMPONENT(CDialogApplicationComp);
		I_REGISTER_INTERFACE(ibase::IApplication);
		I_ASSIGN(m_mainDialogCompPtr, "MainDialogWindow", "Dialog window shown as main window", true, "MainDialogWindow");
	I_END_COMPONENT;

	// reimplemented (ibase::IApplication)
	virtual int Execute(int argc, char** argv);
	virtual istd::CString GetHelpText() const;

private:
	I_REF(IDialog, m_mainDialogCompPtr);
};


} // namespace iqtgui


#endif // iqtgui_CDialogApplicationComp_included

