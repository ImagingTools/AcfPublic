/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_CProcessedBitmapSupplierComp_included
#define iipr_CProcessedBitmapSupplierComp_included


// ACF includes
#include "i2d/ICalibrationProvider.h"

// ACF-Solutions includes
#include "iproc/IProcessor.h"
#include "iinsp/ISupplier.h"
#include "iinsp/TSupplierCompWrap.h"
#include "iimg/IBitmapProvider.h"


namespace iipr
{


/**
	Image supplier providing processed image from some other input image supplier.
*/
class CProcessedBitmapSupplierBase:
			public iinsp::TSupplierCompWrap<istd::TDelPtr<iimg::IBitmap> >,
			virtual public iimg::IBitmapProvider
{
public:
	typedef iinsp::TSupplierCompWrap<istd::TDelPtr<iimg::IBitmap> > BaseClass;

	I_BEGIN_BASE_COMPONENT(CProcessedBitmapSupplierBase);
		I_REGISTER_INTERFACE(iimg::IBitmapProvider);
		I_ASSIGN(m_bitmapProviderCompPtr, "BitmapProvider", "Provide input image", true, "BitmapProvider");
		I_ASSIGN_TO(m_bitmapSupplierCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN_TO(m_bitmapProviderModelCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN(m_imageProcessorCompPtr, "BitmapProcessor", "Bitmap conversion processor (takes bitmap as input and output)", true, "BitmapProcessor");
	I_END_COMPONENT;

protected:
	bool EnsureBitmapCreated(ProductType& result) const;

	// abstract methods
	virtual iimg::IBitmap* CreateBitmap() const = 0;

	// reimplemented (iimg::IBitmapProvider)
	virtual const iimg::IBitmap* GetBitmap() const;

	// reimplemented (iinsp::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iimg::IBitmapProvider, m_bitmapProviderCompPtr);
	I_REF(iinsp::ISupplier, m_bitmapSupplierCompPtr);
	I_REF(imod::IModel, m_bitmapProviderModelCompPtr);
	I_REF(iproc::IProcessor, m_imageProcessorCompPtr);
};


class CProcessedBitmapSupplierComp: public CProcessedBitmapSupplierBase
{
public:
	typedef CProcessedBitmapSupplierBase BaseClass;

	I_BEGIN_COMPONENT(CProcessedBitmapSupplierComp);
		I_ASSIGN(m_bitmapCompFact, "BitmapFactory", "Use to create bitmap object", true, "BitmapFactory");
	I_END_COMPONENT;

protected:
	// reimplemented (CProcessedBitmapSupplierBase)
	virtual iimg::IBitmap* CreateBitmap() const
	{
		if (!m_bitmapCompFact.IsValid()){
			return false;
		}

		return m_bitmapCompFact.CreateInstance();
	}

private:
	I_FACT(iimg::IBitmap, m_bitmapCompFact);
};


} // namespace iipr


#endif // !iipr_CProcessedBitmapSupplierComp_included


