/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// ACF includes
#include <istd/IPolymorphic.h>


namespace icomm
{

	
/**
	Interface for sending & receiving raw data.
*/
class IBinaryStream: virtual public istd::IPolymorphic
{
public:
	/**
		Interface for event handler.
	*/
	class Handler: virtual public istd::IPolymorphic
	{
	public:
		/**
			Called when new incoming data is available.
		*/
		virtual void OnDataReceived(IBinaryStream& stream) = 0;
		/**
			Called when data was sent.
			\param	userContextPtr	user defined object from \c SendData.
		*/
		virtual void OnDataSent(IBinaryStream& stream, void* userContextPtr) = 0;
	};

	/**
		Send new data.
		\param	data			pointer to data block.
		\param	size			size of data block in bytes.
		\param	userContextPtr	user defined object, can be used to identify data during call of \c OnDataSent.
		\return true if data could be sent succesfull.
	*/
	virtual bool SendData(const void* data, int size, void* userContextPtr = NULL) = 0;
	/**
		Read new incoming data.
		\param	data	pointer to data buffer.
		\param	size	as input provide size of data buffer, as output provide number of bytes read from stream.
		\return	true if data available.
	*/
	virtual bool ReadData(void* data, int& size) = 0;

	/**
		Connect handler for receive event.
		\param	handlerPtr	Pointer to user events handler.
							This events will be called in user specificated thread.
		\param	allowOtherThread	if true, it allows calls of handler in other than current caller thread.
	*/
	virtual bool RegisterEventHandler(Handler* handlerPtr, bool allowOtherThread = false) = 0;
	/**
		Disconnect handler connected with \c RegisterEventHandler.
		\param	handlerPtr	Pointer to user events handler.
	*/
	virtual bool UnregisterEventHandler(Handler* handlerPtr) = 0;
};


} // namespace icomm


