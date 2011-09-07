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


