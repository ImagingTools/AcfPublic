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


#ifndef iview_IVisualisable_included
#define iview_IVisualisable_included


#include "istd/IPolymorphic.h"

#include "iview/iview.h"


class QPainter;


namespace iview
{


class IDisplay;


class IVisualizable: virtual public istd::IPolymorphic
{
public:
	/**
		Check, if this object is visible.
	*/
	virtual bool IsVisible() const = 0;
	
	/**
		Check if this object can be connected to this display.
	*/
	virtual bool IsDisplayAccepted(const IDisplay& display) const = 0;
	
	/**
		Called after display is connected.
		It can be called only, when display is accepted (\sa IsDisplayAccepted()).
		\param	displayPtr	an observer object, which should be informed about all shape changes.
	*/
	virtual void OnConnectDisplay(IDisplay* displayPtr) = 0;
	
	/**
		Called after display is disconnected.
		Note, that this display must be previously connected.
		\param	displayPtr	a disconnected observer object.
	*/
	virtual void OnDisconnectDisplay(IDisplay* displayPtr) = 0;
	
	/**	
		Draw this shape using draw context.
	*/
	virtual void Draw(QPainter& drawContext) const = 0;

	/**
		It informs about changes in display.
		It is called e.g. after view transformation change.
		\return	true, if this change follow shape changes.
	*/
	virtual bool OnDisplayChange(int flags) = 0;
};


} // namespace iview


#endif // !iview_IVisualisable_included


