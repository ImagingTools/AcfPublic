/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef isig_ISamplingParams_included
#define isig_ISamplingParams_included


#include <istd/TRange.h>

#include <iser/ISerializable.h>

#include <isig/isig.h>


namespace isig
{


class ISamplingConstraints;


/**
	Sampler parameters.
*/
class ISamplingParams: virtual public iser::ISerializable
{
public:
	enum SamplingMode
	{
		SM_SINGLE,
		SM_PERIODIC,
		SM_SYNCHRONIZED,
		SM_LAST = SM_SYNCHRONIZED
	};

	/**
		Get access to constraints information about possible value ranges.
	*/
	virtual const ISamplingConstraints* GetSamplingConstraints() const = 0;

	/**
		Get sampling interval in seconds.
	*/
	virtual double GetInterval() const = 0;
	/**
		Set sampling interval in seconds.
	*/
	virtual void SetInterval(double value) = 0;

	/**
		Get mode of sampling.
		\sa	SamplingMode.
	*/
	virtual int GetSamplingMode() const = 0;

	/**
		Set mode of sampling.
		\sa	SamplingMode.
		\return	true if this mode was supported and was set correctly.
	*/
	virtual bool SetSamplingMode(int mode) = 0;
};


} // namespace isig


#endif // !isig_ISamplingParams_included


