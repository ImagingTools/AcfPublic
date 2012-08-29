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
	virtual ~CMultiModelObserverBase();

	/**
		Get access to connected model with the index \c index.
	*/
	IModel* GetModelPtr(int modelIndex) const;

	/**
		Gets the number of connected models.	
	*/
	int GetModelCount() const;

	// reimplemented (imod::IObserver)
	virtual bool IsModelAttached(const IModel* modelPtr) const;
	virtual bool OnAttached(IModel* modelPtr);
	virtual bool OnDetached(IModel* modelPtr);
	virtual void BeforeUpdate(IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);
	virtual void AfterUpdate(IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

protected:
	void EnsureModelsDetached();

	virtual void OnUpdate(IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

private:
	typedef QVector<IModel*> Models;

	Models m_models;
};


} // namespace imod


#endif // !imod_CMultiModelObserverBase_included

