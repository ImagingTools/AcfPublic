/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef ifileproc_IFileNaming_included
#define ifileproc_IFileNaming_included


// ACF includes
#include <istd/IPolymorphic.h>


namespace ifileproc
{


class IFileNamingParams;


/**
	Interface for calculation of the new file path for an existing file.
*/
class IFileNaming: virtual public istd::IPolymorphic
{
public:
	/**
		Calculate the new file path for a given input file name.
	*/
	virtual QString CalculateFileName(
				const QString& inputFileName,
				const QString& outputDirectoryPath,
				const ifileproc::IFileNamingParams* fileNamingParamsPtr) const = 0;
};


} // namespace ifileproc


#endif // !ifileproc_IFileNaming_included


