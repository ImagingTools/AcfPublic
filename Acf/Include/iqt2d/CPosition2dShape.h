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


#ifndef iqt2d_CPosition2dShape_included
#define iqt2d_CPosition2dShape_included


#include "imod/TSingleModelObserverBase.h"

#include "i2d/CPosition2d.h"

#include "iqt2d/CGripShape.h"


namespace iqt2d
{


class CPosition2dShape:
			public CGripShape, 
			public imod::TSingleModelObserverBase<i2d::CPosition2d>
{
public:
	typedef CGripShape BaseClass;
	typedef imod::TSingleModelObserverBase<i2d::CPosition2d> BaseClass2;

	CPosition2dShape(bool isEditable = false, const ISceneProvider* providerPtr = NULL);

	// reimplemented (imod::IObserver)
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

protected:
	// reimplemented (CGripShape) 
	virtual void OnPositionChanged(const QPointF& position);

private:
	bool m_ignoreUpdate;
};


} // namespace iqt2d


#endif // !iqt2d_CPosition2dShape_included


