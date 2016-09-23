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


#ifndef imeas_CSamplesInfo_included
#define imeas_CSamplesInfo_included


#include <imeas/CDataSequenceInfoBase.h>


namespace imeas
{


/**
	Stores additional data sequence data used to interpret samples value correctly.
*/
class CSamplesInfo: virtual public CDataSequenceInfoBase
{
public:
	CSamplesInfo(const istd::CRange& logicalSamplesRange = istd::CRange::GetInvalid());

	/**
		Get logical position range (time axis) of this data sequence.
		For example, if you sample sound from second 1 to 5 it will be represented as range [1.0, 5.0].
		If this range is invalid, no logical range is provided.
	*/
	const istd::CRange& GetLogicalSamplesRange() const;
	/**
		Set logical position range (time axis) of this data sequence.
		\sa GetLogicalRange
	*/
	void SetLogicalSamplesRange(const istd::CRange& range);

	// reimplemented (imeas::IDataSequenceInfo)
	virtual int GetDefaultSamplesCount() const;
	virtual int GetDefaultChannelsCount() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:

	istd::CRange m_logicalSamplesRange;
};


} // namespace imeas


#endif // !imeas_CSamplesInfo_included


