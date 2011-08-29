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


#ifndef icam_CExposureParamsComp_included
#define icam_CExposureParamsComp_included


#include "icomp/CComponentBase.h"

#include "icam/IExposureParams.h"
#include "icam/IExposureConstraints.h"


namespace icam
{


class CExposureParamsComp: public icomp::CComponentBase, virtual public IExposureParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CExposureParamsComp);
		I_REGISTER_INTERFACE(IExposureParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_exposureConstraintsCompPtr, "ExposureConstraints", "Information about valid exposure parameters", false, "ExposureConstraints");
		I_ASSIGN(m_defaultShutterTimeAttrPtr, "DefaultShutterTime", "Default value of shutter time in seconds", true, 0.001);
	I_END_COMPONENT;

	CExposureParamsComp();

	// reimplemented (icam::IExposureParams)
	virtual const IExposureConstraints* GetExposureConstraints() const;
	virtual double GetShutterTime() const;
	virtual bool SetShutterTime(double time);
	virtual double GetDelayTime() const;
	virtual bool SetDelayTime(double time);
	virtual double GetEenDelay() const;
	virtual bool SetEenDelay(double time);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(IExposureConstraints, m_exposureConstraintsCompPtr);
	I_ATTR(double, m_defaultShutterTimeAttrPtr);

	double m_shutterTime;
	double m_delayTime;
	double m_eenDelayTime;
};


} // namespace icam


#endif // !icam_CExposureParamsComp_included


