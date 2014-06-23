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


#ifndef imod_CMultiModelObserverBase_included
#define imod_CMultiModelObserverBase_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include "imod/IModel.h"
#include "imod/IObserver.h"


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
		Get access to connected model with the index \c index.
	*/
	IModel* GetModelPtr(int modelIndex) const;

	/**
		Gets the number of connected models.	
	*/
	int GetModelCount() const;

	/**
		Set list of ID's beeing observed.
	*/
	void SetObservedIds(const istd::IChangeable::ChangeSet& changeMask);

	// reimplemented (imod::IObserver)
	virtual bool IsModelAttached(const IModel* modelPtr) const;
	virtual bool OnModelAttached(IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask);
	virtual bool OnModelDetached(IModel* modelPtr);
	virtual void BeforeUpdate(IModel* modelPtr);
	virtual void AfterUpdate(IModel* modelPtr, const istd::IChangeable::ChangeSet& changeSet);

protected:
	void EnsureModelsDetached();

	virtual void OnUpdate(IModel* modelPtr, const istd::IChangeable::ChangeSet& changeSet);

private:
	typedef QVector<IModel*> Models;

	Models m_models;

	istd::IChangeable::ChangeSet m_observedIds;
};


} // namespace imod


#endif // !imod_CMultiModelObserverBase_included

