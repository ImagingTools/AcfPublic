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


#ifndef iqtdoc_CHtmlHelpViewerComp_included
#define iqtdoc_CHtmlHelpViewerComp_included


// Qt includes
#include <QtGui/QTextBrowser>

// ACF includes
#include "istd/TDelPtr.h"

#include "icomp/CComponentBase.h"

#include "idoc/IHelpViewer.h"
#include "idoc/IHelpFileProvider.h"


namespace iqtdoc
{


class CHtmlHelpViewerComp:
			public icomp::CComponentBase,
			virtual public idoc::IHelpViewer
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CHtmlHelpViewerComp);
		I_REGISTER_INTERFACE(idoc::IHelpInfoProvider);
		I_REGISTER_INTERFACE(idoc::IHelpViewer);
		I_ASSIGN(m_helpFileProviderCompPtr, "HelpFileProvider", "Calculate path of html document", true, "HelpFileProvider");
	I_END_COMPONENT;

	// reimplemented (idoc::IHelpInfoProvider)
	virtual double GetHelpQuality(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const;

	// reimplemented (idoc::IHelpViewer)
	virtual void ShowHelp(const QString& contextText, const istd::IPolymorphic* contextObjectPtr);

private:
	I_REF(idoc::IHelpFileProvider, m_helpFileProviderCompPtr);

	istd::TDelPtr<QTextBrowser> m_helpWidgetPtr;
};


} // namespace iqtdoc


#endif // !iqtdoc_CHtmlHelpViewerComp_included


