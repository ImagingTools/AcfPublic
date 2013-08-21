/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "i2d/CTubeNode.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iser/CPrimitiveTypesSerializer.h"


namespace i2d
{


// public methods

CTubeNode::CTubeNode()
	:m_tubeRange(-10, 10)
{
}


CTubeNode::CTubeNode(const CTubeNode& node)
{
	m_tubeRange = node.m_tubeRange;
}


const istd::CRange& CTubeNode::GetTubeRange() const
{
	return m_tubeRange;
}


void CTubeNode::SetTubeRange(const istd::CRange& tubeRange)
{
	if (m_tubeRange != tubeRange){
		istd::CChangeNotifier notifier(this);

		m_tubeRange = tubeRange;
	}
}


void CTubeNode::SetInterpolated(
			const CTubeNode& first,
			const CTubeNode& second,
			double alpha)
{
	istd::CChangeNotifier changePtr(this);

	m_tubeRange.SetInterpolated(first.m_tubeRange, second.m_tubeRange, alpha);
}


// reimplemented (iser::ISerializable)

bool CTubeNode::Serialize(iser::IArchive& archive)
{
	return iser::CPrimitiveTypesSerializer::SerializeRange(archive, m_tubeRange);
}


} // namespace i2d


