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


#ifndef ibarcode_IBarcode_included
#define ibarcode_IBarcode_included


// ACF includes
#include <iser/ISerializable.h>


namespace ibarcode
{


/**
	Interface for access the barcode data.
*/
class IBarcode: virtual public iser::ISerializable
{
public:
	/**
		Supported barcode types.
	*/
	enum BarcodeType
	{
		BT_UNKNOWN,
		BT_CODABAR,
		BT_EAN_8,
		BT_EAN_13,
		BT_CODE_128,
		BT_CODE_39,
		BT_CODE_93,
		BT_INTERLEAVED_2_5,
		BT_PDF_417,
		BT_DATAMATRIX,
		BT_QR
	};

	I_DECLARE_ENUM(BarcodeType, BT_UNKNOWN, BT_CODABAR, BT_EAN_8, BT_EAN_13, BT_CODE_128, BT_CODE_39, BT_CODE_93, BT_INTERLEAVED_2_5, BT_PDF_417, BT_DATAMATRIX, BT_QR);

	/**
		Get the data of the barcode.
	*/
	virtual const QString& GetBarcodeData() const = 0;

	/**
		Get the type of the barcode.
		\sa BarcodeType
	*/
	virtual int GetBarcodeType() const = 0;
};


} // namespace ibarcode


#endif // !ibarcode_IBarcode_included


