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


#ifndef iqt2d_TSceneExtenderDelegatorCompWrap_included
#define iqt2d_TSceneExtenderDelegatorCompWrap_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "iqt2d/IViewExtender.h"


namespace iqt2d
{


template<class Base>
class TSceneExtenderDelegatorCompWrap:
			public Base,
			virtual public iqt2d::IViewExtender
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(TSceneExtenderDelegatorCompWrap);
		I_REGISTER_INTERFACE(iqt2d::IViewExtender);
		I_ASSIGN(m_slaveExtenderCompPtr, "SlaveSceneExtender", "Slave scene extender", false, "SlaveSceneExtender");
	I_END_COMPONENT;

	// reimplemented (iqt2d::IViewExtender)
	virtual void AddItemsToScene(iqt2d::IViewProvider* providerPtr, int flags);
	virtual void RemoveItemsFromScene(iqt2d::IViewProvider* providerPtr);

private:
	I_REF(iqt2d::IViewExtender, m_slaveExtenderCompPtr);
};



// reimplemented (iqt2d::IViewExtender)

template<class Base>
void TSceneExtenderDelegatorCompWrap<Base>::AddItemsToScene(iqt2d::IViewProvider* providerPtr, int flags)
{
	if (m_slaveExtenderCompPtr.IsValid()){
		m_slaveExtenderCompPtr->AddItemsToScene(providerPtr, flags);
	}
}


template<class Base>
void TSceneExtenderDelegatorCompWrap<Base>::RemoveItemsFromScene(iqt2d::IViewProvider* providerPtr)
{
	if (m_slaveExtenderCompPtr.IsValid()){
		m_slaveExtenderCompPtr->RemoveItemsFromScene(providerPtr);
	}
}


typedef TSceneExtenderDelegatorCompWrap<icomp::CComponentBase> CSceneExtenderDelegatorComp;


} // namespace iqt2d


#endif // !iqt2d_TSceneExtenderDelegatorCompWrap_included


