/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
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


