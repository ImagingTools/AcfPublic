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


#ifndef iproc_IProgressManager_included
#define iproc_IProgressManager_included


// STL includes
#include <string>

#include "istd/IPolymorphic.h"
#include "istd/CString.h"


namespace iproc
{


/**
	Consume information about progress of some process.
*/
class IProgressManager: virtual public istd::IPolymorphic
{
public:
	/**
		Begin progress report session.
		\return	session ID or negative value if failed.
	*/
	virtual int BeginProgressSession(
				const std::string& progressId,
				const istd::CString& description,
				bool isCancelable = false) = 0;
	/**
		Close progress report session.
		\param	sessionId	session ID returned by \c BeginProgressSession.
	*/
	virtual void EndProgressSession(int sessionId) = 0;
	/**
		Callback function for an progress event.
		\param	sessionId	session ID returned by \c BeginProgressSession.
	*/
	virtual void OnProgress(int sessionId, double currentProgress) = 0;

	/**
		Check if this processing operation should be canceled.
		\param	sessionId	session ID returned by \c BeginProgressSession.
	*/
	virtual bool IsCanceled(int sessionId) const = 0;
};


} // namespace iproc


#endif // !iproc_IProgressManager_included


