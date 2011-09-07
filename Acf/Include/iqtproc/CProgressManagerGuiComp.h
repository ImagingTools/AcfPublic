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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtproc_CProgressManagerGuiComp_included
#define iqtproc_CProgressManagerGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiCompBase.h"

#include "iproc/CDelegatedProgressManager.h"

#include "iqtproc/Generated/ui_CProgressManagerGuiComp.h"


namespace iqtproc
{


class CProgressManagerGuiComp:
			public iqtgui::TDesignerGuiCompBase<Ui::CProgressManagerGuiComp>,
			public iproc::CDelegatedProgressManager
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiCompBase<Ui::CProgressManagerGuiComp> BaseClass;
	typedef iproc::CDelegatedProgressManager BaseClass2;

	I_BEGIN_COMPONENT(CProgressManagerGuiComp);
		I_REGISTER_INTERFACE(IProgressManager);
		I_ASSIGN(m_showCancelAttrPtr, "ShowCancel", "If true, cancel button will be visible", true, true);
		I_ASSIGN(m_automaticHideAttrPtr, "AutomaticHide", "If true, progress bar will be automatically hidden", true, false);
		I_ASSIGN(m_descriptionAttrPtr, "Description", "Description text show left to progress bar", false, "Progress");
	I_END_COMPONENT;

	CProgressManagerGuiComp();

protected:
	void UpdateVisibleComponents();
	void UpdateProgressBar();

	// reimplemented (iproc::CDelegatedProgressManager)
	void CProgressManagerGuiComp::OnCancelable(bool cancelState);

	// reimplemented (iproc::IProgressManager)
	virtual int CProgressManagerGuiComp::BeginProgressSession(
				const std::string& progressId,
				const istd::CString& description,
				bool isCancelable);
	virtual bool IsCanceled(int sessionId) const;

	// reimplemented (istd::IChangeable)
	virtual void OnEndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

protected Q_SLOTS:
	void on_CancelButton_clicked();

private:
	I_ATTR(bool, m_showCancelAttrPtr);
	I_ATTR(bool, m_automaticHideAttrPtr);
	I_ATTR(istd::CString, m_descriptionAttrPtr);

	bool m_isCanceled;

	bool m_isCancelable;
};


} // namespace iqtproc


#endif // !iqtproc_CProgressManagerGuiComp_included


