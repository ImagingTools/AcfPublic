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


#ifndef iipr_CSearchBasedFeaturesSupplierComp_included
#define iipr_CSearchBasedFeaturesSupplierComp_included


// ACF includes
#include "i2d/IMultiCalibrationProvider.h"
#include "i2d/CVector2d.h"
#include "i2d/CAffineTransformation2d.h"
#include "iprm/IParamsSet.h"
#include "istd/IInformationProvider.h"

// ACF-Solutions includes
#include "iproc/IProcessor.h"
#include "iproc/ISupplier.h"
#include "iproc/TSupplierCompWrap.h"
#include "imeas/INumericValueProvider.h"
#include "iipr/IBitmapProvider.h"
#include "iipr/CFeaturesContainer.h"


namespace iipr
{


class CSearchBasedFeaturesSupplierComp:
			public iproc::TSupplierCompWrap<CFeaturesContainer>,
			virtual public imeas::INumericValueProvider,
			virtual public i2d::IMultiCalibrationProvider,
			virtual public istd::IInformationProvider
{
public:
	typedef iproc::TSupplierCompWrap<CFeaturesContainer> BaseClass;

	I_BEGIN_COMPONENT(CSearchBasedFeaturesSupplierComp);
		I_REGISTER_INTERFACE(imeas::INumericValueProvider);
		I_REGISTER_INTERFACE(i2d::IMultiCalibrationProvider);
		I_REGISTER_INTERFACE(istd::IInformationProvider);
		I_ASSIGN(m_bitmapProviderCompPtr, "BitmapProvider", "Provide image to analyse", true, "BitmapProvider");
		I_ASSIGN_TO(m_bitmapSupplierCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN_TO(m_bitmapProviderModelCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN(m_searchProcessorCompPtr, "Processor", "Calculate model positions in the image", true, "Processor");
		I_ASSIGN(m_slaveInformationProviderCompPtr, "SlaveInformationProvider", "Used to provide the status if set", false, "SlaveInformationProvider");
	I_END_COMPONENT;

	// reimplemented (i2d::IMultiCalibrationProvider)
	virtual const iprm::IOptionsList* GetCalibrationSelectionContraints() const;
	virtual int GetCalibrationsCount() const;
	virtual const i2d::ICalibration2d* GetCalibration(int calibrationIndex) const;

	// reimplemented (imeas::INumericValueProvider)
	virtual int GetValuesCount() const;
	virtual const imeas::INumericValue& GetNumericValue(int index) const;

	// reimplemented (istd::IInformationProvider)
	virtual QDateTime GetInformationTimeStamp() const;
	virtual InformationCategory GetInformationCategory() const;
	virtual int GetInformationId() const;
	virtual QString GetInformationDescription() const;
	virtual QString GetInformationSource() const;
	virtual int GetInformationFlags() const;

protected:
	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(CFeaturesContainer& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(iipr::IBitmapProvider, m_bitmapProviderCompPtr);
	I_REF(iproc::ISupplier, m_bitmapSupplierCompPtr);
	I_REF(imod::IModel, m_bitmapProviderModelCompPtr);
	I_REF(iproc::IProcessor, m_searchProcessorCompPtr);
	I_REF(istd::IInformationProvider, m_slaveInformationProviderCompPtr);

	typedef QVector<i2d::CAffineTransformation2d> TransformationList;
	
	mutable TransformationList m_transformationList;
};


} // namespace iipr


#endif // !iipr_CSearchBasedFeaturesSupplierComp_included


