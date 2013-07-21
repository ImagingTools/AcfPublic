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


#ifndef ibase_CMultiObserverBinderComp_included
#define ibase_CMultiObserverBinderComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "imod/IModelEditor.h"
#include "imod/IObserver.h"
#include "imod/IModel.h"


namespace ibase
{


class CMultiObserverBinderComp: 
		public icomp::CComponentBase,
		virtual public imod::IModelEditor,
		virtual public imod::IObserver
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CMultiObserverBinderComp);
		I_REGISTER_INTERFACE(IModelEditor);
		I_REGISTER_INTERFACE(IObserver);
		I_ASSIGN_MULTI_0(m_observersCompPtr, "SlaveObservers", "List of components that observe the model", true);
		I_ASSIGN_TO(m_modelEditorsCompPtr, m_observersCompPtr, false);
	I_END_COMPONENT;

	CMultiObserverBinderComp();

	// reimplemented (IObserver)
	virtual bool IsModelAttached(const imod::IModel* modelPtr = NULL) const;
	virtual bool OnAttached(imod::IModel* modelPtr);
	virtual bool OnDetached(imod::IModel* modelPtr);
	virtual void BeforeUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

	// reimplemented (IModelEditor)
	virtual void UpdateEditor(int updateFlags = 0);
	virtual void UpdateModel() const;
	virtual bool IsReadOnly() const;
	virtual void SetReadOnly(bool state);

private:
	I_MULTIREF(imod::IModelEditor, m_modelEditorsCompPtr);
	I_MULTIREF(imod::IObserver, m_observersCompPtr);

	imod::IModel* m_attachedModelPtr;
};


} // namespace ibase


#endif // !ibase_CMultiObserverBinderComp_included



