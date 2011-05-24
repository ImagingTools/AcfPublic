/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtfpf_CFileNamingComp_included
#define iqtfpf_CFileNamingComp_included


// ACF includes
#include "iser/IFileLoader.h"

#include "ibase/TLoggerCompWrap.h"

#include "iprm/IFileNameParam.h"


// AcfSln includes
#include "ifpf/IFileNaming.h"
#include "ifpf/IFileNamingParams.h"


namespace iqtfpf
{


/**
	Component for calculating of the new file name.
	\sa ifpf::IFileNaming
*/
class CFileNamingComp:
			public ibase::CLoggerComponentBase,
			virtual public ifpf::IFileNaming
{
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CFileNamingComp);
		I_REGISTER_INTERFACE(ifpf::IFileNaming);
		I_ASSIGN(m_fileTypeInfoCompPtr, "OutputFileInfo", "Output file info, which will be used for file name calculation", false, "OutputFileInfo");
		I_ASSIGN(m_directoryPathCompPtr, "DirectoryPath", "Output directory", true, "DirectoryPath"); 
		I_ASSIGN(m_fileNamingParamsCompPtr, "FileNamingParams", "Rules for the file naming", false, "FileNamingParams"); 
	I_END_COMPONENT();

	// reimplemented (ifpf::IFileNaming)
	virtual istd::CString GetFilePath(const istd::CString& inputFileName) const;

private:
	I_REF(iser::IFileTypeInfo, m_fileTypeInfoCompPtr);
	I_REF(iprm::IFileNameParam, m_directoryPathCompPtr);
	I_REF(ifpf::IFileNamingParams, m_fileNamingParamsCompPtr);
};


} // namespace iqtfpf


#endif // !iqtfpf_CFileNamingComp_included

