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


#ifndef imod_TSingleModelObserverBase_included
#define imod_TSingleModelObserverBase_included


// Qt includes
#include <QtCore/QString>

// ACF includes 
#include "imod/CSingleModelObserverBase.h" 
#include "imod/IModel.h" 


namespace imod
{


/**
	Basic implementation for a single model observer with binding to concrete data object interface.

	\ingroup ModelObserver
*/
template <class ModelInterface> 
class TSingleModelObserverBase: public CSingleModelObserverBase
{
public:
	typedef CSingleModelObserverBase BaseClass;
	typedef ModelInterface ModelType;

	TSingleModelObserverBase();

	ModelInterface* GetObjectPtr() const;

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);
	virtual bool OnDetached(imod::IModel* modelPtr);

private:
	ModelInterface* m_objectPtr;
};


// public methods

template <class ModelInterface> 
TSingleModelObserverBase<ModelInterface>::TSingleModelObserverBase()
{
	m_objectPtr = NULL;
}


template <class ModelInterface> 
ModelInterface* TSingleModelObserverBase<ModelInterface>::GetObjectPtr() const
{
	return m_objectPtr;
}


// reimplemented (imod::IObserver)

template <class ModelInterface> 
bool TSingleModelObserverBase<ModelInterface>::OnAttached(imod::IModel* modelPtr)
{
	m_objectPtr = dynamic_cast<ModelInterface*>(modelPtr);

	I_IF_DEBUG(
		if (m_objectPtr == NULL){
			QString exptectedObjectInterface = typeid(ModelInterface).name();

			QString debugMessage = QString("Data model interface is not supported by this observer. Expected interface is: %1").arg(exptectedObjectInterface);

			qDebug(debugMessage.toUtf8());
		}
	)

	if ((m_objectPtr != NULL) && BaseClass::OnAttached(modelPtr)){
		return true;
	}

	BaseClass::EnsureModelDetached();

	return false;
}


template <class ModelInterface> 
bool TSingleModelObserverBase<ModelInterface>::OnDetached(imod::IModel* modelPtr)
{
	if (BaseClass::OnDetached(modelPtr)){
		// If model was correctly attached m_objectPtr cannot be NULL. OnDetach returns true only if model was correctly attached.
		I_ASSERT(m_objectPtr != NULL);

		m_objectPtr = NULL;

		return true;
	}

	return false;
}


} // namespace imod


#endif // !imod_TSingleModelObserverBase_included


