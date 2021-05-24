/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iprm_CIdParamComp_included
#define iprm_CIdParamComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <iprm/CIdParam.h>


namespace iprm
{


/**
	Component for automatic creation of the Universally Unique Identifier (UUID)
*/
class CIdParamComp:
			public icomp::CComponentBase,
			public iprm::CIdParam
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef iprm::CIdParam BaseClass2;

	I_BEGIN_COMPONENT(CIdParamComp);
		I_REGISTER_INTERFACE(iprm::IIdParam);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_ASSIGN(m_defaultIdAttrPtr, "DefaultId", "Default ID", false, "");
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(QByteArray, m_defaultIdAttrPtr);
};


} // namespace iprm


#endif // !iprm_CIdParamComp_included


