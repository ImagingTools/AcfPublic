/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef iqsci_CTextEditorGuiComp_included
#define iqsci_CTextEditorGuiComp_included


// ACF includes
#include "imod/TSingleModelObserverBase.h"

#include "ibase/ITextDocument.h"

#include "iqtgui/TGuiComponentBase.h"
#include "iqtgui/TGuiObserverWrap.h"

#include "iqsci/CTextEditor.h"


namespace iqsci
{


class CTextEditorGuiComp:
			public iqtgui::TGuiObserverWrap<
					iqtgui::TGuiComponentBase<CTextEditor>,
					imod::TSingleModelObserverBase<ibase::ITextDocument> >,
			virtual public ibase::ICommandsProvider
{
	Q_OBJECT

public:
	typedef iqtgui::TGuiObserverWrap<
				iqtgui::TGuiComponentBase<CTextEditor>,
				imod::TSingleModelObserverBase<ibase::ITextDocument> > BaseClass;

	I_BEGIN_COMPONENT(CTextEditorGuiComp);
		I_REGISTER_INTERFACE(ibase::ICommandsProvider);
		I_REGISTER_INTERFACE(imod::IObserver);
		I_ASSIGN(m_languageAttrPtr, "Language", "Use syntax highlighting for defined language", false, "Language");
		I_ASSIGN(m_useFoldingAttrPtr, "UseFolding", "Use folding in the text document", false, true);
		I_ASSIGN(m_readOnlyAttrPtr, "ReadOnly", "Document view is read only", false, false);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);
	virtual void OnGuiModelDetached();

	// reimplemented (ibase::ICommandsProvider)
	virtual const ibase::IHierarchicalCommand* GetCommands() const;

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiRetranslate();

protected Q_SLOTS:
	virtual void OnTextChanged();

private:
	I_ATTR(bool, m_useFoldingAttrPtr);
	I_ATTR(istd::CString, m_languageAttrPtr);
	I_ATTR(bool, m_readOnlyAttrPtr);
};


} // namespace iqsci


#endif // !iqsci_CTextEditorGuiComp_included


