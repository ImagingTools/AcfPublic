/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef icmpstr_IRegistryPreview_included
#define icmpstr_IRegistryPreview_included


#include "istd/IChangeable.h"

#include "icomp/IRegistry.h"

#include "icmpstr/icmpstr.h"


namespace icmpstr
{


class IRegistryPreview: virtual public istd::IChangeable
{
public:
	/**
		Start registry execution.
	*/
	virtual bool StartRegistry(const icomp::IRegistry& registry) = 0;

	/**
		Returns \c true if the registry \c registry is executing.
	*/
	virtual bool IsRunning() const = 0;

	/**
		Abort registry execution.
	*/
	virtual void AbortRegistry() = 0;
};


} // namespace icmpstr


#endif // !icmpstr_IRegistryPreview_included

