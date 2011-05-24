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


#ifndef ilolv_IDriver_included
#define ilolv_IDriver_included


#include "istd/IPolymorphic.h"

#include "ilolv/ilolv.h"


namespace ilolv
{


class IDriver: virtual public istd::IPolymorphic
{
public:
	/**
		Possible states of signal.
	*/
	enum SignalState
	{
		SS_OK,
		SS_WARNING,
		SS_ERROR,
		SS_CRITICAL
	};

	enum InterruptFlags
	{
		IF_DIGITAL_INPUT = 0x100,
		IF_ENCODER_INTERRUPT = 0x200,
		IF_PULSE_TIMER = 0x400
	};

	typedef I_SQWORD NativeTimer;

	virtual ~IDriver(){}

	/**
		Called if user command should be executed.
		\param	commandCode			code of command.
		\param	commandBuffer		pointer to command buffer.
		\param	commandBufferSize	size of command buffer in bytes.
		\param	responseBuffer		pointer to response buffer.
		\param	responseSize		size of response buffer in bytes.
									It is in/out value, should be set to real size of response.
		\return	true if this command was consumed.
	*/
	virtual bool OnCommand(
				int commandCode,
				const void* commandBuffer,
				int commandBufferSize,
				void* responseBuffer,
				int responseBufferSize,
				int& responseSize) = 0;

	/**
		Called if hardware interrupt is occured.
		\param	interruptFlags	interrupt source flags.
	*/
	virtual void OnHardwareInterrupt(I_DWORD interruptFlags) = 0;

protected:
	/**
		Get value of timer in microseconds.
	*/
	virtual I_SQWORD GetCurrentTimer() const = 0;
	/**
		Get native timer.
		Native timer is needed to exchange absolute timer value between driver and application.
	*/
	virtual NativeTimer GetCurrentNativeTimer() const = 0;

	/**
		Append message or send complete message to application.
		\param	category	category of message, \sa CGeneralInfoCommands::MessageCategory.
		\param	id			ID of message.
		\param	text		message text.
		\param	doSend		if it is true, completed message will be send to application.
	*/
	virtual void AppendMessage(int category, int id, const char* text, bool doSend = true) = 0;

	/**
		Create new signal ID.
		\return	new ID or negative value, if it was not possible to create new signal.
	*/
	virtual int CreateSignalId() = 0;
	/**	Set signal to specified state.
		\param	signalId	ID returned by method CreateSignalId().
		\param	state		state of signal.
	*/
	virtual bool SetSignalState(int signalId, int state) = 0;
};


} // namespace ilolv


#endif // !ilolv_IDriver_included


