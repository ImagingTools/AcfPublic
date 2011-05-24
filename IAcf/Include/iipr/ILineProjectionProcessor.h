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


#ifndef iipr_ILineProjectionProcessor_included
#define iipr_ILineProjectionProcessor_included


#include "i2d/CLine2d.h"

#include "iproc/IProcessor.h"

#include "iimg/IBitmap.h"

#include "imeas/IDataSequence.h"


namespace iipr
{


class IProjectionParams;


class ILineProjectionProcessor: virtual public iproc::IProcessor
{
public:
	/**
		Do line projection with explicite projection parameters.
	*/
	virtual bool DoProjection(
				const iimg::IBitmap& bitmap,
				const i2d::CLine2d& projectionLine,
				const IProjectionParams* paramsPtr,
				imeas::IDataSequence& results) = 0;
};


} // namespace iipr


#endif // !iipr_ILineProjectionProcessor_included


