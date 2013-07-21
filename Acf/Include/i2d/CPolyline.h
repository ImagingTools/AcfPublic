/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef i2d_CPolyline_included
#define i2d_CPolyline_included


// ACF includes
#include "i2d/CLine2d.h"
#include "i2d/CPolygon.h"


namespace i2d
{


/**
	2D-object representing a polyline.
	A polyline is a connected series of line segments and is normally used to approximate curved paths.
*/
class CPolyline: public CPolygon
{
public:
	typedef CPolygon BaseClass;

	CPolyline();

	virtual bool IsClosed() const;

	/**
		Set polyline to be opened or closed.
	*/
	virtual void SetClosed(bool state = true);
	
	/**
		Return number of line segments.
	*/
	virtual int GetSegmentsCount() const;
	
	/**
		Return number of line segments.
	*/
	virtual i2d::CLine2d GetSegmentLine(int segmentIndex) const;
	
	/**
		Get length of this polyline.
	*/
	virtual double GetLength() const;
	
	/**
		Return vector for knee, that has the same angle to both neighbor segments.
	*/
	virtual i2d::CVector2d GetKneeVector(int nodeIndex) const;

	// reimplemented istd::IChangeable
	virtual int GetSupportedOperations() const;
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);
	virtual istd::IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const;

private:
	bool m_isClosed;
};


// public inline methods

inline CPolyline::CPolyline()
{
	m_isClosed = false;
}


inline bool CPolyline::IsClosed() const
{
	return m_isClosed;
}


} // namespace i2d


#endif // !i2d_CPolyline_included


