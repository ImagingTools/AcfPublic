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


#ifndef icomp_IRegistryLoader_included
#define icomp_IRegistryLoader_included


// Qt includes
#include <QtCore/QString>


// ACF includes
#include "istd/IPolymorphic.h"


namespace icomp
{


class IRegistry;


/**
	Interface for a ACF registry loader.
*/
class IRegistryLoader: virtual public istd::IPolymorphic
{
public:
	/**
		Get an ACF registry from a given file.
	*/
	virtual const icomp::IRegistry* GetRegistryFromFile(const QString& path) const = 0;
};
	

} // namespace icomp


#endif // !icomp_IRegistryLoader_included


