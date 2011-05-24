/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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


#include "iser/CBinaryReadArchiveBase.h"


// ACF includes
#include "istd/CString.h"

#include "iser/CArchiveTag.h"


namespace iser
{


bool CBinaryReadArchiveBase::BeginTag(const CArchiveTag& tag)
{
	I_DWORD readId;
	bool retVal = Process(readId);

	if (!retVal){
		return false;
	}

	if (readId != tag.GetBinaryId()){
		if (IsLogConsumed()){
			SendLogMessage(
						istd::ILogger::MC_ERROR,
						MI_TAG_ERROR,
						istd::CString("Bad tag begin code, is ") + istd::CString::FromNumber(readId) + ", should be " + istd::CString::FromNumber(tag.GetBinaryId()) + " (tag '" + tag.GetId() + "')",
						"iser::CBinaryReadArchiveBase",
						MF_SYSTEM);
		}

		return false;
	}

	return true;
}


bool CBinaryReadArchiveBase::EndTag(const CArchiveTag& tag)
{
	I_DWORD readId;
	bool retVal = Process(readId);

	if (!retVal){
		return false;
	}

	if (~readId != tag.GetBinaryId()){
		if (IsLogConsumed()){
			SendLogMessage(
						istd::ILogger::MC_ERROR,
						MI_TAG_ERROR,
						istd::CString("Bad tag begin code, is ") + istd::CString::FromNumber(~readId) + ", should be " + istd::CString::FromNumber(tag.GetBinaryId()) + " (tag '" + tag.GetId() + "')",
						"iser::CBinaryReadArchiveBase",
						MF_SYSTEM);
		}

		return false;
	}

	return true;
}


bool CBinaryReadArchiveBase::Process(bool& value)
{
	return ProcessData(&value, int(sizeof(bool)));
}


bool CBinaryReadArchiveBase::Process(char& value)
{
	return ProcessData(&value, int(sizeof(char)));
}


bool CBinaryReadArchiveBase::Process(I_BYTE& value)
{
	return ProcessData(&value, int(sizeof(I_BYTE)));
}


bool CBinaryReadArchiveBase::Process(I_SBYTE& value)
{
	return ProcessData(&value, int(sizeof(I_SBYTE)));
}


bool CBinaryReadArchiveBase::Process(I_WORD& value)
{
	return ProcessData(&value, int(sizeof(I_WORD)));
}


bool CBinaryReadArchiveBase::Process(I_SWORD& value)
{
	return ProcessData(&value, int(sizeof(I_SWORD)));
}


bool CBinaryReadArchiveBase::Process(I_DWORD& value)
{
	return ProcessData(&value, int(sizeof(I_DWORD)));
}


bool CBinaryReadArchiveBase::Process(I_SDWORD& value)
{
	return ProcessData(&value, int(sizeof(I_SDWORD)));
}


bool CBinaryReadArchiveBase::Process(I_QWORD& value)
{
	return ProcessData(&value, int(sizeof(I_QWORD)));
}


bool CBinaryReadArchiveBase::Process(I_SQWORD& value)
{
	return ProcessData(&value, int(sizeof(I_SQWORD)));
}


bool CBinaryReadArchiveBase::Process(float& value)
{
	return ProcessData(&value, int(sizeof(float)));
}


bool CBinaryReadArchiveBase::Process(double& value)
{
	return ProcessData(&value, int(sizeof(double)));
}


bool CBinaryReadArchiveBase::Process(std::string& value)
{			
	int stringLength;

	bool retVal = Process(stringLength);

	if (retVal && (stringLength > 0)){
		if (stringLength > MaxStringLength){
			if (IsLogConsumed()){
				SendLogMessage(
							istd::ILogger::MC_ERROR,
							MI_STRING_TOO_LONG,
							istd::CString("Read string size is ") + istd::CString::FromNumber(stringLength) + " and it is longer than maximum size",
							"iser::CBinaryReadArchiveBase",
							MF_SYSTEM);
			}

			return false;
		}

		std::vector<char> buffer(stringLength + 1, 0);

		retVal = ProcessData(&buffer[0], stringLength * int(sizeof(char)));	

		if (retVal){
			value = std::string(&buffer[0]);
		}
	}
	
	return retVal;
}


bool CBinaryReadArchiveBase::Process(istd::CString& value)
{
	int stringLength;

	bool retVal = Process(stringLength);

	if (retVal && (stringLength > 0)){
		if (stringLength > MaxStringLength){
			if (IsLogConsumed()){
				SendLogMessage(
							istd::ILogger::MC_ERROR,
							MI_STRING_TOO_LONG,
							istd::CString("Read string size is ") + istd::CString::FromNumber(stringLength) + " and it is longer than maximum size",
							"iser::CBinaryReadArchiveBase",
							MF_SYSTEM);
			}

			return false;
		}

		std::vector<wchar_t> buffer(stringLength + 1, 0);

		retVal = ProcessData(&buffer[0], stringLength * int(sizeof(wchar_t)));	

		if (retVal){
			value = istd::CString(&buffer[0]);
		}
	}

	return retVal;
}


} // namespace iser

