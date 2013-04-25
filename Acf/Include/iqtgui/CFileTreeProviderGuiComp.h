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


#ifndef iqtgui_CFileTreeProviderGuiComp_included
#define iqtgui_CFileTreeProviderGuiComp_included


// ACF includes
#include "ifile/IFileNameParam.h"
#include "ibase/IQtItemModelProvider.h"
#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtgui/Generated/ui_CFileTreeProviderGuiComp.h"


namespace iqtgui
{


class CFileTreeProviderGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CFileTreeProviderGuiComp, ibase::IQtItemModelProvider>
{
	Q_OBJECT
public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CFileTreeProviderGuiComp, ibase::IQtItemModelProvider> BaseClass;

	I_BEGIN_COMPONENT(CFileTreeProviderGuiComp);
		I_ASSIGN(m_currentFileCompPtr, "CurrentFile", "Write name of the currently selected file to", false, "CurrentFile");
	I_END_COMPONENT;

protected:
	// reimplemented (CGuiComponentBase)
	virtual void OnGuiCreated();

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

private Q_SLOTS:
	void OnSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);

private:
	I_REF(ifile::IFileNameParam, m_currentFileCompPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CFileTreeProviderGuiComp_included


