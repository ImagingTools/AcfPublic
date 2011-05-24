/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef isys_CSystemInfoBase_included
#define isys_CSystemInfoBase_included


#include "isys/ISystemInfo.h"



namespace isys
{


/**
	Basic implementation for system info interface.
*/
class CSystemInfoBase: virtual public isys::ISystemInfo
{
public:
	// reimplemented (isys::ISystemInfo)
	virtual istd::CString GetComputerName() const;
	virtual int GetProcessorsCount() const;
	virtual int GetProcessorId(int processorIndex) const;
	virtual bool IsNetworkAdapterInstalled(int* adapterCountPtr = NULL) const;
	virtual std::string GetMacAdress(int adapterIndex) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	typedef std::vector<I_DWORD> ProcessorIds;
	typedef std::vector<std::string> NetworkAdapters;

	istd::CString m_computerName;
	ProcessorIds m_processorIds;
	NetworkAdapters m_networkAdapters;
};


} // namespace isys


#endif // isys_CSystemInfoBase_included


