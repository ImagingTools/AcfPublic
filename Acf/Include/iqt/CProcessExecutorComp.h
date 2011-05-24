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


#ifndef iqt_CProcessExecutorComp_included
#define iqt_CProcessExecutorComp_included


// Qt includes
#include <QObject>
#include <QProcess>
#include <QMutex>


// ACF includes
#include "ibase/IProcessExecutor.h"
#include "ibase/TLoggerCompWrap.h"

#include "iqt/iqt.h"


namespace iqt
{


/**
	Component for execution of an external application.
*/
class CProcessExecutorComp:
			public QObject,
			public ibase::CLoggerComponentBase,
			virtual public ibase::IProcessExecutor
{
	Q_OBJECT
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CProcessExecutorComp);
		I_REGISTER_INTERFACE(ibase::IProcessExecutor);
	I_END_COMPONENT;

	CProcessExecutorComp();

	// reimplemented (ibase::IProcessExecutor)
	virtual void SetEnvironment(const isys::IApplicationEnvironment& processEnvironment);

	virtual int Execute(const istd::CString& executablePath, const istd::CStringList& processArguments);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentDestroyed();

protected Q_SLOTS:
	void OnError(QProcess::ProcessError error);
	void OnReadyReadStandardError();
	void OnReadyReadStandardOutput();

private:
	QProcess m_applicationProcess;
	QMutex m_lock;

	bool m_isFailed;
};


} // namespace iqt


#endif // !iqt_CProcessExecutorComp_included


