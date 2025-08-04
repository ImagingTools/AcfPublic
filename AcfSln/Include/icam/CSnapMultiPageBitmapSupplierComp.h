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


#ifndef icam_CSnapMultiPageBitmapSupplierComp_included
#define icam_CSnapMultiPageBitmapSupplierComp_included


// Qt includes
#include <QtCore/QPair>

// ACF includes
#include <istd/TDelPtr.h>
#include <iimg/CMultiPageBitmapBase.h>
#include <idoc/IMultiPageDocumentProvider.h>

// ACF-Solutions includes
#include <iproc/IProcessor.h>
#include <iinsp/TSupplierCompWrap.h>
#include <imeas/INumericConstraints.h>
#include <imeas/CSimpleNumericValue.h>


namespace icam
{


/**
	Implementation of bitmap supplier based on image acquisition.
*/
class CSnapMultiPageBitmapSupplierComp:
	public iinsp::TSupplierCompWrap<iimg::IMultiBitmapProviderSharedPtr>,
			virtual public iimg::IMultiBitmapProvider,
			virtual public idoc::IMultiPageDocumentProvider
{
public:
	typedef iinsp::TSupplierCompWrap<iimg::IMultiBitmapProviderSharedPtr> BaseClass;

	I_BEGIN_COMPONENT(CSnapMultiPageBitmapSupplierComp);
		I_REGISTER_INTERFACE(iimg::IMultiBitmapProvider);
		I_REGISTER_INTERFACE(idoc::IMultiPageDocumentProvider);
		I_ASSIGN(m_bitmapCompFact, "BitmapFactory", "Use to create bitmap object", true, "BitmapFactory");
		I_ASSIGN(m_bitmapAcquisitionCompPtr, "BitmapAcquisition", "Bitmap acquisition object for image snap", true, "BitmapAcquisition");
	I_END_COMPONENT;

	// reimplemented (iimg::IMultiBitmapProvider)
	virtual int GetBitmapsCount() const;
	virtual const iimg::IBitmap* GetBitmap(int bitmapIndex) const;
	virtual const iprm::IOptionsList* GetBitmapListInfo() const;

	// reimplemented (idoc::IMultiPageDocumentProvider)
	virtual const idoc::IMultiPageDocument* GetDocument() const;

protected:
	// reimplemented (iinsp::TSupplierCompWrap)
	virtual bool InitializeWork();
	virtual iinsp::ISupplier::WorkStatus ProduceObject(ProductType& result) const;

private:
	I_FACT(iimg::IMultiBitmapProvider, m_bitmapCompFact);
	I_REF(iproc::IProcessor, m_bitmapAcquisitionCompPtr);
};


} // namespace icam


#endif // !icam_CSnapMultiPageBitmapSupplierComp_included


