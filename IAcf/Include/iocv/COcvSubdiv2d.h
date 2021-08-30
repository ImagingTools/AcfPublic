/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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


#ifndef iocv_COcvSubdiv2d_included
#define iocv_COcvSubdiv2d_included


// STL includes
#include <vector>

// OpenCV includes
#include <opencv2/opencv.hpp>


namespace iocv
{


class COcvSubdiv2d: public cv::Subdiv2D
{
public:
	struct Triangle
	{
		Triangle()
			:a(-1),
			b(-1),
			c(-1)
		{
		}
	
		int a;
		int b;
		int c;
	};

	void GetTrianglesIndices(std::vector<Triangle>& triangleList) const;
};


} // namespace iocv


#endif // !iocv_COcvSubdiv2d_included


