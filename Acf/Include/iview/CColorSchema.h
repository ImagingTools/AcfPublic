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


#ifndef iview_CColorSchema_included
#define iview_CColorSchema_included


// Qt includes
#include <QtGui/QPainter>


// ACF includes
#include "iview/CColorSchemaBase.h"


namespace iview
{


/**
	Implementation of the color schema object.
	This class extends class iview::CColorSchemaBase with implementation of
	storage of pens, brushes and fonts.
*/
class CColorSchema: public CColorSchemaBase
{
public:
	enum
	{
		/**
			Standard size of pens set.
		*/
		NORMAL_SET_SIZE = 16,
	};

	CColorSchema();

	// reimplemented IColorSchema
	virtual const QFont& GetFont(IColorSchema::StandardFont fontType) const;
	virtual void SetFont(iview::IColorSchema::StandardFont fontType, const QFont& font);
	virtual const QPen& GetPen(IColorSchema::StandardPen penType) const;
	virtual void SetPen(iview::IColorSchema::StandardPen penType, const QPen& pen);
	virtual const QBrush& GetBrush(IColorSchema::StandardBrush brushType) const;
	virtual void SetBrush(iview::IColorSchema::StandardBrush brushType, const QBrush& brush);

private:
	QPen m_pens[int(IColorSchema::SP_LAST) + 1];
	QBrush m_brushes[int(IColorSchema::SB_LAST) + 1];
	QFont m_fonts[int(IColorSchema::SF_LAST) + 1];
};



inline void CColorSchema::SetPen(IColorSchema::StandardPen penType, const QPen& pen)
{
	m_pens[penType] = pen;
}


inline void CColorSchema::SetBrush(IColorSchema::StandardBrush brushType, const QBrush& brush)
{
	m_brushes[brushType] = brush;
}


inline void CColorSchema::SetFont(IColorSchema::StandardFont fontType, const QFont& font)
{
	m_fonts[fontType] = font;
}


inline const QFont& CColorSchema::GetFont(IColorSchema::StandardFont fontType) const
{
	return m_fonts[fontType];
}


inline const QPen& CColorSchema::GetPen(IColorSchema::StandardPen penType) const
{
	return m_pens[penType];
}


inline const QBrush& CColorSchema::GetBrush(IColorSchema::StandardBrush brushType) const
{
	return m_brushes[brushType];
}


} // namespace iview


#endif // !iview_CColorSchema_included


