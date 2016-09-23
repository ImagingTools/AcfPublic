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


#ifndef imath_CGeneralUnitInfo_included
#define imath_CGeneralUnitInfo_included


// ACF includes
#include <imath/IUnitInfo.h>


namespace imath
{


/**
	General implementation of the IUnitInfo interface.
*/
class CGeneralUnitInfo: virtual public IUnitInfo
{
public:
	CGeneralUnitInfo(
				int type = UT_UNKNOWN,
				const QString& name = "",
				double displayMultFactor = 1.0,
				const istd::CRange& range = istd::CRange::GetInvalid(),
				const imath::IDoubleManip* valueManipPtr = NULL);

	void SetUnitType(int type);
	void SetUnitName(const QString& name);
	void SetDisplayMultiplicationFactor(double factor);
	void SetValueRange(const istd::CRange& range);

	//	reimplemented (imath::IUnitInfo)
	virtual int GetUnitType() const;
	virtual QString GetUnitName() const;
	virtual double GetDisplayMultiplicationFactor() const;
	virtual istd::CRange GetValueRange() const;
	virtual const imath::IDoubleManip& GetValueManip() const;

private:
	int m_type;
	QString m_name;
	double m_displayMultFactor;
	istd::CRange m_range;
	const imath::IDoubleManip* m_valueManipPtr;
};


} // namespace imath


#endif // !imath_CGeneralUnitInfo_included


