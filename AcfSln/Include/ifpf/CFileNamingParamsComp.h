/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef ifpf_CFileNamingParamsComp_included
#define ifpf_CFileNamingParamsComp_included


// ACF includes
#include "icomp/CComponentBase.h"


// AcfSln includes
#include "ifpf/IFileNamingParams.h"


namespace ifpf
{


class CFileNamingParamsComp: public icomp::CComponentBase, virtual public ifpf::IFileNamingParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	CFileNamingParamsComp();

	I_BEGIN_COMPONENT(ifpf::CFileNamingParamsComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(ifpf::IFileNamingParams);
	I_END_COMPONENT();

	// reimplemented (ifpf::IFileNamingParams)
	virtual int GetRenamingMode() const;
	virtual void SetRenamingMode(int renamingMode);
	virtual istd::CString GetPrefix() const;
	virtual void SetPrefix(const istd::CString& prefix);
	virtual istd::CString GetSuffix() const;
	virtual void SetSuffix(const istd::CString& suffix);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	int m_renamingMode;
	istd::CString m_suffix;
	istd::CString m_prefix;
};


} // namespace ifpf


#endif // !ifpf_CFileNamingParamsComp_included


