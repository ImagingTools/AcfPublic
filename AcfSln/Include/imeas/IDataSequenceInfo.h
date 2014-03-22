/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef imeas_IDataSequenceInfo_included
#define imeas_IDataSequenceInfo_included


// ACF includes
#include "iser/ISerializable.h"

#include "imeas/INumericConstraints.h"


namespace imeas
{


/**
	Stores additional data sequence data used to interpret samples value correctly.
*/
class IDataSequenceInfo:
			virtual public INumericConstraints,
			virtual public iser::ISerializable
{
public:
	enum SequenceInfoFlags
	{
		/**
			Number of samples is fixed by this info object.
			If this flag is on, default number of samples will be used.
			If you try to create sequence with other number of samples, error will be returned.
		*/
		SIF_SAMPLES_COUNT_FIXED = 1 << 1,
		/**
			Number of channels is fixed by this info object.
			If this flag is on, default number of channels will be used.
			If you try to create sequence with other number of channels, error will be returned.
		*/
		SIF_CHANNELS_COUNT_FIXED = 1 << 2
	};

	/**
		Describe mode of weight information.
	*/
	enum WeightMode
	{
		/**
			There is no weights.
		*/
		WM_NONE,
		/**
			The last channel (if more than 1) describes weight values, weights are shared for all channels.
		*/
		WM_LAST,
		/**
			The weight channels are interleaved with 'normal' channels (e.g. for 6 channels it will be sequence NWNWNW, N - normal, W - weight channel).
		*/
		WM_INTERLEAVED,
		/**
			There is unknown weight channel interpretation.
		*/
		WM_UNKNOWN
	};

	/**
		Get flags for this data sequence.
	*/
	virtual int GetSequenceInfoFlags() const = 0;

	/**
		Get default number of samples.
	*/
	virtual int GetDefaultSamplesCount() const = 0;
	/**
		Get default number of channels.
	*/
	virtual int GetDefaultChannelsCount() const = 0;

	/**
		Get weight mode for this sequence.
		\sa	WeightMode
	*/
	virtual int GetWeightMode() const = 0;
};


} // namespace imeas


#endif // !imeas_IDataSequenceInfo_included


