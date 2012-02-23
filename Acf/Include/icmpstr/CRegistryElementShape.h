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


#ifndef icmpstr_CRegistryElementShape_included
#define icmpstr_CRegistryElementShape_included


// Qt includes
#include <QGraphicsItem>

#include "imod/TSingleModelObserverBase.h"

#include "iqt2d/TObjectShapeBase.h"

#include "icmpstr/CVisualRegistryElement.h"


namespace icmpstr
{


class CVisualRegistryScenographerComp;


/**
	Visualization of geometrical registry elements.
*/
class CRegistryElementShape: public iqt2d::TObjectShapeBase<QGraphicsRectItem, CVisualRegistryElement>
{
	Q_OBJECT

public:
	typedef iqt2d::TObjectShapeBase<QGraphicsRectItem, CVisualRegistryElement> BaseClass;

	CRegistryElementShape(
				const CVisualRegistryScenographerComp* registryViewPtr,
				const iqt2d::ISceneProvider* providerPtr = NULL);

	QRectF GetViewRect() const;

	/**
		Check consistency, if it is changed do update.
	*/
	void CheckConsistency();

	// reimplemented (QGraphicsItem)
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter* painterPtr, const QStyleOptionGraphicsItem* stylePtr, QWidget* widgetPtr);
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* eventPtr);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* eventPtr);

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);

Q_SIGNALS:
	void RectChanged(QRectF rect);
	void SelectionChanged(bool state);

protected:
	enum
	{
		SIDE_OFFSET = 4,
		SHADOW_OFFSET = 10
	};

	void CalcExportedInteraces(const CVisualRegistryElement& element);

	// reimplemented (iqt2d::TObjectShapeBase)
	void UpdateGraphicsItem(const CVisualRegistryElement& element);

	// reimplemented (TShapeBase)
	virtual void OnSelectionChanged(bool isSelected);

private:
	const CVisualRegistryScenographerComp& m_registryView;

	QStringList m_exportedInterfacesList;

	QPointF m_lastClickPosition;

	// shadows
	QString m_addressString;
	QIcon m_icon;
	QIcon m_exportIcon;
	QIcon m_noteAttachedIcon;
	QIcon m_autoInitIcon;
	QColor m_backgroundColor;
	QColor m_backgroundSelectedColor;
	bool m_isConsistent;
	int m_componentType;
};


} // namespace icmpstr


#endif // !icmpstr_CRegistryElementShape_included


