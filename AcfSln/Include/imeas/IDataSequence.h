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


#ifndef imeas_IDataSequence_included
#define imeas_IDataSequence_included


// ACF includes
#include <istd/TTransPtr.h>
#include <iser/ISerializable.h>

#include <imeas/IDataSequenceInfo.h>


namespace imeas
{


/**
	General definition of sequence contains samples in regular time grid.
	All samples has the same number of channels components.
*/
class IDataSequence: virtual public iser::ISerializable
{
public:
	/**
		Create container for sample sequence with specified number of samples, channels and sample depth.
		\param	samplesCount	number of samples.
		\param	channelsCount	number of channels.
		\return					true if sample sequence was created correctly.
	*/
	virtual bool CreateSequence(int samplesCount, int channelsCount = 1) = 0;

	/**
		Create sequence and set the info object.
		\param	infoPtr	sequence info object.
		\param	samplesCount	number of samples. If it is negative, default value will be taken.
		\param	channelsCount	number of channels. If it is negative, default value will be taken.
	*/
	virtual bool CreateSequenceWithInfo(
				const istd::TTransPtr<const IDataSequenceInfo>& infoPtr,
				int samplesCount = -1,
				int channelsCount = -1) = 0;

	/**
		Get additional information about this sequence.
	*/
	virtual const IDataSequenceInfo* GetSequenceInfo() const = 0;

	/**
		Return true if this sequence has no sample.
	*/
	virtual bool IsEmpty() const = 0;

	/**
		Reset this sequence.
		After this operation sequence is set to initial state.
	*/
	virtual void ResetSequence() = 0;

	/**
		Get size of this raster sequence.
	*/
	virtual int GetSamplesCount() const = 0;

	/**
		Get number of channels.
	*/
	virtual int GetChannelsCount() const = 0;

	/**
		Get sample value at specified index.
	*/
	virtual double GetSample(int index, int channel = 0) const = 0;

	/**
		Set sample value at specified index.
	*/
	virtual void SetSample(int index, int channel, double value) = 0;
};


} // namespace imeas


#endif // !imeas_IDataSequence_included


