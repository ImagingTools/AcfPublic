/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef icntl_CLineParamsComp_included
#define icntl_CLineParamsComp_included


// ACF includes
#include "icomp/CComponentBase.h"
#include "ibase/TNamedWrap.h"

#include "icntl/ILineParams.h"
#include "icntl/IInspectionUnitParams.h"
#include "icntl/IEjectorParams.h"


namespace icntl
{


/**
	Implementation of parameters of sinle line.
*/
class CLineParamsComp:
			public icomp::CComponentBase,
			public ibase::TNamedWrap<ILineParams>
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CLineParamsComp);
		I_REGISTER_INTERFACE(ILineParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(istd::INamed);
		I_REGISTER_INTERFACE(istd::IChangeable);

		I_ASSIGN(m_nameAttrPtr, "Name", "Name", true, "");
		I_ASSIGN_MULTI_0(m_inspectionUnitsCompPtr, "InspectionUnits", "List of parameter for inspection units", true);
		I_ASSIGN_MULTI_0(m_ejectorsCompPtr, "Ejectors", "List of parameter for ejectors", true);
		I_ASSIGN(m_ticksPerDistanceUnitAttrPtr, "TicksPerUnit", "Encoder ticks per logical unit", true, 1);
		I_ASSIGN(m_minObjectsSizeAttrPtr, "MinObjectSize", "Minimal object size in logical unit", true, 50);
		I_ASSIGN(m_positionToleranceAttrPtr, "PositionTolerance", "Tolerance of position used by association of light barrier pulse to object", true, 10);
		I_ASSIGN_MULTI_0(m_barrierPositionsAttrPtr, "BarrierPositions", "Positions in logical units of each light barrier (it fixes number of light barrier)", true);
	I_END_COMPONENT;

	CLineParamsComp();

	// reimplemented (icntl::ILineParams)
	virtual int GetInspectionUnitsCount() const;
	virtual IInspectionUnitParams& GetInspectionUnitParams(int unitIndex) const;
	virtual int GetEjectorsCount() const;
	virtual IEjectorParams& GetEjectorParams(int ejectorIndex) const;
	virtual double GetTicksPerDistanceUnit() const;
	virtual void SetTicksPerDistanceUnit(double value);
	virtual double GetMinObjectSize() const;
	virtual void SetMinObjectSize(double value);
	virtual double GetPositionTolerance() const;
	virtual void SetPositionTolerance(double value);
	virtual int GetLightBarriersCount() const;
	virtual double GetLightBarrierPosition(int barrierIndex) const;
	virtual void SetLightBarrierPosition(int barrierIndex, double position);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(istd::CString, m_nameAttrPtr);
	I_MULTIREF(IInspectionUnitParams, m_inspectionUnitsCompPtr);
	I_MULTIREF(IEjectorParams, m_ejectorsCompPtr);
	I_ATTR(double, m_ticksPerDistanceUnitAttrPtr);
	I_ATTR(double, m_minObjectsSizeAttrPtr);
	I_ATTR(double, m_positionToleranceAttrPtr);
	I_MULTIATTR(double, m_barrierPositionsAttrPtr);

	double m_ticksPerDistanceUnit;
	double m_minObjectSize;
	double m_positionTolerance;

	typedef std::vector<double> BarrierPositions;
	BarrierPositions m_barrierPositions;
};


} // namespace icntl


#endif // !icntl_CLineParamsComp_included


