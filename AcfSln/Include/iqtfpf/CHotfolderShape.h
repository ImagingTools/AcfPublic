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


#ifndef iqtfpf_CHotfolderShape_included
#define iqtfpf_CHotfolderShape_included


// Qt includes
#include <QtGui/QGraphicsRectItem>

// ACF includes
#include "imod/TSingleModelObserverBase.h"

#include "ifpf/CVisualHotfolderWorkflowItem.h"

#include "iqt2d/TObjectShapeBase.h"



namespace iqtfpf
{


class CHotfolderShape: public iqt2d::TObjectShapeBase<QGraphicsRectItem, ifpf::CVisualHotfolderWorkflowItem>
{
	Q_OBJECT

public:
	typedef iqt2d::TObjectShapeBase<QGraphicsRectItem, ifpf::CVisualHotfolderWorkflowItem> BaseClass;

	CHotfolderShape(const iqt2d::ISceneProvider* providerPtr = NULL);

	QRectF GetViewRect() const;

	// reimplemented (QGraphicsItem)
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter* painterPtr, const QStyleOptionGraphicsItem* stylePtr, QWidget* widgetPtr);

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);

Q_SIGNALS:
	void SelectionChanged(bool state);

protected:
	enum
	{
		SIDE_OFFSET = 4,
		SHADOW_OFFSET = 10
	};

	// reimplemented (iqt2d::TObjectShapeBase)
	virtual void UpdateGraphicsItem(const ifpf::CVisualHotfolderWorkflowItem& element);

	// reimplemented (TShapeBase)
	virtual void OnSelectionChanged(bool isSelected);

private:
	QGraphicsTextItem* m_hotfolderName;

};


} // namespace iqtfpf


#endif // !iqtfpf_CHotfolderShape_included


