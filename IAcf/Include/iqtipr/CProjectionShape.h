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


#ifndef iqtipr_CProjectionShape_included
#define iqtipr_CProjectionShape_included


// Qt includes
#include <QGraphicsPathItem>

// ACF includes
#include "imod/CMultiModelObserverBase.h"

// ACF-Solutions includes
#include "imeas/IDataSequence.h"

#include "iqtipr/iqtipr.h"


namespace iqtipr
{


class CProjectionShape: public QGraphicsPathItem, public imod::CMultiModelObserverBase
{
public:
	typedef imod::CMultiModelObserverBase BaseClass;

	CProjectionShape();

	// reimplemented (imod::IObserver)
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

private:
	i2d::CLine2d m_projectionLine;
};


} // namespace iqtipr


#endif // !iqtipr_CProjectionShape_included


