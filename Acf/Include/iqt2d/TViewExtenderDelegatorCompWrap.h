/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// ACF includes
#include <iqt2d/IViewExtender.h>


namespace iqt2d
{


template<class Base>
class TViewExtenderDelegatorCompWrap:
			public Base,
			virtual public iqt2d::IViewExtender
{
public:
	typedef Base BaseClass;

	I_BEGIN_COMPONENT(TViewExtenderDelegatorCompWrap);
		I_REGISTER_INTERFACE(iqt2d::IViewExtender);
		I_ASSIGN(m_slaveExtenderCompPtr, "SlaveSceneExtender", "Slave scene extender", false, "SlaveSceneExtender");
	I_END_COMPONENT;

	// reimplemented (iqt2d::IViewExtender)
	virtual void AddItemsToScene(iqt2d::IViewProvider* providerPtr, int flags) override;
	virtual void RemoveItemsFromScene(iqt2d::IViewProvider* providerPtr) override;

private:
	I_REF(iqt2d::IViewExtender, m_slaveExtenderCompPtr);
};


// reimplemented (iqt2d::IViewExtender)

template<class Base>
void TViewExtenderDelegatorCompWrap<Base>::AddItemsToScene(iqt2d::IViewProvider* providerPtr, int flags)
{
	if (m_slaveExtenderCompPtr.IsValid()){
		m_slaveExtenderCompPtr->AddItemsToScene(providerPtr, flags);
	}
}


template<class Base>
void TViewExtenderDelegatorCompWrap<Base>::RemoveItemsFromScene(iqt2d::IViewProvider* providerPtr)
{
	if (m_slaveExtenderCompPtr.IsValid()){
		m_slaveExtenderCompPtr->RemoveItemsFromScene(providerPtr);
	}
}


typedef TViewExtenderDelegatorCompWrap<icomp::CComponentBase> CViewExtenderDelegatorComp;


} // namespace iqt2d

