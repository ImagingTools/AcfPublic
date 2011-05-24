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


#ifndef ilolv_CGeneralInfoCommands_included
#define ilolv_CGeneralInfoCommands_included


#include "ilolv/ilolv.h"


namespace ilolv
{


class CGeneralInfoCommands
{
public:
	/**
		Categories of message info.
	 */
	enum MessageCategory
	{
		MC_INFO,
		MC_WARNING,
		MC_ERROR,
		MC_CRITICAL
	};

	enum MessageId
	{
		/**
			There was no response from application.
		*/
		MI_NO_RESPONSE = 500,
		/**
			Some internal error.
		*/
		MI_INTERNAL_ERROR
	};

	enum
	{
		MAX_ERROR_MESSAGE_SIZE = 256
	};

	struct GeneralInfoParams
	{
		/**
			Maximal time span between two 'Keep Alive' messages in microseconds.
		*/
		int maxKeepAliveTime;
	};


	struct SetParams: public GeneralInfoParams
	{
		enum
		{
			Id = 100
		};

		typedef void Result;
	};

	/**
		Keep Alive message informing driver that application is working.
	*/
	struct KeepAlive
	{
		enum
		{
			Id = SetParams::Id + 1
		};

		typedef void Result;
	};

	/**
		Get driver message and remove it from message list.
	*/
	struct PopMessage
	{
		enum
		{
			Id = KeepAlive::Id + 1
		};

		struct Result
		{
			/**
				Message category \sa MessageCategory.
			*/
			int category;	// value of qstd::IResult::Category, -1 if no message
			/**
				Unique message Id used to automatical message processing.
			*/
			int id;
			/**
				Message flags.
			*/
			int flags;
			/**
				Number of parameters.
			*/
			int paramsCount;
			/**
				Human readable message text.
			*/
			char text[MAX_ERROR_MESSAGE_SIZE];
		};
	};
};


} // namespace ilolv


#endif // !ilolv_CGeneralInfoCommands_included


