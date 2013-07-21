/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef iview_ITouchable_included
#define iview_ITouchable_included


#include "istd/IPolymorphic.h"

#include "iview/iview.h"


namespace iview
{


/**
	This interface describes all untransparent GUI objects, which can be touched.
*/
class ITouchable: virtual public istd::IPolymorphic
{
public:

	/**
		Enumeration for possible shape touch states.
	*/
	enum TouchState
	{
		/**
			Nothing is touched.
		*/
		TS_NONE,
		
		/**
			Inactive element is touched.
		*/
		TS_INACTIVE,
		
		/**
			Ticker is touched.
		*/
		TS_TICKER,
		
		/**
			Draggable element is touched.
		*/
		TS_DRAGGABLE,
		
		/**
			Other element is touched.
		*/
		TS_OTHER,
		
		/**
			Last value in this enum.
		*/
		TS_LAST = TS_OTHER
	};

	/**
		Check, if any shape is touched.
		When shape is touched, it return also pointer to this shape.
		\return	touch state for the shape, or iview::IInteractiveShape::TS_NONE, when nothing found.
	*/
	virtual TouchState IsTouched(istd::CIndex2d position) const = 0;

	/**
		Get description to shape at specified position.
	*/
	virtual QString GetShapeDescriptionAt(istd::CIndex2d position) const = 0;
};


} // namespace iview


#endif // !iview_ITouchable_included


