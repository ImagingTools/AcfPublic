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


#ifndef iimg_CBitmapSurface_included
#define iimg_CBitmapSurface_included



#include "istd/TChangeDelegator.h"

#include "imath/CSampledFunction2d.h"

#include "iimg/CBitmap.h"


namespace iimg
{


/**
	Union of a bitmap objects and its samples represented as a 2D sampled function.
*/
class CBitmapSurface: public iimg::CBitmap, public imath::CSampledFunction2d
{
public:
	typedef iimg::CBitmap BaseClass;
	typedef imath::CSampledFunction2d BaseClass2;

	CBitmapSurface();
	CBitmapSurface(const CBitmapSurface& bitmap);

	// reimplemented (istd::IChangeable)
	virtual void OnEndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr);

private:
	void CreateSurfaceFromBitmap();
};


} // namespace iimg


#endif //!iimg_CBitmapSurface_included


