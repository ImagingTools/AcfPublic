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


#ifndef iprm_CNameParamComp_included
#define iprm_CNameParamComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "iprm/CNameParam.h"


namespace iprm
{


/**
	Component for automatic creation of the Universally Unique Identifier (UUID)
*/
class CNameParamComp:
			public icomp::CComponentBase,
			public iprm::CNameParam
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef iprm::CNameParam BaseClass2;

	I_BEGIN_COMPONENT(CNameParamComp);
		I_REGISTER_INTERFACE(iprm::INameParam);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_ASSIGN(m_defaultNameAttrPtr, "DefaultName", "Default name", false, "");
		I_ASSIGN(m_isNameFixedAttrPtr, "IsNameFixed", "When enabled, the name is fixed and cannot be changed during run tume", true, false);
	I_END_COMPONENT;

	// reimplemented (iprm::INameParam)
	virtual void SetName(const QString& name);
	virtual bool IsNameFixed() const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(QString, m_defaultNameAttrPtr);
	I_ATTR(bool, m_isNameFixedAttrPtr);
};


} // namespace iprm


#endif // !iprm_CNameParamComp_included


