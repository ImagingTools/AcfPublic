/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iqtipr/CSearchResultShape.h"


// Qt includes
#include <QStyleOptionGraphicsItem>
#include <QPainter>

#include "iipr/CSearchFeature.h"


namespace iqtipr
{


// public methods

// reimplemented (imod::IObserver)

void CSearchResultShape::BeforeUpdate(imod::IModel* /*modelPtr*/, int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	for (int itemIndex = 0; itemIndex < m_items.GetCount(); itemIndex++){
		removeFromGroup(m_items.GetAt(itemIndex));
	}

	m_items.Reset();
}


void CSearchResultShape::AfterUpdate(imod::IModel* /*modelPtr*/, int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	const iipr::IFeaturesProvider* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		iipr::IFeaturesProvider::Features features = objectPtr->GetFeatures();

		for (int featureIndex = 0; featureIndex < int(features.size()); featureIndex++){
			const iipr::IFeature* featurePtr = features[featureIndex];
			I_ASSERT(featurePtr != NULL);

			double angle = 0;

			const iipr::CSearchFeature* searchFeaturePtr = dynamic_cast<const iipr::CSearchFeature*>(featurePtr);
			if (searchFeaturePtr != NULL){
				angle = searchFeaturePtr->GetAngle();

				CModelPointShape* itemPtr = new CModelPointShape(
							searchFeaturePtr->GetPosition(),
							i2d::CVector2d(25, 25),
							NULL, NULL, angle);
				itemPtr->setPen(QPen(Qt::yellow));
				addToGroup(itemPtr);

				m_items.PushBack(itemPtr);
			}
		}
	}

	update();
}


// public methods

CSearchResultShape::CModelPointShape::CModelPointShape(
			const i2d::CVector2d& position,
			const i2d::CVector2d& size,
			QGraphicsItem* parentPtr,
			QGraphicsScene* scenePtr,
			double angle)
:	BaseClass(position.GetX(), position.GetY(), size.GetX(), size.GetY(), parentPtr, scenePtr),
	m_angle(angle)
{
}


// protected methods

// reimplemented (QGraphicsRectItem)

void CSearchResultShape::CModelPointShape::paint(QPainter* p, const QStyleOptionGraphicsItem* option, QWidget* widgetPtr)
{
	BaseClass::paint(p, option, widgetPtr);
	
	double radius = rect().width() / 2.0;
	double x = pos().x();
	double y = pos().y();

	p->rotate(m_angle);

	p->drawLine(QPointF(x - radius, y), QPointF(x + radius, y));
	p->drawLine(QPointF(x, y - radius), QPointF(x, y - radius));
}


} // namespace iqtipr

