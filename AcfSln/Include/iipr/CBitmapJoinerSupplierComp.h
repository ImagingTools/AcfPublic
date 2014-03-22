/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_CBitmapJoinerSupplierComp_included
#define iipr_CBitmapJoinerSupplierComp_included


// ACF includes
#include "i2d/ICalibrationProvider.h"
#include "istd/TPointerVector.h"

// ACF-Solutions includes
#include "iproc/IProcessor.h"
#include "iproc/ISupplier.h"
#include "iproc/TSupplierCompWrap.h"
#include "iimg/IBitmapProvider.h"
#include "iimg/IMultiBitmapProvider.h"


namespace iipr
{

/**
	Supplier of bitmap's vector built on bitmap 
*/
class CBitmapJoinerSupplierComp:
			public iproc::TSupplierCompWrap< QPair<i2d::ITransformation2d*,  istd::TDelPtr<iimg::IBitmap> > >,
			virtual public iimg::IBitmapProvider
{
public:
	typedef iproc::TSupplierCompWrap< QPair<i2d::ITransformation2d*,  istd::TDelPtr<iimg::IBitmap> > > BaseClass;

	I_BEGIN_COMPONENT(CBitmapJoinerSupplierComp);
		I_REGISTER_INTERFACE(iimg::IBitmapProvider);
		I_ASSIGN(m_bitmapCompFact, "BitmapFactory", "Use to create bitmap object", true, "BitmapFactory");
		I_ASSIGN(m_bitmapsProviderCompPtr, "BitmapListSupplier", "Provide list of the input images", true, "BitmapListSupplier");
		I_ASSIGN_TO(m_bitmapsSupplierCompPtr, m_bitmapsProviderCompPtr, false);
		I_ASSIGN_TO(m_bitmapsProviderModelCompPtr, m_bitmapsProviderCompPtr, false);
		I_ASSIGN(m_useHorizontalJoinAttrPtr, "JoinHorizontal", "Join the image in horizontal direction", true, false);
	I_END_COMPONENT;

protected:
	bool EnsureBitmapCreated(ProductType& result) const;

	// reimplemented (iimg::IBitmapProvider)
	virtual const iimg::IBitmap* GetBitmap() const;
	virtual const i2d::ITransformation2d* GetLogTransform() const;	

	// reimplemented (iproc::TSupplierCompWrap)
	virtual int ProduceObject(ProductType& result) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_FACT(iimg::IBitmap, m_bitmapCompFact);

	I_REF(iimg::IMultiBitmapProvider, m_bitmapsProviderCompPtr);
	I_REF(iproc::ISupplier, m_bitmapsSupplierCompPtr);
	I_REF(imod::IModel, m_bitmapsProviderModelCompPtr);

	I_ATTR(bool, m_useHorizontalJoinAttrPtr);
};


} // namespace iipr


#endif // !iipr_CBitmapJoinerSupplierComp_included


