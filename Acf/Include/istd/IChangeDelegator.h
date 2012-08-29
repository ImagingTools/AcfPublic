/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef istd_IChangeDelegator_included
#define istd_IChangeDelegator_included


#include "istd/IChangeable.h"


namespace istd
{


/**
	Common interface for all classes that supports delegation of their updates to
	another class. This is usefull for composed objects to delegate information about changes
	from a child element to its owner.
 */
class IChangeDelegator: virtual public istd::IChangeable
{
public:
	/**
		Sets the slave object pointer. 
		Its IChangeable methods will be called, if this object is updated.
	*/
	virtual istd::IChangeable* GetSlavePtr() const = 0;

	/**
		Gets the slave object pointer. 
	*/
	virtual void SetSlavePtr(istd::IChangeable* slavePtr) = 0;
};


} // namespace istd


#endif // !istd_IChangeDelegator_included


