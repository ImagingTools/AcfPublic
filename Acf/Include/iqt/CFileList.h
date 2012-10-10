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


#ifndef iqt_CFileList_included
#define iqt_CFileList_included


#include "iqt/iqt.h"


#include <QtCore/QObject>
#include <QtCore/QStringList>
#include <QtCore/QDir>
 

namespace iqt
{


/**
	This class serves for creation of the list of files in a given root directory.
*/
class CFileList : public QObject, public QStringList
{
	Q_OBJECT

public:
	/**
		Constructs the empty object. 
		To create the file list you have to use the Create() function.
	*/
	CFileList(QObject* parent = 0);
	
	/**
		Creates the list of files in a root directory \c root. 
		Several filters can be applied to the \c root before call of this function. 
		So you can do a separate filtering of files and directories.
		\param	minRecursionDepth	minimal recursion depth.
		\param	maxRecursionDepth	maximal recursion depth, if negative no depth is specified.
	*/
	bool Create(const QDir& root,
				int minRecursionDepth = 0,
				int maxRecursionDepth = 0,
				const QStringList& nameFilters = QStringList(),  
				QDir::SortFlags sortSpec = QDir::Name | QDir::IgnoreCase);	

Q_SIGNALS:
	/**
		This signal is emitted whenever the file \c file has been processed.
	*/
	void currentFile(const QString& file);
};


} // namespace iqt


#endif // !iqt_CFileList_included


