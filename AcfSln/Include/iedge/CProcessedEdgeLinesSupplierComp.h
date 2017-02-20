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


#ifndef iedge_CProcessedEdgeLinesSupplierComp_included
#define iedge_CProcessedEdgeLinesSupplierComp_included


// ACF includes
#include <iinsp/ISupplier.h>
#include <iinsp/TSupplierCompWrap.h>
#include <iedge/IEdgeLinesProvider.h>
#include <iedge/IEdgeLinesProcessor.h>
#include <iedge/CEdgeLineContainer.h>


namespace iedge
{


class CProcessedEdgeLinesSupplierComp:
			public iinsp::TSupplierCompWrap<CEdgeLineContainer>,
			virtual public IEdgeLinesProvider
{
public:
	typedef iinsp::TSupplierCompWrap<CEdgeLineContainer> BaseClass;

	I_BEGIN_COMPONENT(CProcessedEdgeLinesSupplierComp);
		I_REGISTER_INTERFACE(IEdgeLinesProvider);
		I_ASSIGN(m_edgeLinesProviderCompPtr, "EdgeLinesProvider", "Provide list of edge list to processing", true, "EdgeLinesProvider");
		I_ASSIGN_TO(m_edgeLinesSupplierCompPtr, m_edgeLinesProviderCompPtr, false);
		I_ASSIGN_TO(m_edgeLinesProviderModelCompPtr, m_edgeLinesProviderCompPtr, false);
		I_ASSIGN(m_edgesProcessorCompPtr, "EdgesProcessor", "Processor (edges to edges)", true, "EdgesProcessor");
	I_END_COMPONENT;

	// reimplemented (iedge::IEdgeLinesProvider)
	virtual const CEdgeLineContainer* GetEdgesContainer() const;

protected:
	// reimplemented (iinsp::TSupplierCompWrap)
	virtual int ProduceObject(CEdgeLineContainer& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(IEdgeLinesProvider, m_edgeLinesProviderCompPtr);
	I_REF(iinsp::ISupplier, m_edgeLinesSupplierCompPtr);
	I_REF(imod::IModel, m_edgeLinesProviderModelCompPtr);
	I_REF(IEdgeLinesProcessor, m_edgesProcessorCompPtr);
};


} // namespace iedge


#endif // !iedge_CProcessedEdgeLinesSupplierComp_included


