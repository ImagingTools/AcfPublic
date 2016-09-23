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


#ifndef ifileproc_IFileNamingParams_included
#define ifileproc_IFileNamingParams_included


// ACF includes
#include <iser/ISerializable.h>


namespace ifileproc
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
	enum OverwriteStrategy
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
		Get used strategy for possible overwriting of existing files.
		\sa OverwriteStrategy
	*/
	virtual OverwriteStrategy GetOverwriteStrategy() const = 0;

	/**
		Set renaming mode.
		\sa OverwriteStrategy
	*/
	virtual void SetOverwriteStrategy(OverwriteStrategy overwriteStrategy) = 0;

	/**
		Get prefix of the file
	*/
	virtual QString GetPrefix() const = 0;

	/**
		Set prefix of the file
	*/
	virtual void SetPrefix(const QString& prefix) = 0;

	/**
		Set suffix of the file
	*/
	virtual QString GetSuffix() const = 0;

	/**
		Get suffix of the file
	*/
	virtual void SetSuffix(const QString& suffix) = 0;

	/**
		Get list of text patterns, that must be removed from the output file name.
		\sa SetPatternsToRemove
	*/
	virtual QStringList GetPatternsToRemove() const = 0;
	
	/**
		Set list of text patterns, that must be removed from the output file name.
		For example, the file name \c foo_some.txt will be transformed into \c foo.txt if \c _some pattern is set.
		\sa GetPatternsToRemove
	*/
	virtual void SetPatternsToRemove(const QStringList& patternsToRemove) = 0;
};


} // namespace ifileproc


#endif // !ifileproc_IFileNamingParams_included


