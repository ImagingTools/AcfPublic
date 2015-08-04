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


#ifndef iauth_IRightsProvider_included
#define iauth_IRightsProvider_included


// Qt includes
#include <QtCore/QByteArray>

// ACF includes
#include "istd/IChangeable.h"


namespace iauth
{


class IRightsProvider: virtual public istd::IChangeable
{
public:
	/**
		Checks if user has rights for specific operation.
		\param	operationId	id of operation.
		\param	beQuiet if it is true, user can not be asked for password during this check.
	 */
	virtual bool HasRight(
				const QByteArray& operationId,
				bool beQuiet = false) const = 0;
};


} // namespace iauth


#endif // !iauth_IRightsProvider_included


