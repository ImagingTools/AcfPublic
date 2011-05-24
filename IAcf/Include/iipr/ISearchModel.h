/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iipr_ISearchModel_included
#define iipr_ISearchModel_included


#include "iimg/IBitmap.h"

#include "iser/ISerializable.h"

#include "iipr/ISearchParams.h"


namespace iipr
{


/**
	Common interface for all search model implementations for pattern matching.
*/
class ISearchModel: virtual public iser::ISerializable
{
public:
	/**
		Creates search model from the image. 
	*/
	virtual bool CreateFromImage(const iimg::IBitmap& modelImage, const iipr::ISearchParams* params) = 0;

	/**
		Returns a \c true, if the model was created and is ready for use, otherwise a \c false.
	*/
	virtual bool IsModelValid() const = 0;

	/**
		Resets the model object. All model data will be cleared.
	*/
	virtual void ResetModel() = 0;

	/**	
		Gets the model image.
	*/
	virtual const iimg::IBitmap& GetImage() const = 0;
};


} // namespace iipr


#endif // !iipr_ISearchModel_included

