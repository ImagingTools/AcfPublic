/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtgui_IGuiObject_included
#define iqtgui_IGuiObject_included


// Qt includes
#include <QWidget>


// ACF includes
#include "istd/IPolymorphic.h"

#include "icomp/IComponent.h"

#include "iqtgui/iqtgui.h"


namespace iqtgui
{


/**
	Common interface for GUI objects using in component context.
 */
class IGuiObject: virtual public istd::IPolymorphic
{
public:
	/**
		Inform if GUI was initilized.
	 */
	virtual bool IsGuiCreated() const = 0;
	/**
		Initialize GUI and connect it to the parent.
		\return		true if initialization successed.
	 */
	virtual bool CreateGui(QWidget* parentPtr) = 0;
	/**
		Release GUI and disconnect it from parent.
		\return		true if this operation successed.
	 */
	virtual bool DestroyGui() = 0;
	/**
		Get access to internal QWidget object.
	*/
	virtual QWidget* GetWidget() const = 0;
	/**
		Called on trying to close application.
		\param	ignoredPtr		if it is not NULL, ignoring of close is allowed.
								In this case implementation should set pointed value to true.
	 */
	virtual void OnTryClose(bool* ignoredPtr = NULL) = 0;
};


} // namespace iqtgui


#endif // !iqtgui_IGuiObject_included


