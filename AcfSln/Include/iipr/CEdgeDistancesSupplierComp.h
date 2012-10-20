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


#ifndef iipr_CEdgeDistancesSupplierComp_included
#define iipr_CEdgeDistancesSupplierComp_included


// ACF includes
#include "istd/TPointerVector.h"
#include "i2d/CVector2d.h"

// ACF-Solutions includes
#include "iproc/IProcessor.h"
#include "iproc/ISupplier.h"
#include "iproc/TSupplierCompWrap.h"
#include "imeas/INumericValueProvider.h"
#include "imeas/CSimpleNumericValue.h"
#include "iipr/IBitmapProvider.h"
#include "iipr/IImageToFeatureProcessor.h"
#include "iipr/CCaliperDistanceFeature.h"
#include "iipr/CFeaturesContainer.h"


namespace iipr
{


class CEdgeDistancesSupplierComp:
			public iproc::TSupplierCompWrap<CFeaturesContainer>,
			virtual public imeas::INumericValueProvider
{
public:
	typedef iproc::TSupplierCompWrap<CFeaturesContainer> BaseClass;

	I_BEGIN_COMPONENT(CEdgeDistancesSupplierComp);
		I_REGISTER_INTERFACE(imeas::INumericValueProvider);
		I_ASSIGN(m_bitmapProviderCompPtr, "BitmapProvider", "Provide image to analyse", true, "BitmapProvider");
		I_ASSIGN_TO(m_bitmapSupplierCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN_TO(m_bitmapProviderModelCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN(m_processorCompPtr, "Processor", "Processor calculating set of positions from image", true, "Processor");
	I_END_COMPONENT;

	// reimplemented (imeas::INumericValueProvider)
	virtual int GetValuesCount() const;
	virtual const imeas::INumericValue& GetNumericValue(int index) const;

protected:
	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iipr::IBitmapProvider, m_bitmapProviderCompPtr);
	I_REF(iproc::ISupplier, m_bitmapSupplierCompPtr);
	I_REF(imod::IModel, m_bitmapProviderModelCompPtr);
	I_REF(iproc::IProcessor, m_processorCompPtr);
};


} // namespace iipr


#endif // !iipr_CEdgeDistancesSupplierComp_included


