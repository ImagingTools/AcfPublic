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


#ifndef ibase_IProgressLogger_included
#define ibase_IProgressLogger_included


// ACF includes
#include <istd/IPolymorphic.h>


namespace ibase
{


/**
	Consume information about progress of some process.
*/
class IProgressLogger: virtual public istd::IPolymorphic
{
public:
	/**
		Callback function for a progress event.
		\param	currentProgress	progress value in the range [0; 1].
	*/
	virtual void OnProgress(double currentProgress) = 0;

	/**
		Check if this processing operation should be canceled.
	*/
	virtual bool IsCanceled() const = 0;
};


} // namespace ibase


#endif // !ibase_IProgressLogger_included


