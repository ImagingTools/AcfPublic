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


#ifndef iedge_CEdgeNode_included
#define iedge_CEdgeNode_included


// ACF includes
#include <iser/ISerializable.h>
#include <i2d/CVector2d.h>


namespace iedge
{


/**
	Description of single node of the edge.
	Node has position and weight.
*/
class CEdgeNode: virtual public iser::ISerializable
{
public:
	CEdgeNode();
	CEdgeNode(const i2d::CVector2d& position, double weight);

	/**
		Get position of node.
	*/
	const i2d::CVector2d& GetPosition() const;
	/**
		Set position of node.
	*/
	void SetPosition(const i2d::CVector2d& position);
	/**
		Get node weight.
		This value should be normalized (range [0, 1]).
	*/
	double GetWeight() const;
	/**
		Set node weight.
		This value should be normalized (range [0, 1]).
	*/
	void SetWeight(double weight);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

private:
	/**
		Position of edge node.
	*/
	i2d::CVector2d m_position;

	/**
		Weight value of this point.
	*/
	double m_weight;
};


// inline methods

inline const i2d::CVector2d& CEdgeNode::GetPosition() const
{
	return m_position;
}


inline void CEdgeNode::SetPosition(const i2d::CVector2d& position)
{
	m_position = position;
}


inline double CEdgeNode::GetWeight() const
{
	return m_weight;
}


inline void CEdgeNode::SetWeight(double weight)
{
	m_weight = weight;
}


} // namespace iedge


#endif // !iedge_CEdgeNode_included


