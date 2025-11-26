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


// STL includes
#include <memory>

// ACF includes
#include <istd/IChangeable.h>
#include <icmm/icmm.h>


namespace icmm
{


class IColorSpecification: virtual public istd::IChangeable
{
public:
	typedef std::shared_ptr<const IColorSpecification> ConstColorSpecPtr;
	typedef std::shared_ptr<IColorSpecification> ColorSpecPtr;

	enum class SpecType
	{
		Tristimulus,
		Spectral
	};

	/**
		Get the logical type of the specification. Can be tristimulus or spectral-based.
		\sa SpecType
	*/
	virtual SpecType GetSpecificationType() const = 0;
};


} // namespace icmm


