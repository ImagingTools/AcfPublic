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


#include "i2d/CPolygon.h"


// ACF includes
#include "i2d/CLine2d.h"


namespace i2d
{


// public methods

bool CPolygon::InsertNode(const i2d::CVector2d& node)
{
	m_nodes.push_back(node);

	return true;
}


bool CPolygon::InsertNode(int index, const i2d::CVector2d& node)
{
	::std::vector<i2d::CVector2d>::iterator iter = m_nodes.begin();
	iter += index;
	m_nodes.insert(iter, node);

	return true;
}


void CPolygon::Clear()
{
	m_nodes.clear();
}


bool CPolygon::RemoveNode(int index)
{
	::std::vector<i2d::CVector2d>::iterator iter = m_nodes.begin();
	iter += index;
	m_nodes.erase(iter);

	return true;
}


double CPolygon::GetOutlineLength() const
{
	double length = 0;
	int nodesCount = GetNodesCount();
	if (nodesCount > 0){
		i2d::CLine2d segmentLine;
		segmentLine.SetPoint2(GetNode(nodesCount - 1));
		for (int nodeIndex = 0; nodeIndex < nodesCount; ++nodeIndex){
			segmentLine.PushEndPoint(GetNode(nodeIndex));
			length += segmentLine.GetLength();
		}
	}
	return length;
}


void CPolygon::CalcBoundingBox(i2d::CRectangle& result) const
{
	int nodesCount = GetNodesCount();

	if (nodesCount > 0){
		i2d::CVector2d sp = GetNode(0);
		i2d::CRectangle boundingBox(sp, sp);
		for (int i = 1; i < nodesCount; i++){
			sp = GetNode(i);
			boundingBox.Unite(sp);
		}
		result = boundingBox;
		return;
	}

	result.Reset();
}


// reimplemented (iser::ISerializable)

bool CPolygon::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag polygonTag("Polygon", "Polygon");
	static iser::CArchiveTag vectorTag("V", "Vector");

	int nodesCount = m_nodes.size();
	bool retVal = true;

	retVal = retVal && archive.BeginMultiTag(polygonTag, vectorTag, nodesCount);
	if (!archive.IsStoring() && retVal){
		SetNodesCount(nodesCount);
	}

	for (int nodeIndex = 0; nodeIndex < nodesCount; ++nodeIndex){
		retVal = retVal && archive.BeginTag(vectorTag);
		retVal = retVal && m_nodes[nodeIndex].Serialize(archive);
		retVal = retVal && archive.EndTag(vectorTag);
	}
	retVal = retVal && archive.EndTag(polygonTag);

	return retVal;
}


// protected methods

void CPolygon::SetNodesCount(int nodesCount)
{
	m_nodes.resize(nodesCount);
}


} // namespace i2d

