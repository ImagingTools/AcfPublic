/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iipr_CProjectionSupplierComp_included
#define iipr_CProjectionSupplierComp_included


// ACF-Solutions includes
#include <iinsp/ISupplier.h>
#include <iinsp/TSupplierCompWrap.h>
#include <iimg/IBitmapProvider.h>
#include <imeas/IMultiDataSequenceProvider.h>
#include <imeas/CGeneralDataSequence.h>
#include <iproc/IProcessor.h>


namespace iipr
{


/**
	Provider of bitmap projection series, which are calculated using underlaying processor.
*/
class CProjectionSupplierComp:
			public iinsp::TSupplierCompWrap<imeas::CGeneralDataSequence>,
			virtual public imeas::IDataSequenceProvider
{
public:
	typedef iinsp::TSupplierCompWrap<imeas::CGeneralDataSequence> BaseClass;

	I_BEGIN_COMPONENT(CProjectionSupplierComp);
		I_REGISTER_INTERFACE(imeas::IDataSequenceProvider);
		I_ASSIGN(m_bitmapProviderCompPtr, "BitmapProvider", "Provides image to analyse", true, "BitmapProvider");
		I_ASSIGN_TO(m_bitmapSupplierCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN_TO(m_bitmapProviderModelCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN(m_projectionProcessorCompPtr, "ProjectionProcessor", "Processor for projection data generation", true, "ProjectionProcessor");
	I_END_COMPONENT;

	// reimplemented (imeas::IDataSequenceProvider)
	virtual const imeas::IDataSequence* GetDataSequence() const;

protected:
	// reimplemented (iinsp::TSupplierCompWrap)
	virtual int ProduceObject(imeas::CGeneralDataSequence& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iimg::IBitmapProvider, m_bitmapProviderCompPtr);
	I_REF(iinsp::ISupplier, m_bitmapSupplierCompPtr);
	I_REF(imod::IModel, m_bitmapProviderModelCompPtr);
	I_REF(iproc::IProcessor, m_projectionProcessorCompPtr);
};


} // namespace iipr


#endif // !iipr_CProjectionSupplierComp_included


