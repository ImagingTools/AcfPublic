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


#include "iview/CSingleLayer.h"



// Qt includes
#include <QtGui/QPainter>


// ACF includes
#include "iqt/iqt.h"



#include "iview/IShape.h"
#include "iview/IShapeView.h"


namespace iview
{


CSingleLayer::CSingleLayer()
:	m_shapePtr(NULL)
{
}


CSingleLayer::~CSingleLayer()
{
	DisconnectAllShapes();
}


// reimplemented (iview::ILayer)

i2d::CRect CSingleLayer::GetBoundingBox() const
{
	if (m_shapePtr != NULL){
		return m_boundingBox;
	}

	return i2d::CRect::GetEmpty();
}


void CSingleLayer::ConnectShape(IShape* shapePtr)
{
	I_ASSERT(m_shapePtr == NULL);

	shapePtr->OnConnectDisplay(this);
	shapePtr->OnDisplayChange(CF_ALL);

	m_shapePtr = shapePtr;
	m_boundingBox = shapePtr->GetBoundingBox();

	OnAreaInvalidated(i2d::CRect::GetEmpty(), m_boundingBox);
}


int CSingleLayer::GetShapesCount() const
{
	return m_shapePtr != NULL ? 1 : 0;
}


void CSingleLayer::UpdateAllShapes(int changeFlag)
{
	if (m_shapePtr != NULL){
		if (m_shapePtr->OnDisplayChange(changeFlag)){
			m_boundingBox = m_shapePtr->GetBoundingBox();
		}
	}
}


void CSingleLayer::DisconnectAllShapes()
{
	if (m_shapePtr != NULL){
		i2d::CRect oldBoundingBox = m_boundingBox;
		m_boundingBox.Reset();

		OnAreaInvalidated(oldBoundingBox, i2d::CRect::GetEmpty());

		m_shapePtr->OnDisconnectDisplay(this);

		m_shapePtr = NULL;
	}
}


void CSingleLayer::DrawShapes(QPainter& drawContext)
{
	if (IsVisible() && (m_shapePtr != NULL) && m_shapePtr->IsVisible()){
		i2d::CRect updateRect = iqt::GetCRect(drawContext.clipRegion().boundingRect());

		if (!updateRect.IsOutside(m_boundingBox)){
			m_shapePtr->Draw(drawContext);
		}
	}
}


// reimplemented (iview::IShapeObserver)

void CSingleLayer::OnChangeShape(IShape* I_IF_DEBUG(shapePtr))
{
	I_ASSERT(shapePtr != NULL);
	I_ASSERT(m_shapePtr == shapePtr);

	i2d::CRect oldBoundingBox = m_boundingBox;
	m_boundingBox = m_shapePtr->GetBoundingBox();

	OnAreaInvalidated(oldBoundingBox, m_boundingBox);
}


void CSingleLayer::DisconnectShape(IShape* shapePtr)
{
	I_ASSERT(shapePtr != NULL);

	if (m_shapePtr == shapePtr){
		i2d::CRect oldBoundingBox = m_boundingBox;
		m_boundingBox.Reset();

		shapePtr->OnDisconnectDisplay(this);
		m_shapePtr = NULL;

		OnAreaInvalidated(oldBoundingBox, m_boundingBox);
	}
}


} // namespace iview



