/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef iwin_CTimeStampCacheComp_included
#define iwin_CTimeStampCacheComp_included


// ACF includes
#include "icomp/CComponentBase.h"

// ACF-Solutions includes
#include "iinsp/ITimeStampProvider.h"

// IACF includes
#include "iwin/CPerformanceTimeStamp.h"


namespace iwin
{


/**
	Time stamp provider returning always stored time stamp.
	Stored time stamp can be changed only copying their from another time stamp provider using CopyFrom method.
	This object will be used to manage threading barrier for object supplier chain.
*/
class CTimeStampCacheComp:
			public icomp::CComponentBase,
			virtual public iinsp::ITimeStampProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CTimeStampCacheComp);
		I_REGISTER_INTERFACE(iinsp::ITimeStampProvider);
	I_END_COMPONENT;

	// reimplemented (iinsp::ITimeStampProvider)
	virtual const istd::ITimeStamp* GetCurrentTimeStamp() const;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);

private:
	bool m_isTimerValid;
	iwin::CPerformanceTimeStamp m_timer;
};


} // namespace iwin


#endif // !iwin_CTimeStampCacheComp_included


