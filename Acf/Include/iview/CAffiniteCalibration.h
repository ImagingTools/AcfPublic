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


#ifndef iview_CAffiniteCalibration_included
#define iview_CAffiniteCalibration_included


#include "i2d/CAffine2d.h"

#include "iview/IIsomorphicCalibration.h"


namespace iview
{


// TODO: Switch to ACF i2d::ITransformation2d and i2d::CAffineTransformation2d.
/**	Affinite calibration.
 *		This class describe a calibration where the coordination system is moved and rotated.
 *		You need this calibration when your logical coordination system is flat,
 *		but not orthogonal to camera axis.
 *		Please note, that logical coordination system represents only finite
 *		rectangle area, you can set using SetBounds(const i2d::CRectangle&) method.
*/
class CAffiniteCalibration: public IIsomorphicCalibration
{
public:
	CAffiniteCalibration();

	/**	Get global transformation from logical into view units representing this calibration.
	*/
	const i2d::CAffine2d& GetLogToViewTransform() const;
	/**	Get global transformation from logical into view units representing this calibration.
	 *		@overload
	*/
	void GetLogToViewTransform(i2d::CAffine2d& result) const;
	/**	Get global transformation from view into logical units representing this calibration.
	*/
	i2d::CAffine2d GetViewToLogTransform() const;
	/**	Get global transformation from view into logical units representing this calibration.
	 *		@overload
	*/
	void GetViewToLogTransform(i2d::CAffine2d& result) const;

	/**	Reset this calibration, set to be identity transform.
	*/
	void Reset();
	void Reset(const i2d::CVector2d& position, double angle, double scale = 1.0);

	void SetTransform(const i2d::CAffine2d& transform);

	i2d::CVector2d GetCenter() const;
	double GetAngle() const;
	double GetScaleFactor() const;

	virtual void Apply(const iview::IIsomorphicCalibration& calib);
	virtual void ApplyLeft(const iview::IIsomorphicCalibration& calib);
	virtual CAffiniteCalibration GetApply(const iview::IIsomorphicCalibration& calib);
	virtual CAffiniteCalibration GetApplyLeft(const iview::IIsomorphicCalibration& calib);

	// reimplemented (iview::ICalibration)
	virtual CalcStatus GetLogLength(const i2d::CLine2d& line, double& result) const;
	virtual CalcStatus GetLogDeform(const i2d::CVector2d& logPosition, i2d::CMatrix2d& result) const;
	virtual CalcStatus GetViewDeform(const i2d::CVector2d& viewPosition, i2d::CMatrix2d& result) const;

	// reimplemented (iview::IIsomorphicCalibration)
	virtual CalcStatus GetApplyToLog(const i2d::CVector2d& viewPosition, i2d::CVector2d& result) const;
	virtual CalcStatus GetApplyToView(const i2d::CVector2d& logPosition, i2d::CVector2d& result) const;

	// reimplemented (iser::ISerializable)
	bool Serialize(iser::IArchive& archive);

protected:
	static i2d::CAffine2d ExtractTransform(const i2d::CVector2d& position, const iview::IIsomorphicCalibration& calibration);

private:
	i2d::CAffine2d m_logToViewTransform;
};



} // namespace iview



#endif // !iview_CPerspectiveCalibration_included
