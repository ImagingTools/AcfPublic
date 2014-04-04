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


#ifndef imeas_CProcessedDataSequenceSupplierComp_included
#define imeas_CProcessedDataSequenceSupplierComp_included


// ACF-Solutions includes
#include "iproc/IProcessor.h"
#include "iinsp/ISupplier.h"
#include "iinsp/TSupplierCompWrap.h"
#include "imeas/CGeneralDataSequence.h"
#include "imeas/IDataSequenceProvider.h"


namespace imeas
{


/**
	Data sequence supplier providing processed data sequence from some other input data sequence supplier.
*/
class CProcessedDataSequenceSupplierComp:
			public iinsp::TSupplierCompWrap<
						imod::TModelWrap< imeas::CGeneralDataSequence> >,
			virtual public imeas::IDataSequenceProvider
{
public:
	typedef iinsp::TSupplierCompWrap<
				imod::TModelWrap< imeas::CGeneralDataSequence> > BaseClass;

	I_BEGIN_COMPONENT(CProcessedDataSequenceSupplierComp);
		I_REGISTER_INTERFACE(imeas::IDataSequenceProvider);
		I_ASSIGN(m_dataSequenceProviderCompPtr, "DataSequenceProvider", "Provide input data sequence", true, "DataSequenceProvider");
		I_ASSIGN_TO(m_dataSequenceSupplierCompPtr, m_dataSequenceProviderCompPtr, false);
		I_ASSIGN_TO(m_dataSequenceProviderModelCompPtr, m_dataSequenceProviderCompPtr, false);
		I_ASSIGN(m_dataSequenceProcessorCompPtr, "DataSequenceProcessor", "Data sequence conversion processor (takes data sequence as input and output)", true, "DataSequenceProcessor");
	I_END_COMPONENT;

protected:
	// reimplemented (imeas::IDataSequenceProvider)
	virtual const imeas::IDataSequence* GetDataSequence() const;

	// reimplemented (iinsp::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(imeas::IDataSequenceProvider, m_dataSequenceProviderCompPtr);
	I_REF(iinsp::ISupplier, m_dataSequenceSupplierCompPtr);
	I_REF(imod::IModel, m_dataSequenceProviderModelCompPtr);
	I_REF(iproc::IProcessor, m_dataSequenceProcessorCompPtr);
};


} // namespace imeas


#endif // !imeas_CProcessedDataSequenceSupplierComp_included


