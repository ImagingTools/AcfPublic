/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef iipr_CSearchBasedFeaturesSupplierComp_included
#define iipr_CSearchBasedFeaturesSupplierComp_included


// ACF includes
#include "i2d/CVector2d.h"
#include "iprm/IParamsSet.h"
#include "iproc/IProcessor.h"
#include "iproc/TSupplierCompWrap.h"

#include "iipr/IBitmapSupplier.h"
#include "iipr/IFeaturesSupplier.h"
#include "iipr/CFeaturesContainer.h"


namespace iipr
{


class CSearchBasedFeaturesSupplierComp: public iproc::TSupplierCompWrap<iipr::IFeaturesSupplier, CFeaturesContainer>
{
public:
	typedef iproc::TSupplierCompWrap<iipr::IFeaturesSupplier, CFeaturesContainer> BaseClass;

	I_BEGIN_COMPONENT(CSearchBasedFeaturesSupplierComp);
		I_REGISTER_INTERFACE(CSearchBasedFeaturesSupplierComp);
		I_ASSIGN(m_bitmapSupplierCompPtr, "BitmapSupplier", "Provide image to analyse", true, "BitmapSupplier");
		I_ASSIGN(m_searchProcessorCompPtr, "Processor", "Calculate model positions in the image", true, "Processor");
	I_END_COMPONENT;

	// reimplemented (iipr::IFeaturesSupplier)
	virtual const iipr::IFeaturesContainer* GetFeatures() const;

protected:
	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(CFeaturesContainer& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iipr::IBitmapSupplier, m_bitmapSupplierCompPtr);
	I_REF(iproc::IProcessor, m_searchProcessorCompPtr);
};


} // namespace iipr


#endif // !iipr_CSearchBasedFeaturesSupplierComp_included


