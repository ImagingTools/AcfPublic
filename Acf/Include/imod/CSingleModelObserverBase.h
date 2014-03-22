/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef imod_CSingleModelObserverBase_included
#define imod_CSingleModelObserverBase_included


// ACF includes
#include "imod/IObserver.h" 


namespace imod
{


class IModel;


/**
	Basic implementation for a single model observer.
	Derrived implementations can reimplement simplified OnUpdate method to be notified about model changes.

	\ingroup ModelObserver
*/
class CSingleModelObserverBase: virtual public IObserver 
{
public:
	typedef imod::IModel ModelType;

	CSingleModelObserverBase();
	virtual ~CSingleModelObserverBase();

	/**
		Get access to observed model.
		\return	pointer to observed model, or NULL if no model is connected.
	*/
	imod::IModel* GetModelPtr() const;
	/**
		Make sure this observer is detached.
		It calls model method DetachObserver() if model is available.
	*/
	void EnsureModelDetached();

	// reimplemented (imod::IObserver)
	virtual bool IsModelAttached(const imod::IModel* modelPtr = NULL) const;
	virtual bool OnAttached(imod::IModel* modelPtr);
	virtual bool OnDetached(imod::IModel* modelPtr);
	virtual void BeforeUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

protected:
	/**
		Set internal model pointer to specified value.
	*/
	void SetModelPtr(imod::IModel* modelPtr);

	virtual void OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr);

private:
	imod::IModel* m_modelPtr;
};


// inline methods

inline imod::IModel* CSingleModelObserverBase::GetModelPtr() const
{
	return m_modelPtr;
}


// reimplemented (imod::IObserver)

inline bool CSingleModelObserverBase::IsModelAttached(const imod::IModel* modelPtr) const
{
	if (modelPtr == NULL){
		return m_modelPtr != NULL;
	}

	return m_modelPtr == modelPtr;
}


// protected inline methods

inline void CSingleModelObserverBase::SetModelPtr(imod::IModel* modelPtr)
{
	m_modelPtr = modelPtr;
}


} // namespace imod


#endif // !imod_CSingleModelObserverBase_included


