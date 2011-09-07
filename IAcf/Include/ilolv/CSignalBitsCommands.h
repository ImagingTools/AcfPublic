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


#ifndef ilolv_CSignalBitsCommands_included
#define ilolv_CSignalBitsCommands_included


#include "ilolv/ilolv.h"


namespace ilolv
{


class CSignalBitsCommands
{
public:
	enum SignalBit
	{
		SB_HEARTBEAT,
		SB_ERROR,
		SB_WARNING
	};

	struct SignalParams
	{
		/**
			Heartbeat signal period in microseconds.
		*/
		int heartbeatPeriod;
		int signalBitsCount;
	};

	struct SetParams: public SignalParams
	{
		enum
		{
			Id = 200
		};

		typedef void Result;
	};

	struct SetSignalBitIndex
	{
		enum
		{
			Id = SetParams::Id + 1
		};

		typedef void Result;

		int signalIndex;

		int bitIndex;
	};

	struct SetApplicationStatus
	{
		enum
		{
			Id = SetSignalBitIndex::Id + 1
		};

		typedef void Result;

		int status;
	};
};


} // namespace ilolv


#endif // !ilolv_CSignalBitsCommands_included


