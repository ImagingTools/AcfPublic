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


#ifndef imod_CMultiModelObserverBase_included
#define imod_CMultiModelObserverBase_included


// Qt includes
#include <QtCore/QVector>
#include <QtCore/QMutex>

// ACF includes
#include <imod/IModel.h>
#include <imod/IObserver.h>


namespace imod
{


/**
	Basic implementation of a multiple model observer.

	\ingroup ModelObserver
*/
class CMultiModelObserverBase: virtual public IObserver
{
public:
	CMultiModelObserverBase();
	virtual ~CMultiModelObserverBase();

	/**
		Gets the number of connected models.	
	*/
	int GetModelCount() const;

	/**
		Get access to connected model with the index \c index.
		\param	modelIndex index of model.
	*/
	IModel* GetObservedModel(int modelIndex) const;

	/**
		Get access to connected model with the index \c index.
		\deprecated use \c GetObservedModel instead.
	*/
	IModel* GetModelPtr(int modelIndex) const;

	/**
		Ensure all attached models are detached.
		If there are some attached models they will be detached and removed from observed list.
	*/
	void EnsureModelsDetached();

	/**
		Set list of ID's beeing observed.
	*/
	void SetObservedIds(const istd::IChangeable::ChangeSet& changeMask);

	// reimplemented (imod::IObserver)
	virtual bool IsModelAttached(const IModel* modelPtr) const override;
	virtual bool OnModelAttached(IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask) override;
	virtual bool OnModelDetached(IModel* modelPtr) override;
	virtual void BeforeUpdate(IModel* modelPtr) override;
	virtual void AfterUpdate(IModel* modelPtr, const istd::IChangeable::ChangeSet& changeSet) override;

protected:
	/**
		Called on update of observed model.
		This method is designed to be overload by derrived classes.
	*/
	virtual void OnUpdate(IModel* modelPtr, const istd::IChangeable::ChangeSet& changeSet);

private:
	bool IsAttached(const imod::IModel* modelPtr) const;

	typedef QVector<IModel*> Models;
	Models m_models;

	istd::IChangeable::ChangeSet m_observedIds;

#if QT_VERSION >= 0x060000
	mutable QRecursiveMutex m_mutex;
#else
	mutable QMutex m_mutex;
#endif
};


} // namespace imod


#endif // !imod_CMultiModelObserverBase_included

