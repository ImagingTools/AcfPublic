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


#ifndef ibase_IFileConvertCopy_included
#define ibase_IFileConvertCopy_included


#include "istd/IPolymorphic.h"


namespace istd
{
	class CString;
}


namespace iprm
{
	class IParamsSet;
}


namespace ibase
{


/**
	Common interface for copy a file.
*/
class IFileConvertCopy: virtual public istd::IPolymorphic
{
public:
	/**
		Copy a file \c inputFilePath to destination \c outputFilePath. Optionally, you can use \c paramsPtr to control the copy process.
	*/
	virtual bool ConvertFile(
				const istd::CString& inputFilePath,
				const istd::CString& outputFilePath,
				const iprm::IParamsSet* paramsPtr = NULL) const = 0;
};


} // namespace ibase


#endif // !ibase_IFileConvertCopy_included


