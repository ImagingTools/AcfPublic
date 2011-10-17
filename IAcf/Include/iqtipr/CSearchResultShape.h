/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
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

#include "iipr/IFeaturesProvider.h"


namespace iqtipr
{


class CSearchResultShape: 
			public QGraphicsItemGroup, 
			public imod::TSingleModelObserverBase<iipr::IFeaturesProvider>
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

