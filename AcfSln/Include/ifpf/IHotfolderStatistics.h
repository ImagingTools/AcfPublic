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


#ifndef ifpf_IHotfolderStatistics_included
#define ifpf_IHotfolderStatistics_included


// ACF includes
#include "iser/ISerializable.h"


namespace ifpf
{


/**
	Interface for a simple static of the hotfolder processing.
*/
class IHotfolderStatistics: virtual public iser::ISerializable
{
public:
	virtual int GetItemsCount(const istd::CString& directoryPath = istd::CString()) const = 0;
	virtual int GetSuccessCount(const istd::CString& directoryPath = istd::CString()) const = 0;
	virtual int GetErrorsCount(const istd::CString& directoryPath = istd::CString()) const = 0;
	virtual int GetAbortedCount(const istd::CString& directoryPath = istd::CString()) const = 0;
	virtual double GetProcessingTime(const istd::CString& directoryPath = istd::CString()) const = 0;
};


} // namespace ifpf


#endif // !ifpf_IHotfolderStatistics_included


