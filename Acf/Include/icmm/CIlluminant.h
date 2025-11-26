/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
#include <icmm/IIlluminant.h>


namespace icmm
{


class CIlluminant: virtual public IIlluminant
{
public:
	/**
		Construct an illuminant based on a standard type.
	*/
	CIlluminant(StandardIlluminant illuminantType = StandardIlluminant::D50);

	/**
		Construct a custom Illuminant.
	*/
	CIlluminant(
		const QString& illuminantName,
		const icmm::CVarColor& whitePoint);

	/**
		Copy constructor
	*/
	CIlluminant(const CIlluminant& other);

	// reimplemented (IWhitePointProvider)
	virtual icmm::CVarColor GetWhitePoint() const override;

	// reimplemented (IIluminant)
	virtual void SetWhitePoint(const icmm::CVarColor& whitePoint) override;
	virtual QString GetIlluminantName() const override;
	virtual void SetIlluminantName(const QString& illuminantName) override;
	virtual StandardIlluminant GetIlluminantType() const override;
	virtual void SetIlluminantType(const StandardIlluminant& illuminantType) override;

	// reimplemented (istd::IChangeable)
	virtual bool IsEqual(const istd::IChangeable& other) const override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

protected:
	void InitFromStandardIlluminant(StandardIlluminant illuminantType);

private:
	StandardIlluminant m_illuminantType = StandardIlluminant::D50;
	QString m_illuminantName = "D50";
	icmm::CVarColor m_whitePoint;
};


} // namespace icmm


