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


#ifndef i2d_CTubePolyline_included
#define i2d_CTubePolyline_included


// ACF includes
#include <i2d/TDataNodePolyline.h>
#include <i2d/CTubeNode.h>


namespace i2d
{


/**
	Definition of tube region based on polyline.
*/
class CTubePolyline: public TDataNodePolyline<CTubeNode>
{
public:
	typedef TDataNodePolyline<CTubeNode> BaseClass;

	// reimplemented (i2d::IObject2d)
	virtual bool Transform(
				const ITransformation2d& transformation,
				ITransformation2d::ExactnessMode mode = ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) override;
};


} // namespace i2d


#endif // !i2d_CTubePolyline_included



