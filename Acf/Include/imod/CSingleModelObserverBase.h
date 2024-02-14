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


#ifndef imod_CSingleModelObserverBase_included
#define imod_CSingleModelObserverBase_included


// ACF includes
#include <imod/IObserver.h>


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
	imod::IModel* GetObservedModel() const;
	/**
		Get access to observed model.
		\deprecated use \c GetObservedModel instead.
		\return	pointer to observed model, or NULL if no model is connected.
	*/
	imod::IModel* GetModelPtr() const;
	/**
		Make sure this observer is detached.
		It calls model method DetachObserver() if model is available.
	*/
	void EnsureModelDetached();

	/**
		Set list of ID's beeing observed.
	*/
	void SetObservedIds(const istd::IChangeable::ChangeSet& changeMask);

	// reimplemented (imod::IObserver)
	virtual bool IsModelAttached(const imod::IModel* modelPtr = NULL) const;
	virtual bool OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask);
	virtual bool OnModelDetached(imod::IModel* modelPtr);
	virtual void BeforeUpdate(imod::IModel* modelPtr);
	virtual void AfterUpdate(imod::IModel* modelPtr, const istd::IChangeable::ChangeSet& changeSet);

protected:
	/**
		Set internal model pointer to specified value.
	*/
	void SetModelPtr(imod::IModel* modelPtr);

	/**
		Called on update of observed model.
		This method is designed to be overload by derrived classes.
	*/
	virtual void OnUpdate(const istd::IChangeable::ChangeSet& changeSet);

protected:
	static const istd::IChangeable::ChangeSet s_undoChanges;

private:
	Q_DISABLE_COPY(CSingleModelObserverBase)

	imod::IModel* m_modelPtr;

	istd::IChangeable::ChangeSet m_observedIds;
};


// inline methods

inline imod::IModel* CSingleModelObserverBase::GetObservedModel() const
{
	return m_modelPtr;
}


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


