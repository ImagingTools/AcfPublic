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


#ifndef iipr_CArcProjectionProcessorComp_included
#define iipr_CArcProjectionProcessorComp_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include "icomp/CComponentBase.h"
#include "iimg/IBitmap.h"
#include "i2d/CArc.h"

// ACF-Solutions includes
#include "imeas/IDataSequence.h"
#include "iproc/TSyncProcessorWrap.h"
#include "iproc/TSyncProcessorCompBase.h"
#include "iipr/IProjectionConstraints.h"
#include "iipr/IFeatureToImageMapper.h"
#include "iipr/IFeatureToProjectionMapper.h"
#include "iipr/IProjectionParams.h"


namespace iipr
{


class CArcProjectionProcessorComp:
			public iproc::CSyncProcessorCompBase,
			virtual public IFeatureToImageMapper
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef iproc::CSyncProcessorCompBase BaseClass2;

	I_BEGIN_COMPONENT(CArcProjectionProcessorComp);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_REGISTER_INTERFACE(IFeatureToImageMapper);
		I_ASSIGN(m_arcParamIdAttrPtr, "ArcParamId", "ID of arc parameter in parameter set", true, "ArcParam");
		I_ASSIGN(m_featureMapperCompPtr, "FeatureMapper", "Map result feature to projection position, it is needed for mapping operation", false, "FeatureMapper");
	I_END_COMPONENT;

	// reimplemented (iipr::IArcProjectionProcessor)
	virtual bool DoProjection(
				const iimg::IBitmap& bitmap,
				const i2d::CArc& projectionArc,
				const IProjectionParams* paramsPtr,
				imeas::IDataSequence& results);

	// reimplemented (iipr::IFeatureToImageMapper)
	virtual bool GetImagePosition(
				const imeas::INumericValue& feature,
				const iprm::IParamsSet* paramsPtr,
				i2d::CVector2d& result) const;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

private:
	I_ATTR(QByteArray, m_arcParamIdAttrPtr);
	I_REF(IFeatureToProjectionMapper, m_featureMapperCompPtr);
};


} // namespace iipr


#endif // !iipr_CArcProjectionProcessorComp_included


