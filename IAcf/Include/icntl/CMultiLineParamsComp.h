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


#ifndef icntl_CMultiLineParamsComp_included
#define icntl_CMultiLineParamsComp_included


// ACF includes
#include "icomp/CComponentBase.h"
#include "ibase/TNamedWrap.h"

#include "icntl/ILineParams.h"
#include "icntl/IMultiLineParams.h"


namespace icntl
{


/**
	Implementation of parameters of multi line system.
*/
class CMultiLineParamsComp:
			public icomp::CComponentBase,
			public ibase::TNamedWrap<IMultiLineParams>
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CMultiLineParamsComp);
		I_REGISTER_INTERFACE(IMultiLineParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(istd::IChangeable);

		I_ASSIGN(m_nameAttrPtr, "Name", "Name", true, "");
		I_ASSIGN_MULTI_0(m_linesCompPtr, "Lines", "List of line parameters", true);
	I_END_COMPONENT;

	// reimplemented (icntl::IMultiLineParams)
	virtual int GetLinesCount() const;
	virtual ILineParams& GetLineParams(int lineIndex) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(istd::CString, m_nameAttrPtr);
	I_MULTIREF(ILineParams, m_linesCompPtr);
};


} // namespace icntl


#endif // !icntl_CMultiLineParamsComp_included


