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
#include <icmm/IColorantColor.h>


namespace icmm
{


class CColorantColor : virtual public icmm::IColorantColor
{
public:
	CColorantColor(const icmm::CFastColor& color, icmm::ColorModelPtr modelPtr);

	// reimplemented (icmm::IColorObject)
	virtual icmm::CVarColor GetColor() const override;
	virtual icmm::ConstColorModelPtr GetColorModel() const override;
	virtual std::unique_ptr<IColorObject> CloneIntoUniquePtr() const override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

	//reimplemented (icmm::IColorantColor)
	virtual const icmm::CFastColor& GetFastColor() const override;

private:
	icmm::CFastColor m_color;
	std::shared_ptr<icmm::IColorModel> m_modelPtr;
};


} // namespace icmm
