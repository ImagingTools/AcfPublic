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


#ifndef ilolv_CSingleCountTracerDriverBase_included
#define ilolv_CSingleCountTracerDriverBase_included


#include "ilolv/CTracerDriverBase.h"
#include "ilolv/TOrderedPositionsQueue.h"


namespace ilolv
{


/**
	Object tracer based on single line position counter.
	This single counter will be 'multiplied' using set of queues.
*/
class CSingleCountTracerDriverBase: public CTracerDriverBase
{
public:
	typedef CTracerDriverBase BaseClass;

	CSingleCountTracerDriverBase();

	// reimplemented (ilolv::CTracerDriverBase)
	virtual void ResetQueue();
	virtual bool SetCounterQueuesCount(int count);
	virtual void InsertPositionToQueue(int queueIndex, I_DWORD counterPosition, void* userContext);

protected:
	/**
		Check all position queues and calculate the next single position event.
	*/
	bool CalculateNextSinglePositionEvent();

	/**
		Called by derived implementation when single position event is occured.
	*/
	void OnSinglePositionEvent();

	// abstract methods
	/**
		Set or remove position of next position event.
		\param	eventPositionPtr	optional position value.
									If this is NULL, position of next event will be removed.
	*/
	virtual void SetNextSinglePositionEvent(const I_DWORD* eventPositionPtr) = 0;

private:
	enum
	{
		MAX_EVENTS_COUNT = 50,
	};

	typedef TOrderedPositionsQueue<void*> EventQueue;
	EventQueue m_positionEventQueues[MAX_EVENTS_COUNT];

	int m_positionEventsCount;
};


} // namespace ilolv


#endif // !ilolv_CSingleCountTracerDriverBase_included


