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


#ifndef iqtgui_IGuiApplication_included
#define iqtgui_IGuiApplication_included


#include "ibase/IApplication.h"

#include "iqtgui/IGuiObject.h"


namespace iqtgui
{		


/**
	Interface for Qt based application with GUI.
*/
class IGuiApplication: virtual public ibase::IApplication
{
public:
	/**
		Get the main UI object of the application.
	*/
	virtual const iqtgui::IGuiObject* GetApplicationGui() const = 0;
};


} // namespace iqtgui


#endif // !iqtgui_IGuiApplication_included


