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


#pragma once

// ACF-Solutions includes
#include <iproc/TSyncProcessorCompBase.h>
#include <iipr/IImageToFeatureProcessor.h>


namespace iipr
{


/**
	Extracts NxN points grid from no distorted checkerboard
*/
class CCheckerboardPointGridExtractorComp : public iproc::TSyncProcessorCompBase<iipr::IImageToFeatureProcessor>
{
public:
	typedef iproc::TSyncProcessorCompBase<iipr::IImageToFeatureProcessor> BaseClass;

	I_BEGIN_COMPONENT(CCheckerboardPointGridExtractorComp);
		I_ASSIGN(m_resultConsumerCompPtr, "ResultConsumer", "Consumer of result messages with geometrical layout", false, "ResultConsumer");
		I_ASSIGN(m_lineFinderCompPtr, "LineFinder", "Finder of lines on image", true, "LineFinder");
	I_END_COMPONENT;

	// reimplemented (iipr::IImageToFeatureProcessor)
	virtual int DoExtractFeatures(
		const iprm::IParamsSet* paramsPtr,
		const iimg::IBitmap& image,
		IFeaturesConsumer& results,
		ibase::IProgressManager* progressManagerPtr = NULL)  override;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
		const iprm::IParamsSet* paramsPtr,
		const istd::IPolymorphic* inputPtr,
		istd::IChangeable* outputPtr,
		ibase::IProgressManager* progressManagerPtr = NULL) override;

protected:

private:
	I_REF(ilog::IMessageConsumer, m_resultConsumerCompPtr);
	I_REF(iipr::IImageToFeatureProcessor, m_lineFinderCompPtr);
};


} // namespace iipr


