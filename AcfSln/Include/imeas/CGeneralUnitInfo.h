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


#ifndef imeas_CGeneralUnitInfo_included
#define imeas_CGeneralUnitInfo_included


// ACF-Solutions includes
#include "imeas/IUnitInfo.h"


namespace imeas
{


class CGeneralUnitInfo: virtual public IUnitInfo
{
public:
	CGeneralUnitInfo(
				int type = UT_UNKNOWN,
				const istd::CString& name = "",
				double displayMultFactor = 1.0,
				const istd::CRange& range = istd::CRange::GetInvalid());

	void SetUnitType(int type);
	void SetUnitName(const istd::CString& name);
	void SetDisplayMultiplicationFactor(double factor);
	void SetValueRange(const istd::CRange& range);

	//	reimplemented (imeas::IUnitInfo)
	virtual int GetUnitType() const;
	virtual istd::CString GetUnitName() const;
	virtual double GetDisplayMultiplicationFactor() const;
	virtual istd::CRange GetValueRange() const;
	virtual const imath::IDoubleManip& GetValueManip() const;

private:
	int m_type;
	istd::CString m_name;
	double m_displayMultFactor;
	istd::CRange m_range;
};


} // namespace imeas


#endif // !imeas_CGeneralUnitInfo_included


