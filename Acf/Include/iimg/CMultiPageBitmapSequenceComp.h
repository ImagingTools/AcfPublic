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


#ifndef iimg_CMultiPageBitmapSequenceComp_included
#define iimg_CMultiPageBitmapSequenceComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <idoc/TMultiPageDocumentWrap.h>
#include <iimg/IMultiBitmapProvider.h>


namespace iimg
{


/**
	Realization of the multi-page bitmap sequence used the component factory for the instatiation of the single sequence frame.
*/
class CMultiPageBitmapSequenceComp:
			public icomp::CComponentBase,
			public idoc::TMultiPageDocumentWrap<idoc::IMultiPageDocument>
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CMultiPageBitmapSequenceComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(iprm::IOptionsList);
		I_REGISTER_INTERFACE(idoc::IMultiPageDocument);
		I_ASSIGN(m_multiBitmapFactoryCompPtr, "MultiPageBitmapFactory", "Factory used for creation of multi-page bitmap for a single document page", true, "MultiPageBitmapFactory");
	I_END_COMPONENT;

protected:
	// reimplemented (idoc::IMultiPageDocument)
	virtual istd::IChangeable* InsertPage(
				const idoc::IDocumentMetaInfo* pageMetaInfoPtr = NULL,
				const iprm::IParamsSet* pageParameterPtr = NULL,
				int position = -1);

private:
	I_FACT(iimg::IMultiBitmapProvider, m_multiBitmapFactoryCompPtr);
};


} // namespace iimg


#endif // !iimg_CMultiPageBitmapSequenceComp_included


