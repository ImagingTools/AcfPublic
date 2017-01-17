/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#ifndef iinsp_IEnableableSupplier_included
#define iinsp_IEnableableSupplier_included


// ACF includes
#include <iinsp/ISupplier.h>


namespace iinsp
{


/**
	Extension of ISupplier interface with possiblity to activate/deactivate supplier's producing logic.
*/
class IEnableableSupplier: virtual public ISupplier
{
public:
	/**
		Data model change notification flags.
	*/
	enum ChangeFlags
	{
		/**
			Supplier's activation state was changed.
		*/
		CF_SUPPLIER_ACTIVATION = 0x6326416
	};

	/**
		Set supplier's activation state.
		If the state of supplier cannot be changed, the method will failed.
		\sa IsStateFixed
	*/
	virtual bool SetSupplierEnabled(bool isEnabled = true) = 0;

	/**
		Get activation state of the supplier.
	*/
	virtual bool IsSupplierEnabled() const = 0;

	/**
		Get \c true if the state of the supplier is fixed and cannot be changed.
	*/
	virtual bool IsStateFixed() const = 0;
};


} // namespace iinsp


#endif // !iinsp_IEnableableSupplier_included


