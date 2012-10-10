/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef isig_ISamplingConstraints_included
#define isig_ISamplingConstraints_included


#include "istd/TRange.h"

#include "iser/ISerializable.h"

#include "iprm/IParamsSet.h"

#include "isig/isig.h"


namespace isig
{


/**
	Define constrains of sampling parameters.
*/
class ISamplingConstraints: virtual public istd::IPolymorphic
{
public:
	/**
		Return range of possible sampling interval values.
	*/
	virtual istd::CRange GetIntervalRange() const = 0;

	/**
		Check if specified sampling mode is supported.
		\sa	isig::ISamplingParams::SamplingMode
	*/
	virtual bool IsSamplingModeSupported(int mode) const = 0;

	/**
		Get range of possible/representable sample values.
	*/
	virtual istd::CRange GetValueRange(bool forInput = true, bool forOutput = true, const iprm::IParamsSet* paramsSetPtr = NULL) const = 0;

	/**
		Get maximal number of samples can be received/send at one time.
		\return	number of samples can be processed at one time in single sample container, or -1 if there is no restrictions.
	*/
	virtual int GetMaximalSamplesCount(bool forInput = true, bool forOutput = true, const iprm::IParamsSet* paramsSetPtr = NULL) const = 0;
};


} // namespace isig


#endif // !isig_ISamplingConstraints_included


