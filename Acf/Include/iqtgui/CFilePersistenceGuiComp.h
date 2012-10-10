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


#ifndef iqtgui_CFilePersistenceGuiComp_included
#define iqtgui_CFilePersistenceGuiComp_included


// ACF includes
#include "iser/IFileLoader.h"

#include "iqtgui/TDesignerGuiCompBase.h"

#include "iqtgui/Generated/ui_CFilePersistenceGuiComp.h"


namespace iqtgui
{


class CFilePersistenceGuiComp: public iqtgui::TDesignerGuiCompBase<Ui::CFilePersistenceGuiComp>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiCompBase<Ui::CFilePersistenceGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CFilePersistenceGuiComp);
		I_ASSIGN(m_objectCompPtr, "Object", "Object will be restored and stored", true, "Object");
		I_ASSIGN(m_fileLoaderCompPtr, "FileLoader", "File loader used to store and restore object", true, "FileLoader");
		I_ASSIGN(m_showLoadAttrPtr, "ShowLoad", "Show load button", true, true);
		I_ASSIGN(m_showSaveAttrPtr, "ShowSave", "Show save button", true, true);
	I_END_COMPONENT;

protected Q_SLOTS:
	void on_LoadButton_clicked();
	void on_SaveButton_clicked();

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	void OnGuiCreated();

private:
	I_REF(istd::IChangeable, m_objectCompPtr);
	I_REF(iser::IFileLoader, m_fileLoaderCompPtr);
	I_ATTR(bool, m_showLoadAttrPtr);
	I_ATTR(bool, m_showSaveAttrPtr);
};

} // namespace iqtgui


#endif // !iqtgui_CFilePersistenceGuiComp_included


