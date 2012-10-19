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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_CTubeProjectionLinesProviderComp_included
#define iipr_CTubeProjectionLinesProviderComp_included


// ACF-Solutions includes
#include "iipr/CMultiLineSupplierCompBase.h"


namespace iipr
{


class CTubeProjectionLinesProviderComp: public iipr::CMultiLineSupplierCompBase
{
public:
	typedef iipr::CMultiLineSupplierCompBase BaseClass;

	I_BEGIN_COMPONENT(CTubeProjectionLinesProviderComp);
		I_ASSIGN(m_tubeParamsIdAttrPtr, "TubeParamsId", "ID of the tube parameter in the parameter set", true, "TubeParamsId");
		I_ASSIGN(m_linesCountParamsIdAttrPtr, "LinesCountParamsId", "ID of the line count parameter in the parameter set", true, "LinesCountParamsId");
		I_ASSIGN(m_calibrationProviderCompPtr, "CalibrationProvider", "Provider of the transformation between logical and physical coordinate systems", false, "CalibrationProvider");
	I_END_COMPONENT;

protected:
	// reimplemented (iipr::CMultiLineSupplierCompBase)
	virtual int ProduceObject(ProductType& result) const;

private:
	I_ATTR(QByteArray, m_tubeParamsIdAttrPtr);
	I_ATTR(QByteArray, m_linesCountParamsIdAttrPtr);
	I_REF(i2d::ICalibrationProvider, m_calibrationProviderCompPtr);
};


} // namespace iipr


#endif // !iipr_CTubeProjectionLinesProviderComp_included


