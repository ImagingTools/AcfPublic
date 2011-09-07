/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iproc_IBitmapAcquisition_included
#define iproc_IBitmapAcquisition_included


#include "istd/CIndex2d.h"

#include "isys/ITimer.h"

#include "iimg/IBitmap.h"

#include "iproc/IProcessor.h"


namespace iproc
{


/**
	Bitmap acquisition processor.
	This processor use as \c iproc::IProcessor template parameter Input optional isys::ITimer object to indicate trigger time of acquision.
*/
class IBitmapAcquisition: virtual public iproc::IProcessor
{
public:
	/**
		Get size of acquired bitmap fo specified parameters.
		\return		if size of bitmap is known it returns this value. Elsewhere invalid size will be returned.
					\sa \c istd::TIndex::IsValid().
	*/
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const = 0;
};


} // namespace iproc


#endif // !iproc_IBitmapAcquisition_included


