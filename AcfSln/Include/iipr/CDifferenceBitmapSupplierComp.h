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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_CDifferenceBitmapSupplierComp_included
#define iipr_CDifferenceBitmapSupplierComp_included


// ACF includes
#include "i2d/ICalibrationProvider.h"
#include "iproc/IProcessor.h"
#include "iproc/TSupplierCompWrap.h"

// ACF-Solutions includes
#include "iipr/IBitmapProvider.h"


namespace iipr
{


/**
	Supplier of bitmap built on difference of two images.
*/
class CDifferenceBitmapSupplierComp:
			public iproc::TSupplierCompWrap< QPair<i2d::ITransformation2d*,  istd::TDelPtr<iimg::IBitmap> > >,
			virtual public iipr::IBitmapProvider,
			virtual public i2d::ICalibrationProvider
{
public:
	typedef iproc::TSupplierCompWrap< QPair<i2d::ITransformation2d*,  istd::TDelPtr<iimg::IBitmap> > > BaseClass;

	I_BEGIN_COMPONENT(CDifferenceBitmapSupplierComp);
		I_REGISTER_INTERFACE(iipr::IBitmapProvider);
		I_REGISTER_INTERFACE(i2d::ICalibrationProvider);
		I_ASSIGN(m_bitmapCompFact, "BitmapFactory", "Use to create bitmap object", true, "BitmapFactory");
		I_ASSIGN(m_firstBitmapProviderCompPtr, "FirstBitmapSupplier", "Provide fist input image", true, "FirstBitmapSupplier");
		I_ASSIGN_TO(m_firstBitmapProviderModelCompPtr, m_firstBitmapProviderCompPtr, false);
		I_ASSIGN(m_secondBitmapProviderCompPtr, "SecondBitmapSupplier", "Provide second input image", true, "SecondBitmapSupplier");
		I_ASSIGN_TO(m_secondBitmapProviderModelCompPtr, m_secondBitmapProviderCompPtr, false);
	I_END_COMPONENT;

protected:
	bool EnsureBitmapCreated(ProductType& result) const;

	// reimplemented (iipr::IBitmapProvider)
	virtual const iimg::IBitmap* GetBitmap() const;

	// reimplemented (i2d::ICalibrationProvider)
	virtual const i2d::ITransformation2d* GetCalibration() const;

	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	int CalculateDifferenceBitmap(
				const iimg::IBitmap& firstInputBitmap,
				const iimg::IBitmap& secondInputBitmap,
				ProductType& result) const;
private:
	I_FACT(iimg::IBitmap, m_bitmapCompFact);

	I_REF(iipr::IBitmapProvider, m_firstBitmapProviderCompPtr);
	I_REF(imod::IModel, m_firstBitmapProviderModelCompPtr);

	I_REF(iipr::IBitmapProvider, m_secondBitmapProviderCompPtr);
	I_REF(imod::IModel, m_secondBitmapProviderModelCompPtr);
};


} // namespace iipr


#endif // !iipr_CDifferenceBitmapSupplierComp_included


