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


#pragma once


// ACF includes
#include <istd/IPolymorphic.h>


namespace icomm
{


/**
	Describes actual state of station.
*/
class IStationState: virtual public istd::IPolymorphic
{
public:
	enum State
	{
		S_UNKNOWN,

		/**
			Station is initialized, but it is not ready.
		*/
		S_INIT,
		
		/**
			Station is ready, no user is logged.
		*/
		S_READY,
		
		/**
			Station is ready and user is logged.
		*/
		S_LOGGED
	};

	/**
		Gets station state.
	*/
	virtual State GetStationState() const = 0;
	
	/**
		Gets name of logged user.
	*/
	virtual const QString& GetLoggedUser() const = 0;
	
	/**
		Gets computer name of logged user.
	*/
	virtual const QString& GetLoggedComputer() const = 0;
	
	/**
		Gets IP address of logged user.
	*/
	virtual const QByteArray& GetLoggedIp() const = 0;
};


} // namespace icomm


