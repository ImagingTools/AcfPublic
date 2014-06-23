/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iview_CLabelShape_included
#define iview_CLabelShape_included


#include "i2d/CLabel.h"

#include "iview/CPinShape.h"


namespace iview
{


class CLabelShape: public CPinShape
{
public:
	typedef CPinShape BaseClass;
	typedef CInteractiveShapeBase ShapeBaseClass;

	enum TextAlign
	{
		TAL_CENTER,
		TAL_LEFT_TOP,
		TAL_RIGHT_TOP,
		TAL_LEFT_BOTTOM,
		TAL_RIGHT_BOTTOM,
		TAL_AUTOMATIC,
		TAL_LAST = TAL_AUTOMATIC
	};

	CLabelShape(
				TextAlign align = TAL_RIGHT_TOP,
				const istd::CIndex2d& offset = istd::CIndex2d(20, -20));

	virtual TextAlign GetTextAlign() const;
	virtual void SetTextAlign(TextAlign align);
	virtual const istd::CIndex2d& GetDrawOffset() const;
	virtual void SetDrawOffset(const istd::CIndex2d& offset);

	virtual bool IsPositionVisible() const;
	virtual void SetPositionVisible(bool visible = true);
	virtual bool IsBackgroundTransparent() const;
	virtual void SetBackgroundTransparent(bool state = true);
	virtual bool IsEditableOffset() const;
	virtual void SetEditableOffset(bool editable = true);

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);
	virtual bool OnMouseMove(istd::CIndex2d position);

	// reimplemented (iview::IVisualizable)
	virtual void Draw(QPainter& drawContext) const;

	// reimplemented (imod::IObserver)
	virtual bool OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask);

	// reimplemented (iview::ITouchable)
	virtual TouchState IsTouched(istd::CIndex2d position) const;

protected:
	enum EditMode
	{
		EM_NONE,
		EM_POSITION,
		EM_OFFSET
	};

	void CalculateTextOriginSize(i2d::CRect& textBox) const;

	// reimplemented (iview::CInteractiveShapeBase)
	virtual i2d::CRect CalcBoundingBox() const;

private:
	istd::CIndex2d m_referenceOffset;
	TextAlign   m_textAlign;
	mutable istd::CIndex2d m_drawOffset;
	bool m_isPositionVisible;
	bool m_isBackgroundTransparent;
	bool m_isEditableOffset;
	EditMode m_editMode;

	bool m_isAlignFixed;
};


inline CLabelShape::TextAlign CLabelShape::GetTextAlign() const
{
	return m_textAlign;
}


inline void CLabelShape::SetTextAlign(CLabelShape::TextAlign align)
{
	m_textAlign = align;
}


inline const istd::CIndex2d& CLabelShape::GetDrawOffset() const
{
	return m_drawOffset;
}


inline void CLabelShape::SetDrawOffset(const istd::CIndex2d& offset)
{
	m_drawOffset = offset;
}


inline bool CLabelShape::IsPositionVisible() const
{
	return m_isPositionVisible;
}


inline void CLabelShape::SetPositionVisible(bool visible)
{
	m_isPositionVisible = visible;
}


inline bool CLabelShape::IsBackgroundTransparent() const
{
	return m_isBackgroundTransparent;
}


inline void CLabelShape::SetBackgroundTransparent(bool state)
{
	m_isBackgroundTransparent = state;
}


inline bool CLabelShape::IsEditableOffset() const
{
	return m_isEditableOffset;
}


inline void CLabelShape::SetEditableOffset(bool editable)
{
	m_isEditableOffset = editable;
}


} // namespace iview


#endif // !iview_CLabelShape_included


