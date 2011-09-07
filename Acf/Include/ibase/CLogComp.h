/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_CLogComp_included
#define ibase_CLogComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "ibase/IMessageContainer.h"
#include "ibase/TMessageContainerWrap.h"

#include "ibase/CMessage.h"


namespace ibase
{


/**
	Data model of logging component.
*/
class CLogComp:
	public icomp::CComponentBase,
	public ibase::CMessageContainer
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef ibase::CMessageContainer BaseClass2;

	I_BEGIN_COMPONENT(CLogComp);
		I_REGISTER_INTERFACE(ibase::IMessageConsumer);
		I_REGISTER_INTERFACE(ibase::IMessageContainer);
		I_ASSIGN(m_maxMessageCountAttrPtr, "MaxMessageCount", "Maximal number of messages", false, 1000);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(int, m_maxMessageCountAttrPtr);
};


} // namespace ibase


#endif // !ibase_CLogComp_included

