/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef ifpf_CFilePathesContainer_included
#define ifpf_CFilePathesContainer_included


// Qt includes
#include <QFileInfoList>

// ACF includes
#include "ibase/IFileListProvider.h"

#include "ifpf/ifpf.h"


namespace ifpf
{


class CFilePathesContainer: virtual public ibase::IFileListProvider
{
public:
	void ResetFiles();

	/**
		Insert a new file into the list.
	*/
	virtual bool InsertFile(const QString& file, int index = -1);

	// reimplemented (ibase::IFileListProvider)
	virtual QStringList GetFileList() const;

private:
	QFileInfoList m_fileList;
};


} // namespace ifpf


#endif //!ifpf_CFilePathesContainer_included


