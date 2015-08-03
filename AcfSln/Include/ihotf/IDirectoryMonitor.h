/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef ihotf_IDirectoryMonitor_included
#define ihotf_IDirectoryMonitor_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include "iprm/IParamsSet.h"


namespace ihotf
{


/**
	Interface for a folder monitor.
	Observers of this interface are notified about all changes made in the monitored directory, 
	such as removing or adding files, changes in file contents or file attributes.
*/
class IDirectoryMonitor: virtual public istd::IPolymorphic
{
public:
	/**
		Checks if the folder monitoring is active.
	*/
	virtual bool IsRunning() const = 0;

	/**
		Start observing process.
		If the \c paramsSetPtr is not equal NULL, the observing parameter are get from this params set,
		otherwise, default parameters are using.
	*/
	virtual bool StartObserving(const iprm::IParamsSet* paramsSetPtr = NULL) = 0;

	/**
		Stop observing process.
	*/
	virtual void StopObserving() = 0;
};


} // namespace ihotf


#endif // !ihotf_IDirectoryMonitor_included


