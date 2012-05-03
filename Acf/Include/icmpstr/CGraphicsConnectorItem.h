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


#ifndef icmpstr_CGraphicsConnectorItem_included
#define icmpstr_CGraphicsConnectorItem_included


// Qt includes
#include <QtCore/QObject>
#include <QtGui/QGraphicsItem>

// ACF includes
#include "icmpstr/ISceneProvider.h"


namespace icmpstr
{


class CComponentSceneItem;
class CRegistryElementShape;


class CGraphicsConnectorItem:
			public QObject,
			public QGraphicsItem
{
	Q_OBJECT

public:
	typedef QGraphicsItem BaseClass;

	enum ConnectFlags
	{
		CF_FACTORY = 0x0001,
		CF_EMBEDDED  =0x0002
	};

	enum GeometricParams
	{
		GP_RADIUS = 4,
		GP_RADIUS2 = 8,
		GP_OFFSET = 12
	};

    CGraphicsConnectorItem(
				const icmpstr::ISceneProvider& sceneProvider,
				int connectFlags = 0,
				QGraphicsItem* parent = NULL);

	void InitEnds(CRegistryElementShape* sourceShapePtr, CRegistryElementShape* destShapePtr);
    
	// reimplemented (QGraphicsItem)
    virtual int type() const;
	virtual QPainterPath shape() const;
	virtual bool contains(const QPointF& point) const;

protected:
    void Adjust();

	// reimplemented (QGraphicsItem)
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

protected Q_SLOTS:
	void OnSourceRectMoved(const QRectF& rect);
	void OnDestRectMoved(const QRectF& rect);
	void OnSourceSelected(bool state);
	void OnDestSelected(bool state);

private:
	const icmpstr::ISceneProvider& m_sceneProvider;

	int m_connectFlags;

	QPolygonF m_connectionLine;
	QPointF m_touchPoint;

	QRectF m_sourceRect;
	QRectF m_destRect;
	bool m_isSourceSelected;
	bool m_isDestSelected;
};


} // namespace icmpstr


#endif // !icmpstr_CGraphicsConnectorItem_included


