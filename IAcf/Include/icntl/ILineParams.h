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


#ifndef icntl_ILineParams_included
#define icntl_ILineParams_included


// ACF includes
#include "istd/INamed.h"
#include "iser/ISerializable.h"

#include "icntl/icntl.h"


namespace icntl
{


class IInspectionUnitParams;
class IEjectorParams;


class ILineParams:
			virtual public iser::ISerializable,
			virtual public istd::INamed
{
public:
	/**
		Get number of inspection units.
	*/
	virtual int GetInspectionUnitsCount() const = 0;
	/**
		Get access to parameter of single inspection unit.
	*/
	virtual IInspectionUnitParams& GetInspectionUnitParams(int unitIndex) const = 0;
	/**
		Get number of ejectors.
	*/
	virtual int GetEjectorsCount() const = 0;
	/**
		Get access to parameter of single ejector.
	*/
	virtual IEjectorParams& GetEjectorParams(int ejectorIndex) const = 0;
	/**
		Get proportion between encoder ticks and physical units.
	*/
	virtual double GetTicksPerDistanceUnit() const = 0;
	/**
		Set proportion between encoder ticks and physical units.
	*/
	virtual void SetTicksPerDistanceUnit(double value) = 0;
	/**
		Get minimal object size.
		This value is in physical units.
	*/
	virtual double GetMinObjectSize() const = 0;
	/**
		Set minimal object size.
		This value is in physical units.
	*/
	virtual void SetMinObjectSize(double value) = 0;
	/**
		Get tolerance of position used to associate signals from few light barriers to single object.
		This value is in physical units.
	*/
	virtual double GetPositionTolerance() const = 0;
	/**
		Set tolerance of position used to associate signals from few light barriers to single object.
		This value is in physical units.
	*/
	virtual void SetPositionTolerance(double value) = 0;
	/**
		Get number of light barriers.
	*/
	virtual int GetLightBarriersCount() const = 0;
	/**
		Get position of light barrier.
		This value is in physical units relative to abstract base position.
	*/
	virtual double GetLightBarrierPosition(int barrierIndex) const = 0;
	/**
		Set position of light barrier.
		This value is in physical units relative to abstract base position.
	*/
	virtual void SetLightBarrierPosition(int barrierIndex, double position) = 0;
};


} // namespace icntl


#endif // !icntl_ILineParams_included


