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


#include "i2d/CMultiPolylineBase.h"


namespace i2d
{


void CMultiPolylineBase::SelectAllSegments(bool selected)
{
	int segmentsCount = GetSegmentsCount();
	for(int i = 0; i < segmentsCount; i++){
		SelectSegment(i, selected);
	}
}


double CMultiPolylineBase::GetMaxParallel() const
{
	double maxWidth = 0;
	int parallelsCount = GetParallelsCount();

	if(parallelsCount > 0){
		int segmentsCount = GetSegmentsCount();

		for(int segmentIndex = 0; segmentIndex < segmentsCount; segmentIndex++){
			for (int parallelIndex = 0; parallelIndex < parallelsCount; ++parallelIndex){
				double width = GetParallel(segmentIndex, parallelIndex);
				if (width > maxWidth){
					maxWidth = width;
				}
			}
		}
	}

	return maxWidth;
}


} // namespace i2d

