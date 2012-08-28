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


#ifndef iqt_CSystem_included
#define iqt_CSystem_included


// Qt includes
#include <QtCore/QString>
#include <QtCore/QMap>
#include <QtCore/QDir>

namespace iqt
{


/**
	Implementation of global system helpers based on QT.
 */
class CSystem
{
public:
	typedef QMap<QString, QString> EnvironmentVariables;

	// static members
	/**
		Get normalized path with enrolled system variables.
	 */
	static QString GetNormalizedPath(const QString& path);
	/**
		Get value of system variables.
	 */
	static QString FindVariableValue(const QString& varName);
	/**
		Get path with enrolled system variables.
	 */
	static QString GetEnrolledPath(const QString& path);

	/** 
		Evaluate a (possibly relative) path containing environment variables to an absolute path
	 */
	static QString GetAbsolutePath(const QString& filePath, QDir baseDir);

	static EnvironmentVariables GetEnvironmentVariables();
	/**
		Sleep current thread.
	 */
	static void Sleep(double seconds);

	/**
		Remove a given directory with all contents.
	 */
	static bool RemoveDirectory(const QString& directoryPath);
};


} // namespace iqt


#endif // !iqt_CSystem_included


