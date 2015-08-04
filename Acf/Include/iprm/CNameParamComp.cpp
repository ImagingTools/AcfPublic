/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include "iprm/CNameParamComp.h"


namespace iprm
{


// public methods

// reimplemented (iprm::INameParam)

void CNameParamComp::SetName(const QString& name)
{
	if (!*m_isNameFixedAttrPtr){
		BaseClass2::SetName(name);
	}
}


bool CNameParamComp::IsNameFixed() const
{
	return *m_isNameFixedAttrPtr;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CNameParamComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_defaultNameAttrPtr.IsValid()){
		BaseClass2::SetName(*m_defaultNameAttrPtr);
	}
}


} // namespace iprm


