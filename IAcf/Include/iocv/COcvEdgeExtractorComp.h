/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// ACF includes
#include <iproc/TSyncProcessorCompBase.h>
#include <iedge/IEdgesExtractor.h>


namespace iocv
{


class COcvEdgeExtractorComp: public iproc::TSyncProcessorCompBase<iedge::IEdgesExtractor>
{
public:
	typedef iproc::TSyncProcessorCompBase<iedge::IEdgesExtractor> BaseClass;

	I_BEGIN_COMPONENT(COcvEdgeExtractorComp);
		I_ASSIGN(m_aoiParamIdAttrPtr, "AoiParamId", "ID of area of interest in parameter set", false, "AoiParams");
		I_ASSIGN(m_defaultAoiCompPtr, "DefaultAoi", "Area of interest used if not specified in parameters", false, "DefaultAoi");
	I_END_COMPONENT;

public:
	//	reimplemented (iedge::IEdgesExtractor)
	virtual bool DoContourExtraction(
				const iprm::IParamsSet* paramsPtr,
				const iimg::IBitmap& bitmap,
				iedge::CEdgeLineContainer& result) const;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

private:
	I_ATTR(QByteArray, m_aoiParamIdAttrPtr);
	I_REF(i2d::IObject2d, m_defaultAoiCompPtr);
};


} // namespace iocv


