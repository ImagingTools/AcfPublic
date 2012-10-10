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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iview_ILogicalCoords_included
#define iview_ILogicalCoords_included


#include "iview/CScreenTransform.h"

#include "iview/iview.h"


namespace iview
{


class ILogicalCoords: virtual public istd::IPolymorphic
{
public:
	/**
		Get logical units to view transformation.
		This transformation converts logical units to view coordinate system.
		Please note, that it is only affine transformation, not a calibration.
		You can use it as a calibration only, when linear transformation is enough.
		To get transformation to convert logical units to screen pixel, use GetLogToScreenTransform().
	*/
	virtual const i2d::CAffine2d& GetLogToViewTransform() const = 0;
	
	/**
		Get a direct transformation from logical units to screen pixels.
	*/
	virtual const iview::CScreenTransform& GetLogToScreenTransform() const = 0;
};


} // namespace iview


#endif // !iview_ILogicalCoords_included



