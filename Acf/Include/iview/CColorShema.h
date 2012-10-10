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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iview_CColorShema_included
#define iview_CColorShema_included


// Qt includes
#include <QtGui/QPainter>


// ACF includes
#include "iview/CColorShemaBase.h"


namespace iview
{


/**
	Implementation of the color shema object.
	This class extends class iview::CColorShemaBase with implementation of
	storage of pens, brushes and fonts.
*/
class CColorShema: public CColorShemaBase
{
public:
    enum
	{
		/**
			Standard size of pens set.
		*/
		NORMAL_SET_SIZE = 16,
	};

	CColorShema();

	// reimplemented IColorShema
    virtual const QFont& GetFont(IColorShema::StandardFont fontType) const;
    virtual void SetFont(iview::IColorShema::StandardFont fontType, const QFont& font);
	virtual const QPen& GetPen(IColorShema::StandardPen penType) const;
	virtual void SetPen(iview::IColorShema::StandardPen penType, const QPen& pen);
	virtual const QBrush& GetBrush(IColorShema::StandardBrush brushType) const;
	virtual void SetBrush(iview::IColorShema::StandardBrush brushType, const QBrush& brush);

private:
	QPen m_pens[int(IColorShema::SP_LAST) + 1];
	QBrush m_brushes[int(IColorShema::SB_LAST) + 1];
	QFont m_fonts[int(IColorShema::SF_LAST) + 1];
};



inline void CColorShema::SetPen(IColorShema::StandardPen penType, const QPen& pen)
{
	m_pens[penType] = pen;
}


inline void CColorShema::SetBrush(IColorShema::StandardBrush brushType, const QBrush& brush)
{
    m_brushes[brushType] = brush;
}


inline void CColorShema::SetFont(IColorShema::StandardFont fontType, const QFont& font)
{
    m_fonts[fontType] = font;
}


inline const QFont& CColorShema::GetFont(IColorShema::StandardFont fontType) const
{
    return m_fonts[fontType];
}


inline const QPen& CColorShema::GetPen(IColorShema::StandardPen penType) const
{
	return m_pens[penType];
}


inline const QBrush& CColorShema::GetBrush(IColorShema::StandardBrush brushType) const
{
	return m_brushes[brushType];
}


} // namespace iview


#endif // !iview_CColorShema_included


