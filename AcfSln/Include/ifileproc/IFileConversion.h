/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


// Qt includes
#include <QtCore/QString>

// ACF includes
#include "iprm/IParamsSet.h"
#include "ibase/IProgressManager.h"
#include "iproc/IProcessor.h"


namespace ifileproc
{


/**
	General interface for conversion of files.
*/
class IFileConversion: virtual public istd::IPolymorphic
{
public:
	/**
		Types of messages which can be produced during execution of ConvertFiles method.
	*/
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

		\param inputPath	Path to the input file or directory.
		\param outputPath	Path to the output file or directory.
		\param paramsPtr	File conversion parameters
		\param progressManagerPtr	Progress manager used for getting information about file conversion progress state and canceling.

		\return Status of conversion operation. \sa iproc::IProcessor::ProcessorState
	*/
	virtual int ConvertFiles(
				const QString& inputPath,
				const QString& outputPath,
				const iprm::IParamsSet* paramsPtr = NULL,
				ibase::IProgressManager* progressManagerPtr = NULL) const = 0;
};


} // namespace ifileproc


#endif // !ifileproc_IFileConvertCopy_included


