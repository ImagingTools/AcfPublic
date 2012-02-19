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


#ifndef iview_ILogicalView_included
#define iview_ILogicalView_included



#include "iview/IShapeView.h"
#include "iview/ILogicalCoords.h"



namespace iview{



/**	Comon interface for all views with logical transform support.
*/
class  ILogicalView: public IShapeView, public ILogicalCoords
{
public:
	/**	Set logical to view units transformation.
	*/
	virtual void SetLogToViewTransform(const i2d::CAffine2d& transform) = 0;
};



} // namespace iview



#endif // !iview_ILogicalView_included



