/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef icmpstr_CComponentNoteEditorComp_included
#define icmpstr_CComponentNoteEditorComp_included


// Qt includes
#include <QtCore/QTimer>

// ACF includes
#include "imod/CMultiModelDispatcherBase.h"
#include "iqtgui/TDesignerGuiObserverCompBase.h"

// ACF-Solutions includes
#include "icmpstr/IElementSelectionInfo.h"

#include "icmpstr/Generated/ui_CComponentNoteEditorComp.h"


namespace icmpstr
{


class CComponentNoteEditorComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CComponentNoteEditorComp, IElementSelectionInfo>,
			protected imod::CMultiModelDispatcherBase
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CComponentNoteEditorComp, IElementSelectionInfo> BaseClass;

	I_BEGIN_COMPONENT(CComponentNoteEditorComp);
	I_END_COMPONENT;

	CComponentNoteEditorComp();

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);
	virtual void UpdateModel() const;
	virtual void OnGuiModelAttached();
	virtual void OnGuiModelDetached();

	// reimplemented (QObject)
	virtual bool eventFilter(QObject* sourcePtr, QEvent* eventPtr);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

	// reimplemented (imod::CMultiModelDispatcherBase)
	virtual void OnModelChanged(int modelId, int changeFlags, istd::IPolymorphic* updateParamsPtr);

protected Q_SLOTS:
	void on_NoteEditor_textChanged();

private:
	QTextCursor m_lastCursorPosition;
	bool m_textWasChanged;
};


} // namespace icmpstr


#endif // !icmpstr_CComponentNoteEditorComp_included

