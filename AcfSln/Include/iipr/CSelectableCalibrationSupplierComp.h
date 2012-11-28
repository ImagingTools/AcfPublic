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


#ifndef iipr_CSelectableCalibrationSupplierComp_included
#define iipr_CSelectableCalibrationSupplierComp_included


// ACF includes
#include "istd/TDelPtr.h"
#include "i2d/ICalibration2d.h"
#include "i2d/ICalibrationProvider.h"
#include "i2d/IMultiCalibrationProvider.h"
#include "iprm/ISelectionParam.h"
#include "iproc/TSupplierCompWrap.h"


namespace iipr
{


/**
	Single 2D-calibration supplier implemented as a selector from a multi calibration provider.
*/
class CSelectableCalibrationSupplierComp:
			public iproc::TSupplierCompWrap< istd::TDelPtr<i2d::ICalibration2d> >,
			virtual public i2d::ICalibrationProvider
{
public:
	typedef iproc::TSupplierCompWrap< istd::TDelPtr<i2d::ICalibration2d> > BaseClass;

	I_BEGIN_COMPONENT(CSelectableCalibrationSupplierComp);
		I_REGISTER_INTERFACE(i2d::ICalibrationProvider);
		I_ASSIGN(m_calibrationCompFact, "CalibrationFactory", "Use to create calibration object", true, "CalibrationFactory");
		I_ASSIGN(m_multiCalibrationProviderCompPtr, "MultiCalibrationProvider", "Provider of the calibration list", true, "MultiCalibrationProvider");
		I_ASSIGN_TO(m_multiCalibrationSupplierCompPtr, m_multiCalibrationProviderCompPtr, false);
		I_ASSIGN_TO(m_multiCalibrationProviderModelCompPtr, m_multiCalibrationProviderCompPtr, false);
		I_ASSIGN(m_calibrationSelectionCompPtr, "CalibrationSelection", "Index of the calibration in the list", true, "CalibrationSelection");
		I_ASSIGN_TO(m_calibrationSelectionModelCompPtr, m_calibrationSelectionCompPtr, true);
	I_END_COMPONENT;

	// reimplemented (i2d::ICalibrationProvider)
	virtual const i2d::ICalibration2d* GetCalibration() const;

protected:
	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_FACT(i2d::ICalibration2d, m_calibrationCompFact);

	I_REF(i2d::IMultiCalibrationProvider, m_multiCalibrationProviderCompPtr);
	I_REF(iproc::ISupplier, m_multiCalibrationSupplierCompPtr);
	I_REF(imod::IModel, m_multiCalibrationProviderModelCompPtr);

	I_REF(iprm::ISelectionParam, m_calibrationSelectionCompPtr);
	I_REF(imod::IModel, m_calibrationSelectionModelCompPtr);
};


} // namespace iipr


#endif // !iipr_CSelectableCalibrationSupplierComp_included


