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


#ifndef iipr_IPatternController_included
#define iipr_IPatternController_included


#include <istd/IChangeable.h>


namespace iipr
{


class IPatternController: virtual public istd::IChangeable
{
public:
	/**
		Data model change notification flags.
	*/
	enum ChangeFlags
	{
		/**
			Supplier result changed.
		*/
		CF_PATTERN_LEARNED = 0x456d447
	};

	/**
		Do teaching of the pattern.
	*/
	virtual bool TeachPattern(const istd::IChangeable* sourceObjectPtr = NULL) = 0;

	/**
		Clear all pattern features.
	*/
	virtual void ResetPattern() = 0;

	/**
		Get \c true of the pattern is valid
	*/
	virtual bool IsPatternValid() const = 0;

	/**
		Get pattern object.
	*/
	virtual const iser::ISerializable* GetPatternObject() const = 0;
};


} // namespace iipr


#endif // !iipr_IPatternController_included
