/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iwin/CDllFunctionsProvider.h"


namespace iwin
{


CDllFunctionsProvider::CDllFunctionsProvider(const istd::CString& dllPath)
{
	if (!dllPath.empty()){
		m_handler = ::LoadLibraryW(dllPath.c_str());
	}
}


CDllFunctionsProvider::~CDllFunctionsProvider()
{
	Reset();
}


void CDllFunctionsProvider::Reset()
{
	if (m_handler != NULL){
		::FreeLibrary(m_handler);
	}

	m_handler = NULL;
}


bool CDllFunctionsProvider::OpenDll(const istd::CString& dllPath)
{
	Reset();

	m_handler = ::LoadLibraryW(dllPath.c_str());

	return IsValid();
}


// reimplemented (isys::IFunctionsProvider)

bool CDllFunctionsProvider::IsValid() const
{
	return m_handler != NULL;
}


void* CDllFunctionsProvider::GetFunction(const std::string& id) const
{
	if (IsValid()){
		return (void*)::GetProcAddress(m_handler, id.c_str());
	}
	else{
		return NULL;
	}
}


} // namespace iwin


