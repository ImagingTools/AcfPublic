/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_CExternalFileConverterComp_included
#define ibase_CExternalFileConverterComp_included


#include "ibase/IProcessExecutor.h"
#include "ibase/IFileConvertCopy.h"
#include "ibase/TLoggerCompWrap.h"

#include "iprm/IFileNameParam.h"


namespace ibase
{


/**
	File converter, which uses an external programm to perform the convert action. 
*/
class CExternalFileConverterComp:
			public ibase::CLoggerComponentBase,
			virtual public IFileConvertCopy
{
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CExternalFileConverterComp);
		I_REGISTER_INTERFACE(IFileConvertCopy);
		I_ASSIGN(m_processExecuterCompPtr, "ProcessExecutor", "Process executor, that will be used for convert action", true, "ProcessExecutor");
		I_ASSIGN(m_processArgumentsAttrPtr, "ProcessArguments", "Application conversion arguments.\nUse $(Input) to specify the input and $(Output) for output file name", false, "$(Input) $(Output)");
		I_ASSIGN(m_executablePathCompPtr, "ExecutablePath", "Path to the application's binary", true, "ExecutablePath");
	I_END_COMPONENT;

	// reimplemented (ibase::IFileConvertCopy)
	virtual bool ConvertFile(
				const istd::CString& inputFilePath,
				const istd::CString& outputFilePath,
				const iprm::IParamsSet* paramsPtr = NULL) const;

private:
	I_REF(ibase::IProcessExecutor, m_processExecuterCompPtr);
	I_ATTR(istd::CString, m_processArgumentsAttrPtr);
	I_REF(iprm::IFileNameParam, m_executablePathCompPtr);
};


} // namespace ibase


#endif // !ibase_CExternalFileConverterComp_included


