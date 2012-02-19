/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iview_CScaleCalibration_included
#define iview_CScaleCalibration_included


#include "i2d/CRectangle.h"

#include "i3d/CVector3d.h"

#include "iview/IIsomorphicCalibration.h"

#include "i2d/CAffine2d.h"




namespace iview
{


// TODO: Redesign it to ACF transformation concept.

/**
	Isomorphic calibration.
	You need this calibration when your logical coordination system is flat,
	and orthogonal to camera axis.
*/
class CScaleCalibration: public IIsomorphicCalibration
{
public:
	CScaleCalibration();

	/**
		Reset this calibration, set to be identity transform.
	*/
	void Reset();

	/**
		Get scale factor.
		This scale factor is multiplier used to calculate
		view position from logical position.
	*/
	double GetScaleFactor() const;

	/**
	
		Set scale factor.
		This scale factor is multiplier used to calculate
		view position from logical position.
	*/
	void SetScaleFactor(double value);

	/**
		Get position of logical center in view units.
	*/
	const i2d::CVector2d& GetViewCenter() const;

	/**
		Set position of logical center in view units.
	*/
	void SetViewCenter(const i2d::CVector2d& center);

	/**
		Check, if this calibration is identity.
	*/
	bool IsIdentity() const;
	
	/**
		Get global transformation from logical into view units representing this calibration.
	*/
	i2d::CAffine2d GetLogToViewTransform() const;
	
	/**
		Get global transformation from logical into view units representing this calibration.
		@overload
	*/
	void GetLogToViewTransform(i2d::CAffine2d& result) const;

	// reimplemented (iview::ICalibration)
	virtual CalcStatus GetLogLength(const i2d::CLine2d& line, double& result) const;
	virtual CalcStatus GetLogDeform(const i2d::CVector2d& logPosition, i2d::CMatrix2d& result) const;
	virtual CalcStatus GetViewDeform(const i2d::CVector2d& viewPosition, i2d::CMatrix2d& result) const;

	// reimplemented (iview::IIsomorphicCalibration)
	virtual CalcStatus GetApplyToLog(const i2d::CVector2d& viewPosition, i2d::CVector2d& result) const;
	virtual CalcStatus GetApplyToView(const i2d::CVector2d& logPosition, i2d::CVector2d& result) const;

	// reimplemented (iser::ISerializable)
	bool Serialize(iser::IArchive& archive);

private:
	i2d::CVector2d m_viewCenter;
	double m_scaleFactor;
};


// inline methods

inline double CScaleCalibration::GetScaleFactor() const
{
	return m_scaleFactor;
}


inline void CScaleCalibration::SetScaleFactor(double value)
{
	m_scaleFactor = value;
}


inline const i2d::CVector2d& CScaleCalibration::GetViewCenter() const
{
	return m_viewCenter;
}


inline void CScaleCalibration::SetViewCenter(const i2d::CVector2d& center)
{
	m_viewCenter = center;
}


inline bool CScaleCalibration::IsIdentity() const
{
	return	(m_viewCenter.GetLength2() < I_EPSILON) &&
			(::fabs(m_scaleFactor) < I_EPSILON);
}


} // namespace iview


#endif // !iview_CScaleCalibration_included




