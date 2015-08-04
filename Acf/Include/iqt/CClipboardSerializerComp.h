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


#ifndef iqt_CClipboardSerializerComp_included
#define iqt_CClipboardSerializerComp_included


// ACF includes
#include "iser/IVersionInfo.h"
#include "ifile/IFilePersistence.h"
#include "ilog/TLoggerCompWrap.h"
#include "iqt/iqt.h"


namespace iqt
{


/**
	A clipboard serializer component.

	\ingroup Persistence
*/
class CClipboardSerializerComp:
			public ilog::CLoggerComponentBase,
			virtual public ifile::IFilePersistence
{
public:
	typedef ilog::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CClipboardSerializerComp);
		I_REGISTER_INTERFACE(ifile::IFilePersistence);
		I_ASSIGN(m_versionInfoCompPtr, "VersionInfo", "Provide information about archive versions", false, "VersionInfo");
		I_ASSIGN(m_mimeTypeAttrPtr, "MimeType", "Describe clipboard type", true, "acf/generic");
	I_END_COMPONENT;

	// reimplemented (ifile::IFilePersistence)
	virtual bool IsOperationSupported(
				const istd::IChangeable* dataObjectPtr,
				const QString* filePathPtr = NULL,
				int flags = -1,
				bool beQuiet = true) const;
	virtual int LoadFromFile(
				istd::IChangeable& data,
				const QString& filePath = QString(),
				ibase::IProgressManager* progressManagerPtr = NULL) const;
	virtual int SaveToFile(
				const istd::IChangeable& data,
				const QString& filePath = QString(),
				ibase::IProgressManager* progressManagerPtr = NULL) const;

	// reimplemented (ifile::IFileTypeInfo)
	virtual bool GetFileExtensions(QStringList& result, const istd::IChangeable* dataObjectPtr = NULL, int flags = -1, bool doAppend = false) const;
	virtual QString GetTypeDescription(const QString* extensionPtr = NULL) const;

private:
	I_REF(iser::IVersionInfo, m_versionInfoCompPtr);
	I_ATTR(QString, m_mimeTypeAttrPtr);
};



} // namespace iqt


#endif // !iqt_CClipboardSerializerComp_included


