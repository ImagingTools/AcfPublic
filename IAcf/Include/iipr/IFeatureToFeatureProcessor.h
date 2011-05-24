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


#ifndef iipr_IFeatureToFeatureProcessor_included
#define iipr_IFeatureToFeatureProcessor_included


#include "iproc/IProcessor.h"

#include "iipr/IFeaturesConsumer.h"
#include "iipr/IFeaturesContainer.h"


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
				const IFeaturesContainer& container,
				IFeaturesConsumer& results) = 0;
};


} // namespace iipr


#endif // !iipr_IFeatureToFeatureProcessor_included


