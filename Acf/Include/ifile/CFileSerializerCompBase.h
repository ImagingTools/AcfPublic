/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#pragma once


// Qt includes
#include <QtCore/QObject>
#include <QtCore/QStringList>
#include <QtCore/QFileInfo>

// ACF includes
#include <ilog/TLoggerCompWrap.h>
#include <ifile/IFilePersistence.h>
#include <ifile/CFileTypeInfoComp.h>


namespace ifile
{


/**
	Base implementation of file serializer.
	Serializer allows to load and save objects implementing iser::ISerializable interface.

	\ingroup Persistence
*/
class CFileSerializerCompBase:
			public ilog::TLoggerCompWrap<CFileTypeInfoComp>,
			virtual public ifile::IFilePersistence
{
public:	
	typedef ilog::TLoggerCompWrap<CFileTypeInfoComp> BaseClass;

	I_BEGIN_BASE_COMPONENT(CFileSerializerCompBase);
		I_REGISTER_INTERFACE(ifile::IFileTypeInfo);
		I_REGISTER_INTERFACE(ifile::IFilePersistence);
		I_ASSIGN(m_beQuiteOnLoadAttrPtr, "BeQuiteOnLoad", "Do not log message when loading if file is missing", true, false);
		I_ASSIGN(m_versionInfoCompPtr, "VersionInfo", "Provide information about archive versions", false, "VersionInfo");
	I_END_COMPONENT;

	// reimplemented (ifile::IFilePersistence)
	virtual bool IsOperationSupported(
				const istd::IChangeable* dataObjectPtr,
				const QString* filePathPtr = nullptr,
				int flags = -1,
				bool beQuiet = true) const override;

protected:
	/**
		Get working version info.
	*/
	virtual const iser::IVersionInfo* GetVersionInfo() const;

	/**
		Check if the minimal version of some serializable object is supported by version info.
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

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;

protected:
	I_ATTR(bool, m_beQuiteOnLoadAttrPtr);

private:
	I_REF(iser::IVersionInfo, m_versionInfoCompPtr);
};


} // namespace ifile


