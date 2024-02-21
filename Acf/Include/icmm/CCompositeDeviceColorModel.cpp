/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <icmm/CCompositeDeviceColorModel.h>


namespace icmm
{


// public methods

// reimplemented (icmm::IColorantList)

QByteArrayList icmm::CCompositeDeviceColorModel::GetColorantIds() const
{
	QByteArrayList retVal;

	for (const ColorantInfo& colorant : m_colorants){
		retVal.push_back(colorant.id);
	}

	return retVal;
}


QString icmm::CCompositeDeviceColorModel::GetColorantName(const QByteArray& colorantId) const
{
	for (const ColorantInfo& colorant : m_colorants){
		if (colorantId == colorant.id){
			return colorant.name;
		}
	}

	return QString();
}


icmm::ColorantType icmm::CCompositeDeviceColorModel::GetColorantType(const QByteArray& colorantId) const
{
	for (const ColorantInfo& colorant : m_colorants){
		if (colorantId == colorant.id){
			return colorant.type;
		}
	}

	return CT_NONE;
}


icmm::ProcessColorantUsage icmm::CCompositeDeviceColorModel::GetProcessColorantUsage(const QByteArray& colorantId) const
{
	for (const ColorantInfo& colorant : m_colorants){
		if (colorantId == colorant.id){
			return colorant.usage;
		}
	}

	return PCU_NONE;
}


} // namespace icmm


