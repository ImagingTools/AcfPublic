/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iipr_ILineProjectionProcessor_included
#define iipr_ILineProjectionProcessor_included


// ACF includes
#include <i2d/CLine2d.h>
#include <iimg/IBitmap.h>

// ACF-Solutions includes
#include <iproc/IProcessor.h>
#include <imeas/IDataSequence.h>


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


