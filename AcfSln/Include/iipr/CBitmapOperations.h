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


#ifndef iipr_CBitmapOperations_included
#define iipr_CBitmapOperations_included


// ACF includes
#include <istd/ILogger.h>

// ACF-Solutions includes
#include <iimg/IBitmapProvider.h>


namespace iipr
{


/**
	Set of atmomic bitmap manipulations.
*/
class CBitmapOperations
{
public:
	/**
		Processing mode for join of more bitmaps.
	*/
	enum JoinMode
	{
		/**
			Bitmaps are placed vertically in the output image.
		*/
		JM_VERTICAL,

		/**
			Bitmaps are placed horizontally in the output image.
		*/
		JM_HORIZONTAL,
	};

	/**
		Processing mode for calculation of more bitmaps into a single one.
	*/
	enum CombineMode
	{
		/**
			Average value of all bitmaps will be used in the output.
			If this mode is active, an additional list of weights (for each input bitmap) can be set.
			In this case the averaging is weighted and calculated as outputValue = (input1 * weight1 + input2 * weight 2 + ... ) / Sum (weights)
		*/
		CM_AVERAGE,

		/**
			As result value of a bitmap pixel the maximum of all input bitmap values on the given position is taken.
		*/
		CM_MAX,
		/**
			As result value of a bitmap pixel the minimum of all input bitmap values on the given position is taken.
		*/
		CM_MIN
	};

	/**
		Definition of bitmap list.
	*/
	typedef QVector<const iimg::IBitmap*> BitmapList;

	/**
		Crop the bitmap to the bounding box of a given region.
	*/
	static bool ReduceBitmapToRegion(const iimg::IBitmap& inputBitmap, const i2d::IObject2d& region, iimg::IBitmap& outputBitmap);

	/**
		Join more bitmaps into a single one by placing of the input bitmaps into the output.
		\sa JoinMode
	*/
	static bool JoinBitmaps(
				const BitmapList& bitmapList,
				JoinMode joinMode,
				iimg::IBitmap& outputBitmap,
				istd::ILogger* operationLogPtr = NULL);

	/**
		Join more bitmaps into a single one by calculation of the pixel values from the input bitmap list.
		\sa CombineMode
	*/
	static bool CombineBitmaps(
				const BitmapList& bitmapList,
				CombineMode combineMode,
				iimg::IBitmap& outputBitmap,
				imath::CVarVector* weghtsPtr = NULL,
				istd::ILogger* operationLogPtr = NULL);
};


} // namespace iipr


#endif // !iipr_CBitmapOperations_included


