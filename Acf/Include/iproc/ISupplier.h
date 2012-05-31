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


#ifndef iproc_ISupplier_included
#define iproc_ISupplier_included


// ACF includes
#include "istd/IPolymorphic.h"

#include "iprm/IParamsSet.h"

#include "iproc/iproc.h"


namespace iproc
{


/**
	Base interface for suppliers providing synchrone processing of single object with <em>"pull data" model</em>.
	Additional interfaces (providers) should provide access to intern stored produced objects.
	For example image provider should provide method \c{const iimg::IBitmap* GetBitmap() const}.
	The internal stored object should be created on demand.
*/
class ISupplier: virtual public istd::IPolymorphic
{
public:
	enum WorkStatus
	{
		/**
			Supplier is invalidated and will produce new result on demand.
		*/
		WS_INVALID,
		/**
			New work is initialized.
		*/
		WS_INIT,
		/**
			Supplier is locked becouse it is doing processing step.
		*/
		WS_LOCKED,
		/**
			Work was done correctly and no error occure.
		*/
		WS_OK,
		/**
			Work was canceled.
		*/
		WS_CANCELED,
		/**
			Work was done, but there were errors.
		*/
		WS_ERROR,
		/**
			Work cannot be done.
		*/
		WS_CRITICAL
	};

	enum ChangeFlags
	{
		/**
			Supplier result chenged.
		*/
		CF_SUPPLIER_RESULTS = 1 << 22
	};

	/**
		Called to signalize that this supplier is invalid.
		This signal will be transfered to all supplier which are registered as output.
		\return	true, if initialization could be done.
	*/
	virtual void InvalidateSupplier() = 0;

	/**
		Force the supplier to initialize its work.
	*/
	virtual void EnsureWorkInitialized() = 0;

	/**
		Ensure that all objects are produced.
	*/
	virtual void EnsureWorkFinished() = 0;

	/**
		Remove all stored work results.
		This set also work state to \c WS_INIT.
	*/
	virtual void ClearWorkResults() = 0;

	/**
		Get status of last work.
		\return	work status defined in iproc::ISupplier::WorkStatus.
	*/
	virtual int GetWorkStatus() const = 0;

	/**
		Get parameter set using by this supplier.
	*/
	virtual iprm::IParamsSet* GetModelParametersSet() const = 0;
};


} // namespace iproc


#endif // !iproc_ISupplier_included


