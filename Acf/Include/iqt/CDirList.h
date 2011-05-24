/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt_CDirList_included
#define iqt_CDirList_included


#include "iqt/iqt.h"


#include <QObject>
#include <QStringList>
#include <QDir>
 

namespace iqt
{


/**
	This class serves for creation of the list of directories in a given root directory.
*/
class CDirList : public QObject, public QStringList
{
	Q_OBJECT

public:
	/**
		Constructs an empty list of directories.
	*/
	CDirList(QObject* parent = 0);

	/**
		Constructs a list of directories in a given root directory \c root.
		All filters which are installed in \c root, are applied.
		\sa Create()
		\param	minRecursionDepth	minimal recursion depth. If it is 0, root will be included.
		\param	maxRecursionDepth	maximal recursion depth, if negative no depth is specified.
	*/
	CDirList(	QObject* parent,
				const QDir& root,
				int minRecursionDepth = 0,
				int maxRecursionDepth = 0);

	/**
		\overload
		Several filters can be applied to the QDir object before call of this function.
		\param	minRecursionDepth	minimal recursion depth. If it is 0, root will be included.
		\param	maxRecursionDepth	maximal recursion depth, if negative no depth is specified.
	*/
	bool Create(const QDir& root,
				int minRecursionDepth = 0,
				int maxRecursionDepth = 0,
				bool doAppend = false);

signals:
	/**
		This signal is emitted whenever the directory \c dir has been processed.
	*/
	void currentDir(const QString& dir);

protected:
	void DoSearch(
				const QDir& root,
				int minRecursionDepth,
				int maxRecursionDepth);
};


} // namespace iqt


#endif // !iqt_CDirList_included


