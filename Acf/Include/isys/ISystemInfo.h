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


#ifndef isys_ISystemInfo_included
#define isys_ISystemInfo_included


#include "isys/isys.h"


#include "istd/CString.h"

#include "iser/ISerializable.h"



namespace isys
{


/**
	Common interface to get the information about the system resources.

	\ingroup System
*/
class ISystemInfo: virtual public iser::ISerializable
{
public:
	/**
		Get computer/workstation name.
	*/
	virtual istd::CString GetComputerName() const = 0;
	/**
		Get number of processors installed.
	*/
	virtual int GetProcessorsCount() const = 0;

	/**
		Get ID of the processor with index \c processorIndex.
	*/
	virtual int GetProcessorId(int processorIndex) const = 0;

	/**
		Returns \c true if there are network adapter(s) installed.
	*/
	virtual bool IsNetworkAdapterInstalled(int* adapterCountPtr = NULL) const = 0;

	/**
		Get MAC address of the network adapter.
	*/
	virtual std::string GetMacAdress(int adapterIndex) const = 0;
};


} // namespace isys


#endif // isys_ISystemInfo_included


