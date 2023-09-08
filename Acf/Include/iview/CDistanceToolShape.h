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


#pragma once


// ACF includes
#include <iview/CShapeBase.h>
#include <iview/IInteractiveShape.h>


namespace iview
{


class CDistanceToolShape:
			public CShapeBase,
			virtual public iview::IInteractiveShape
{
public:
	typedef CShapeBase BaseClass;

	CDistanceToolShape();

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);
	virtual bool OnMouseMove(istd::CIndex2d position);

	// reimplemented (iview::IInteractiveShape)
	virtual bool IsSelected() const;
	virtual void SetSelected(bool selectFlag = true);

	// reimplemented (imod::IObserver)
	virtual bool OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask);

	// reimplemented (iview::ITouchable)
	virtual TouchState IsTouched(istd::CIndex2d position) const;

protected:
	const i2d::ICalibration2d* GetCalibration() const;

	virtual void DrawLabel(QPainter& drawContext) const;

	// reimplemented (iview::IVisualizable)
	virtual void Draw(QPainter& drawContext) const;

	// reimplemented (iview::CShapeBase)
	virtual i2d::CRect CalcBoundingBox() const;

private:
	enum MeasureState
	{
		MS_NONE = 0,
		MS_START,
		MS_DONE
	};

	bool IsDistanceMeasureToolActive() const;
	void BeginDrag();
	void EndDrag();

private:
	istd::CIndex2d m_screenPos;
	MeasureState m_measureState;
	int m_dragNodeIndex;
	bool m_isSelected;
};


} // namespace iview

