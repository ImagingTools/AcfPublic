/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef ilolv_CGeneralInfoDriverBase_included
#define ilolv_CGeneralInfoDriverBase_included


#include "ilolv/IDriver.h"
#include "ilolv/CGeneralInfoCommands.h"


namespace ilolv
{


/**
	Implementation of general information (for example error handling) for driver.
*/
class CGeneralInfoDriverBase: virtual public IDriver
{
public:
	CGeneralInfoDriverBase();

	const CGeneralInfoCommands::GeneralInfoParams& GetGeneralInfoParams() const;

	// reimplemented (ilolv::IDriver)
	virtual bool OnCommand(
				int commandCode,
				const void* commandBuffer,
				int commandBufferSize,
				void* responseBuffer,
				int responseBufferSize,
				int& responseSize);
	virtual void OnHardwareInterrupt(I_DWORD interruptFlags);

protected:
	// reimplemented (ilolv::IDriver)
	virtual void AppendMessage(int category, int id, const char* text, bool doSend = true);

private:
	void OnPopMessageCommand(CGeneralInfoCommands::PopMessage::Result& result);
	void OnKeepAliveCommand();

	mutable CGeneralInfoCommands::PopMessage::Result m_message;
	int m_messagePosition;

	CGeneralInfoCommands::GeneralInfoParams m_params;

	I_SQWORD m_nextMinKeepAliveTime;
};


// inline methods

inline const CGeneralInfoCommands::GeneralInfoParams& CGeneralInfoDriverBase::GetGeneralInfoParams() const
{
	return m_params;
}


} // namespace ilolv


#endif // !ilolv_CGeneralInfoDriverBase_included


