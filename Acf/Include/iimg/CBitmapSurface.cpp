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


#include "iimg/CBitmapSurface.h"


// Qt includes
#include <QtCore/QVector>
#include <QtGui/QColor>


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iimg
{


CBitmapSurface::CBitmapSurface()
{
}


CBitmapSurface::CBitmapSurface(const CBitmapSurface& bitmap)
:	BaseClass(bitmap),
	BaseClass2()
{
}


// reimplemented (istd::IChangeable)

void CBitmapSurface::OnEndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	CreateSurfaceFromBitmap();

	BaseClass::OnEndChanges(changeFlags, changeParamsPtr);
	BaseClass2::OnEndChanges(changeFlags, changeParamsPtr);
}


// private methods

void CBitmapSurface::CreateSurfaceFromBitmap()
{
	if (GetQImageRef().isNull()){
		return;
	}

	BaseClass2::CreateGrid2d(GetImageSize());

	int componentBitsCount = GetComponentBitsCount();
	int pixelBitsCount = GetPixelBitsCount();
	int bufferIncrement = 	pixelBitsCount >> 3;

	for (int y = 0; y < GetImageSize().GetY(); y++){
		quint8* bufferPtr = (quint8*)GetLinePtr(y);

		for (int x = 0; x < GetImageSize().GetX(); x++){
			double functionValue = 0;
			if (componentBitsCount == 8){
				if (pixelBitsCount == 32){
					functionValue = qGray(*((int*)(bufferPtr)));
				}
				else if (pixelBitsCount == 8){
					functionValue = *bufferPtr;					
				}
			}

			ArgumentType index;
			index.SetAt(0, x);
			index.SetAt(1, y);
			BaseClass2::SetSampleValue(index, functionValue);

			bufferPtr += bufferIncrement;
		}
	}
}


} // namespace iimg


