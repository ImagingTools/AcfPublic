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


#ifndef iqt2d_CSelectableSceneExtenderComp_included
#define iqt2d_CSelectableSceneExtenderComp_included


// ACF includes
#include "imod/TSingleModelObserverBase.h"

#include "icomp/CComponentBase.h"

#include "iprm/ISelectionParam.h"

#include "iqt2d/IViewExtender.h"


namespace iqt2d
{


class CSelectableSceneExtenderComp:
			public icomp::CComponentBase,
			public imod::TSingleModelObserverBase<iprm::ISelectionParam>,
			virtual public iqt2d::IViewExtender
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef imod::TSingleModelObserverBase<iprm::ISelectionParam> BaseClass2;

	CSelectableSceneExtenderComp();

	I_BEGIN_COMPONENT(CSelectableSceneExtenderComp);
		I_REGISTER_INTERFACE(iqt2d::IViewExtender);
		I_REGISTER_INTERFACE(imod::IObserver);
		I_ASSIGN_MULTI_0(m_extendersCompPtr, "SceneExtenders", "List of scene extenders", true);
	I_END_COMPONENT;

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);
	virtual bool OnDetached(imod::IModel* modelPtr);

	// reimplemented (iqt2d::IViewExtender)
	virtual void AddItemsToScene(iqt2d::IViewProvider* providerPtr, int flags);
	virtual void RemoveItemsFromScene(iqt2d::IViewProvider* providerPtr);

protected:
	void AttachCurrent();
	void DetachCurrent();

	// reimplemented (imod::CSingleModelObserverBase)
	virtual void BeforeUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

private:
	I_MULTIREF(iqt2d::IViewExtender, m_extendersCompPtr);

	typedef QMap<iqt2d::IViewProvider*, int> ConnectedSceneFlags;	// maps connected scene provider to connection flags
	ConnectedSceneFlags m_connectedSceneFlags;

	int m_currentSelectedIndex;
};


} // namespace iqt2d


#endif // !iqt2d_CSelectableSceneExtenderComp_included


