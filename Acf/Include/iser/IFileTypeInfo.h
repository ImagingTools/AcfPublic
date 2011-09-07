/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iser_IFileTypeInfo_included
#define iser_IFileTypeInfo_included


// ACF includes
#include "istd/IPolymorphic.h"
#include "istd/CString.h"


namespace iser
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
		QF_NO_LOADING = 1 << 0,
		/**
			No saving operation should be considered.
		*/
		QF_NO_SAVING = 1 << 1
	};

	/**
		Get file extensions supported by this loader
		\param	result		list of extensions, e.g. {"txt", "doc"}.
		\param	flags		set of flags \sa QueryFlags.
		\param	doAppend	if true, list of extensions should be appended to existing list.
	*/
	virtual bool GetFileExtensions(istd::CStringList& result, int flags = 0, bool doAppend = false) const = 0;

	/**
		Get description of object type associated with single extension.
	*/
	virtual istd::CString GetTypeDescription(const istd::CString* extensionPtr = NULL) const = 0;
};


} // namespace iser


#endif // !iser_IFileTypeInfo_included


