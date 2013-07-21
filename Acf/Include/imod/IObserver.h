/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef imod_IObserver_included
#define imod_IObserver_included


// ACF includes
#include "istd/IPolymorphic.h"

#include "imod/imod.h"


namespace imod
{


class IModel;


/**
	Common interface for all classes implementing the Observer functionality
	in the Model/Observer design pattern.

	\ingroup ModelObserver
*/
class IObserver: virtual public istd::IPolymorphic
{
public:
	/**
		Check if specified model is attached.
		\modelPtr	pointer to model object. If this pointer is NULL, any model is meaned.
		\return	true, if \c modelPtr is attached yet to this observer, false otherwise.
	*/
	virtual bool IsModelAttached(const IModel* modelPtr = NULL) const = 0;
	/**
		This call back function will be called, if an observable object is about to be attached.
		This function returns a \c true, if observable object is accepted 
		by the implementation logic of the observer, otherwise the function 
		returns a \c false.
	*/
	virtual bool OnAttached(IModel* modelPtr) = 0;

	/**
		This call back function will be called, if an observable object is about to be detached.
	*/
	virtual bool OnDetached(IModel* modelPtr) = 0;

	/**
		This function will be called before update of the observer contents occures.
		Please note, that in some cases no following AfterUpdate can be called.
	*/
	virtual void BeforeUpdate(IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr) = 0;

	/**
		This function will be called after update of the observer contents occures.
	*/
	virtual void AfterUpdate(IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr) = 0;
};


} // namespace imod


#endif // !imod_IObserver_included


