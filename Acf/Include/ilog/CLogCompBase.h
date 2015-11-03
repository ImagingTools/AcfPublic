/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef ilog_CLogCompBase_included
#define ilog_CLogCompBase_included


// Qt includes
#include <QtCore/QObject>

// ACF includes
#include "ilog/TMessageDelegatorComp.h"


namespace ilog
{


/**
	Basic implementation for logging using event queue for message transportation.

	\ingroup Logging
*/
class CLogCompBase:
			public QObject,
			public ilog::TMessageDelegatorComp<icomp::CComponentBase>
{
	Q_OBJECT
public:
	typedef ilog::TMessageDelegatorComp<icomp::CComponentBase> BaseClass;
	typedef QObject BaseClass2;

	I_BEGIN_BASE_COMPONENT(CLogCompBase);
	I_END_COMPONENT;

	CLogCompBase();

	// reimplemented (ilog::IMessageConsumer)
	virtual void AddMessage(const MessagePtr& messagePtr);

protected:
	virtual void WriteMessageToLog(const MessagePtr& messagePtr) = 0;

private Q_SLOTS:
	void OnAddMessage(const MessagePtr& messagePtr);

Q_SIGNALS:
	void EmitAddMessage(const MessagePtr& messagePtr);
};


} // namespace ilog


#endif // !ilog_CLogCompBase_included

