/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "icomp/CComponentAddress.h"


#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace icomp
{


CComponentAddress::CComponentAddress()
{
}


CComponentAddress::CComponentAddress(const std::string& packageId, const std::string& componentId)
:	m_packageId(packageId),
	m_componentId(componentId)
{
}


bool CComponentAddress::IsValid() const
{
	return !m_packageId.empty() && !m_componentId.empty();
}


QString CComponentAddress::ToString() const
{
	return QString(QString::fromStdString(m_packageId) + "/" + QString::fromStdString(m_componentId));
}


// reimplemented (iser::ISerializable)

bool CComponentAddress::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag packageIdTag("PackageId", "ID of package");
	static iser::CArchiveTag componentIdTag("ComponentId", "ID of factory");

	bool retVal = true;

	retVal = retVal && archive.BeginTag(packageIdTag);
	retVal = retVal && archive.Process(m_packageId);
	retVal = retVal && archive.EndTag(packageIdTag);

	retVal = retVal && archive.BeginTag(componentIdTag);
	retVal = retVal && archive.Process(m_componentId);
	retVal = retVal && archive.EndTag(componentIdTag);

	return retVal;
}


} // namespace icomp


