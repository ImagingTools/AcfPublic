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


#ifndef icomp_IComponentInterfaceExtractor_included
#define icomp_IComponentInterfaceExtractor_included


// ACF includes
#include "istd/IPolymorphic.h"
#include "istd/CClassInfo.h"


namespace icomp
{


class IComponent;


/**
	Provide extracting of some interface from component.
*/
class IComponentInterfaceExtractor: virtual public istd::IPolymorphic
{
public:
	/**
		Extract instance implemented specified interface from some component.
	*/
	virtual void* GetComponentInterface(
				const istd::CClassInfo& interfaceType,
				IComponent& component,
				const QByteArray& subId) const = 0;
};


} // namespace icomp


#endif // !icomp_IComponentInterfaceExtractor_included


