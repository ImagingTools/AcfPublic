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


#ifndef ifpf_IFileNamingParams_included
#define ifpf_IFileNamingParams_included


// ACF includes
#include "iser/ISerializable.h"


namespace ifpf
{


/**
	Interface for calculation parameters of the new file name for any file item.
	\sa IFileNaming
*/
class IFileNamingParams: virtual public iser::ISerializable
{
public:

	/**
		Strategy mode
	*/
	enum RenamingMode
	{
		/**
			Output file name is equals the input file name.
		*/
		RM_OVERWRITE,

		/**
			Output file name will be automatic numbered if the file already exists.
		*/
		RM_NUMBERING
	};

	/**
		Get current renaming mode.
		\sa RenamingMode
	*/
	virtual int GetRenamingMode() const = 0;

	/**
		Set renaming mode.
		\sa RenamingMode
	*/
	virtual void SetRenamingMode(int renamingMode) = 0;

	/**
		Get prefix of the file
	*/
	virtual istd::CString GetPrefix() const = 0;

	/**
		Set prefix of the file
	*/
	virtual void SetPrefix(const istd::CString& prefix) = 0;

	/**
		Set suffix of the file
	*/
	virtual istd::CString GetSuffix() const = 0;

	/**
		Get suffix of the file
	*/
	virtual void SetSuffix(const istd::CString& suffix) = 0;
};


} // namespace ifpf


#endif // !ifpf_IFileNamingParams_included


