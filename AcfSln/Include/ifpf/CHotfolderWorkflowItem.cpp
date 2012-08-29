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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "ifpf/CHotfolderWorkflowItem.h"


// Qt includes
#include <QtCore/QStringList>


namespace ifpf
{


// public methods

QString CHotfolderWorkflowItem::GetHotfolderId() const
{
	return m_hotfolderId;
}


void CHotfolderWorkflowItem::Initialize(
			const QString& hotfolderId,
			const ifpf::IHotfolderInfoManager* infoManagerPtr)
{
	m_hotfolderId = hotfolderId;

	m_infoManagerPtr = infoManagerPtr;
}


// reimplemented (ifpf::IHotfolderWorkflowItem)

QStringList CHotfolderWorkflowItem::GetInputDirectories() const
{
	QStringList retVal;

	return retVal;
}


QString CHotfolderWorkflowItem::GetOutputDirectory() const
{
	QString retVal;

	return retVal;
}


// reimplemented (iser::ISerializable)

bool CHotfolderWorkflowItem::Serialize(iser::IArchive& /*archive*/)
{
	return true;
}


} // namespace ifpf



