/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
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

