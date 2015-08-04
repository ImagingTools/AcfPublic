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


#ifndef imeas_CSimpleNumericValueProvider_included
#define imeas_CSimpleNumericValueProvider_included


// ACF includes
#include "iser/ISerializable.h"
#include "ilog/TLoggerCompWrap.h"
#include "imeas/CSimpleNumericValue.h"

// QSF includes
#include "imeas/INumericValueProvider.h"


namespace imeas
{


class CSimpleNumericValueProvider: virtual public INumericValueProvider
{
public:
	// reimplemented (imeas::INumericValueProvider)
	virtual int GetValuesCount() const;
	virtual const imeas::INumericValue& GetNumericValue(int index) const;
	
	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive & archive);

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);

private:
	typedef QVector<imeas::CSimpleNumericValue> Values;

	Values m_values;
};


} // namespace imeas


#endif // !imeas_CSimpleNumericValueProvider_included


