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


#ifndef ilolv_CSignalBitsDriverBase_included
#define ilolv_CSignalBitsDriverBase_included


#include "ilolv/IDriver.h"
#include "ilolv/IDigitalIo.h"
#include "ilolv/CSignalBitsCommands.h"


namespace ilolv
{


/**
	Implementation of standard bits signalizing (like error, warning and heartbeat output bits) for drivers.
*/
class CSignalBitsDriverBase: virtual public IDriver, virtual public IDigitalIo
{
public:
	CSignalBitsDriverBase();

	const CSignalBitsCommands::SignalParams& GetSignalParams() const;

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
	enum{
		MAX_SIGNALS = 16,
		MAX_SIGNAL_BITS = 16
	};

	/**
		Set signal bit to specified state.
	*/
	void SetSignalBit(int signal, bool state);

	// reimplemented (ilolv::IDriver)
	virtual int CreateSignalId();
	virtual bool SetSignalState(int signalId, int state);

private:
	CSignalBitsCommands::SignalParams m_params;

	// indices of output bits
	int m_signalBitIndices[MAX_SIGNAL_BITS];

	int m_signalStates[MAX_SIGNALS];
	int m_nextFreeSignalId;

	int m_globalStatus;
	int m_shownGlobalStatus;

	// internal counters
	I_SQWORD m_lastHeartbeatTime;
	bool m_doHeartbeatPullDown;
};


// inline methods

inline const CSignalBitsCommands::SignalParams& CSignalBitsDriverBase::GetSignalParams() const
{
	return m_params;
}


} // namespace ilolv


#endif // !ilolv_CSignalBitsDriverBase_included


