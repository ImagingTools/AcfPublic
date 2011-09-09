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


#ifndef iqt_CBitmapLoaderComp_included
#define iqt_CBitmapLoaderComp_included


// Qt includes
#include <QDir>
#include <QStringList>


// ACF includes
#include "iser/IFileLoader.h"

#include "icomp/CComponentBase.h"

#include "ibase/TLoggerCompWrap.h"

#include "iqt/iqt.h"


namespace iqt
{


/**
	Bitmap loader component implementing interfaces \c iser::IFileLoader.
*/
class CBitmapLoaderComp:
			public QObject,
			public ibase::CLoggerComponentBase,
			virtual public iser::IFileLoader
{
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	enum MessageId
	{
		MI_BAD_EXTENSION = 0xa7d0,
		MI_FILE_NOT_EXIST,
		MI_BAD_FORMAT
	};

	I_BEGIN_COMPONENT(CBitmapLoaderComp);
		I_REGISTER_INTERFACE(iser::IFileTypeInfo);
		I_REGISTER_INTERFACE(iser::IFileLoader);
	I_END_COMPONENT;

	// reimplemented (iser::IFileLoader)
	virtual bool IsOperationSupported(
				const istd::IChangeable* dataObjectPtr,
				const istd::CString* filePathPtr = NULL,
				int flags = -1,
				bool beQuiet = true) const;
	virtual int LoadFromFile(istd::IChangeable& data, const istd::CString& filePath) const;
	virtual int SaveToFile(const istd::IChangeable& data, const istd::CString& filePath) const;

	// reimplemented (iser::IFileTypeInfo)
	virtual bool GetFileExtensions(istd::CStringList& result, int flags = -1, bool doAppend = false) const;
	virtual istd::CString GetTypeDescription(const istd::CString* extensionPtr = NULL) const;

protected:
	bool IsOperationSupportedIntern(
				const istd::IChangeable* dataObjectPtr,
				const istd::CString* filePathPtr,
				bool forLoading,
				bool forSaving,
				bool useLog) const;
};


} // namespace iqt


#endif // !iqt_CBitmapLoaderComp_included


