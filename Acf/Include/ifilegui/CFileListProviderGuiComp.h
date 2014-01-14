/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef ifilegui_CFileListProviderGuiComp_included
#define ifilegui_CFileListProviderGuiComp_included


// ACF includes
#include "ifile/IFileListProvider.h"
#include "iqtgui/TDesignerGuiObserverCompBase.h"
#include "GeneratedFiles/ifilegui/ui_CFileListProviderGuiComp.h"


namespace ifilegui
{


class CFileListProviderGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CFileListProviderGuiComp, ifile::IFileListProvider>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CFileListProviderGuiComp, ifile::IFileListProvider> BaseClass;

	I_BEGIN_COMPONENT(CFileListProviderGuiComp);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);
};


} // namespace ifilegui


#endif // !ifilegui_CFileListProviderGuiComp_included


