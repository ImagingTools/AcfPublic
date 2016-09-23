/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtprm_CMultiParamsManagerGuiComp_included
#define iqtprm_CMultiParamsManagerGuiComp_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QStackedWidget>
#else
#include <QtGui/QStackedWidget>
#endif

// ACF includes
#include <iqt2d/IViewExtender.h>

#include <iqtprm/CParamsManagerGuiCompBase.h>


namespace iqtprm
{


class CMultiParamsManagerGuiComp: public CParamsManagerGuiCompBase
{
public:
	typedef CParamsManagerGuiCompBase BaseClass;

	I_BEGIN_COMPONENT(CMultiParamsManagerGuiComp);
		I_ASSIGN_MULTI_0(m_paramsGuiCompPtr, "ParamsGui", "GUI object used to display parameters", false);
		I_ASSIGN_TO(m_paramsObserverCompPtr, m_paramsGuiCompPtr, false);
		I_ASSIGN_TO(m_viewExtendersCompPtr, m_paramsGuiCompPtr, false);
		I_ASSIGN_MULTI_0(m_paramsSetTypeIdsAttrPtr, "ParamTypeIds", "The list of type IDs for supported parameter sets", true);
	I_END_COMPONENT;

protected:
	// reimplemented (CParamsManagerGuiCompBase)
	virtual imod::IObserver* GetObserverPtr(const iprm::IParamsSet* paramsSetPtr) const;
	virtual iqtgui::IGuiObject* GetEditorGuiPtr(const iprm::IParamsSet* paramsSetPtr) const;
	virtual void UpdateParamsView(int selectedIndex);
	virtual iqt2d::IViewExtender* GetCurrentViewExtenderPtr() const;

	// reimplemented (iqtgui::CComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
	I_MULTIREF(iqtgui::IGuiObject, m_paramsGuiCompPtr);
	I_MULTIREF(imod::IObserver, m_paramsObserverCompPtr);
	I_MULTIREF(iqt2d::IViewExtender, m_viewExtendersCompPtr);
	I_MULTIATTR(QByteArray, m_paramsSetTypeIdsAttrPtr);

	QStackedWidget* m_parameterEditorStack;

	typedef QMap<QWidget*, iqtgui::IGuiObject*> WidgetGuiMap;
	typedef QMap<QByteArray /*parameter type ID*/, int /*Position in the page stack*/> TypeToStackPositionMap;
	typedef QMap<QByteArray /*parameter type ID*/, iqt2d::IViewExtender* /*Corresponding view extender*/> TypeToExtenderMap;
	typedef QMap<iqt2d::IViewProvider*, int> ConnectedSceneFlags; // maps connected scene provider to connection flags

	WidgetGuiMap m_widgetToGuiMap;
	TypeToStackPositionMap m_typeToStackPositionMap;
	TypeToExtenderMap m_typeToExtenderMap;
	ConnectedSceneFlags m_connectedSceneFlags;
};


} // namespace iqtprm


#endif // !iqtprm_CMultiParamsManagerGuiComp_included


