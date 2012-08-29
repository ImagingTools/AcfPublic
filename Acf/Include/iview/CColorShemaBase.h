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


#ifndef iview_CColorShemaBase_included
#define iview_CColorShemaBase_included


// Qt includes
#include <QtGui/QPainter>


// ACF includes
#include "iview/IColorShema.h"


namespace iview
{


class CColorShemaBase: public IColorShema
{
public:
    enum
	{
		TICKER_SIZE = 4,
		SMALL_TICKER_SIZE = 2,
		LOGICAL_LINE_WIDTH = 4
	};

	// reimplemented (IColorShema)
	virtual void Assign(const IColorShema& colorShema);
	virtual void DrawTicker(QPainter& drawContext, istd::CIndex2d point, IColorShema::TickerType tickerType) const;
	virtual const i2d::CRect& GetTickerBox(IColorShema::TickerType tickerType) const;
	virtual int GetLogicalLineWidth() const;

protected:
     // static attributes
	static i2d::CRect s_tickersBoxes[(int)TT_LAST + (int)1];
};


inline int CColorShemaBase::GetLogicalLineWidth() const
{
	return LOGICAL_LINE_WIDTH;
}


} // namespace iview


#endif // !iview_CColorShemaBase_included



