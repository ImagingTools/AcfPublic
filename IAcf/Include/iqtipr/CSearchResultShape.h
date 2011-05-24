/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iqtipr_CSearchResultShape_included
#define iqtipr_CSearchResultShape_included


// Qt includes
#include <QGraphicsItemGroup>

// ACF includes
#include "istd/TPointerVector.h"
#include "imod/TSingleModelObserverBase.h"
#include "i2d/CVector2d.h"

#include "iipr/IFeaturesContainer.h"


namespace iqtipr
{


class CSearchResultShape: 
			public QGraphicsItemGroup, 
			public imod::TSingleModelObserverBase<iipr::IFeaturesContainer>
{
public:
	// reimplemented (imod::IObserver)
	virtual void BeforeUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

private:
	class CModelPointShape: public QGraphicsEllipseItem
	{
	public:
		typedef QGraphicsEllipseItem BaseClass;

		CModelPointShape(
					const i2d::CVector2d& position,
					const i2d::CVector2d& size,
					QGraphicsItem* parentPtr = NULL,
					QGraphicsScene* scenePtr = NULL,
					double angle = 0);
	
	protected:
		// reimplemented (QGraphicsRectItem)
		virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

	private:
		double m_angle;
	};

	typedef istd::TPointerVector<QGraphicsItem> Items;

	Items m_items;
};


} // namespace iqtipr


#endif // !iqtipr_CSearchResultShape_included

