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


#ifndef iqt_CDllFunctionsProvider_included
#define iqt_CDllFunctionsProvider_included


#include "iqt/iqt.h"

#include "istd/CString.h"

#include "isys/IFunctionsProvider.h"

#include <QLibrary>


namespace iqt
{


/**
	Provide access to public functions in DLL.
 */
class CDllFunctionsProvider: virtual public isys::IFunctionsProvider
{
public:
	/**
		Construct this object opening specified DLL.
		\param	dllPath	path to DLL or empty string if no DLL should be opened.
	 */
	CDllFunctionsProvider(const istd::CString& dllPath = "");
	virtual ~CDllFunctionsProvider();

	bool OpenDll(const istd::CString& dllPath);

	void Reset();

	// reimplemented (isys::IFunctionsProvider)
	virtual bool IsValid() const;
	virtual void* GetFunction(const std::string& id) const;

private:
	mutable QLibrary m_library;
};


} // namespace iqt


#endif // !iqt_CDllFunctionsProvider_included


