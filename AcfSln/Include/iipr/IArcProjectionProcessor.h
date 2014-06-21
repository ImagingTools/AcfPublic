/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_IArcProjectionProcessor_included
#define iipr_IArcProjectionProcessor_included


#include "i2d/CArc.h"
#include "iproc/IProcessor.h"
#include "iimg/IBitmap.h"
#include "imeas/IDataSequence.h"


namespace iipr
{


class IProjectionParams;


class IArcProjectionProcessor: virtual public iproc::IProcessor
{
public:
	/**
		Do line projection with explicit projection parameters.
	*/
	virtual bool DoProjection(
				const iimg::IBitmap& bitmap,
                const i2d::CArc& projectionLine,
				const IProjectionParams* paramsPtr,
				imeas::IDataSequence& results) = 0;
};


} // namespace iipr


#endif // !iipr_IArcProjectionProcessor_included


