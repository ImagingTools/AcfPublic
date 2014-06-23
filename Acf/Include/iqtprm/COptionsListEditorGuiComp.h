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


#ifndef iqtprm_COptionsListEditorGuiComp_included
#define iqtprm_COptionsListEditorGuiComp_included


//Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMenu>
#else
#include <QtGui/QMenu>
#endif

// ACF includes
#include "iprm/IOptionsManager.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "GeneratedFiles/iqtprm/ui_COptionsListEditorGuiComp.h"


namespace iqtprm
{


class COptionsListEditorGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::COptionsListEditorGuiComp,
			iprm::IOptionsList>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::COptionsListEditorGuiComp,
				iprm::IOptionsList> BaseClass;

	I_BEGIN_COMPONENT(COptionsListEditorGuiComp);
		I_ASSIGN(m_allowAddRemoveAttrPtr, "AllowAddRemove", "If it is false, 'Add' and 'Remove' buttons will be always hidden", true, true);
		I_ASSIGN(m_allowUpDownAttrPtr, "AllowUpDown", "If it is false, 'Up' and 'Down' buttons will be always hidden", true, true);
		I_ASSIGN(m_iconSizeAttrPtr, "IconSize", "Size for page icons", false, 32);
	I_END_COMPONENT;

	COptionsListEditorGuiComp();

protected Q_SLOTS:
	void on_AddButton_clicked();
	void on_RemoveButton_clicked();
	void on_UpButton_clicked();
	void on_DownButton_clicked();
	void on_OptionsList_itemSelectionChanged();
	void on_OptionsList_itemChanged(QListWidgetItem* item);
	void OnAddMenuOptionClicked(QAction* action);

protected:
	void UpdateActions();
	void UpdateList();
	int GetSelectedIndex() const;
	void EnsureSelectedIndexUpdated() const;
	QByteArray GetSelectedParamsSetTypeId() const;

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void OnGuiModelDetached();
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CComponentBase)
	virtual void OnGuiCreated();

private:
	I_ATTR(bool, m_allowAddRemoveAttrPtr);
	I_ATTR(bool, m_allowUpDownAttrPtr);
	I_ATTR(int, m_iconSizeAttrPtr);

	QMenu m_startVariableMenus;

	mutable int m_lastSelectedIndex;
};


} // namespace iqtprm


#endif // !iqtprm_COptionsListEditorGuiComp_included


