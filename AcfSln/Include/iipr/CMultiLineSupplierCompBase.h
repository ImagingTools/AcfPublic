/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_CMultiLineSupplier_included
#define iipr_CMultiLineSupplier_included


// ACF includes
#include "i2d/CPolyline.h"
#include "iprm/IParamsSet.h"
#include "iproc/TSupplierCompWrap.h"

// ACF-Solutions includes
#include "imeas/INumericValueProvider.h"


namespace iipr
{


class CMultiLineSupplierCompBase:
			public iproc::TSupplierCompWrap< QVector<i2d::CLine2d> >,
			virtual public imeas::INumericValueProvider
{
public:
	typedef iproc::TSupplierCompWrap< QVector<i2d::CLine2d> > BaseClass;

	I_BEGIN_BASE_COMPONENT(CMultiLineSupplierCompBase);
		I_REGISTER_INTERFACE(imeas::INumericValueProvider);
	I_END_COMPONENT;

	// reimplemented (imeas::INumericValueProvider)
	virtual int GetValuesCount() const;
	virtual const imeas::INumericValue& GetNumericValue(int index) const;

private:
	class Line: virtual public imeas::INumericValue
	{
	public:
		Line();
		Line(const i2d::CLine2d& line);

		// reimplemented (imeas::INumericValue)
		virtual bool IsValueTypeSupported(ValueTypeId valueTypeId) const;
		virtual const imeas::INumericConstraints* GetNumericConstraints() const;
		virtual imath::CVarVector GetComponentValue(ValueTypeId valueTypeId) const;
		virtual imath::CVarVector GetValues() const;
		virtual bool SetValues(const imath::CVarVector& values);

		// reimplemented (iser::ISerializable)
		virtual bool Serialize(iser::IArchive& archive);

		// reimplemented (istd::IChangeable)
		virtual bool CopyFrom(const IChangeable& object);

	protected:
		imath::CVarVector m_values;
	};

	typedef QMap<int, Line> LinesCache;

	mutable LinesCache m_linesCache;
};


} // namespace iipr


#endif // !iipr_CMultiLineSupplier_included


