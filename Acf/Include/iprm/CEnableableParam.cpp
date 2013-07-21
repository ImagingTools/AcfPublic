/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "iprm/CEnableableParam.h"


#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iprm
{


CEnableableParam::CEnableableParam(bool isEnabled)
:	m_isEnabled(isEnabled)
{
}


// pseudo-reimplemented (iprm::IEnableableParam)

bool CEnableableParam::IsEnabled() const
{
	return m_isEnabled;
}


bool CEnableableParam::IsEnablingAllowed() const
{
	return true;
}


bool CEnableableParam::SetEnabled(bool isEnabled)
{
	if (!IsEnablingAllowed()){
		return false;
	}

	if (isEnabled != m_isEnabled){
		istd::CChangeNotifier changePtr(this);
	
		m_isEnabled = isEnabled;
	}

	return true;
}


// reimplemented (iser::ISerializable)

bool CEnableableParam::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag enabledTag("IsEnabled", "Object enabled state");

	bool isStoring = archive.IsStoring();

	istd::CChangeNotifier notifier(isStoring? NULL: this);

	bool isEnabled = m_isEnabled;

	bool retVal = archive.BeginTag(enabledTag);
	retVal = retVal && archive.Process(isEnabled);
	retVal = retVal && archive.EndTag(enabledTag);

	if (!isStoring){
		SetEnabled(isEnabled);
	}

	return retVal;
}


} // namespace iprm


