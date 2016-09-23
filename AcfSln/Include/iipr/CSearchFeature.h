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


#pragma once


// ACF-Solutions includes
#include <iipr/CObjectFeature.h>


namespace iipr
{


/**
	Implementation of the pattern search feature.
*/
class CSearchFeature: public CObjectFeature
{
public:
	typedef CObjectFeature BaseClass;

	CSearchFeature();

	CSearchFeature(
				double weight,
				const i2d::CVector2d& position,
				double angle,
				const i2d::CVector2d& scale,
				bool negativeModel = false,
				int index = -1,
				const QByteArray& objectId = QByteArray());

	int GetIndex() const;
	bool IsNegativeModelEnabled() const;
	void SetNegativeModelEnabled(bool enable);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);
	virtual istd::IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const;

private:
	int m_index;
	bool m_isNegativeModelEnabled;
};


} // namespace iipr


