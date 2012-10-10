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


#ifndef imebase_CChannelAddressParamComp_included
#define imebase_CChannelAddressParamComp_included


#include "icomp/CComponentBase.h"

#include "IMeilhausAccess.h"
#include "CChannelSelectionNode.h"


namespace imebase
{


class CChannelAddressParamComp: public icomp::CComponentBase, public CChannelSelectionNode
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CChannelAddressParamComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(iprm::ISelectionParam);
		I_ASSIGN(m_mailhausAccessCompPtr, "MeilhausAccess", "Allows to read set of possible options based on connected Me hardware", true, "MeilhausAccess");
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(IMeilhausAccess, m_mailhausAccessCompPtr);
};

	
} // namespace imebase


#endif // !imebase_CChannelAddressParamComp_included


