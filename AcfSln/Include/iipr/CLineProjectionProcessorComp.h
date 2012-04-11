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


#ifndef iipr_CLineProjectionProcessorComp_included
#define iipr_CLineProjectionProcessorComp_included


// ACF includes
#include <QtCore/QString>
#include "icomp/CComponentBase.h"
#include "iproc/TSyncProcessorWrap.h"

#include "iipr/ILineProjectionProcessor.h"
#include "iipr/IProjectionConstraints.h"
#include "iipr/IFeatureToImageMapper.h"
#include "iipr/IFeatureToProjectionMapper.h"


namespace iipr
{


class CLineProjectionProcessorComp:
			public icomp::CComponentBase,
			public iproc::TSyncProcessorWrap<ILineProjectionProcessor>,
			virtual public IFeatureToImageMapper,
			virtual public IProjectionConstraints
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef iproc::TSyncProcessorWrap<ILineProjectionProcessor> BaseClass2;

	I_BEGIN_COMPONENT(CLineProjectionProcessorComp);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_REGISTER_INTERFACE(ILineProjectionProcessor);
		I_REGISTER_INTERFACE(IProjectionConstraints);
		I_REGISTER_INTERFACE(IFeatureToImageMapper);
		I_ASSIGN(m_lineParamIdAttrPtr, "LineParamId", "ID of line parameter in parameter set", true, "LineParam");
		I_ASSIGN(m_featureMapperCompPtr, "FeatureMapper", "Map result feature to projection position, it is needed for mapping operation", false, "FeatureMapper");
	I_END_COMPONENT;

	/**
		Do projection along specified line with variable projection size.
	*/
	bool DoAutosizeProjection(
				const iimg::IBitmap& bitmap,
				const i2d::CLine2d& projectionLine,
				imeas::IDataSequence& results) const;

	// reimplemented (iipr::IFeatureToImageMapper)
	virtual bool GetImagePosition(
				const IFeature& feature,
				const iprm::IParamsSet* paramsPtr,
				i2d::CVector2d& result) const;

	// reimplemented (iipr::ILineProjectionProcessor)
	virtual bool DoProjection(
				const iimg::IBitmap& bitmap,
				const i2d::CLine2d& projectionLine,
				const IProjectionParams* paramsPtr,
				imeas::IDataSequence& results);

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (iipr::IProjectionConstraints)
	virtual istd::CRange GetLineWidthRange() const;
	virtual int GetMinProjectionSize() const;
	virtual int GetMaxProjectionSize() const;
	virtual bool IsAutoProjectionSizeSupported() const;

private:
	I_ATTR(QByteArray, m_lineParamIdAttrPtr);
	I_REF(IFeatureToProjectionMapper, m_featureMapperCompPtr);
};


} // namespace iipr


#endif // !iipr_CLineProjectionProcessorComp_included


