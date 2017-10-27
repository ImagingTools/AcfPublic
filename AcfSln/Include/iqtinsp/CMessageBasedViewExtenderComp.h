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


#pragma once


// ACF includes
#include <istd/TPointerVector.h>
#include <icomp/CComponentBase.h>
#include <iprm/ISelectionParam.h>
#include <ilog/IMessageContainer.h>
#include <iview/IShapeView.h>
#include <iview/IShapeFactory.h>
#include <iqt2d/IViewExtender.h>
#include <iqt2d/IViewProvider.h>
#include <iinsp/ISupplier.h>
#include <iqtinsp/TResultShapeCreatorWrap.h>


namespace iqtinsp
{


/**
	Basic view extender showing geometric messages as inactive shapes.
	\c ResultShapeFactory is used for shape creation (i.e. must be set).
	\c MessageContainer is used as message source (e.g the task log of the supplier will be used)
*/
class CMessageBasedViewExtenderComp:
			public iqtinsp::TResultShapeCreatorWrap<icomp::CComponentBase>,
			virtual public iqt2d::IViewExtender
{
public:
	typedef iqtinsp::TResultShapeCreatorWrap<icomp::CComponentBase> BaseClass;

	I_BEGIN_COMPONENT(CMessageBasedViewExtenderComp);
		I_REGISTER_INTERFACE(iqt2d::IViewExtender);
		I_ASSIGN(m_resultShapeFactoryCompPtr, "ResultShapeFactory", "Creates shapes to display", true, "ResultShapeFactory");
		I_ASSIGN(m_messageContainerCompPtr, "MessageContainer", "Shape messages provider", true, "MessageContainer");
		I_ASSIGN(m_slaveViewExtenderCompPtr, "SlaveViewExtender", "Slave view extender", false, "ViewExtender");
		I_ASSIGN(m_shapeSelectorCompPtr, "ShapeSelector", "Optional selector of the shapes. Only shapes with source-ID corresponding to the given selection will be processed", false, "ShapeSelector");
	I_END_COMPONENT;

	// reimplemented (iqt2d::IViewExtender)
	virtual void AddItemsToScene(iqt2d::IViewProvider* providerPtr, int flags);
	virtual void RemoveItemsFromScene(iqt2d::IViewProvider* providerPtr);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

protected:
	virtual bool IsMessageAccepted(const istd::IInformationProvider& message) const;

private:
	I_REF(iview::IShapeFactory, m_resultShapeFactoryCompPtr);
	I_REF(ilog::IMessageContainer, m_messageContainerCompPtr);
	I_REF(iqt2d::IViewExtender, m_slaveViewExtenderCompPtr);
	I_REF(iprm::ISelectionParam, m_shapeSelectorCompPtr);

	typedef istd::TSmartPtr<iview::IShape> ShapePtr;
	typedef QList<ShapePtr> ShapeList;
	typedef QMap<iqt2d::IViewProvider*, ShapeList> ShapesMap;
	typedef QMap<iqt2d::IViewProvider*, ilog::IMessageContainer::Messages> MessagesMap;

	ShapesMap m_shapes;
	MessagesMap m_shapeMessages;
};


} // namespace iqtinsp

