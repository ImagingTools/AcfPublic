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


#ifndef TCalibratedViewBase_included
#define TCalibratedViewBase_included


#include "iview/TFramedViewBase.h"


namespace iview
{


template <class ViewBase>
class TCalibratedViewBase: public iview::TFramedViewBase<ViewBase>
{
public:
	typedef iview::TFramedViewBase<ViewBase> BaseClass;

	TCalibratedViewBase(Frame* framePtr)
		:BaseClass(framePtr)
	{
	}
	template <typename ConstructorParam>
	TCalibratedViewBase(Frame* framePtr, ConstructorParam* param)
		:BaseClass(framePtr, param)
	{
	}

	// reimplemented (iview::CCalibratedViewBase)
	virtual void ConnectCalibrationShape(iview::IShape* shapePtr);
};


// public methods

template <class ViewBase>
void TCalibratedViewBase<ViewBase>::ConnectCalibrationShape(iview::IShape* shapePtr)
{
	BaseClass::ConnectCalibrationShape(shapePtr);

	Frame* framePtr = GetFramePtr();
	if (framePtr != NULL){
		framePtr->UpdateButtonsState();
	}
}


} // namespace iview


#endif // !TCalibratedViewBase_included


