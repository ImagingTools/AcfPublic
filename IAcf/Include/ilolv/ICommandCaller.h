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


#ifndef ilolv_ICommandCaller_included
#define ilolv_ICommandCaller_included


namespace ilolv
{


/**
	Call low level commands (for example implemented in hardware driver).
	This commands will call method ilolv::IDriver::OnCommand on driver implementation level.
*/
class ICommandCaller: public istd::IPolymorphic
{
public:
	/**
		Call driver command.
		\param	commandCode			code of command.
		\param	commandBuffer		pointer to command buffer.
		\param	commandBufferSize	size of command buffer in bytes.
		\param	responseBuffer		pointer to response buffer.
		\param	responseSize		size of response buffer in bytes.
									It is in/out value, should be set to real size of response.
		\return	true if this command was called correctly.
	*/
	virtual bool CallCommand(
				int commandCode,
				const void* commandBuffer,
				int commandBufferSize,
				void* responseBuffer,
				int responseBufferSize,
				int& responseSize) = 0;
};


} // namespace ilolv


#endif // !ilolv_ICommandCaller_included


