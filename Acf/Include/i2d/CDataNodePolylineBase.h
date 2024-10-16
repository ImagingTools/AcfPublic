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


#ifndef i2d_CDataNodePolylineBase_included
#define i2d_CDataNodePolylineBase_included


// ACF includes
#include <i2d/CPolyline.h>


namespace i2d
{


/**
	Base class for polylines with additional data stored in each node.
*/
class CDataNodePolylineBase: public CPolyline
{
public:
	typedef CPolyline BaseClass;

	/**
		Get user data from the given node.
	*/
	virtual const iser::ISerializable& GetNodeData(int nodeIndex) const = 0;

	/**
		\overload
	*/
	virtual iser::ISerializable& GetNodeDataRef(int nodeIndex) = 0;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;
};


} // namespace i2d


#endif // !i2d_CDataNodePolylineBase_included

