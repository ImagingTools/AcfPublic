/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef ifile_IFileTypeInfo_included
#define ifile_IFileTypeInfo_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include "istd/IPolymorphic.h"
#include "istd/IChangeable.h"


namespace ifile
{


/**
	Provide loading and saving of objects.

	\ingroup Persistence
*/
class IFileTypeInfo: virtual public istd::IPolymorphic
{
public:
	/**
		Describe detailed options of query.
	*/
	enum QueryFlags
	{
		/**
			No loading operation should be considered.
		*/
		QF_SAVE = 1 << 0,
		/**
			No saving operation should be considered.
		*/
		QF_LOAD = 1 << 1,
		/**
			Operations with specified file name should be considered.
		*/
		QF_FILE = 1 << 2,

		/**
			Operations with specified directory name should be considered.
		*/
		QF_DIRECTORY = 1 << 3,

		/**
			Operations without specified path (anonymous) should be considered.
		*/
		QF_ANONYMOUS = 1 << 4
	};

	/**
		Get file extensions supported by this loader
		\param	result			list of extensions, e.g. {"txt", "doc"}.
		\param	dataObjectPtr	optional pointer to data object for which all possible extensions are requested.
								It can be NULL if any object is meant.
		\param	flags			set of flags \sa QueryFlags.
		\param	doAppend		if true, list of extensions should be appended to existing list.
	*/
	virtual bool GetFileExtensions(QStringList& result, const istd::IChangeable* dataObjectPtr = NULL, int flags = -1, bool doAppend = false) const = 0;

	/**
		Get description of object type associated with single extension.
	*/
	virtual QString GetTypeDescription(const QString* extensionPtr = NULL) const = 0;
};


} // namespace ifile


#endif // !ifile_IFileTypeInfo_included


