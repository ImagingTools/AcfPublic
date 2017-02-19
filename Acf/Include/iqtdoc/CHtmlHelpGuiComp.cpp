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


#include <iqtdoc/CHtmlHelpGuiComp.h>


namespace iqtdoc
{


// reimplemented (idoc::IHelpInfoProvider)

double CHtmlHelpGuiComp::GetHelpQuality(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const
{
	if (m_helpFileProviderCompPtr.IsValid()){
		return m_helpFileProviderCompPtr->GetHelpQuality(contextText, contextObjectPtr);
	}

	return 0;
}


// reimplemented (idoc::IHelpViewer)

void CHtmlHelpGuiComp::ShowHelp(const QString& contextText, const istd::IPolymorphic* contextObjectPtr)
{
	QTextBrowser* editorPtr = GetQtWidget();
	if (		(editorPtr != NULL) &&
				m_helpFileProviderCompPtr.IsValid() &&
				(m_helpFileProviderCompPtr->GetHelpQuality(contextText, contextObjectPtr) > 0)){
		QString filePath = m_helpFileProviderCompPtr->GetHelpFilePath(contextText, contextObjectPtr);

		QUrl url = QUrl::fromLocalFile(filePath);

		if (editorPtr->isVisible()){
			editorPtr->setSource(url);

			m_urlToShow.clear();
		}
		else{
			m_urlToShow = url;
		}
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CHtmlHelpGuiComp::OnGuiShown()
{
	BaseClass::OnGuiShown();

	QTextBrowser* editorPtr = GetQtWidget();
	if ((editorPtr != NULL) && !m_urlToShow.isEmpty()){
		editorPtr->setSource(m_urlToShow);
	}
}


} // namespace iqtdoc


