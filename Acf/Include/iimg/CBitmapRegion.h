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


#ifndef iimg_CBitmapRegion_included
#define iimg_CBitmapRegion_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include "i2d/CRectangle.h"
#include "i2d/CCircle.h"
#include "i2d/CAnnulus.h"

#include "iimg/IBitmap.h"


namespace iimg
{


/**
	Representation of a 2D-region as container of bitmap line scans.
*/
class CBitmapRegion: virtual public istd::IPolymorphic
{
public:
	struct PixelRange
	{
		PixelRange()
		:	pixelBufferPtr(NULL)
		{
		}

		istd::CRange range;
		const void* pixelBufferPtr;
	};

	typedef QVector<PixelRange> PixelRanges;

	CBitmapRegion(const IBitmap* bitmapPtr = NULL);

	/**
		Create 2D-region from the geometrical object.
	*/
	bool CreateFromGeometry(const i2d::IObject2d& geometry);

	/**
		Get the list of pixel ranges per given line.
	*/
	const PixelRanges* GetPixelRanges(int lineIndex) const;

	const i2d::CRectangle& GetBoundingBox() const;
	void ResetBitmapRegion();
	bool IsBitmapRegionEmpty() const;

	const IBitmap* GetBitmapPtr() const;

private:
	void CalculateRegionBoundingBox(const i2d::CRectangle& objectBoundingBox);
	void CreateFromCircle(const i2d::CCircle& circle);
	void CreateFromRectangle(const i2d::CRectangle& rect);
	void CreateFromAnnulus(const i2d::CAnnulus& annulus);

private:
	const IBitmap* m_bitmapPtr;
	QVector<PixelRanges> m_rangesContainer;
	QVector<const PixelRanges*> m_lineRangePtr;
	i2d::CRectangle m_boundingBox;
	bool m_isEmpty;
};


// public inline methods

inline const IBitmap* CBitmapRegion::GetBitmapPtr() const
{
	return m_bitmapPtr;
}


} // namespace iimg


#endif // !iimg_CBitmapRegion_included



