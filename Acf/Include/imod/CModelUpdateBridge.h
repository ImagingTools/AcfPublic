/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef imod_CModelUpdateBridge_included
#define imod_CModelUpdateBridge_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include <istd/IChangeable.h>
#include <imod/IModel.h>
#include <imod/IObserver.h>


namespace imod
{


/**
	Reflects the changes of observed objects as changes of some other object (over istd::IChangeable), typically delegated to itself.
	In other words: it allows to connect as observer to multiple models and call \c BeginChanges and \c EndChanges on some its changes.
	\sa imod::CMultiModelDispatcherBase.

	\ingroup ModelObserver

*/
class CModelUpdateBridge: virtual public IObserver
{
public:
	explicit CModelUpdateBridge(istd::IChangeable* changeablePtr);

	virtual ~CModelUpdateBridge();

	/**
		Get access to connected model with the index \c index.
	*/
	imod::IModel* GetObservedModel(int modelIndex) const;

	/**
		Gets the number of connected models.	
	*/
	int GetModelCount() const;

	/**
		Remove all observed models from this bridge.
	*/
	void EnsureModelsDetached();

	// reimplemented (imod::IObserver)
	virtual bool IsModelAttached(const imod::IModel* modelPtr) const;
	virtual bool OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask);
	virtual bool OnModelDetached(imod::IModel* modelPtr);
	virtual void BeforeUpdate(imod::IModel* modelPtr);
	virtual void AfterUpdate(imod::IModel* modelPtr, const istd::IChangeable::ChangeSet& changeSet);

private:
	typedef QVector<imod::IModel*> Models;
	Models m_models;

	istd::IChangeable* m_changeablePtr;
};


} // namespace imod


#endif // !imod_CModelUpdateBridge_included

