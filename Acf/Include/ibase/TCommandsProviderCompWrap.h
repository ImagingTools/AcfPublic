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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_TCommandsProviderCompWrap_included
#define ibase_TCommandsProviderCompWrap_included


#include "imod/TModelWrap.h"

#include "icomp/CComponentBase.h"

#include "ibase/ICommandsProvider.h"


namespace ibase
{


/**
	Generic macro for ICommandsProvider implementation.
*/
template <class Base>
class TCommandsProviderCompWrap:
			public Base,
			public imod::TModelWrap<ibase::ICommandsProvider>
{
public:
	typedef Base BaseClass;

	I_BEGIN_COMPONENT(TCommandsProviderCompWrap);
		I_REGISTER_INTERFACE(ibase::ICommandsProvider);
	I_END_COMPONENT;
};


} // namespace ibase


#endif // !ibase_TCommandsProviderCompWrap_included


