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


#ifndef ifileproc_IFileConvertCopy_included
#define ifileproc_IFileConvertCopy_included


#include "istd/IPolymorphic.h"


class QString;


namespace iprm
{
	class IParamsSet;
}


namespace ifileproc
{


/**
	Common interface for file copying.
*/
class IFileConvertCopy: virtual public istd::IPolymorphic
{
public:
	enum MessageId
	{
		/**
			Message ID if input path is invalid
		*/
		MI_INPUT_PATH = 0x5cd40,
		/**
			Message ID if output path is invalid
		*/
		MI_OUTPUT_PATH
	};

	/**
		Copy a file or files from \c inputPath to destination \c outputPath.
		Optionally, you can use \c paramsPtr to control the copy process.
	*/
	virtual bool ConvertFiles(
				const QString& inputPath,
				const QString& outputPath,
				const iprm::IParamsSet* paramsPtr = NULL) const = 0;
};


} // namespace ifileproc


#endif // !ifileproc_IFileConvertCopy_included


