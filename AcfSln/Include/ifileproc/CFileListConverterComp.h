/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef ifileproc_CFileListConverterComp_included
#define ifileproc_CFileListConverterComp_included


// ACF includes
#include "istd/TPointerVector.h"
#include "iproc/TSyncProcessorCompBase.h"
#include "ifile/IFileListProvider.h"
#include "ibase/IFileConvertCopy.h"

// ACF-Solutions includes
#include "ifileproc/IFileNaming.h"


namespace ifileproc
{


class CFileListConverterComp: public iproc::CSyncProcessorCompBase
{
public:
	typedef iproc::CSyncProcessorCompBase BaseClass;

	I_BEGIN_COMPONENT(CFileListConverterComp);
		I_ASSIGN(m_fileConvertCompPtr, "FileCopy", "File conversion component used for execution. If not set, the files will be only copied", false, "FileCopy");
		I_ASSIGN(m_outputFileNameCompPtr, "OutputFileNaming", "File naming component for the processing output", true, "OutputFileNaming");
		I_ASSIGN(m_inputFilesRemovingEnabledAttrPtr, "InputFilesRemovingEnabled", "If set, the input files will be removed from the file system", true, false);
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

private:
	I_REF(ibase::IFileConvertCopy, m_fileConvertCompPtr);
	I_REF(IFileNaming, m_outputFileNameCompPtr);
	I_ATTR(bool, m_inputFilesRemovingEnabledAttrPtr);
};


} // namespace ifileproc


#endif // !ifileproc_CFileListConverterComp_included


