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


#ifndef iser_CTextWriteArchiveBase_included
#define iser_CTextWriteArchiveBase_included


// STL includes
#include <sstream>


// ACF includes
#include "iser/CWriteArchiveBase.h"


namespace iser
{


/**
	Common archive implementation of text-based storing archives.
*/
class CTextWriteArchiveBase: public CWriteArchiveBase
{
public:
	typedef CWriteArchiveBase BaseClass;

	using BaseClass::Process;

	// reimplemented (iser::IArchive)
	virtual bool Process(bool& value);
	virtual bool Process(char& value);
	virtual bool Process(I_BYTE& value);
	virtual bool Process(I_SBYTE& value);
	virtual bool Process(I_WORD& value);
	virtual bool Process(I_SWORD& value);
	virtual bool Process(I_DWORD& value);
	virtual bool Process(I_SDWORD& value);
	virtual bool Process(I_QWORD& value);
	virtual bool Process(I_SQWORD& value);
	virtual bool Process(float& value);
	virtual bool Process(double& value);
	virtual bool ProcessData(void* dataPtr, int size);

protected:
	CTextWriteArchiveBase(const IVersionInfo* versionInfoPtr);

	// template methods
	template <typename Type>
	bool ProcessInternal(const Type& value);
};


// template methods

template <typename Type>
bool CTextWriteArchiveBase::ProcessInternal(const Type& value)
{
	bool retVal = true;

	std::ostringstream stream;

	stream << value;

	std::string str(stream.str());

	retVal = retVal && Process(str);

	return retVal;
}


} // namespace iser


#endif // !iser_CTextWriteArchiveBase_included


