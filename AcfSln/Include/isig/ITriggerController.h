/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef isig_ITriggerController_included
#define isig_ITriggerController_included


// ACF includes
#include <istd/IPolymorphic.h>
#include <istd/ITimeStamp.h>
#include <istd/TDelPtr.h>

#include <iprm/IParamsSet.h>


namespace isig
{


class ITriggerController: virtual public istd::IPolymorphic
{
public:
	typedef istd::TDelPtr<istd::ITimeStamp> TimeStampPtr;

	/**
		Check, if software trigger is accepted and possible.
	*/
	virtual bool IsSoftwareTriggerActive() const = 0;

	/**
		Send software trigger to device.
		\param	timeStampPtr	optional pointer to time stamp object, if it is not \c NULL, will be filled with trigger time stamp.
	*/
	virtual bool SendSoftwareTrigger(TimeStampPtr* timeStampPtrPtr = NULL, const iprm::IParamsSet* paramsPtr = NULL) = 0;
};


} // namespace imeas


#endif // !isig_ITriggerController_included


