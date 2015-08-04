/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef istd_IContainerInfo_included
#define istd_IContainerInfo_included


// ACF includes
#include "istd/IChangeable.h"


namespace istd
{


/**
	Common interface for all container implementations.
*/
class IContainerInfo: virtual public IChangeable
{
public:
	/**
		Returns number of elements in the container.
	*/
	virtual int GetItemsCount() const = 0;

	/**
		Returns a \c true if container is empty, otherwise a \c false.
	*/
	virtual bool IsEmpty() const = 0;

	/*
		Returns \c true if the index \c index is valid, otherwise a \c false.
	*/
	virtual bool IsIndexValid(int index) const = 0;
};


} // namespace istd


#endif // istd_IContainerInfo_included

