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


#ifndef icomp_IRealComponentStaticInfo_included
#define icomp_IRealComponentStaticInfo_included


#include "icomp/IComponentStaticInfo.h"


namespace icomp
{


/**
	Interface adding to component static info functionality existing only for real components.
	Real components are components which can be created in memory.
*/
class IRealComponentStaticInfo: virtual public IComponentStaticInfo
{
public:
	/**
		Create component instance.
		\return				pointer to created component or NULL if this component cannot be created.
	 */
	virtual IComponent* CreateComponent() const = 0;

	/**
		Extract instance implemented specified interface from some component.
	*/
	virtual void* GetComponentInterface(const std::string& interfaceName, IComponent& component) const = 0;
};


}//namespace icomp


#endif // !icomp_IRealComponentStaticInfo_included


