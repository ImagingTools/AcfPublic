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


#ifndef iimg_CMultiPageBitmapBase_included
#define iimg_CMultiPageBitmapBase_included


// ACF includes
#include "imod/TModelWrap.h"
#include "idoc/TMultiPageDocumentWrap.h"
#include "idoc/CStandardDocumentMetaInfo.h"
#include "iimg/IMultiBitmapProvider.h"
#include "iimg/IMultiPageBitmapController.h"


namespace iimg
{


/**
	Definition of a multi-page bitmap document.
*/
class CMultiPageBitmapBase:
			public idoc::CMultiPageDocumentBase,
			virtual public IMultiBitmapProvider,
			virtual public IMultiPageBitmapController
{
public:
	typedef idoc::CMultiPageDocumentBase BaseClass;

	// reimplemented (idoc::IMultiPageDocument)
	virtual istd::IChangeable* InsertPage(
				const idoc::IDocumentMetaInfo* pageMetaInfoPtr = NULL,
				const iprm::IParamsSet* pageParameterPtr = NULL,
				int position = -1);

	// reimplemented (iimg::IMultiBitmapProvider)
	virtual const iprm::IOptionsList* GetBitmapListInfo() const;
	virtual int GetBitmapsCount() const;
	virtual const iimg::IBitmap* GetBitmap(int bitmapIndex) const;

	// reimplemented (iimg::IMultiPageBitmapController)
	virtual void Reset();
	virtual iimg::IBitmap* InsertBitmap(
				iimg::IBitmap::PixelFormat pixelFormat,
				const istd::CIndex2d& size);
	virtual iimg::IBitmap* InsertBitmap(
				iimg::IBitmap::PixelFormat pixelFormat,
				const istd::CIndex2d& size,
				void* dataPtr,
				bool releaseFlag,
				int linesDifference = 0);
	virtual void RemoveBitmap(int index);

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const istd::IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);

protected:
	// abstract methods
	virtual IBitmap* CreateBitmap() const = 0;
};


} // namespace iimg


#endif // !iimg_CMultiPageBitmapBase_included


