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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef i2d_IObject2d_included
#define i2d_IObject2d_included


// ACF includes
#include "iser/ISerializable.h"
#include "i2d/ICalibration2d.h"
#include "i2d/ICalibrationProvider.h"


namespace i2d
{


class CVector2d;
class CRectangle;


/**
	Common interface for describing the 2D-objects.
*/
class IObject2d:
			virtual public iser::ISerializable,
			virtual public ICalibrationProvider
{
public:
	enum ChangeFlags
	{
		CF_OBJECT_POSITION = 1 << 20
	};

	/**
		Returns center of this 2D-object.
	*/
	virtual CVector2d GetCenter() const = 0;

	/**
		Move object to position \c position.
	*/
	virtual void MoveCenterTo(const CVector2d& position) = 0;

	/**
		Get bounding box of this shape.
		Please note, this bounding box is in logical units, the calibration will not be considered.
	*/
	virtual CRectangle GetBoundingBox() const = 0;

	/**
		Transform this object using some transformation.
		Please note, that this operation transforms logical coordinates, it means that the calibration will be ignored.
		\param	mode			controls needed transformation exactness.
		\param	errorFactorPtr	optional output where approximated length of transformation error vector will be stored.
								Value 0 means that transformation is exactly done.
		\return	true, if  transformation was done correctly.
	*/
	virtual bool Transform(
				const ITransformation2d& transformation,
				ITransformation2d::ExactnessMode mode = ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) = 0;

	/**
		Do inverse transformation of this object.
		Please note, that this operation transforms logical coordinates, it means that the calibration will be ignored.
		\param	mode			controls needed transformation exactness.
		\param	errorFactorPtr	optional output where approximated length of transformation error vector will be stored.
								Value 0 means that transformation is exactly done.
		\return	true, if  transformation was done correctly.
	*/
	virtual bool InvTransform(
				const ITransformation2d& transformation,
				ITransformation2d::ExactnessMode mode = ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) = 0;

	/**
		Calulate transformation of the object into second one.
		Please note, that this operation transforms logical coordinates, it means that the calibration will be ignored.
		\param	mode			controls needed transformation exactness.
		\param	errorFactorPtr	optional output where approximated length of transformation error vector will be stored.
								Value 0 means that transformation is exactly done.
		\param	result			result object.
		\return	true, if  transformation was done correctly.
	*/
	virtual bool GetTransformed(
				const ITransformation2d& transformation,
				IObject2d& result,
				ITransformation2d::ExactnessMode mode = ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) const = 0;

	/**
		Calulate inverse transformation of the object into second one.
		Please note, that this operation transforms logical coordinates, it means that the calibration will be ignored.
		\param	mode			controls needed transformation exactness.
		\param	errorFactorPtr	optional output where approximated length of transformation error vector will be stored.
								Value 0 means that transformation is exactly done.
		\param	result			result object.
		\return	true, if  transformation was done correctly.
	*/
	virtual bool GetInvTransformed(
				const ITransformation2d& transformation,
				IObject2d& result,
				ITransformation2d::ExactnessMode mode = ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) const = 0;
};


} // namespace i2d


#endif // !i2d_IObject2d_included

