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


bool CTextReadArchiveBase::Process(quint8& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(qint8& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(quint16& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(qint16& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(quint32& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(qint32& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(quint64& value)
{
	return ProcessInternal(value);
}


bool CTextReadArchiveBase::Process(qint64& value)
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
	quint8* data = (quint8*)dataPtr;

	std::string text;
	bool retVal = Process(text);

	if (retVal){
		std::vector<quint8> decodedData = istd::CBase64::ConvertFromBase64(text);
		I_ASSERT(size == int(decodedData.size()));

		std::memcpy(data, &decodedData[0], size);
	}

	return retVal;
}


} // namespace iser


