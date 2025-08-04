/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iimg_TMultiPageBitmap_included
#define iimg_TMultiPageBitmap_included


// ACF includes
#include <iimg/CMultiPageBitmapBase.h>
#include <iimg/CGeneralBitmap.h>


namespace iimg
{

	
/**
	Generic implementation of a multi-page bitmap.

	\tparam	BitmapImpl	Type of the bitmap implementation.

	\ingroup ImageProcessing
	\ingroup Geometry
*/
template <class BitmapImpl>
class TMultiPageBitmap: public CMultiPageBitmapBase
{
public:
	typedef CMultiPageBitmapBase BaseClass;
	typedef BitmapImpl BitmapType;

	// reimplemented (istd::IChangeable)
	virtual istd::IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const override;

protected:
	// reimplemented (CMultiPageBitmapBase)
	virtual IBitmapUniquePtr CreateBitmap() const override;
};


// public methods

// reimplemented (istd::IChangeable)

template <class BitmapImpl>
istd::IChangeable* TMultiPageBitmap<BitmapImpl>::CloneMe(CompatibilityMode mode) const
{
	istd::TDelPtr< TMultiPageBitmap<BitmapImpl> > clonedPtr(new TMultiPageBitmap<BitmapImpl>);
	if (clonedPtr->CopyFrom(*this, mode)){
		return clonedPtr.PopPtr();
	}

	return NULL;
}


// protected methods

// reimplemented (CMultiPageBitmapBase)

template <class BitmapImpl>
IBitmapUniquePtr TMultiPageBitmap<BitmapImpl>::CreateBitmap() const
{
	return new BitmapImpl;
}


typedef TMultiPageBitmap<CGeneralBitmap> CGeneralMultiPageBitmap;


} // namespace iimg


#endif // !iimg_TMultiPageBitmap_included


