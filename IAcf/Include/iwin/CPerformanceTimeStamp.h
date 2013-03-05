/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#ifndef iwin_CPerformanceTimeStamp_included
#define iwin_CPerformanceTimeStamp_included


// ACF includes
#include "istd/ITimeStamp.h"


namespace iwin
{


/**
	High perfomance time stamp implementation.

	\ingroup Windows
*/
class CPerformanceTimeStamp: virtual public istd::ITimeStamp
{
public:
	CPerformanceTimeStamp();

	bool IsVaild() const;

	double GetTimeTo(const CPerformanceTimeStamp& timeStamp) const;

	quint64 GetNativeRepresentation() const;
	void SetNativeRepresentation(quint64 value);

	// reimplemented (istd::ITimeStamp)
	virtual void Start(double elapsedTime = 0);
	virtual QDateTime GetStartTime() const;
	virtual double GetElapsed() const;
	virtual double GetTimeTo(const istd::ITimeStamp& timeStamp) const;
	virtual void WaitTo(double time) const;
	virtual double GetTimerResolution() const;

	// reimplemented (istd::IChangeable)
	virtual int GetSupportedOperations() const;
	virtual bool CopyFrom(const istd::IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);

private:
	qint64 m_startCounter;

	// static attributes
	static qint64 s_timerFrequence;
	static bool s_isTimerFrequenceValid;
};


// inline methods

} // namespace iwin


#endif // !iwin_CPerformanceTimeStamp_included
