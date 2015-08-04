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


#include "iprm/CSelectionConstraintsComp.h"


namespace iprm
{


// reimplemented (iprm::IOptionsList)

int CSelectionConstraintsComp::GetOptionsFlags() const
{
	return SCF_NONE;
}


int CSelectionConstraintsComp::GetOptionsCount() const
{
	Q_ASSERT(m_optionNamesAttrPtr.IsValid());

	return m_optionNamesAttrPtr.GetCount();
}


QString CSelectionConstraintsComp::GetOptionName(int index) const
{
	Q_ASSERT(m_optionNamesAttrPtr.GetCount() > index);
	Q_ASSERT(index >= 0);

	return m_optionNamesAttrPtr[index];
}


QString CSelectionConstraintsComp::GetOptionDescription(int index) const
{
	Q_ASSERT(index >= 0);

	if (index < m_optionDescriptionsAttrPtr.GetCount()){
		return m_optionDescriptionsAttrPtr[index];
	}

	return QString();
}


QByteArray CSelectionConstraintsComp::GetOptionId(int index) const
{
	Q_ASSERT(index >= 0);

	if (index < m_optionIdsAttrPtr.GetCount()){
		return m_optionIdsAttrPtr[index];
	}

	return QByteArray();
}


bool CSelectionConstraintsComp::IsOptionEnabled(int /*index*/) const
{
	return true;
}


} // namespace iprm


