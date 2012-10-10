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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_CMultiBitmapCacheComp_included
#define iipr_CMultiBitmapCacheComp_included


// ACF includes
#include "istd/TPointerVector.h"
#include "icomp/CComponentBase.h"

// ACF-Solutions includes
#include "iipr/IMultiBitmapProvider.h"


namespace iipr
{


/**
	Multi bitmap provider returning always stored bitmaps.
	Stored bitmaps can be changed only copying their from another multi bitmap provider using CopyFrom method.
	This object will be used to manage threading barrier for object supplier chain.
*/
class CMultiBitmapCacheComp:
			public icomp::CComponentBase,
			virtual public IMultiBitmapProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CMultiBitmapCacheComp);
		I_REGISTER_INTERFACE(IMultiBitmapProvider);
	I_END_COMPONENT;

	CMultiBitmapCacheComp();

	// reimplemented (iipr::IMultiBitmapProvider)
	virtual const iprm::ISelectionConstraints* GetBitmapSelectionContraints() const;
	virtual int GetBitmapsCount() const;
	virtual const iimg::IBitmap* GetBitmap(int bitmapIndex) const;
	virtual const i2d::ITransformation2d* GetLogTransform(int bitmapIndex) const;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object);

private:
	istd::TPointerVector<iimg::IBitmap> m_bitmapsPtr;
	istd::TPointerVector<i2d::ITransformation2d> m_transformsPtr;
};


} // namespace iipr


#endif // !iipr_CMultiBitmapCacheComp_included


