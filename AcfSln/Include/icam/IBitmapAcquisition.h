/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef icam_IBitmapAcquisition_included
#define icam_IBitmapAcquisition_included


// ACF includes
#include <istd/CIndex2d.h>
#include <iproc/IProcessor.h>


namespace icam
{


/**
	Bitmap acquisition processor.
	This processor uses optional input parameter of type \c istd::ITimeStamp to identify the image by its trigger time.
*/
class IBitmapAcquisition: virtual public iproc::IProcessor
{
public:
	/**
		Get size of acquired bitmap for specified parameters.
		\return		if size of bitmap is known it returns this value. Otherwise invalid size will be returned.
					\sa \c istd::TIndex::IsValid().
	*/
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const = 0;
};


} // namespace icam


#endif // !icam_IBitmapAcquisition_included


