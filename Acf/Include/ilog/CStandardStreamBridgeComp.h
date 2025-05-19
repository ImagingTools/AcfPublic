/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef ilog_CStandardStreamBridgeComp_included
#define ilog_CStandardStreamBridgeComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <ilog/CStandardStreamBridge.h>


namespace ilog
{


/**
	\ingroup Logging
*/
class CStandardStreamBridgeComp:public icomp::CComponentBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CStandardStreamBridgeComp);
		I_ASSIGN(m_slaveMessageConsumerCompPtr, "SlaveMessageConsumer", "Slave message consumer", false, "SlaveMessageConsumer");
	I_END_COMPONENT;


protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed() override;

private:
	istd::TDelPtr<CStandardStreamBridge> m_coutBridgePtr;
	istd::TDelPtr<CStandardStreamBridge> m_cerrBridgePtr;

	I_REF(ilog::IMessageConsumer, m_slaveMessageConsumerCompPtr);
};


} // namespace ilog


#endif // !ilog_CStandardStreamBridgeComp_included

