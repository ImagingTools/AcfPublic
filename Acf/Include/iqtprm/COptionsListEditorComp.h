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


#ifndef iqtprm_COptionsListEditorComp_included
#define iqtprm_COptionsListEditorComp_included


//Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMenu>
#else
#include <QtGui/QMenu>
#endif

// ACF includes
#include <iprm/IOptionsManager.h>

#include <iqtgui/TDesignerGuiObserverCompBase.h>

#include <GeneratedFiles/iqtprm/ui_COptionsListEditorComp.h>


namespace iqtprm
{


class COptionsListEditorComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::COptionsListEditorComp,
			iprm::IOptionsList>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::COptionsListEditorComp,
				iprm::IOptionsList> BaseClass;

	I_BEGIN_COMPONENT(COptionsListEditorComp);
		I_ASSIGN(m_iconSizeAttrPtr, "IconSize", "Size for page icons", false, 32);
	I_END_COMPONENT;

	COptionsListEditorComp();

protected Q_SLOTS:
	void on_OptionsList_itemSelectionChanged();

protected:
	void UpdateList();
	int GetSelectedListOption() const;
	QByteArray GetSelectedParamsSetTypeId() const;

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void OnGuiModelDetached();
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiRetranslate();

private:
	I_ATTR(int, m_iconSizeAttrPtr);
};


} // namespace iqtprm


#endif // !iqtprm_COptionsListEditorComp_included


