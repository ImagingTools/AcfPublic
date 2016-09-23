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


#ifndef ifile_CApplicationInfoBasedFileNameComp_included
#define ifile_CApplicationInfoBasedFileNameComp_included


// ACF includes
#include <ifile/CRelativeFileNameParamComp.h>
#include <ibase/IApplicationInfo.h>

namespace ifile
{

class CApplicationInfoBasedFileNameComp: public ifile::CRelativeFileNameParamComp
{
public:
	typedef ifile::CRelativeFileNameParamComp BaseClass;

	I_BEGIN_COMPONENT(CApplicationInfoBasedFileNameComp);
		I_ASSIGN(m_applicationInfoCompPtr, "ApplicationInfo", "Application info", false, "ApplicationInfo");
	I_END_COMPONENT;

	// reimplemented (ifile::IFileNameParam)
	virtual const QString& GetPath() const;

private:
	I_REF(ibase::IApplicationInfo, m_applicationInfoCompPtr);

	mutable QString m_calculatedPath;

	static QString s_processIdVariable;
	static QString s_companyNameVariable;
	static QString s_productNameVariable;
	static QString s_applicationNameVariable;
	static QString s_applicationSubnameVariable;
	static QString s_applicationTypeVariable;
	static QString s_mainVersionVariable;
	static QString s_userVariable;
};


} // namespace ifile


#endif // !ifile_CApplicationInfoBasedFileNameComp_included


