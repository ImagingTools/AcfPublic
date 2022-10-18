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


#include <iqtdoc/CHtmlHelpViewerComp.h>


// ACF includes
#include <iqt/iqt.h>


namespace iqtdoc
{


// reimplemented (idoc::IHelpInfoProvider)

double CHtmlHelpViewerComp::GetHelpQuality(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const
{
	if (m_helpFileProviderCompPtr.IsValid()){
		return m_helpFileProviderCompPtr->GetHelpQuality(contextText, contextObjectPtr);
	}

	return 0;
}


// reimplemented (idoc::IHelpViewer)

void CHtmlHelpViewerComp::ShowHelp(const QString& contextText, const istd::IPolymorphic* contextObjectPtr)
{
	if (		m_helpFileProviderCompPtr.IsValid() &&
				(m_helpFileProviderCompPtr->GetHelpQuality(contextText, contextObjectPtr) > 0)){
		QString filePath = m_helpFileProviderCompPtr->GetHelpFilePath(contextText, contextObjectPtr);

		QUrl url = QUrl::fromLocalFile(filePath);

		if (!m_helpWidgetPtr.IsValid()){
			m_helpWidgetPtr.SetPtr(new QTextBrowser(NULL));
			m_helpWidgetPtr->showMaximized();
		}
		Q_ASSERT(m_helpWidgetPtr.IsValid());

		m_helpWidgetPtr->setSource(url);
		m_helpWidgetPtr->setVisible(true);
	}
}


} // namespace iqtdoc


