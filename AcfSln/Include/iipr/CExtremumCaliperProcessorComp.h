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


#ifndef iipr_CExtremumCaliperProcessorComp_included
#define iipr_CExtremumCaliperProcessorComp_included


// ACF includes
#include <QtCore/QString>
#include <icomp/CComponentBase.h>
#include <iproc/TSyncProcessorWrap.h>

#include <iipr/ICaliperProcessor.h>
#include <iipr/IFeatureToProjectionMapper.h>


namespace iipr
{


class CExtremumCaliperProcessorComp:
			public icomp::CComponentBase,
			public iproc::TSyncProcessorWrap<ICaliperProcessor>,
			virtual public IFeatureToProjectionMapper
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef iproc::TSyncProcessorWrap<ICaliperProcessor> BaseClass2;

	I_BEGIN_COMPONENT(CExtremumCaliperProcessorComp);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_REGISTER_INTERFACE(ICaliperProcessor);
		I_REGISTER_INTERFACE(IFeatureToProjectionMapper);
		I_ASSIGN(m_caliperParamsIdAttrPtr, "CaliperParamsId", "ID of caliper parameters in parameter set", true, "CaliperParams");
	I_END_COMPONENT;

	// reimplemented (iipr::ICaliperProcessor)
	virtual bool DoCaliper(
				const imeas::IDataSequence& derivative,
				const ICaliperParams* paramsPtr,
				IFeaturesConsumer& results);

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (iipr::IFeatureToProjectionMapper)
	virtual bool GetProjectionPosition(
				const imeas::INumericValue& feature,
				const iprm::IParamsSet* paramsPtr,
				double& result) const;

private:
	I_ATTR(QByteArray, m_caliperParamsIdAttrPtr);
};


} // namespace iipr


#endif // !iipr_CExtremumCaliperProcessorComp_included


