/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef idoc_CSelectedDocModelBinderComp_included
#define idoc_CSelectedDocModelBinderComp_included


#include "imod/TSingleModelObserverBase.h"

#include "icomp/CComponentBase.h"

#include "idoc/IDocumentManager.h"


namespace idoc
{


/**
	Conditional model-observer binder depending on actual selection.
	This component allows to work-around of problems with observing of selected document or view.
	It connects model with observer only if some document (or view) is currently selected.
	Please note, that there is no assumption that connected model must be the same as observed model.
*/
class CSelectedDocModelBinderComp:
			public icomp::CComponentBase,
			protected imod::TSingleModelObserverBase<IDocumentManager>
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef imod::TSingleModelObserverBase<IDocumentManager> BaseClass2;

	I_BEGIN_COMPONENT(CSelectedDocModelBinderComp);
		I_ASSIGN(m_observedObjectCompPtr, "ActivationObject", "Object will be observed if it is active", true, "ActivationObject");
		I_ASSIGN(m_documentManagerCompPtr, "DocumentManager", "Document manager used to check which object is active", true, "DocumentManager");
		I_ASSIGN_TO(m_documentManagerModelCompPtr, m_documentManagerCompPtr, true);
		I_ASSIGN(m_modelCompPtr, "Model", "Model to be connected", true, "Model");
		I_ASSIGN_MULTI_0(m_observersCompPtr, "Observers", "Observers for the model", true);
	I_END_COMPONENT;

	CSelectedDocModelBinderComp();

protected:
	enum
	{
		RELEVANT_FLAGS = IDocumentManager::CF_DOCUMENT_CREATED | IDocumentManager::CF_DOCUMENT_REMOVED | IDocumentManager::CF_VIEW_ACTIVATION_CHANGED
	};

	void TryConnectObservers();
	void TryDisconnectObservers();

	// reimplemented (imod::IObserver)
	virtual void BeforeUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(icomp::IComponent, m_observedObjectCompPtr);
	I_REF(IDocumentManager, m_documentManagerCompPtr);
	I_REF(imod::IModel, m_documentManagerModelCompPtr);
	I_REF(imod::IModel, m_modelCompPtr);
	I_MULTIREF(imod::IObserver, m_observersCompPtr);

	bool m_isActive;
};


} // namespace idoc


#endif // !idoc_CSelectedDocModelBinderComp_included


