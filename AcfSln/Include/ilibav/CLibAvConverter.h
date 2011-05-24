/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef ilibav_CLibAvConverter_included
#define ilibav_CLibAvConverter_included


// LIBAV includes
extern "C"{
#include "libavformat/avformat.h"
}

// ACF includes
#include "istd/CIndex2d.h"
#include "iimg/IBitmap.h"


namespace ilibav
{


/**
	Helper class containing static methods to convert between AvLib and ACF classes.
*/
class CLibAvConverter
{
public:
	static bool ConvertBitmap(const AVFrame& avFrame, const istd::CIndex2d& size, PixelFormat frameFormat, iimg::IBitmap& result);

protected:
	struct Rgba{
		I_BYTE r;
		I_BYTE g;
		I_BYTE b;
		I_BYTE a;
	};
};


} // namespace ilibav


#endif // !ilibav_CLibAvConverter_included


