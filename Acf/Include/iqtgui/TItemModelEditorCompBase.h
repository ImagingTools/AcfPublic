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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtgui_TItemModelEditorCompBase_included
#define iqtgui_TItemModelEditorCompBase_included


// Qt includes
#include <QtCore/QAbstractItemModel>

// ACF includes
#include "ibase/IQtItemModelProvider.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"
#include "iqtgui/TGuiObserverWrap.h"


namespace iqtgui
{


/**
	Basic generic implementation of a data model editor for components which provide access to Qt's item model (QAbstractItemModel).
	\sa ibase::IQtItemModelProvider
*/
template <class ItemWidgetClass>
class TItemModelEditorCompBase:
				public ibase::TModelObserverCompWrap<
							TGuiObserverWrap<
										TGuiComponentBase<ItemWidgetClass>,
										imod::TSingleModelObserverBase<ibase::IQtItemModelProvider> > >
{
public:
	typedef ibase::TModelObserverCompWrap<
				TGuiObserverWrap<
							TGuiComponentBase<ItemWidgetClass>,
							imod::TSingleModelObserverBase<ibase::IQtItemModelProvider> > > BaseClass;

	I_BEGIN_COMPONENT(TItemModelEditorCompBase);
		I_ASSIGN(m_sortingEnabledAttrPtr, "SortingEnabled", "If set, sorting of table data is enabled", true, true);
	I_END_COMPONENT;

protected:
	using BaseClass::GetObjectPtr;
	using BaseClass::GetQtWidget;

	// reimplemented (CGuiComponentBase)
	virtual void OnGuiCreated();

	// reimplemented (TGuiObserverWrap)
	virtual void OnGuiModelAttached();

private:
	I_ATTR(bool, m_sortingEnabledAttrPtr);
};


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

template <class ItemWidgetClass>
void TItemModelEditorCompBase<ItemWidgetClass>::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	ibase::IQtItemModelProvider* objectPtr = BaseClass::GetObjectPtr();
	I_ASSERT(objectPtr != NULL);

	QAbstractItemModel* itemModelPtr = const_cast<QAbstractItemModel*>(objectPtr->GetItemModel());
	if (itemModelPtr != NULL){
		ItemWidgetClass* viewPtr = BaseClass::GetQtWidget();
		I_ASSERT(viewPtr != NULL);

		viewPtr->setModel(itemModelPtr);
	}
}


// reimplemented (CGuiComponentBase)

template <class ItemWidgetClass>
void TItemModelEditorCompBase<ItemWidgetClass>::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	ItemWidgetClass* viewPtr = BaseClass::GetQtWidget();

	I_ASSERT(viewPtr != NULL);
	I_ASSERT(m_sortingEnabledAttrPtr.IsValid());

	viewPtr->setSortingEnabled(*m_sortingEnabledAttrPtr);
}


} // namespace iqtgui


#endif // !iqtgui_TItemModelEditorCompBase_included


