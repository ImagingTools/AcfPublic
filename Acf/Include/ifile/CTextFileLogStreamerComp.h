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


#ifndef ifile_CTextFileLogStreamerComp_included
#define ifile_CTextFileLogStreamerComp_included


// Qt includes
#include <QtCore/QFile>
#include <QtCore/QTextStream>

// ACF includes
#include <ifile/IFileNameParam.h>
#include <ifile/IFilePersistence.h>
#include <ilog/CStreamLogCompBase.h>


namespace ifile
{


/**
	Message container displaying messages as log list.
*/
class CTextFileLogStreamerComp: 
			public ilog::CStreamLogCompBase,
			public ifile::IFilePersistence
{
public:
	typedef ilog::CStreamLogCompBase BaseClass;

	I_BEGIN_COMPONENT(CTextFileLogStreamerComp);
		I_REGISTER_INTERFACE(ifile::IFilePersistence);
		I_ASSIGN(m_isAppendAttrPtr, "AppendToExisting", "Don't overwrite existing log file", true, false);
	I_END_COMPONENT;

	CTextFileLogStreamerComp();

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

protected:
	// reimplemented (CStreamLogCompBase)
	virtual void WriteText(const QString& text, istd::IInformationProvider::InformationCategory category);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	bool OpenFileStream(const QString& filePath);
	void CloseFileStream();

private:
	I_ATTR(bool, m_isAppendAttrPtr);

	mutable QFile m_outputFile;
	mutable QTextStream m_outputFileStream;
};


} // namespace ifile


#endif // !ifile_CTextFileLogStreamerComp_included


