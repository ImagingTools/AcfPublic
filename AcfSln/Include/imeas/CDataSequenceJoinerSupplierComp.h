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


#ifndef imeas_CDataSequenceJoinerSupplierComp_included
#define imeas_CDataSequenceJoinerSupplierComp_included


// ACF-Solutions includes
#include "iproc/IProcessor.h"
#include "iproc/ISupplier.h"
#include "iproc/TSupplierCompWrap.h"
#include "imeas/CGeneralDataSequence.h"
#include "imeas/IDataSequenceProvider.h"
#include "imeas/IMultiDataSequenceProvider.h"


namespace imeas
{


class CDataSequenceJoinerSupplierComp:
			public iproc::TSupplierCompWrap<
						imod::TModelWrap< imeas::CGeneralDataSequence> >,
			virtual public imeas::IDataSequenceProvider
{
public:
	typedef iproc::TSupplierCompWrap<
				imod::TModelWrap< imeas::CGeneralDataSequence> > BaseClass;

	I_BEGIN_COMPONENT(CDataSequenceJoinerSupplierComp);
		I_REGISTER_INTERFACE(imeas::IDataSequenceProvider);
		I_ASSIGN_MULTI_0(m_dataSequenceProviderCompPtr, "DataSequenceProvider", "Provide list of the data sequence provider", false);
		I_ASSIGN_TO(m_dataSequenceSupplierCompPtr, m_dataSequenceProviderCompPtr, false);
		I_ASSIGN_TO(m_dataSequenceProviderModelCompPtr, m_dataSequenceProviderCompPtr, false);
		I_ASSIGN_MULTI_0(m_multiDataSequenceProviderCompPtr, "MultiDataSequenceProvider", "Provide list of the multi data sequence provider", false);
		I_ASSIGN_TO(m_multiDataSequenceSupplierCompPtr, m_multiDataSequenceProviderCompPtr, false);
		I_ASSIGN_TO(m_multiDataSequenceProviderModelCompPtr, m_multiDataSequenceProviderCompPtr, false);
	I_END_COMPONENT;

protected:
	// reimplemented (imeas::IDataSequenceProvider)
	virtual const imeas::IDataSequence* GetDataSequence() const;

	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_MULTIREF(imeas::IDataSequenceProvider, m_dataSequenceProviderCompPtr);
	I_MULTIREF(iproc::ISupplier, m_dataSequenceSupplierCompPtr);
	I_MULTIREF(imod::IModel, m_dataSequenceProviderModelCompPtr);
	I_MULTIREF(imeas::IMultiDataSequenceProvider, m_multiDataSequenceProviderCompPtr);
	I_MULTIREF(iproc::ISupplier, m_multiDataSequenceSupplierCompPtr);
	I_MULTIREF(imod::IModel, m_multiDataSequenceProviderModelCompPtr);
};


} // namespace imeas


#endif // !imeas_CDataSequenceJoinerSupplierComp_included


