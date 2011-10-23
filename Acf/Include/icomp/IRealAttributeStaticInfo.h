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


#ifndef icomp_IRealAttributeStaticInfo_included
#define icomp_IRealAttributeStaticInfo_included


// STL includes
#include <string>


// ACF includes
#include "icomp/IAttributeStaticInfo.h"


namespace icomp
{


/**
	Interface adding to attribute static info functionality existing only for real attributes.
*/
class IRealAttributeStaticInfo: virtual public IAttributeStaticInfo
{
public:
	/**
		Get ID of this attribute.
	 */
	virtual const std::string& GetAttributeId() const = 0;
	/**
		Add related interface to this attribute info.
		\param	relatedInterfaceInfo	specify interface.
		\param	flags					set of flags defined in \c icomp::IAttributeStaticInfo::AttributeFlags.
	*/
	virtual void AddRelatedMetaId(int metaGroupId, const std::string& id, int flags) = 0;
};


} // namespace icomp


#endif // !icomp_IRealAttributeStaticInfo_included


