/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iedge/CEdgeNode.h"


// ACF includes
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iedge
{


CEdgeNode::CEdgeNode()
{
}


CEdgeNode::CEdgeNode(const i2d::CVector2d& position, double weight)
:	m_position(position),
	m_weight(weight)
{
}


// reimplemented (iser::ISerializable)

bool CEdgeNode::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag positionTag("Position", "Position of edge node", iser::CArchiveTag::TT_GROUP);
	static iser::CArchiveTag weightTag("Weight", "Weight of edge node", iser::CArchiveTag::TT_LEAF);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(positionTag);
	retVal = retVal && m_position.Serialize(archive);
	retVal = retVal && archive.EndTag(positionTag);

	retVal = retVal && archive.BeginTag(weightTag);
	retVal = retVal && archive.Process(m_weight);
	retVal = retVal && archive.EndTag(weightTag);

	return retVal;
}


} // namespace iedge


