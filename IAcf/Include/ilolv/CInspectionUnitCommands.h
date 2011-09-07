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


#ifndef ilolv_CInspectionUnitCommands_included
#define ilolv_CInspectionUnitCommands_included


#include "ilolv/IDriver.h"


namespace ilolv
{


class CInspectionUnitCommands
{
public:
	enum MessageId
	{
		/**
			Unidentified object was found.
		*/
		MI_UNIDENTIFIED_OBJECT_FOUND,
	};

	struct LightBarrierParams
	{
		/**
			Index of used light barrier.
			If this value is negative, this function is disabled.
		*/
		int index;
		/**
			Number of encoder clocks between light barrier and imaginated base position.
		*/
		int offset;
	};

	struct UnitParams
	{
		enum
		{
			FALLING_EDGE = 0x100
		};

		/**
			Index of used light barrier.
			If this value is negative, this function is disabled.
		*/
		int lightBarrierIndex;

		/**
			Position inside of edge when trigger should be done.
			If this value is 0, rising edge is mean, if this is equal to FALLING_EDGE than position of falling edge is mean.
			Other values mean some proportion between.
		*/
		int edgePosition;

		/**
			Number of microseconds should be trigger active.
		*/
		int triggerDuration;
		/**
			Relaxation time needed to send next trigger.
			This can usefull for example to block new camera trigger before complete acquision of previos image is done.
			Please note, that in this case object will be processed with incomplete number of acquisions.
			This value is in microseconds.
		*/
		int triggerRelaxationTime;
		/**
			Number of encoder clocks between trigger position and light barrier.
		*/
		int triggerOffset;
	};

	struct SetParams: public UnitParams
	{
		enum
		{
			Id = 370
		};

		typedef void Result;
	};

	struct SetMode
	{
		enum
		{
			Id = SetParams::Id + 1
		};

		typedef void Result;

		I_DWORD mode;
	};

	struct SingleTrigger
	{
		enum
		{
			Id = SetMode::Id + 1
		};

		struct Result
		{
			IDriver::NativeTimer nativeTimestamp;
		};
	};

	struct PopId
	{
		enum
		{
			Id = SingleTrigger::Id + 1
		};

		struct Result
		{
			int inspectionId;
			IDriver::NativeTimer nativeTimestamp;
			I_DWORD objectIndex;
			I_DWORD objectPosition;
		};
	};

	struct SetResult
	{
		enum
		{
			Id = PopId::Id + 1
		};

		struct Result{
			bool wasSet;
		};

		int inspectionId;
		int ejectorIndex;
	};
};


} // namespace ilolv


#endif // !ilolv_CInspectionUnitCommands_included


