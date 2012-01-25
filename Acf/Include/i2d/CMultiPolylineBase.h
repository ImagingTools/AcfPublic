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


#ifndef i2d_CMultiPolylineBase_included
#define i2d_CMultiPolylineBase_included


// STL includes
#include <algorithm>


// ACF includes
#include "istd/IPolymorphic.h"

#include "i2d/CLine2d.h"
#include "i2d/CPolyline.h"


namespace i2d
{


/**	Represent polyline and set of parallel lines.
 */
class CMultiPolylineBase: public CPolyline
{
public:
	typedef CPolyline BaseClass;

	/** Select or deselect all segments.
	*/
	virtual void SelectAllSegments(bool selected = true);
	/** Get maximal width.
	*/
	virtual double GetMaxParallel() const;

	// pure virtual methods
	/** Number of parallel pair of lines.
	*/
	virtual void SetParallelsCount(int count) = 0;
	/** Get number of parallel pair of lines.
	*/
	virtual int GetParallelsCount() const = 0;
	/** Set width of parallel lines.
	*/
	virtual void SetParallel(int segmentIndex, int parallelIndex, double width) = 0;
	/** Get width of parallel lines.
	*/
	virtual double GetParallel(int segmentIndex, int parallelIndex) const = 0;
	/** Get segment user data.
	*/
	virtual const iser::ISerializable& GetSegmentData(int segmentIndex) const = 0;
	/** Remove node and segment.
	*/
	virtual bool RemoveSegment(int node, int segment) = 0;
	/** Select and deselect segment.
	*/
	virtual void SelectSegment(int segmentIndex, bool selected = true) = 0;
	/** Test if segment is selected.
	*/
	virtual bool IsSegmentSelected(int segmentIndex) const = 0;
};


} // namespace i2d


#endif // !i2d_CMultiPolylineBase_included



