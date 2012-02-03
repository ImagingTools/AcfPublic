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


#ifndef ibase_CCopyAppComp_included
#define ibase_CCopyAppComp_included


#include "istd/IChangeable.h"

#include "iser/IFileLoader.h"

#include "ibase/IApplication.h"
#include "ibase/IFileConvertCopy.h"
#include "ibase/TLoggerCompWrap.h"


namespace ibase
{


/**
	General file transformation application.
	This implementation uses some slave ibase::IFileConvertCopy implementation to provide copy operation.
	It implements ibase::IApplication and can be used as standalone application.
*/
class CCopyAppComp:
			public ibase::CLoggerComponentBase,
			virtual public IApplication
{
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CCopyAppComp);
		I_REGISTER_INTERFACE(IApplication);

		I_ASSIGN(m_fileCopyCompPtr, "FileCopy", "Provide copy of single file", true, "FileCopy");
		I_ASSIGN(m_needExplicitInputAttrPtr, "NeedExplicitInput", "Indicate if explicit input file with -input is needed, otherwise first argument will be taken", true, false);
	I_END_COMPONENT;

	// reimplemented (ibase::IApplication)
	virtual bool InitializeApplication(int argc, char** argv);
	virtual int Execute(int argc, char** argv);
	virtual istd::CString GetHelpText() const;

private:
	I_REF(IFileConvertCopy, m_fileCopyCompPtr);
	I_ATTR(bool, m_needExplicitInputAttrPtr);
};


} // namespace ibase


#endif // !ibase_CCopyAppComp_included


