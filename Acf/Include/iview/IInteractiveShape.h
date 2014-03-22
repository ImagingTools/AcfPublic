/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iview_IInteractiveShape_included
#define iview_IInteractiveShape_included


#include "iview/IShape.h"
#include "iview/IMouseActionObserver.h"


namespace iview
{


class IShapeView;


/**
	Common interface for all display console shapes which can interacts with user.
*/
class IInteractiveShape: virtual public IShape, virtual public IMouseActionObserver
{
public:
	/**
		Check, if this shape is selected.
	*/
	virtual bool IsSelected() const = 0;
	
	/**
		Inform that this object was selected or deselected.
		\param	selectFlag	if \c true - selection, else deselection.
	*/
	virtual void SetSelected(bool selectFlag = true) = 0;
};


} // namespace iview


#endif // !iview_IInteractiveShape_included


