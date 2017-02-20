/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#pragma once



// ACF-Solutions includes
#include <icam/CSnapBitmapSupplierCompBase.h>


namespace icam
{


/**
	Factory-based Snap Bitmap Supplier (not thread-safe). 
*/
class CSnapBitmapSupplierComp: public CSnapBitmapSupplierCompBase
{
public:
	typedef CSnapBitmapSupplierCompBase BaseClass;

	I_BEGIN_COMPONENT(CSnapBitmapSupplierComp);
		I_ASSIGN(m_bitmapCompFact, "BitmapFactory", "Use to create bitmap object", true, "BitmapFactory");
	I_END_COMPONENT;

protected:
	// reimplemented (CSnapBitmapSupplierCompBase)
	virtual iimg::IBitmap* CreateBitmap() const;

private:
	I_FACT(iimg::IBitmap, m_bitmapCompFact);
};


} // namespace icam


