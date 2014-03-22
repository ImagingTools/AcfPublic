/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_CModelProxyComp_included
#define ibase_CModelProxyComp_included


#include "imod/CModelProxy.h"
#include "imod/IModelSelection.h"
#include "imod/TSingleModelObserverBase.h"

#include "icomp/CComponentBase.h"


namespace ibase
{


/**
	Implementation of a model proxy for containers containing selectable model objects.
	\deprecated
*/
class CModelProxyComp: public icomp::CComponentBase, public imod::CModelProxy
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef imod::CModelProxy BaseClass2;

	I_BEGIN_COMPONENT(CModelProxyComp);
		I_REGISTER_INTERFACE(imod::IModel);
		I_ASSIGN(m_modelSelectionCompPtr, "ModelSelectionProvider", "Container of switchable models", true, "ModelSelectionProvider");
		I_ASSIGN_TO(m_selectionModelCompPtr, m_modelSelectionCompPtr, true);
	I_END_COMPONENT;

	CModelProxyComp();

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	class ModelSelectionListener: public imod::TSingleModelObserverBase<imod::IModelSelection>
	{
	public:
		ModelSelectionListener(CModelProxyComp& parent);

		// reimplemented (imod::CSingleModelObserverBase)
		virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

	private:
		CModelProxyComp& m_parent;
	};

	ModelSelectionListener m_modelSelectionListener;

	I_REF(imod::IModelSelection, m_modelSelectionCompPtr);
	I_REF(imod::IModel, m_selectionModelCompPtr);
};


} // namespace ibase


#endif // !ibase_CModelProxyComp_included


