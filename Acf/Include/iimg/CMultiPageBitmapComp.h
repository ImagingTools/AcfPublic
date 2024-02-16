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


#ifndef iimg_CMultiPageBitmapComp_included
#define iimg_CMultiPageBitmapComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <iimg/CMultiPageBitmapBase.h>


namespace iimg
{


/**
	Realization of the multi-page bitmap used the component factory for the instatiation of the page bitmap.

	\ingroup ImageProcessing
	\ingroup Geometry
*/
class CMultiPageBitmapComp:
			public icomp::CComponentBase,
			public CMultiPageBitmapBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CMultiPageBitmapComp);
		I_REGISTER_INTERFACE(IMultiBitmapProvider);
		I_REGISTER_INTERFACE(IMultiPageBitmapController);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(iprm::IOptionsList);
		I_REGISTER_INTERFACE(idoc::IMultiPageDocument);
		I_ASSIGN(m_bitmapFactoryCompPtr, "BitmapFactory", "Factory used for creation of bitmap for a single document page", true, "BitmapFactory");
	I_END_COMPONENT;

protected:
	// reimplemented (CMultiPageBitmapBase)
	virtual IBitmap* CreateBitmap() const override;

private:
	I_FACT(IBitmap, m_bitmapFactoryCompPtr);
};


} // namespace iimg


#endif // !iimg_CMultiPageBitmapComp_included


