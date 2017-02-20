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


#ifndef icalib_CAffineCalibration2dComp_included
#define icalib_CAffineCalibration2dComp_included


// ACF includes
#include <icomp/CComponentBase.h>

// ACF-Solutions includes
#include <icalib/CAffineCalibration2d.h>


namespace icalib
{


/**
	Attributable component for affine 2D calibration.
*/
class CAffineCalibration2dComp: public icomp::CComponentBase, public CAffineCalibration2d
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef CAffineTransformation2d BaseClass2;

	I_BEGIN_COMPONENT(CAffineCalibration2dComp);
		I_REGISTER_INTERFACE(ICalibration2d);
		I_REGISTER_INTERFACE(ITransformation2d);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(i2d::CAffineTransformation2d);
		I_ASSIGN(m_m00AttrPtr, "M00", "Matrix value at the position (0, 0)", false, 1.0);
		I_ASSIGN(m_m10AttrPtr, "M10", "Matrix value at the position (1, 0)", false, 0);
		I_ASSIGN(m_m01AttrPtr, "M01", "Matrix value at the position (0, 1)", false, 0);
		I_ASSIGN(m_m11AttrPtr, "M11", "Matrix value at the position (1, 1)", false, 1.0);
		I_ASSIGN(m_translationXAttrPtr, "TranslationX", "Translation in X-direction", false, 0.0);
		I_ASSIGN(m_translationYAttrPtr, "TranslationY", "Translation in Y-direction", false, 0.0);
		I_ASSIGN(m_argumentUnitInfoCompPtr, "ArgumentUnitInfo", "Unit information for calibration argument", false, "ArgumentUnitInfo");
		I_ASSIGN(m_resultUnitInfoCompPtr, "ResultUnitInfo", "Unit information for calibration argument", false, "ResultUnitInfo");
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_ATTR(double, m_m00AttrPtr);
	I_ATTR(double, m_m10AttrPtr);
	I_ATTR(double, m_m01AttrPtr);
	I_ATTR(double, m_m11AttrPtr);
	I_ATTR(double, m_translationXAttrPtr);
	I_ATTR(double, m_translationYAttrPtr);
	I_REF(imath::IUnitInfo, m_argumentUnitInfoCompPtr);
	I_REF(imath::IUnitInfo, m_resultUnitInfoCompPtr);
};


} // namespace icalib


#endif // !icalib_CAffineCalibration2dComp_included


