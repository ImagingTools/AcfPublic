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


#ifndef iipr_IISearchParams_included
#define iipr_IISearchParams_included


#include "iser/ISerializable.h"

#include "i2d/CRectangle.h"

#include "iimg/IBitmap.h"


namespace iipr
{


/**	
	Common interface for a set of parameters for a model search.
*/
class ISearchParams: virtual public iser::ISerializable
{
public:
	/**
		Gets the region that is used for model search.
	*/
	virtual i2d::CRectangle GetSearchRegion() const = 0;
		
	/** 
		Returns the model image. 
	*/
	virtual const iimg::IBitmap& GetModelImage() const = 0;

	/**
		Get minimum score for a succefull search.
	*/
	virtual double GetMinScore() const = 0;

	/**
		Set minimum score for a succefull search.
	*/
	virtual void SetMinScore(double minScore) = 0;

	/**
		Set minimum score for a succefull search.
	*/
	virtual const istd::CRange& GetRotationRange() const = 0;

	/**
		Set rotation range for the model search.
	*/
	virtual void SetRotationRange(const istd::CRange& angleRange) = 0;

	/**
		Get scale range for the model search.
		\sa SetScaleRange()
	*/
	virtual const istd::CRange& GetScaleRange() const = 0;

	/**
		Set scale range for the model search. Range [0, 0] means the scaling is off.
	*/
	virtual void SetScaleRange(const istd::CRange& scaleRange) = 0;

	/**
		Get the number of models that should be found for a successfull search result.
	*/
	virtual int GetNominalModelsCount() const = 0;

	/**
		Set the number of models that should be found for a successfull search result.
		\param nominalModelsCount number of models.
	*/
	virtual void SetNominalModelsCount(int nominalModelsCount) = 0;

	/**
		Get \c true if the rotation invariance is enabled.
	*/
	virtual bool IsRotationEnabled() const = 0; 
	
	/**
		Enable the rotation invariance.
		\sa SetRotationRange(), GetRotationRange()
	*/
	virtual void SetRotationEnabled(bool isRotationEnabled) = 0;
	
	/**
		Get \c true if the scale invariance is enabled.
	*/
	virtual bool IsScaleEnabled() const = 0;
	
	/**
		Enable the scale invariance.
		\sa SetScaleRange(), GetScaleRange()
	*/
	virtual void SetScaleEnabled(bool isScaleEnabled) = 0;
};


} // namespace iipr


#endif // !iipr_IISearchParams_included

