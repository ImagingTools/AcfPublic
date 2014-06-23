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


#ifndef iqtgui_CProgressManagerGuiComp_included
#define iqtgui_CProgressManagerGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiCompBase.h"

#include "ibase/CDelegatedProgressManager.h"

#include "GeneratedFiles/iqtgui/ui_CProgressManagerGuiComp.h"


namespace iqtgui
{


class CProgressManagerGuiComp:
			public iqtgui::TDesignerGuiCompBase<Ui::CProgressManagerGuiComp>,
			public ibase::CDelegatedProgressManager
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiCompBase<Ui::CProgressManagerGuiComp> BaseClass;
	typedef ibase::CDelegatedProgressManager BaseClass2;

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

	// reimplemented (ibase::CDelegatedProgressManager)
	void OnCancelable(bool cancelState);

	// reimplemented (ibase::IProgressManager)
	virtual int BeginProgressSession(
				const QByteArray& progressId,
				const QString& description,
				bool isCancelable);
	virtual bool IsCanceled(int sessionId) const;

	// reimplemented (istd::IChangeable)
	virtual void OnEndChanges(const ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

protected Q_SLOTS:
	void on_CancelButton_clicked();

private:
	I_ATTR(bool, m_showCancelAttrPtr);
	I_ATTR(bool, m_automaticHideAttrPtr);
	I_ATTR(QString, m_descriptionAttrPtr);

	bool m_isCanceled;

	bool m_isCancelable;
};


} // namespace iqtgui


#endif // !iqtgui_CProgressManagerGuiComp_included


