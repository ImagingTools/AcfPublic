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


#include "iimg/CMultiPageBitmapBase.h"


namespace iimg
{


// public methods

// reimplemented (idoc::IMultiPageDocument)

istd::IChangeable* CMultiPageBitmapBase::InsertPage(
			const idoc::IDocumentMetaInfo* pageMetaInfoPtr,
			const iprm::IParamsSet* /*pageParameterPtr*/,
			int position)
{
	istd::CChangeNotifier changePtr(this);

	Page newPage;

	IBitmap* bitmapPtr = CreateBitmap();

	if (pageMetaInfoPtr != NULL){
		newPage.pageMetaInfo.CopyFrom(*pageMetaInfoPtr);
	}

	newPage.pagePtr.SetPtr(bitmapPtr);

	if (position < 0){
		m_documentPages.push_back(newPage);
	}
	else{
		position = qMin(m_documentPages.count(), position);

		m_documentPages.insert(position, newPage);
	}

	return bitmapPtr;
}


// reimplemented (iimg::IMultiBitmapProvider)

const iprm::IOptionsList* CMultiPageBitmapBase::GetBitmapListInfo() const
{
	return this;
}


int CMultiPageBitmapBase::GetBitmapsCount() const
{
	return GetPagesCount();
}


const iimg::IBitmap* CMultiPageBitmapBase::GetBitmap(int bitmapIndex) const
{
	return dynamic_cast<const iimg::IBitmap*>(m_documentPages.at(bitmapIndex).pagePtr.GetPtr());
}


// reimplemented (iimg::IMultiPageBitmapController)

void CMultiPageBitmapBase::Reset()
{
	ResetPages();
}


iimg::IBitmap* CMultiPageBitmapBase::InsertBitmap(
			iimg::IBitmap::PixelFormat pixelFormat, 
			const istd::CIndex2d& size)
{
	iimg::IBitmap* pagePtr = dynamic_cast<iimg::IBitmap*>(InsertPage());
	if (!pagePtr->CreateBitmap(pixelFormat, size)){
		RemovePage(GetPagesCount() - 1);

		return NULL;
	}

	return pagePtr;
}


iimg::IBitmap* CMultiPageBitmapBase::InsertBitmap(
			iimg::IBitmap::PixelFormat pixelFormat, 
			const istd::CIndex2d& size, 
			void* dataPtr, 
			bool releaseFlag, 
			int linesDifference /*= 0*/)
{
	iimg::IBitmap* pagePtr = dynamic_cast<iimg::IBitmap*>(InsertPage());
	if (!pagePtr->CreateBitmap(pixelFormat, size, dataPtr, releaseFlag, linesDifference)){
		RemovePage(GetPagesCount() - 1);

		return NULL;
	}

	return pagePtr;
}


void CMultiPageBitmapBase::RemoveBitmap(int index)
{
	RemovePage(index);
}


} // namespace iimg


