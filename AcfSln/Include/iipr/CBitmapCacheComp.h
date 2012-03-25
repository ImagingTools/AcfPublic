/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_CBitmapCacheComp_included
#define iipr_CBitmapCacheComp_included


// ACF includes
#include "istd/TDelPtr.h"
#include "icomp/CComponentBase.h"
#include "i2d/ICalibrationProvider.h"

// ACF-Solutions includes
#include "iipr/IBitmapProvider.h"


namespace iipr
{


/**
	Bitmap provider returning always stored bitmap.
	Stored bitmap can be changed only copying the bitmap from another bitmap provider using CopyFrom method.
	This object will be used to manage threading barrier for object supplier chain.
*/
class CBitmapCacheComp:
			public icomp::CComponentBase,
			virtual public IBitmapProvider,
			virtual public i2d::ICalibrationProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CBitmapCacheComp);
		I_REGISTER_INTERFACE(IBitmapProvider);
		I_REGISTER_INTERFACE(ICalibrationProvider);
	I_END_COMPONENT;

	// reimplemented (iipr::IBitmapProvider)
	virtual const iimg::IBitmap* GetBitmap() const;

	// reimplemented (i2d::ICalibrationProvider)
	virtual const i2d::ITransformation2d* GetLogicalTransform() const;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object);

private:
	istd::TDelPtr<iimg::IBitmap> m_bitmapPtr;
	istd::TDelPtr<i2d::ITransformation2d> m_transformPtr;
};


} // namespace iipr


#endif // !iipr_CBitmapCacheComp_included


