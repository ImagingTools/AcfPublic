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


#ifndef iqt_CBitmapSurface_included
#define iqt_CBitmapSurface_included



#include "istd/TChangeDelegator.h"

#include "imath/CSampledFunction2d.h"

#include "iqt/CBitmap.h"


namespace iqt
{


/**
	Bitmap implementation based on Qt QImage.
*/
class CBitmapSurface: public iqt::CBitmap, public imath::CSampledFunction2d
{
public:
	typedef iqt::CBitmap BaseClass;
	typedef imath::CSampledFunction2d BaseClass2;

	CBitmapSurface();
	CBitmapSurface(const CBitmapSurface& bitmap);

	// reimplemented (istd::IChangeable)
	virtual void OnEndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr);

private:
	void CreateSurfaceFromBitmap();
};


} // namespace iqt


#endif //!iqt_CBitmapSurface_included


