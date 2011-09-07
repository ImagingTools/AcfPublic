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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt2d/CPosition2dShape.h"


// Qt includes
#include <QPen>
#include <QBrush>


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iqt2d
{


// public methods

CPosition2dShape::CPosition2dShape(bool isEditable, const ISceneProvider* providerPtr)
:	BaseClass(this, providerPtr),
	m_ignoreUpdate(false)
{
	SetEditable(isEditable);
}


// reimplemented (imod::IObserver)

void CPosition2dShape::AfterUpdate(imod::IModel* /*modelPtr*/, int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	i2d::CPosition2d* positionPtr = GetObjectPtr();
	if ((positionPtr != NULL) && !m_ignoreUpdate){
		setPos((iqt::GetQPointF(positionPtr->GetCenter())));
	}
}


// protected methods

// reimplemented (CGripShape) 

void CPosition2dShape::OnPositionChanged(const QPointF& position)
{
	i2d::CPosition2d* positionPtr = GetObjectPtr();
	if ((positionPtr != NULL) && !m_ignoreUpdate){
		m_ignoreUpdate = true;

		positionPtr->SetPosition(iqt::GetCVector2d(position));

		m_ignoreUpdate = false;
	}
}


} // namespace iqt2d


