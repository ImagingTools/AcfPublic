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


#ifndef iipr_CLineProjectionSupplierComp_included
#define iipr_CLineProjectionSupplierComp_included


// ACF includes
#include "i2d/CVector2d.h"
#include "iprm/IParamsSet.h"
#include "iproc/IProcessor.h"
#include "iproc/TSupplierCompWrap.h"

// ACF-Solutions includes
#include "imeas/CGeneralDataSequence.h"

#include "iipr/IBitmapProvider.h"
#include "iipr/IDataSequenceProvider.h"
#include "iipr/ILineProjectionProcessor.h"


namespace iipr
{


class CLineProjectionSupplierComp:
			public iproc::TSupplierCompWrap<imeas::CGeneralDataSequence>,
			virtual public iipr::IDataSequenceProvider
{
public:
	typedef iproc::TSupplierCompWrap<imeas::CGeneralDataSequence> BaseClass;

	I_BEGIN_COMPONENT(CLineProjectionSupplierComp);
		I_REGISTER_INTERFACE(iipr::IDataSequenceProvider);
		I_ASSIGN(m_bitmapProviderCompPtr, "BitmapProvider", "Provide image to analyse", true, "BitmapProvider");
		I_ASSIGN_TO(m_bitmapProviderModelCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN(m_projectionProcessorCompPtr, "ProjectionProcessor", "Processor for projection data generation", true, "ProjectionProcessor");
	I_END_COMPONENT;

	// reimplemented (iipr::IDataSequenceProvider)
	virtual const imeas::IDataSequence* GetDataSequence() const;

protected:
	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(imeas::CGeneralDataSequence& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iipr::IBitmapProvider, m_bitmapProviderCompPtr);
	I_REF(imod::IModel, m_bitmapProviderModelCompPtr);
	I_REF(iipr::ILineProjectionProcessor, m_projectionProcessorCompPtr);
};


} // namespace iipr


#endif // !iipr_CLineProjectionSupplierComp_included


