/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef imeas_CSimpleNumericValue_included
#define imeas_CSimpleNumericValue_included


// ACF includes
#include "iser/ISerializable.h"

// ACF-Solutions includes
#include "imeas/INumericValue.h"


namespace imeas
{


/**
	Basic implementation of imeas::INumericValue interface.
*/
class CSimpleNumericValue: virtual public INumericValue
{
public:
	// reimplemented (imeas::INumericValue)
	virtual bool IsValueTypeSupported(ValueTypeId valueTypeId) const;
	virtual const INumericConstraints* GetNumericConstraints() const;
	virtual imath::CVarVector GetComponentValue(ValueTypeId valueTypeId) const;
	virtual imath::CVarVector GetValues() const;
	virtual bool SetValues(const imath::CVarVector& values);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);

protected:
	imath::CVarVector m_values;
};


} // namespace imeas


#endif // !imeas_CSimpleNumericValue_included


