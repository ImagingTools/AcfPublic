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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_CFileSerializerCompBase_included
#define ibase_CFileSerializerCompBase_included


// Qt includes
#include <QtCore/QObject>
#include <QtCore/QStringList>
#include <QtCore/QFileInfo>

// ACF includes
#include "iser/IFileLoader.h"

#include "ibase/TLoggerCompWrap.h"
#include "ibase/CFileTypeInfoComp.h"


namespace ibase
{


/**
	Base implementation of file serializer.
	Serializer allows to load and save objects implementing iser::ISerializable interface.
*/
class CFileSerializerCompBase:
			public ibase::TLoggerCompWrap<CFileTypeInfoComp>,
			virtual public iser::IFileLoader
{
public:	
	typedef ibase::TLoggerCompWrap<CFileTypeInfoComp> BaseClass;

	enum MessageId
	{
		MI_BAD_EXTENSION = 0xac10,
		MI_UNSUPPORTED_VERSION
	};

	I_BEGIN_BASE_COMPONENT(CFileSerializerCompBase);
		I_REGISTER_INTERFACE(iser::IFileTypeInfo);
		I_REGISTER_INTERFACE(iser::IFileLoader);
		I_ASSIGN(m_versionInfoCompPtr, "VersionInfo", "Provide information about archive versions", false, "VersionInfo");
	I_END_COMPONENT;

	// reimplemented (iser::IFileLoader)
	virtual bool IsOperationSupported(
				const istd::IChangeable* dataObjectPtr,
				const QString* filePathPtr = NULL,
				int flags = -1,
				bool beQuiet = true) const;

protected:
	/**
		Get working version info.
	*/
	virtual const iser::IVersionInfo* GetVersionInfo() const;

	/**
		Check if minimal version of some serializable object is supported by version info.
	*/
	bool CheckMinimalVersion(const iser::ISerializable& object, const iser::IVersionInfo& versionInfo) const;

	/**
		Check if input file is OK.
	*/
	bool CheckInputFile(const QString filePath, bool beQuiet = true) const;

	/**
		Check if output file is OK.
	*/
	bool CheckOutputFile(const QString filePath, bool beQuiet = true) const;

private:
	I_REF(iser::IVersionInfo, m_versionInfoCompPtr);
};


} // namespace ibase


#endif // !ibase_CFileSerializerCompBase_included


