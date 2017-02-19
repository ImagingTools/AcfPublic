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


#ifndef iview_IMouseActionObserver_included
#define iview_IMouseActionObserver_included


// Qt includes
#include <qnamespace.h>


// ACF includes
#include <istd/IPolymorphic.h>

#include <iview/iview.h>


namespace iview
{


/**
	Common interface for all shapes which are mouse events receiver.
*/
class IMouseActionObserver: virtual public istd::IPolymorphic
{
public:
	/**
		It is called, when mouse button is pushed down or up on this object.
		\param	position	-	position of mouse pointer on client area (picture coords).
		\param	downFlag	-	true, if mouse button is pushed down, false if pushed up.
	 *		\return	true	if this shape should get focus to catch all mouse movements.
	*/
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag) = 0;

	/**
		It is called, when mouse is moved.
		Only objects with focus receive this event.
		\param	position	-	position of mouse pointer on client area (picture coords).
		\return	true	if this shape should hold focus to catch longer all mouse movements.
	*/
	virtual bool OnMouseMove(istd::CIndex2d position) = 0;
};


} // namespace iview


#endif // !iview_IMouseActionObserver_included


