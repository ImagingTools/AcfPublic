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


// ACF includes
#include <iblob/IBlobFilterParams.h>


namespace iblob
{


class CBlobFilterParams: virtual public IBlobFilterParams
{
public:
	CBlobFilterParams();

	/**
		Set list of supported features.
	*/
	void SetSupportedProperties(const iprm::IOptionsList* featureListPtr);

	// reimplemented (IBlobFilterParams)
	virtual const iprm::IOptionsList* GetSupportedProperties() const;
	virtual bool IsFiltersEnabled() const;
	virtual void SetFiltersEnabled(bool enabled = true);
	virtual int GetFiltersCount() const;
	virtual Filter& GetFilterAt(int index);
	virtual const Filter& GetFilterAt(int index) const;
	virtual void RemoveFilterAt(int index);
	virtual void ResetFilters();
	virtual void AddFilter(const Filter& filterInfo);

	// reimplemented (i2d::ICalibrationProvider)
	virtual const i2d::ICalibration2d* GetCalibration() const;

	// reimplemented (i2d::ICalibrationProvider)
	virtual bool Serialize(iser::IArchive& archive);

private:
	typedef QList<Filter> FilterList;
	FilterList m_filters;

	bool m_filtersEnabled;

	const iprm::IOptionsList* m_supportedFeaturesListPtr;
};


} // namespace iblob


