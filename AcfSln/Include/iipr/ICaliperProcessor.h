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


#ifndef iipr_ICaliperProcessor_included
#define iipr_ICaliperProcessor_included


// ACF includes
#include "iproc/IProcessor.h"

// ACF-Solutions includes
#include "imeas/IDataSequence.h"

#include "iipr/IFeaturesConsumer.h"


namespace iipr
{


class ICaliperParams;


class ICaliperProcessor: virtual public iproc::IProcessor
{
public:
	enum FeatureTypeId
	{
		/**
			Unique ID of the caliper feature.
		*/
		FTI_CALIPER_FEATURE = 6572
	};

	virtual bool DoCaliper(
				const imeas::IDataSequence& derivative,
				const ICaliperParams* paramsPtr,
				IFeaturesConsumer& results) = 0;
};


} // namespace iipr


#endif // !iipr_ICaliperProcessor_included


