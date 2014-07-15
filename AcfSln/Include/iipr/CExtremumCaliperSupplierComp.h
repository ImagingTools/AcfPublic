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


#ifndef iipr_CExtremumCaliperSupplierComp_included
#define iipr_CExtremumCaliperSupplierComp_included


// Acf includes
#include "iinsp/TSupplierCompWrap.h"
#include "iipr/CFeaturesContainer.h"
#include "imeas/IDataSequenceProvider.h"
#include "iproc/IProcessor.h"


namespace iipr
{


class CExtremumCaliperSupplierComp: public iinsp::TSupplierCompWrap<iipr::CFeaturesContainer>
{
public:
	typedef public iinsp::TSupplierCompWrap<iipr::CFeaturesContainer> BaseClass;

	I_BEGIN_COMPONENT(CExtremumCaliperSupplierComp);
		I_ASSIGN(m_sequenceProviderCompPtr, "SequenceProvider", "Provides sequence to analyse", true, "SequenceProvider");
		I_ASSIGN_TO(m_sequenceSupplierCompPtr, m_sequenceProviderCompPtr, false);
		I_ASSIGN_TO(m_sequenceProviderModelCompPtr, m_sequenceProviderCompPtr, false);
		I_ASSIGN(m_extremumProcessorCompPtr, "ExtremumProcessor", "Processor for extremum calculation", true, "ExtremumProcessor");
	I_END_COMPONENT;

protected:
	// reimplemented (iinsp::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(imeas::IDataSequenceProvider, m_sequenceProviderCompPtr);
	I_REF(iinsp::ISupplier, m_sequenceSupplierCompPtr);
	I_REF(imod::IModel, m_sequenceProviderModelCompPtr);
	I_REF(iproc::IProcessor, m_extremumProcessorCompPtr);
};


} // namespace iipr


#endif // !iipr_CExtremumCaliperSupplierComp_included
