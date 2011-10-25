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


#ifndef iipr_CSearchBasedFeaturesSupplierComp_included
#define iipr_CSearchBasedFeaturesSupplierComp_included


// ACF includes
#include "i2d/CVector2d.h"
#include "iprm/IParamsSet.h"
#include "iproc/IProcessor.h"
#include "iproc/TSupplierCompWrap.h"

#include "iipr/IBitmapProvider.h"
#include "iipr/IFeaturesProvider.h"
#include "iipr/CFeaturesContainer.h"


namespace iipr
{


class CSearchBasedFeaturesSupplierComp:
			public iproc::TSupplierCompWrap<CFeaturesContainer>,
			virtual public iipr::IFeaturesProvider
{
public:
	typedef iproc::TSupplierCompWrap<CFeaturesContainer> BaseClass;

	I_BEGIN_COMPONENT(CSearchBasedFeaturesSupplierComp);
		I_REGISTER_INTERFACE(iipr::IFeaturesProvider);
		I_ASSIGN(m_bitmapProviderCompPtr, "BitmapSupplier", "Provide image to analyse", true, "BitmapSupplier");
		I_ASSIGN_TO(m_bitmapProviderModelCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN(m_searchProcessorCompPtr, "Processor", "Calculate model positions in the image", true, "Processor");
	I_END_COMPONENT;

	// reimplemented (iipr::IFeaturesProvider)
	virtual Features GetFeatures() const;

protected:
	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(CFeaturesContainer& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iipr::IBitmapProvider, m_bitmapProviderCompPtr);
	I_REF(imod::IModel, m_bitmapProviderModelCompPtr);
	I_REF(iproc::IProcessor, m_searchProcessorCompPtr);
};


} // namespace iipr


#endif // !iipr_CSearchBasedFeaturesSupplierComp_included


