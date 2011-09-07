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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef ifpf_IFileNaming_included
#define ifpf_IFileNaming_included


// ACF includes
#include "istd/IPolymorphic.h"


namespace ifpf
{


/**
	Interface for calculation of the new file path for an existing file.
*/
class IFileNaming: virtual public istd::IPolymorphic
{
public:
	/**
		Get the new file path for a given input file name.
		\sa isys::IFileSystem
	*/
	virtual istd::CString GetFilePath(const istd::CString& inputFileName) const = 0;
};


} // namespace ifpf


#endif // !ifpf_IFileNaming_included


