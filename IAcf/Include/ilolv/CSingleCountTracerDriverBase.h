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


