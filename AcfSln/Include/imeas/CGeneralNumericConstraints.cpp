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



#include <imeas/CGeneralNumericConstraints.h>


#include <istd/CChangeNotifier.h>


namespace imeas
{


void CGeneralNumericConstraints::Reset()
{
	istd::CChangeNotifier notifier(this);
	Q_UNUSED(notifier);

	m_valueInfos.clear();
}


void CGeneralNumericConstraints::InsertValueInfo(const QString& name, const QString& description, const imath::CGeneralUnitInfo& unitInfo, int index)
{
	istd::CChangeNotifier notifier(this);
	Q_UNUSED(notifier);

	Info info;
	info.name = name;
	info.description = description;
	info.unitInfo = unitInfo;

	if (index >= 0){
		m_valueInfos.insert(index, info);
	}
	else{
		m_valueInfos.append(info);
	}
}


void CGeneralNumericConstraints::RemoveValueInfo(int index)
{
	m_valueInfos.remove(index);
}


// reimplemented (imeas::INumericConstraints)

int CGeneralNumericConstraints::GetNumericValuesCount() const
{
	return m_valueInfos.size();
}


QString CGeneralNumericConstraints::GetNumericValueName(int index) const
{
	return m_valueInfos[index].name;
}


QString CGeneralNumericConstraints::GetNumericValueDescription(int index) const
{
	return m_valueInfos[index].description;
}


const imath::IUnitInfo* CGeneralNumericConstraints::GetNumericValueUnitInfo(int index) const
{
	return &m_valueInfos[index].unitInfo;
}


} // namespace imeas

