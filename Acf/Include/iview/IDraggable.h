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


#ifndef iview_IMoveable_included
#define iview_IMoveable_included


#include <istd/IPolymorphic.h>

#include <i2d/CVector2d.h>


namespace iview
{


/**
	Common interface for all, you can drag.
*/
class IDraggable: virtual public istd::IPolymorphic
{
public:
	/** 
		Called before dragging is begin.
		It set also reference value for dragging position.
	*/
	virtual void BeginDrag(const istd::CIndex2d& reference) = 0;

	/**
		Set new drag position.
		It must be enclosed using BeginDrag() and EndDrag() methods.
	*/
	virtual void SetDragPosition(const istd::CIndex2d& position) = 0;
	
	/**
		Called after dragging.
	*/
	virtual void EndDrag() = 0;
	
	/**
		Check if drag is enabled.
	*/
	virtual bool IsDraggable() const = 0;
};


} // namespace iview


#endif // !iview_IMoveable_included


