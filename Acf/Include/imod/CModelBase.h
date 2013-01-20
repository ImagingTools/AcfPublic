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


#ifndef imod_CModelBase_included
#define imod_CModelBase_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include "imod/imod.h"
#include "imod/IModel.h"
#include "imod/IObserver.h"


namespace imod
{		


/**
	Basic implementation of a model.

	\ingroup ModelObserver
*/
class CModelBase: virtual public imod::IModel
{
public:
	CModelBase();
	virtual ~CModelBase();

	/**
		Returns count of connected observers.
	*/
	virtual int GetObserverCount() const;

	/**
		Returns pointer to a given observer.
	*/
	virtual IObserver* GetObserverPtr(int index) const;

	// reimplemented (imod::IModel)
	virtual bool AttachObserver(imod::IObserver* observerPtr);
	virtual void DetachObserver(imod::IObserver* observerPtr);
	virtual void DetachAllObservers();
	virtual bool IsAttached(const imod::IObserver* observerPtr) const;

protected:
	/**
		Notifies all observers about begin of changes in the data model.
		For updating control you can use some specified flags \c updateFlags
		and for additional data transfer \c udpateParamsPtr.
		\sa NotifyAfterUpdate()
	*/
	virtual void NotifyBeforeUpdate(int updateFlags = 0, istd::IPolymorphic* updateParamsPtr = NULL);

	/**
		Notifies all observers that the changes are finished.
		For updating control you can use some specified flags \c updateFlags
		and for additional data transfer \c udpateParamsPtr.
		\sa NotifyBeforeUpdate()
	*/
	virtual void NotifyAfterUpdate(int updateFlags = 0, istd::IPolymorphic* updateParamsPtr = NULL);

private:
	CModelBase(const CModelBase& modelBase);

	/**
		Observer connection state.
	*/
	enum StateFlag
	{
		/**
			Observer is connected to the model.
		*/
		SF_CONNECTED,

		/**
			Observer is in detaching stage.
		*/
		SF_DETACHING_STAGE
	};

	struct ObserverInfo
	{
		IObserver* observerPtr;
		StateFlag connectionState;
	};

	typedef QVector<ObserverInfo> Observers;
	Observers m_observers;
};


} // namespace imod


#endif // !imod_CModelBase_included

