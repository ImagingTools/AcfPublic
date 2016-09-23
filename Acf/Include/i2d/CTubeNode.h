/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef i2d_CTubeNode_included
#define i2d_CTubeNode_included


// ACF includes
#include <istd/TRange.h>

#include <iser/ISerializable.h>

#include <i2d/i2d.h>


namespace i2d
{


/**
	Polygon node used to define tube boundaries at the given point.
	\sa CTubePolyline
*/
class CTubeNode: public iser::ISerializable
{
public:
	CTubeNode();
	CTubeNode(const CTubeNode& node);

	/**
		Get boundaries of the tube node.
	*/
	const istd::CRange& GetTubeRange() const;

	/**
		Set boundaries of the tube node.
	*/
	void SetTubeRange(const istd::CRange& tubeRange);

	/**
		Set this object to be linear interpolated between first and second parameter.
		\param	first	first node parameter.
		\param	second	second node parameter.
		\param	alpha	when 0 result equals first parameter, when 1 equals second.
		For other values is linear interpolated between this two edge parameters.
	*/
	virtual void SetInterpolated(const CTubeNode& first, const CTubeNode& second, double alpha);

	// reimplemented (qcom::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	istd::CRange m_tubeRange;
};


} // namespace i2d


#endif // !i2d_CTubeNode_included


