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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef imeas_IDiscreteDataSequence_included
#define imeas_IDiscreteDataSequence_included


#include "imeas/IDataSequence.h"


namespace imeas
{


/**
	General definition of sequence contains discrete sample values in regular time grid.
	All samples has the same number of channels components.
*/
class IDiscreteDataSequence: virtual public IDataSequence
{
public:
	/**
		Create container for sample sequence using external samples buffer.
		\param	samplesCount	number of samples.
		\param	dataPtr			pointer to external buffer.
		\param	releaseFlag		if its true, external buffer will be managed (removed) by this object.
		\param	sampleDiff		address difference between next and previos sample. If it equals 0, the value will be taken from number of samples, number of channels and \c channelDiff.
		\param	channelDiff		address difference between next and previos sample. If it equals 0, the value will be calculated from number of bits per single sample.
		\param	sampleDepth		number of bits used for representation of a single sample.
		\param	channelsCount	number of channels.
		\return					true if sample sequence was created correctly.
	*/
	virtual bool CreateDiscrSequence(
				int samplesCount,
				void* dataPtr,
				bool releaseFlag,
				int sampleDiff,
				int channelDiff,
				int sampleDepth,
				int channelsCount = 1) = 0;

	/**
		Get number of bits used to represent single sample.
	*/
	virtual int GetSampleDepth() const = 0;

	/**
		Get discrete sample at specified position.
		\param	position	position, must be inside of returned size.
	*/
	virtual I_DWORD GetDiscrSample(int position, int channel = 0) const = 0;

	/**
		Set discrete sample at specified position.
		\param	position	position, must be inside of returned size.
		\param	channel		sample channel.
		\param	sample		sample value will be set.
		\return				true, if sample was changed.
	*/
	virtual bool SetDiscrSample(int position, int channel, I_DWORD sample) = 0;
};


} // namespace imeas


#endif // !imeas_IDiscreteDataSequence_included


