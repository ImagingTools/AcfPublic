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


#ifndef icam_CExposureParamsComp_included
#define icam_CExposureParamsComp_included


#include <icomp/CComponentBase.h>

#include <icam/IExposureParams.h>
#include <icam/IExposureConstraints.h>


namespace icam
{


class CExposureParamsComp: public icomp::CComponentBase, virtual public IExposureParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CExposureParamsComp);
		I_REGISTER_INTERFACE(IExposureParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_exposureConstraintsCompPtr, "Constraints", "Information about valid exposure parameters", false, "Constraints");
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


