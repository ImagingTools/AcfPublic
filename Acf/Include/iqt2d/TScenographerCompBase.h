/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt2d_TScenographerCompBase_included
#define iqt2d_TScenographerCompBase_included


// Qt includes
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneDragDropEvent>


// ACF includes
#include "icomp/CComponentBase.h"

#include "iqtgui/IDropConsumer.h"

#include "iqt2d/ISceneProvider.h"


namespace iqt2d
{


template <class Observer>
class TScenographerCompBase:
			public icomp::CComponentBase,
			public Observer,
			virtual public iqtgui::IDropConsumer
{

public:
	typedef icomp::CComponentBase BaseClass;
	typedef Observer BaseClass2;

	I_BEGIN_COMPONENT(TScenographerCompBase);
		I_REGISTER_INTERFACE(iqtgui::IDropConsumer);
		I_REGISTER_INTERFACE(imod::IObserver);
		I_ASSIGN(m_sceneProviderCompPtr, "SceneProvider", "Display view where the registry will be shown", true, "SceneProvider");
	I_END_COMPONENT;

	TScenographerCompBase();

	/**
		Specifiy the flags that will be ignored by the update logic of the scene.
	*/
	void SetIgnoreChanges(int ignoreUpdateFlags);

	/**
		Set accepted mime types.
		For this types drag'n'drop functionality is enabled.
	*/
	void SetAcceptedMimeTypes(const QStringList& mimeTypes);

	// reimplemented (iqtgui::IDropConsumer)
	virtual QStringList GetAcceptedMimeIds() const;
	virtual void OnDropFinished(const QMimeData& mimeData, QEvent* eventPtr);

	// reimplemented (imod::IObserver)
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

protected:
	/**
		Event handler for the drop action.

		Default implementation does nothing.
	*/
	virtual bool OnDropObject(const QMimeData& data, QGraphicsSceneDragDropEvent* eventPtr);

	/**
		Update scene according to made changes.

		Default implementation does nothing.
	*/
	virtual void UpdateScene(int updateFlags);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

protected:
	I_REF(iqt2d::ISceneProvider, m_sceneProviderCompPtr);

	QGraphicsScene* m_scenePtr;

	bool m_isUpdating;

	int m_ignoreUpdateFlags;

	QStringList m_acceptedMimeTypes;
};



// public methods

template <class Observer>
TScenographerCompBase<Observer>::TScenographerCompBase()
:	m_scenePtr(NULL),
	m_isUpdating(false),
	m_ignoreUpdateFlags(0)
{
}


	
template <class Observer>
void TScenographerCompBase<Observer>::SetIgnoreChanges(int ignoreUpdateFlags)
{
	m_ignoreUpdateFlags = ignoreUpdateFlags;
}


template <class Observer>
void TScenographerCompBase<Observer>::SetAcceptedMimeTypes(const QStringList& mimeTypes)
{
	m_acceptedMimeTypes = mimeTypes;
}


// reimplemented (iqtgui::IDropConsumer)

template <class Observer>
QStringList TScenographerCompBase<Observer>::GetAcceptedMimeIds() const
{
	return m_acceptedMimeTypes;
}


template <class Observer>
void TScenographerCompBase<Observer>::OnDropFinished(const QMimeData& mimeData, QEvent* eventPtr)
{
	QGraphicsSceneDragDropEvent* sceneEventPtr = dynamic_cast<QGraphicsSceneDragDropEvent*>(eventPtr);
	if (sceneEventPtr != NULL){
		OnDropObject(mimeData, sceneEventPtr);
	}
}


// reimplemented (imod::CSingleModelObserverBase)

template <class Observer>
void TScenographerCompBase<Observer>::AfterUpdate(imod::IModel* /*modelPtr*/, int updateFlags, istd::IPolymorphic* /*updateParamsPtr*/)
{
	int filteredFlags = (updateFlags & ~m_ignoreUpdateFlags);
	if (filteredFlags == 0){
		// some unimportant model changes
		return;
	}

	if (m_scenePtr == NULL){
		return;
	}

	m_isUpdating = true;

	UpdateScene(filteredFlags);

	m_isUpdating = false;
}


// protected methods

template <class Observer>
bool TScenographerCompBase<Observer>::OnDropObject(const QMimeData& /*mimeData*/, QGraphicsSceneDragDropEvent* /*eventPtr*/)
{
	return true;
}


template <class Observer>
void TScenographerCompBase<Observer>::UpdateScene(int /*updateFlags*/)
{
}


// reimplemented (icomp::CComponentBase)

template <class Observer>
void TScenographerCompBase<Observer>::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_sceneProviderCompPtr.IsValid()){
		I_ASSERT(m_scenePtr == NULL);
		m_scenePtr = m_sceneProviderCompPtr->GetScene();

	}
}


template <class Observer>
void TScenographerCompBase<Observer>::OnComponentDestroyed()
{
	m_scenePtr = NULL;
}


} // namespace iqt2d


#endif // !iqt2d_TScenographerCompBase_included


