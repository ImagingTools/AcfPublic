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


#pragma once


// ACF-Solutions includes
#include <imeas/IDataSequenceInfo.h>
#include <imeas/CGeneralNumericConstraints.h>


namespace imeas
{


/**
	Simple implementation of imeas::IDataSequenceInfo interface.
*/
class CGeneralDataSequenceInfo:
			public CGeneralNumericConstraints,
			virtual public IDataSequenceInfo
{
public:
	typedef imeas::CGeneralNumericConstraints BaseClass;

	CGeneralDataSequenceInfo(
				int defaultChannelsCount,
				int defaultSamplesCount,
				WeightMode mode = WeightMode::WM_NONE,
				int sequenceFlags = 0);

	bool InsertValueInfo(const QString& name, const QString& description, const imath::CGeneralUnitInfo& unitInfo, int index = -1);

	void SetSequenceInfoFlags(int flags);
	void SetDefaultSamplesCount(int samplesCount);
	void SetDefaultChannelsCount(int channelsCount);
	void SetWeightMode(WeightMode mode);

	// reimplemented (imeas::IDataSequenceInfo)
	virtual int GetSequenceInfoFlags() const;
	virtual int GetDefaultSamplesCount() const;
	virtual int GetDefaultChannelsCount() const;
	virtual int GetWeightMode() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	WeightMode m_weightMode;
	int m_sequenceInfoFlags;
	int m_defaultSamplesCount;
	int m_defaultChannelsCount;
};


} // namespace imeas


