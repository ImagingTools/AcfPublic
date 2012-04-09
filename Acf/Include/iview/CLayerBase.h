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


#ifndef iview_CLayerBase_included
#define iview_CLayerBase_included


#include "iview/ILayer.h"
#include "iview/TLayerBaseEx.h"


namespace iview
{


class CLayerBase: public TLayerBaseEx<ILayer>
{
public:
	typedef TLayerBaseEx<ILayer> BaseClass;

	CLayerBase();
	virtual ~CLayerBase();

	// reimplemented (iview::TLayerBaseEx)
	void CalcBoundingBox(i2d::CRect& result) const;

	// reimplemented (iview::ILayer)
	virtual bool IsShapeConnected(IShape* shapePtr);
	virtual bool ConnectShape(IShape* shapePtr);
	virtual int GetShapesCount() const;
	virtual void UpdateAllShapes(int changeFlag);
	virtual void DisconnectAllShapes();
	virtual void DrawShapes(QPainter& drawContext);
	
	// reimplemented (iview::IShapeObserver)
	virtual void OnChangeShape(IShape* shapePtr);
	virtual void DisconnectShape(IShape* shapePtr);

protected:
	ShapeMap m_shapes;
};


} // namespace iview


#endif // !iview_CLayerBase_included


