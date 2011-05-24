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


#ifndef ibase_CFileCopyOverLoaderComp_included
#define ibase_CFileCopyOverLoaderComp_included


#include "istd/IChangeable.h"

#include "iser/IFileLoader.h"

#include "icomp/CComponentBase.h"

#include "ibase/IFileConvertCopy.h"


namespace ibase
{


/**
	General file copy or transformation.
	This implementation uses general file loader, saver and any object instance.
*/
class CFileCopyOverLoaderComp:
			public icomp::CComponentBase,
			virtual public IFileConvertCopy
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CFileCopyOverLoaderComp);
		I_REGISTER_INTERFACE(IFileConvertCopy);

		I_ASSIGN(m_objectCompPtr, "Object", "Object used as representation of copied data", true, "Object");
		I_ASSIGN(m_inputLoaderCompPtr, "InputLoader", "input file loader", true, "InputLoader");
		I_ASSIGN(m_outputLoaderCompPtr, "OutputLoader", "output file loader", true, "OutputLoader");
	I_END_COMPONENT;

	// reimplemented (ibase::IFileConvertCopy)
	virtual bool CopyFile(
				const istd::CString& inputFilePath,
				const istd::CString& outputFilePath,
				const iprm::IParamsSet* paramsPtr = NULL) const;

private:
	I_REF(istd::IChangeable, m_objectCompPtr);
	I_REF(iser::IFileLoader, m_inputLoaderCompPtr);
	I_REF(iser::IFileLoader, m_outputLoaderCompPtr);
};


} // namespace ibase


#endif // !ibase_CFileCopyOverLoaderComp_included


