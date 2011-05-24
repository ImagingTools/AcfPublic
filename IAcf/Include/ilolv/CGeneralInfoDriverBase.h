/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
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


