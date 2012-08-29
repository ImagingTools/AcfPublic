/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iprm_CSelectionDelegatorComp_included
#define iprm_CSelectionDelegatorComp_included


#include "icomp/CComponentBase.h"

#include "imod/CSingleModelObserverBase.h"

#include "iprm/ISelectionParam.h"


namespace iprm
{


/**
	Component for synchronization of a list of selections.
	
*/
class CSelectionDelegatorComp:
			public icomp::CComponentBase,
			protected imod::CSingleModelObserverBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSelectionDelegatorComp);
		I_ASSIGN(m_sourceSelectionCompPtr, "SourceSelection", "Source selection", true, "SourceSelection");
		I_ASSIGN_TO(m_sourceSelectionModelCompPtr, m_sourceSelectionCompPtr, true);
		I_ASSIGN_MULTI_0(m_slaveSelectionsCompPtr, "SlaveSelections", "List of slave selection components", true);		
	I_END_COMPONENT;
	
protected:
	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(iprm::ISelectionParam, m_sourceSelectionCompPtr);
	I_REF(imod::IModel, m_sourceSelectionModelCompPtr);
	I_MULTIREF(iprm::ISelectionParam, m_slaveSelectionsCompPtr);
};


} // namespace iprm


#endif // !iprm_CSelectionDelegatorComp_included


