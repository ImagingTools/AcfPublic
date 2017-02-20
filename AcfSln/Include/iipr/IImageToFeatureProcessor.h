/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_IImageToFeatureProcessor_included
#define iipr_IImageToFeatureProcessor_included


// ACF includes
#include <iimg/IBitmap.h>
#include <iprm/IParamsSet.h>
#include <iproc/IProcessor.h>

#include <iipr/IFeaturesConsumer.h>


namespace iipr
{


/**
	Allow to extract some features from the image.
*/
class IImageToFeatureProcessor: virtual public iproc::IProcessor
{
public:
	/**
		Specialization of processing interface for extraction of features from image.
		\return				state of this processor task \sa iproc::IProcessor::TaskState.
	*/
	virtual int DoExtractFeatures(
				const iprm::IParamsSet* paramsPtr,
				const iimg::IBitmap& image,
				IFeaturesConsumer& results,
				ibase::IProgressManager* progressManagerPtr = NULL) = 0;
};


} // namespace iipr


#endif // !iipr_IImageToFeatureProcessor_included


