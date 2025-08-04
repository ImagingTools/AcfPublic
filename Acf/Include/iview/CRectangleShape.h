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


#ifndef iview_CRectangleShape_included
#define iview_CRectangleShape_included


#include <iview/CInteractiveShapeBase.h>


namespace iview
{


/**
	Interactive shape object for iview::CSearchArea.
*/
class CRectangleShape: public CInteractiveShapeBase
{
public:
	typedef CInteractiveShapeBase BaseClass;

	CRectangleShape();

	// reimplemented (iview::CInteractiveShapeBase)
	virtual void InvalidateBoundingBox() override;

	// reimplemented (iview::ITouchable)
	virtual TouchState IsTouched(istd::CIndex2d position) const override;

	// reimplemented (iview::IVisualizable)
	virtual void Draw(QPainter& drawContext) const override;

	// reimplemented (imod::IObserver)
	virtual bool OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask) override;

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag) override;
	virtual bool OnMouseMove(istd::CIndex2d position) override;

protected:
	void CalcPoints(const i2d::CRectangle& rectangle) const;

	// reimplemented (iview::CInteractiveShapeBase)
	virtual void BeginLogDrag(const i2d::CVector2d& reference) override;
	virtual void SetLogDragPosition(const i2d::CVector2d& position) override;

	// reimplemented (iview::CInteractiveShapeBase)
	virtual i2d::CRect CalcBoundingBox() const override;

	enum EditNode
	{
		EN_NONE = -1,
		EN_CORNER_FIRST = 0,
		EN_CORNER11 = EN_CORNER_FIRST,
		EN_CORNER12 = 1,
		EN_CORNER21 = 2,
		EN_CORNER22 = 3,
		EN_LAST = EN_CORNER22
	};

	i2d::CVector2d m_referencePosition;
	EditNode m_editNode;

	mutable i2d::CVector2d m_corners[4];
	mutable i2d::CVector2d m_ctrlsLeft[4];
	mutable i2d::CVector2d m_ctrlsRight[4];
	mutable bool m_arePointsValid;
};


} // namespace iview


#endif //iview_CRectangleShape_included


