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


#include "iser/CTextReadArchiveBase.h"


// STL includes
#include <cstring>


// ACF includes
#include "istd/CBase64.h"


namespace iser
{


// reimplemented (iser::IArchive)

bool CTextReadArchiveBase::Process(bool& value)
{
	std::string elementText;

	if (Process(elementText)){
		value = (elementText == "true");

		return true;
	}

	return false;
}


bool CTextReadArchiveBase::Process(char& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(I_BYTE& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(I_SBYTE& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(I_WORD& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(I_SWORD& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(I_DWORD& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(I_SDWORD& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(I_QWORD& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(I_SQWORD& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(float& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(double& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::ProcessData(void* dataPtr, int size)
{
	I_BYTE* data = (I_BYTE*)dataPtr;

	std::string text;
	bool retVal = Process(text);

	if (retVal){
		std::vector<I_BYTE> decodedData = istd::CBase64::ConvertFromBase64(text);
		I_ASSERT(size == int(decodedData.size()));

		std::memcpy(data, &decodedData[0], size);
	}

	return retVal;
}


} // namespace iser


