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


#ifndef iview_ICalibration_included
#define iview_ICalibration_included


// ACF includes
#include "i2d/CVector2d.h"
#include "i2d/CLine2d.h"
#include "i2d/CMatrix2d.h"


namespace iview
{


// TODO: Replace it with i2d::ITransformation2d

/**
	Common interface for all calibration objects.
	It is used to work with real world units.
	It provides only two simple operations: distance computation and local transformation.
*/
class ICalibration: public iser::ISerializable
{
public:
	/**
		Describe a computation status for calibration methods.
	*/
	enum CalcStatus
	{
		/**
			There was no possibility to calculte result value.
		*/
		CS_FAILED,
		
		/**
			Result value is calculated, but it is invalid.
			Result value can be used only temporary,
			but it doesn't represent valid position.
		*/
		CS_INVALID,
		
		/**
			Result value is valid.
		*/
		CS_OK
	};

	/**	
		Compute a distance in real world units.
		\param	line	line in view coords system.
		\return			distance between line ends in real world units.
	*/
	virtual CalcStatus GetLogLength(const i2d::CLine2d& line, double& result) const = 0;

	/**
		Get local deformation (from logical to view system) at defined logical position.
		\param	viewPosition	position in view coordination system.
		\param	result			local transformation. The columns of this transform are derative in specified position.
		\return	status of this operation.
	*/
	virtual CalcStatus GetLogDeform(const i2d::CVector2d& logPosition, i2d::CMatrix2d& result) const = 0;

	/**
		Get local deformation (from view to logical system) at defined view position.
		\param	viewPosition	position in view coordination system.
		\param	result			local transformation. The columns of this transform are derative in specified position.
		\return	status of this operation.
	*/
	virtual CalcStatus GetViewDeform(const i2d::CVector2d& viewPosition, i2d::CMatrix2d& result) const = 0;
};


} // namespace iview


#endif // !iview_ICalibration_included


