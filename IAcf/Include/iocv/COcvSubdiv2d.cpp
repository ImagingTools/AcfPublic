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


#include <iocv/COcvSubdiv2d.h>


namespace iocv
{


// public methods

void COcvSubdiv2d::GetTrianglesIndices(std::vector<Triangle>& triangleList) const
{
	triangleList.clear();

	int total = (int)(qedges.size() * 4);
	std::vector<bool> edgemask(total, false);

	for (int i = 4; i < total; i += 2){
		if (edgemask[i]){
			continue;
		}

		cv::Point2f a, b, c;
		int edge_a = i;

		int indexA = edgeOrg(edge_a, &a) - 4;
		int edge_b = getEdge(edge_a, NEXT_AROUND_LEFT);

		int indexB = edgeOrg(edge_b, &b) - 4;
		int edge_c = getEdge(edge_b, NEXT_AROUND_LEFT);

		int indexC = edgeOrg(edge_c, &c) - 4;

		edgemask[edge_a] = true;
		edgemask[edge_b] = true;
		edgemask[edge_c] = true;

		Triangle t;
		t.a = indexA;
		t.b = indexB;
		t.c = indexC;

		triangleList.push_back(t);
	}
}


} // namespace iocv


