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


#ifndef ibarcode_CGeneralBarcodeSearchParams_included
#define ibarcode_CGeneralBarcodeSearchParams_included


// ACF includes
#include <ibarcode/IGeneralBarcodeSearchParams.h>


namespace ibarcode
{


/**
	Interface for basic barcode search parameters.
*/
class CGeneralBarcodeSearchParams: virtual public IGeneralBarcodeSearchParams
{
public:
	// reimplemented (IGeneralBarcodeSearchParams)
	virtual BarcodeTypes GetSearchBarcodeTypes() const;
	virtual void SetSearchBarcodeTypes(const BarcodeTypes& barcodeTypes);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	BarcodeTypes m_barcodeTypes;
};


} // namespace ibarcode


#endif // !ibarcode_CGeneralBarcodeSearchParams_included


