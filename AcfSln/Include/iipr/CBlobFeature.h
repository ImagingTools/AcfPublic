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


#pragma once


// ACF includes
#include "i2d/CPosition2d.h"
#include "i2d/CAffineTransformation2d.h"

// ACF-Solutions includes
#include "iipr/CObjectFeature.h"


namespace iipr
{


/**
	Implementation of the blob-based feature.
*/
class CBlobFeature: public iipr::CObjectFeature
{
public:
	typedef iipr::CObjectFeature BaseClass;

	CBlobFeature();
	CBlobFeature(
				int pixelCount,
				int perimeter,
				const i2d::CVector2d& position,
				double angle = 0.0);

	double GetCircularity() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);
	virtual istd::IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const;

private:
	int m_pixelCount;
	int m_perimeter;
};


} // namespace iipr


