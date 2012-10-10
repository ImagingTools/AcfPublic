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


#ifndef icomp_TMakeComponentWrap_included
#define icomp_TMakeComponentWrap_included


// ACF includes
#include "icomp/CComponentBase.h"


namespace icomp
{


/**
	Simple wrapper making component from non-component class.

	\ingroup ComponentConcept
	\ingroup Helpers
*/
template <	class Base,
			typename Interface1 = void,
			typename Interface2 = void,
			typename Interface3 = void,
			typename Interface4 = void,
			typename Interface5 = void,
			typename Interface6 = void,
			typename Interface7 = void,
			typename Interface8 = void,
			typename Interface9 = void,
			typename Interface10 = void>
class TMakeComponentWrap: public icomp::CComponentBase, public Base
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef Base BaseClass2;

	I_BEGIN_COMPONENT(TMakeComponentWrap);
		I_REGISTER_INTERFACE(Interface1);
		I_REGISTER_INTERFACE(Interface2);
		I_REGISTER_INTERFACE(Interface3);
		I_REGISTER_INTERFACE(Interface4);
		I_REGISTER_INTERFACE(Interface5);
		I_REGISTER_INTERFACE(Interface6);
		I_REGISTER_INTERFACE(Interface7);
		I_REGISTER_INTERFACE(Interface8);
		I_REGISTER_INTERFACE(Interface9);
		I_REGISTER_INTERFACE(Interface10);
	I_END_COMPONENT;
};


} // namespace icomp


#endif // !icomp_TMakeComponentWrap_included


