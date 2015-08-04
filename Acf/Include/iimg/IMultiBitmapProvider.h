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


#ifndef iimg_IMultiBitmapProvider_included
#define iimg_IMultiBitmapProvider_included


// ACF includes
#include "istd/IChangeable.h"
#include "i2d/ITransformation2d.h"
#include "iprm/IOptionsList.h"
#include "iimg/IBitmap.h"


namespace iimg
{


/**
	Supplier allowing to access of multiple produced bitmaps.
*/
class IMultiBitmapProvider: virtual public istd::IChangeable
{
public:
	/**
		Get optional information about bitmaps in form of section constraints.
		It allows to get name and description of each bitmap channel.
	*/
	virtual const iprm::IOptionsList* GetBitmapListInfo() const = 0;

	/**
		Get number of produced bitmaps.
	*/
	virtual int GetBitmapsCount() const = 0;
	/**
		Get access to produced bitmap object.
		\return	pointer to bitmap instance if this bitmap is accessible, or NULL.
	*/
	virtual const iimg::IBitmap* GetBitmap(int bitmapIndex) const = 0;
};


} // namespace iimg


#endif // !iimg_IMultiBitmapProvider_included


