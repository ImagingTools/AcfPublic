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


#ifndef imeas_CGeneralNumericValue_included
#define imeas_CGeneralNumericValue_included


// Qt includes
#include "QtCore/QMap"

// ACF includes
#include "imath/CVarVector.h"

// ACF-Solutions includes
#include "imeas/INumericValue.h"

namespace imeas
{


class CGeneralNumericValue: virtual public imeas::INumericValue
{
public:
	void SetComponentValue(imeas::INumericValue::ValueTypeId valueTypeId, imath::CVarVector value);

	// reimplemented (imeas::INumericValue)
	virtual bool IsValueTypeSupported(imeas::INumericValue::ValueTypeId valueTypeId) const;
	virtual const imeas::INumericConstraints* GetNumericConstraints() const;
	virtual imath::CVarVector GetComponentValue(imeas::INumericValue::ValueTypeId valueTypeId) const;
	virtual imath::CVarVector GetValues() const;
	virtual bool SetValues(const imath::CVarVector& values);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive &archive);

	// reimplemented (istd::IChangable)
	virtual bool CopyFrom(const istd::IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);
	virtual istd::IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const;

private:
	typedef QMap<imeas::INumericValue::ValueTypeId, imath::CVarVector> SupportMap;
	SupportMap m_supportMap;
};


} // namespace imeas


#endif // !imeas_CGeneralNumericValue_included


