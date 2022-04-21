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


#ifndef icalib_CNoneCalibration2d
#define icalib_CNoneCalibration2d


// ACF includes
#include <i2d/ICalibration2d.h>


namespace icalib
{


/**
	Identity calibration, no transformation will be done.
*/
class CNoneCalibration2d: virtual public i2d::ICalibration2d
{
public:
	// reimplemented (i2d::ICalibration2d)
	virtual const i2d::CRectangle* GetArgumentArea() const;
	virtual const i2d::CRectangle* GetResultArea() const;
	virtual const imath::IUnitInfo* GetArgumentUnitInfo() const;
	virtual const imath::IUnitInfo* GetResultUnitInfo() const;
	virtual const ICalibration2d* CreateCombinedCalibration(const ITransformation2d& transformation) const;

	// reimplemented (i2d::ITransformation2d)
	virtual int GetTransformationFlags() const;
	virtual bool GetDistance(
				const i2d::CVector2d& origPos1,
				const i2d::CVector2d& origPos2,
				double& result,
				i2d::ITransformation2d::ExactnessMode mode = EM_NONE) const;
	virtual bool GetLocalTransform(const i2d::CVector2d& logPosition, i2d::CAffine2d& result, ExactnessMode mode = EM_NONE) const;
	virtual bool GetLocalInvTransform(const i2d::CVector2d& viewPosition, i2d::CAffine2d& result, ExactnessMode mode = EM_NONE) const;
	virtual bool GetPositionAt(const i2d::CVector2d& viewPosition, i2d::CVector2d& result, ExactnessMode mode = EM_NONE) const;
	virtual bool GetInvPositionAt(const i2d::CVector2d& logPosition, i2d::CVector2d& result, ExactnessMode mode = EM_NONE) const;

	// reimplemented (imath::TISurjectFunction)
	virtual bool GetInvValueAt(const i2d::CVector2d& argument, i2d::CVector2d& result) const;
	virtual i2d::CVector2d GetInvValueAt(const i2d::CVector2d& argument) const;

	// reimplemented (imath::TIMathFunction)
	virtual bool GetValueAt(const i2d::CVector2d& argument, i2d::CVector2d& result) const;
	virtual i2d::CVector2d GetValueAt(const i2d::CVector2d& argument) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// static methods
	static const CNoneCalibration2d& GetInstance();

private:
	// static attributes
	static CNoneCalibration2d s_defaultInstance;
};


} // namespace icalib


#endif // !icalib_CNoneCalibration2d


