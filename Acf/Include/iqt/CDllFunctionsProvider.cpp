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


#include "iqt/CDllFunctionsProvider.h"


namespace iqt
{


CDllFunctionsProvider::CDllFunctionsProvider(const istd::CString& dllPath)
{
	if (!dllPath.IsEmpty()){
		OpenDll(dllPath);
	}
}


CDllFunctionsProvider::~CDllFunctionsProvider()
{
	Reset();
}


void CDllFunctionsProvider::Reset()
{
	m_library.unload();
}


bool CDllFunctionsProvider::OpenDll(const istd::CString& dllPath)
{
	Reset();

	m_library.setFileName(iqt::GetQString(dllPath));
	m_library.setLoadHints(QLibrary::ExportExternalSymbolsHint);

	m_library.load();

	return IsValid();
}


// reimplemented (isys::IFunctionsProvider)

bool CDllFunctionsProvider::IsValid() const
{
	return m_library.isLoaded();
}


void* CDllFunctionsProvider::GetFunction(const std::string& id) const
{
	if (IsValid()){
		return m_library.resolve(id.c_str());
	}

	return NULL;
}


} // namespace iqt


