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


#ifndef ifpf_IMonitoringSession_included
#define ifpf_IMonitoringSession_included


// ACF includes
#include "istd/IChangeable.h"
#include "istd/CString.h"

#include "isys/CFileInfo.h"

#include "iser/ISerializable.h"


namespace ifpf
{


/**
	Common interface for a monitoring session for a directory.
	Each directory monitor can persist its monitoring state in a monitoring session, which is provided by IMonitoringSessionManager.
	\sa IMonitoringSessionManager
*/
class IMonitoringSession: virtual public iser::ISerializable
{
public:
	typedef std::vector<isys::CFileInfo> FileItems;

	/**
		Get the list of file items.
	*/
	virtual const FileItems& GetFileInfoList() const = 0;

	/**
		Set the file list.
	*/
	virtual void SetFileInfoList(const FileItems& fileList) = 0;
};


} // namespace ifpf


#endif // !ifpf_IMonitoringSession_included


