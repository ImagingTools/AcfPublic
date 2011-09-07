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


#include "iser/CBinaryWriteArchiveBase.h"


// ACF includes
#include "istd/CString.h"

#include "iser/CArchiveTag.h"


namespace iser
{


// reimplemented (iser::IArchive)

bool CBinaryWriteArchiveBase::BeginTag(const CArchiveTag& tag)
{
	I_DWORD binaryId = tag.GetBinaryId();

	return Process(binaryId);
}


bool CBinaryWriteArchiveBase::EndTag(const CArchiveTag& tag)
{
	I_DWORD binaryId = ~tag.GetBinaryId();

	return Process(binaryId);
}


bool CBinaryWriteArchiveBase::Process(bool& value)
{
	return ProcessData(&value, int(sizeof(bool)));
}


bool CBinaryWriteArchiveBase::Process(char& value)
{
	return ProcessData(&value, int(sizeof(char)));
}


bool CBinaryWriteArchiveBase::Process(I_BYTE& value)
{
	return ProcessData(&value, int(sizeof(I_BYTE)));
}


bool CBinaryWriteArchiveBase::Process(I_SBYTE& value)
{
	return ProcessData(&value, int(sizeof(I_SBYTE)));
}


bool CBinaryWriteArchiveBase::Process(I_WORD& value)
{
	return ProcessData(&value, int(sizeof(I_WORD)));
}


bool CBinaryWriteArchiveBase::Process(I_SWORD& value)
{
	return ProcessData(&value, int(sizeof(I_SWORD)));
}


bool CBinaryWriteArchiveBase::Process(I_DWORD& value)
{
	return ProcessData(&value, int(sizeof(I_DWORD)));
}


bool CBinaryWriteArchiveBase::Process(I_SDWORD& value)
{
	return ProcessData(&value, int(sizeof(I_SDWORD)));
}


bool CBinaryWriteArchiveBase::Process(I_QWORD& value)
{
	return ProcessData(&value, int(sizeof(I_QWORD)));
}


bool CBinaryWriteArchiveBase::Process(I_SQWORD& value)
{
	return ProcessData(&value, int(sizeof(I_SQWORD)));
}


bool CBinaryWriteArchiveBase::Process(float& value)
{
	return ProcessData(&value, int(sizeof(float)));
}


bool CBinaryWriteArchiveBase::Process(double& value)
{
	return ProcessData(&value, int(sizeof(double)));
}


bool CBinaryWriteArchiveBase::Process(std::string& value)
{			
	int stringLength = value.size();

	bool retVal = Process(stringLength);

	retVal = retVal && ProcessData((void*)value.c_str(), stringLength * int(sizeof(char)));

	return retVal;
}


bool CBinaryWriteArchiveBase::Process(istd::CString& value)
{
	int stringLength = value.size();

	bool retVal = Process(stringLength);

	retVal = retVal && ProcessData((void*)value.c_str(), stringLength * int(sizeof(wchar_t)));	

	return retVal;
}


// protected methods

CBinaryWriteArchiveBase::CBinaryWriteArchiveBase(const IVersionInfo* versionInfoPtr)
:	BaseClass(versionInfoPtr)
{
}


} // namespace iser


