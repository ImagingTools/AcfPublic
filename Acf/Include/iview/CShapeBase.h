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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iview_CShapeBase_included
#define iview_CShapeBase_included


// ACF includes
#include "imod/CSingleModelObserverBase.h"
#include "iview/IShape.h"
#include "iview/CShapeControl.h"


namespace iview
{


class CShapeBase:
			public imod::CSingleModelObserverBase,
			public CShapeControl,
			virtual public IShape

{
public:
	typedef CShapeControl BaseClass2;
	typedef imod::CSingleModelObserverBase BaseClass3;

	CShapeBase();
	CShapeBase(const CShapeBase& shape);
	virtual ~CShapeBase();

	/**
		Make this shape visible.
	*/
	virtual void SetVisible(bool state = true);
	virtual bool AssignToLayer(int layerType);

	// reimplemented (iview::CShapeControl)
	virtual void Invalidate(int changeFlags = 0);
	virtual iview::IDisplay* GetDisplayPtr() const;

	// reimplemented (iview::IShape)
	virtual int GetLayerType() const;
	virtual i2d::CRect GetBoundingBox() const;
	virtual const IColorSchema* GetUserColorSchema() const;
	virtual void SetUserColorSchema(const IColorSchema* schemaPtr);

	// reimplemented (iview::IVisualizable)
	virtual bool IsVisible() const;
	virtual bool IsDisplayAccepted(const IDisplay& display) const;
	virtual void OnConnectDisplay(IDisplay* displayPtr);
	virtual void OnDisconnectDisplay(IDisplay* displayPtr);
	virtual bool OnDisplayChange(int flags);

	// reimplemented (iview::ITouchable)
	virtual ITouchable::TouchState IsTouched(istd::CIndex2d position) const;
	virtual QString GetShapeDescriptionAt(istd::CIndex2d position) const;

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);
	virtual bool OnDetached(imod::IModel* modelPtr);
	virtual void OnUpdate(int changeFlags, istd::IPolymorphic* updateParamsPtr);

protected:
	/**
		Get display changes mask.
		Only changes there are in mask will be accepted, rest will be ignored.
	*/
	virtual int GetDisplayChangesMask();
	
	/**
		Invalidate bounding box.
		You can overload this method to provide validation of your internal attributes,
		because this method is called from Invalidate(int) and OnDisplayChange(int) methods.
		Please don't forget base method call in your implementations.
	*/
	virtual void InvalidateBoundingBox();

	/**
		Check if display is connected.
	*/
	bool IsDisplayConnected() const;

	/**
		Get color schema for this shape.
		It can be called only when display is connected \sa IsDisplayConnected().
	*/
	const IColorSchema& GetColorSchema() const;
	
	/**
		Get display client rectangle.
		It can be called only when display is connected \sa IsDisplayConnected().
	*/
	i2d::CRect GetClientRect() const;

	bool IsBoundingBoxValid() const;

	void DisconnectDisplay();

	// reimplemented (iview::CShapeControl)
	virtual const iview::CScreenTransform& GetViewToScreenTransform() const;

	// abstract methods
	/**
		Calculate bounding box.
		You have to implement this method in your shapes implementations.
	*/
	virtual i2d::CRect CalcBoundingBox() const = 0;

private:
	const IColorSchema* m_userColorSchemaPtr;
	IDisplay* m_displayPtr;
	mutable bool m_isBoundingBoxValid;
	mutable i2d::CRect m_boundingBox;
	int m_layerType;
	bool m_isVisible;
};


} // namespace iview


#endif // !iview_CShapeBase_included


