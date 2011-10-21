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


#ifndef iqtdoc_CHtmlHelpGuiComp_included
#define iqtdoc_CHtmlHelpGuiComp_included


// Qt includes
#include <QTextBrowser>


// ACF includes
#include "iqtgui/TGuiComponentBase.h"

#include "idoc/IHelpViewer.h"
#include "idoc/IHelpFileProvider.h"


namespace iqtdoc
{


class CHtmlHelpGuiComp:
			public iqtgui::TGuiComponentBase<QTextBrowser>,
			virtual public idoc::IHelpViewer
{
public:
	typedef iqtgui::TGuiComponentBase<QTextBrowser> BaseClass;

	I_BEGIN_COMPONENT(CHtmlHelpGuiComp);
		I_REGISTER_INTERFACE(idoc::IHelpInfoProvider);
		I_REGISTER_INTERFACE(idoc::IHelpViewer);
		I_ASSIGN(m_helpFileProviderCompPtr, "HelpFileProvider", "Calculate path of html document", true, "HelpFileProvider");
	I_END_COMPONENT;

	// reimplemented (idoc::IHelpInfoProvider)
	virtual double GetHelpQuality(const istd::CString& contextText, const istd::IPolymorphic* contextObjectPtr) const;

	// reimplemented (idoc::IHelpViewer)
	virtual void ShowHelp(const istd::CString& contextText, const istd::IPolymorphic* contextObjectPtr);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiShown();

private:
	I_REF(idoc::IHelpFileProvider, m_helpFileProviderCompPtr);

	mutable QUrl m_urlToShow;
};


} // namespace iqtdoc


#endif // !iqtdoc_CHtmlHelpGuiComp_included


