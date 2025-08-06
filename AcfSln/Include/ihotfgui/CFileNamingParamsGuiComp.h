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


#ifndef ihotfgui_CFileNamingParamsGuiComp_included
#define ihotfgui_CFileNamingParamsGuiComp_included


// ACF includes
#include <iqtgui/TDesignerGuiObserverCompBase.h>

// ACF-Solutions includes
#include <ifileproc/IFileNamingParams.h>
#include <GeneratedFiles/ihotfgui/ui_CFileNamingParamsGuiComp.h>


namespace ihotfgui
{


class CFileNamingParamsGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CFileNamingParamsGuiComp,
						ifileproc::IFileNamingParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CFileNamingParamsGuiComp,
				ifileproc::IFileNamingParams> BaseClass;

	I_BEGIN_COMPONENT(CFileNamingParamsGuiComp);
	I_END_COMPONENT;

protected:
	// reimplemenented (iqtgui::TGuiObserverWrap)
	virtual void UpdateModel() const override;
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet) override;

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated() override;

protected Q_SLOTS:
	void OnModelChanged();
};


} // namespace ihotfgui


#endif // !ihotfgui_CFileNamingParamsGuiComp_included


