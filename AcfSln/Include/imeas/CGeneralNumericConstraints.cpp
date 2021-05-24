/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


bool CGeneralNumericConstraints::InsertValueInfo(
			const QString& name,
			const QString& description,
			const QByteArray& valueId,
			const imath::CGeneralUnitInfo& unitInfo,
			int index)
{
	istd::CChangeNotifier notifier(this);
	Q_UNUSED(notifier);

	Info info;
	info.name = name;
	info.description = description;
	info.id = valueId;
	info.unitInfo = unitInfo;

	if (index >= 0){
		m_valueInfos.insert(index, info);
	}
	else{
		m_valueInfos.append(info);
	}

	return true;
}


void CGeneralNumericConstraints::RemoveValueInfo(int index)
{
	m_valueInfos.remove(index);
}


const imath::CGeneralUnitInfo& CGeneralNumericConstraints::GetGeneralUnitInfo(int index) const
{
	return m_valueInfos[index].unitInfo;
}


// reimplemented (imeas::INumericConstraints)

const iprm::IOptionsList& CGeneralNumericConstraints::GetValueListInfo() const
{
	return *this;
}


const imath::IUnitInfo* CGeneralNumericConstraints::GetNumericValueUnitInfo(int index) const
{
	return &m_valueInfos[index].unitInfo;
}


// reimplemented (iprm::IOptionsList)

int CGeneralNumericConstraints::GetOptionsFlags() const
{
	return SCF_SUPPORT_UNIQUE_ID;
}


int CGeneralNumericConstraints::GetOptionsCount() const
{
	return m_valueInfos.count();
}


QString CGeneralNumericConstraints::GetOptionName(int index) const
{
	return m_valueInfos[index].name;
}


QString CGeneralNumericConstraints::GetOptionDescription(int index) const
{
	return m_valueInfos[index].description;
}


QByteArray CGeneralNumericConstraints::GetOptionId(int index) const
{
	return m_valueInfos[index].id;
}


bool CGeneralNumericConstraints::IsOptionEnabled(int /*index*/) const
{
	return true;
}


} // namespace imeas

