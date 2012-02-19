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


#ifndef INCLUEDED__qqt_CDrawBuffer_included
#define INCLUEDED__qqt_CDrawBuffer_included


// Qt includes
#include <QPixmap>
#include <QPainter>


// ACF includes
#include "istd/TDelPtr.h"

#include "iqt/iqt.h"


namespace iview
{


class CDrawBuffer: public QPixmap
{
public:
	typedef QPixmap BaseClass;

	CDrawBuffer();

	/**
		Reset state of this bitmap.
	*/
	void Reset();
	
	/**
		Check, if bitmap was created.
	*/
	bool IsCreated() const;

	/**
		Create new buffer with the given size.
	*/
	void Create(const QPaintDevice& device, ibase::CSize size);

	/**
		Copy rectangle area to specified draw context.
		It is used for native-compatible template implementation in iview::TViewImpl.
	*/
	void CopyRectTo(const i2d::CRect& source, QPainter& drawContext, istd::CIndex2d contextPos) const;
	
	/**
		Copy rectangle area to specified native paint device.
		It is used for native-compatible template implementation in iview::TViewImpl.
	*/
	void CopyRectTo(const i2d::CRect& source, QPaintDevice& device, istd::CIndex2d devicePos) const;

	/**
		Get used painter for drawing operations.
	*/
	QPainter& GetDrawContext();

protected:
	void EnsureDrawContext();

private:
	mutable istd::TDelPtr<QPainter> m_drawContextPtr;
};


// inline methods

inline CDrawBuffer::CDrawBuffer()
{
}


inline QPainter& CDrawBuffer::GetDrawContext()
{
	EnsureDrawContext();

	I_ASSERT(m_drawContextPtr.IsValid());

	return *m_drawContextPtr;
}


} // namespace iview


#endif // !_qqt_CDrawBuffer_included

