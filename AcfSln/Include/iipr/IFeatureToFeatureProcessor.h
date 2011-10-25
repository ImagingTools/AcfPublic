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


#ifndef iipr_IFeatureToFeatureProcessor_included
#define iipr_IFeatureToFeatureProcessor_included


#include "iproc/IProcessor.h"

#include "iipr/IFeaturesConsumer.h"
#include "iipr/IFeaturesProvider.h"


namespace iipr
{


/**
	Allow to extract some features from another one.
*/
class IFeatureToFeatureProcessor: virtual public iproc::IProcessor
{
public:
	/**
		Specialization of processing interface for extraction of features from image.
		\return				state of this processor \sa iproc::IProcessor::ProcessorState.
	*/
	virtual int DoConvertFeatures(
				const iprm::IParamsSet* paramsPtr,
				const IFeaturesProvider& container,
				IFeaturesConsumer& results) = 0;
};


} // namespace iipr


#endif // !iipr_IFeatureToFeatureProcessor_included


