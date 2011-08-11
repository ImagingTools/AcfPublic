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


#ifndef ixln_CXsltFileLoaderComp_included
#define ixln_CXsltFileLoaderComp_included

// ACF includes
#include "iser/IFileLoader.h"
#include "ibase/TLoggerCompWrap.h"
#include "ibase/CFileTypeInfoComp.h"
#include "iprm/IFileNameParam.h"

#include "ixln/ixln.h"


namespace ixln
{


/**
	Template implementation of file serializer using loading and storing archive implementation.
*/
class CXsltFileLoaderComp:
			public ibase::TLoggerCompWrap<ibase::CFileTypeInfoComp>,
			virtual public iser::IFileLoader
{
public:
	typedef ibase::TLoggerCompWrap<ibase::CFileTypeInfoComp> BaseClass;

	enum MessageId
	{
		MI_BAD_EXTENSION = 0xac10,
		MI_UNSUPPORTED_VERSION,
		MI_BAD_TRANSFORMATION,
		MI_INTERNAL
	};

	I_BEGIN_COMPONENT(CXsltFileLoaderComp);
		I_REGISTER_INTERFACE(iser::IFileLoader);
		I_REGISTER_INTERFACE(iser::IFileTypeInfo);
		I_ASSIGN(m_transformFileNameParamCompPtr, "LoadTransformFile", "Parameter storing file name of XSL transformation", true, "LoadTransformFile");
		I_ASSIGN(m_standardFileLoaderCompPtr, "StandardFileLoader", "Loader for the transformed File", true, "StandardFileLoader");
	I_END_COMPONENT;

	// reimplemented (iser::IFileLoader)
	virtual bool IsOperationSupported(
				const istd::IChangeable* dataObjectPtr,
				const istd::CString* filePathPtr = NULL,
				int flags = 0,
				bool beQuiet = true) const;
	virtual int LoadFromFile(istd::IChangeable& data, const istd::CString& filePath = istd::CString()) const;
	virtual int SaveToFile(const istd::IChangeable& data, const istd::CString& filePath = istd::CString()) const;

protected:
	

private:
	I_REF(iprm::IFileNameParam, m_transformFileNameParamCompPtr);
	I_REF(iser::IFileLoader, m_standardFileLoaderCompPtr);
};


} // namespace ixln


#endif // !ixln_CXsltFileLoaderComp_included


