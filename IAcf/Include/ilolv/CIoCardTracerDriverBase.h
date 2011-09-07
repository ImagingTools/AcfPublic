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


#ifndef ilolv_CIoCardTracerDriverBase_included
#define ilolv_CIoCardTracerDriverBase_included


#include "ilolv/IDigitalIo.h"
#include "ilolv/CIoCardTracerCommands.h"
#include "ilolv/CSingleCountTracerDriverBase.h"


namespace ilolv
{


/**
	Implementation of line controller based on simple standard I/O card hardware.
 */
class CIoCardTracerDriverBase: public CSingleCountTracerDriverBase, virtual public IDigitalIo
{
public:
	typedef CSingleCountTracerDriverBase BaseClass;

	CIoCardTracerDriverBase();

	I_DWORD GetInterruptsMask() const;

	// reimplemented (ilolv::CTracerDriverBase)
	virtual I_DWORD GetLinePosition() const;
	virtual bool GetLightBarrierBit(int lightBarrierIndex) const;
	virtual void SetTriggerBit(int bit, bool state);
	virtual void SetEjectorBit(int ejectorIndex, bool state);
	virtual I_SQWORD GetCurrentTimer() const;
	virtual NativeTimer GetCurrentNativeTimer() const;

	// reimplemented (ilolv::IDriver)
	virtual bool OnCommand(
				int commandCode,
				const void* commandBuffer,
				int commandBufferSize,
				void* responseBuffer,
				int responseBufferSize,
				int& responseSize);
	virtual void OnHardwareInterrupt(I_DWORD interruptFlags);

	// reimplemented (ilolv::IDigitalIo)
	virtual I_DWORD GetInputBits() const;

protected:
	/**
		Update hardware input values.
	*/
	virtual void UpdateHardwareValues(I_DWORD inputBits, I_WORD counterValue, I_SQWORD microsecsTimer, IDriver::NativeTimer nativeTimer);

	/**
		Called internal when counter is ready.
	*/
	void OnCounterReady();

	// reimplemented (ilolv::CSingleCountTracerDriverBase)
	virtual void SetNextSinglePositionEvent(const I_DWORD* eventPositionPtr);

	// abstract methods
	/**
		Set counter value to specified value.
		This counter counts encoder pulses down.
		When 0 is achived, implementation of counter has to call method \c OnHardwareInterrupt with set flag IF_ENCODER_INTERRUPT.
	*/
	virtual void SetEncoderCounter(I_WORD value) = 0;

private:
	enum
	{
		MAX_COUNTER_VALUE = 0x7ff8
	};

	CIoCardTracerCommands::IoParams m_ioParams;

	I_DWORD m_nextEventPosition;
	bool m_isPositionEventActive;

	I_WORD m_lastCounterValue;

	// Shadows of hardware
	I_DWORD m_inputBits;
	I_DWORD m_linePosition;
	I_SQWORD m_currentTimer;
	IDriver::NativeTimer m_currentNativeTimer;
};


} // namespace ilolv


#endif // !ilolv_CIoCardTracerDriverBase_included


