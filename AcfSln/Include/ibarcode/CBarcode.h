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


#ifndef ibarcode_CBarcode_included
#define ibarcode_CBarcode_included


// ACF includes
#include <ibarcode/IBarcode.h>


namespace ibarcode
{


/**
	Implementation of the simple barcode data container.
*/
class CBarcode: virtual public IBarcode
{
public:
	CBarcode(int barcodeType = BT_UNKNOWN, const QString& data = QString());
	CBarcode(const ibarcode::CBarcode& barcode);

	virtual CBarcode& operator=(const CBarcode& barcode);
	virtual bool operator==(const CBarcode& barcode) const;
	virtual bool operator!=(const CBarcode& barcode) const;

	virtual void SetData(const QString& barcodeData);

	// reimplemented (ibarcode::IBarcode)
	virtual const QString& GetBarcodeData() const;
	virtual int GetBarcodeType() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	QString m_barcodeData;
	int m_barcodeType;
};


} // namespace ibarcode


#endif // !ibarcode_CBarcode_included


