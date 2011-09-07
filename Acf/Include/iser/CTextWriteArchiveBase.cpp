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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iser/CTextWriteArchiveBase.h"


// ACF includes
#include "istd/CBase64.h"


namespace iser
{


bool CTextWriteArchiveBase::Process(bool& value)
{
	std::string elementText = value? "true": "false";

	return Process(elementText);
}


bool CTextWriteArchiveBase::Process(char& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(I_BYTE& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(I_SBYTE& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(I_WORD& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(I_SWORD& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(I_DWORD& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(I_SDWORD& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(I_QWORD& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(I_SQWORD& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(float& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(double& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::ProcessData(void* dataPtr, int size)
{
	std::string encodedString = istd::CBase64::ConvertToBase64(dataPtr, size);

	return Process(encodedString);
}


// protected methods

CTextWriteArchiveBase::CTextWriteArchiveBase(const IVersionInfo* versionInfoPtr)
:	BaseClass(versionInfoPtr)
{
}


} // namespace iser


