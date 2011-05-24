/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt2d_CGripShape_included
#define iqt2d_CGripShape_included


#include "iqt2d/TShapeBase.h"


namespace iqt2d
{


class CGripShape: public TShapeBase<QGraphicsEllipseItem>
{
	Q_OBJECT

public:
	enum LabelPosition
	{
		LabelLeft,
		LabelRight,
		LabelTop,
		LabelBottom
	};


	typedef TShapeBase<QGraphicsEllipseItem> BaseClass;

	CGripShape(QGraphicsItem* parentPtr = NULL, const ISceneProvider* providerPtr = NULL);

	i2d::CVector2d GetPosition() const;
	void SetPosition(const i2d::CVector2d& position);

	/**
		Set label position relative to the grip point.
		\sa LabelPosition
	*/
	void SetLabelPosition(int labelArea);

signals:
	void PositionChanged(const i2d::CVector2d& position);

protected:
	// reimplemented (TShapeBase<QGraphicsEllipseItem>)
	virtual void OnPositionChanged(const QPointF& position);
	virtual void OnSelectionChanged(bool isSelected);

private:
	QGraphicsSimpleTextItem m_labelItem;
};


} // namespace iqt2d


#endif // !iqt2d_CGripShape_included


