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


#include <iimg/CMultiPageBitmapBase.h>


namespace iimg
{


// public methods

// reimplemented (idoc::IMultiPageDocument)

istd::IChangeable* CMultiPageBitmapBase::InsertPage(
			const idoc::IDocumentMetaInfo* pageMetaInfoPtr,
			const iprm::IParamsSet* /*pageParameterPtr*/,
			int position)
{
	Page newPage;

	if (pageMetaInfoPtr != NULL){
		if (!newPage.pageMetaInfo.CopyFrom(*pageMetaInfoPtr)){
			return NULL;
		}
	}

	IBitmap* bitmapPtr = CreateBitmap();
	if (bitmapPtr == NULL){
		return NULL;
	}

	newPage.pagePtr.SetPtr(bitmapPtr);

	istd::CChangeNotifier changePtr(this);

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

iimg::IBitmap* CMultiPageBitmapBase::InsertBitmap(
			iimg::IBitmap::PixelFormat pixelFormat, 
			const istd::CIndex2d& size,
			const idoc::IDocumentMetaInfo* metaInfoPtr)
{
	iimg::IBitmap* pagePtr = dynamic_cast<iimg::IBitmap*>(InsertPage(metaInfoPtr));
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
			int linesDifference /*= 0*/,
			const idoc::IDocumentMetaInfo* metaInfoPtr)
{
	iimg::IBitmap* pagePtr = dynamic_cast<iimg::IBitmap*>(InsertPage(metaInfoPtr));
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


// reimplemented (istd::IChangeable)

bool CMultiPageBitmapBase::CopyFrom(const istd::IChangeable& object, CompatibilityMode mode)
{
	if (BaseClass::CopyFrom(object, mode)){
		return true;
	}
	
	const IMultiBitmapProvider* sourcePtr = dynamic_cast<const IMultiBitmapProvider*>(&object);
	if (sourcePtr != NULL){
		istd::CChangeNotifier changeNotifier(this);

		ResetPages();

		Q_ASSERT(m_documentPages.isEmpty());

		int bitmapsCount = sourcePtr->GetBitmapsCount();

		bool retVal = true;

		for (int bitmapIndex = 0; bitmapIndex < bitmapsCount; ++bitmapIndex){
			const iimg::IBitmap* sourceBitmapPtr = sourcePtr->GetBitmap(bitmapIndex);
			if (sourceBitmapPtr != NULL){
				const idoc::IDocumentMetaInfo* pageMetaInfoPtr = NULL;
				const idoc::IMultiPageDocument* documentPtr = dynamic_cast<const idoc::IMultiPageDocument*>(&object);
				if (documentPtr != NULL){
					pageMetaInfoPtr = documentPtr->GetPageMetaInfo(bitmapIndex);
				}

				istd::IChangeable* newPagePtr = InsertPage(pageMetaInfoPtr);
				if (newPagePtr != NULL){
					retVal  = retVal && m_documentPages[bitmapIndex].pagePtr->CopyFrom(*sourcePtr->GetBitmap(bitmapIndex));
				}
				else{
					ResetPages();

					return false;
				}
			}
		}

		return retVal;
	}

	return false;
}


bool CMultiPageBitmapBase::ResetData(CompatibilityMode /*mode*/)
{
	ResetPages();

	return true;
}


} // namespace iimg


