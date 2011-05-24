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

