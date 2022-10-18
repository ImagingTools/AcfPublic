/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef i2d_CSpline_included
#define i2d_CSpline_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include <i2d/CPolyline.h>
#include <i2d/CSplineSegment.h>


// forward declarations
namespace i2d{
	class CSpline;
} // namespace i2d


namespace i2d
{


class CSpline: public i2d::CPolyline
{
public:
	typedef i2d::CPolyline BaseClass;

	CSpline();

	/**
		Get count of segments.
	 */
	virtual int GetSegmentCount() const;
	
	/**	
		Get segment in polynomial.
		\param	index	Index of segment.
	 */
	virtual const CSplineSegment& GetSplineSegment(int index) const;

	/**
		Insert a segment at the end of spline segment table.
	*/
	virtual bool InsertSplineSegment(const CSplineSegment& segment);

	// reimplemented (istd::IChangeable)
	virtual int GetSupportedOperations() const;
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);
	virtual istd::IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const;

protected:
	void CalcAllSegments() const;
	
private:
	static void SolveOpen(double* d,int count);

	mutable QVector<CSplineSegment> m_segments;
	mutable bool m_isInvalidated;
};


} // namespace i2d


#endif // !i2d_CSpline_included

