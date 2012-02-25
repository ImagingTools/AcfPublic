/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iauth_CStaticRightsProviderComp_included
#define iauth_CStaticRightsProviderComp_included


// STL includes
#include <set>
#include <string>

// ACF includes
#include "icomp/CComponentBase.h"

// ACF-Solutions includes
#include "iauth/IRightsProvider.h"


namespace iauth
{


class CStaticRightsProviderComp:
			public icomp::CComponentBase,
			public IRightsProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CStaticRightsProviderComp);
		I_REGISTER_INTERFACE(IRightsProvider);
		I_ASSIGN(m_slaveProviderIfPtr, "SlaveProvider", "Slave rights provider", false, "SlaveProvider");
		I_ASSIGN(m_defaultRightAttrPtr, "DefaultRight", "Default rights enabled", false, false);
		I_ASSIGN_MULTI_0(m_rightsOnAttrPtr, "RightsOn", "List of enabled rights", false);
		I_ASSIGN_MULTI_0(m_rightsOffAttrPtr, "RightsOff", "List of disabled rights", false);
	I_END_COMPONENT;

	// reimeplemented (IRightsProvider)
	virtual bool HasRight(
					const std::string& operationId,
					bool beQuiet = false) const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(IRightsProvider, m_slaveProviderIfPtr);
	I_ATTR(bool, m_defaultRightAttrPtr);
	I_MULTIATTR(QString, m_rightsOnAttrPtr);
	I_MULTIATTR(QString, m_rightsOffAttrPtr);

	typedef std::set<std::string> RightsList;

	RightsList m_rightsOn;
	RightsList m_rightsOff;
};



} // namespace iauth



#endif // !iauth_CStaticRightsProviderComp_included



