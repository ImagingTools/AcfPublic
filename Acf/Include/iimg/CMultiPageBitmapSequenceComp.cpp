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


#include <iimg/CMultiPageBitmapSequenceComp.h>


namespace iimg
{


// protected methods
	
// reimplemented (idoc::IMultiPageDocument)

istd::IChangeable* CMultiPageBitmapSequenceComp::InsertPage(
			const idoc::IDocumentMetaInfo* pageMetaInfoPtr,
			const iprm::IParamsSet* /*pageParameterPtr*/,
			int position)
{
	istd::TDelPtr<iimg::IMultiBitmapProvider> multiBitmapPtr(m_multiBitmapFactoryCompPtr.CreateInstance());
	if (multiBitmapPtr.IsValid()){
		Page newPage;
			
		if (pageMetaInfoPtr != NULL){
			newPage.pageMetaInfo.CopyFrom(*pageMetaInfoPtr);
		}

		newPage.pagePtr.SetPtr(multiBitmapPtr.PopPtr());

		m_documentPages.insert(position, newPage);

		return newPage.pagePtr.GetPtr();
	}

	return NULL;
}


} // namespace iimg


