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


#ifndef iqtdoc_CStaticHelpFileProviderComp_included
#define iqtdoc_CStaticHelpFileProviderComp_included


// ACF includes
#include "icomp/CComponentBase.h"
#include "ifile/IFileNameParam.h"
#include "idoc/IHelpFileProvider.h"


namespace iqtdoc
{


class CStaticHelpFileProviderComp:
			public icomp::CComponentBase,
			virtual public idoc::IHelpFileProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CStaticHelpFileProviderComp);
		I_REGISTER_INTERFACE(idoc::IHelpFileProvider);
		I_ASSIGN(m_helpFileDirCompPtr, "HelpFileDir", "Directory where help files are stored", true, "HelpFileDir");
		I_ASSIGN(m_defaultFileNameAttrPtr, "DefaultHelpFileName", "Help file name used if help without context is asked", true, "GeneralHelp.html");
		I_ASSIGN(m_contextPrefixAttrPtr, "ContextPrefix", "File name prefix used for context based help file name", true, "");
		I_ASSIGN(m_contextSuffixAttrPtr, "ContextSuffix", "File name suffix added to context based help file name", true, ".html");
	I_END_COMPONENT;

	// reimplemented (idoc::IHelpFileProvider)
	virtual double GetHelpQuality(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const;
	virtual QString GetHelpFilePath(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const;

private:
	I_REF(ifile::IFileNameParam, m_helpFileDirCompPtr);
	I_ATTR(QString, m_defaultFileNameAttrPtr);
	I_ATTR(QString, m_contextPrefixAttrPtr);
	I_ATTR(QString, m_contextSuffixAttrPtr);
};


} // namespace iqtdoc


#endif // !iqtdoc_CStaticHelpFileProviderComp_included


