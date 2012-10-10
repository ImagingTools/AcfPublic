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


#ifndef iedge_CExtractedEdgeLinesSupplierComp_included
#define iedge_CExtractedEdgeLinesSupplierComp_included


// ACF includes
#include "iproc/TSupplierCompWrap.h"
#include "i2d/ICalibrationProvider.h"

// ACF-Solutions includes
#include "iipr/IBitmapProvider.h"

#include "iedge/IEdgeLinesProvider.h"
#include "iedge/IEdgesExtractor.h"
#include "iedge/CEdgeLine.h"


namespace iedge
{


class CExtractedEdgeLinesSupplierComp:
			public iproc::TSupplierCompWrap<CEdgeLine::Container>,
			virtual public IEdgeLinesProvider
{
public:
	typedef iproc::TSupplierCompWrap<CEdgeLine::Container> BaseClass;

	I_BEGIN_COMPONENT(CExtractedEdgeLinesSupplierComp);
		I_REGISTER_INTERFACE(IEdgeLinesProvider);
		I_ASSIGN(m_bitmapProviderCompPtr, "BitmapProvider", "Provide image to analyse", true, "BitmapProvider");
		I_ASSIGN_TO(m_bitmapProviderModelCompPtr, m_bitmapProviderCompPtr, false);
		I_ASSIGN(m_calibrationProviderCompPtr, "CalibrationProvider", "Provide 2D-calibration object", false, "CalibrationProvider");
		I_ASSIGN_TO(m_calibrationProviderModelCompPtr, m_calibrationProviderCompPtr, false);
		I_ASSIGN(m_edgesExtractorCompPtr, "EdgesExtractor", "Extractor of edges", true, "EdgesExtractor");
	I_END_COMPONENT;

	// reimplemented (iedge::IEdgeLinesProvider)
	virtual const CEdgeLine::Container* GetEdgesContainer() const;

protected:
	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(CEdgeLine::Container& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iipr::IBitmapProvider, m_bitmapProviderCompPtr);
	I_REF(imod::IModel, m_bitmapProviderModelCompPtr);
	I_REF(i2d::ICalibrationProvider, m_calibrationProviderCompPtr);
	I_REF(imod::IModel, m_calibrationProviderModelCompPtr);
	I_REF(IEdgesExtractor, m_edgesExtractorCompPtr);
};


} // namespace iedge


#endif // !iedge_CExtractedEdgeLinesSupplierComp_included


