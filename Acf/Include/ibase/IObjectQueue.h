/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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


#ifndef ibase_IObjectQueue_included
#define ibase_IObjectQueue_included


// Qt includes
#include <QtCore/QByteArray>
#include <QtCore/QVector>

// ACF includes
#include "istd/IChangeable.h"


namespace ibase
{


/**
	Interface allowing to manage queue of some objects.
*/
class IObjectQueue: virtual public istd::IChangeable
{
public:
	typedef QVector<istd::IChangeable*> ObjectList;

	/**
		Get number of objects in this queue.
		\param	typeIdPtr	optional object ID, if many of object types are supported.
	*/
	virtual int GetObjectsCount(const QByteArray* typeIdPtr = NULL) const = 0;

	/**
		Remove all objects from queue.
	*/
	virtual void ClearQueue() = 0;

	/**
		Create object at the front of this queue.
		This object belongs to queue, and will be by the queue removed from memory.
		\param	offsetPos	position from the front, where the object should be placed.
		\param	typeIdPtr	optional object ID, if many of object types are supported.
	*/
	virtual istd::IChangeable* CreateFrontObject(int offsetPos = 0, const QByteArray* typeIdPtr = NULL) = 0;
	/**
		Create object at the end of this queue.
		This object belongs to queue, and will be by the queue removed from memory.
		\param	offsetPos	position from the end, where the object should be placed.
		\param	typeIdPtr	optional object ID, if many of object types are supported.
	*/
	virtual istd::IChangeable* CreateBackObject(int offsetPos = 0, const QByteArray* typeIdPtr = NULL) = 0;

	/**
		Remove object at the front of this queue.
		The object must not be physically removed from memory at this moment.
		\param	offsetPos	position from the front.
		\param	typeIdPtr	optional object ID, if many of object types are supported.
	*/
	virtual void RemoveFrontObject(int offsetPos = 0, const QByteArray* typeIdPtr = NULL) = 0;
	/**
		Remove object at the end of this queue.
		The object must not be physically removed from memory at this moment.
		\param	offsetPos	position from the end.
		\param	typeIdPtr	optional object ID, if many of object types are supported.
	*/
	virtual void RemoveBackObject(int offsetPos = 0, const QByteArray* typeIdPtr = NULL) = 0;

	/**
		Get object at the front of queue.
		\param	offsetPos	position from the front.
		\param	typeIdPtr	optional object ID, if many of object types are supported.
	*/
	virtual istd::IChangeable* GetFrontObject(int offsetPos = 0, const QByteArray* typeIdPtr = NULL) const = 0;
	/**
		Get object at the end of queue.
		\param	offsetPos	position from the end.
		\param	typeIdPtr	optional object ID, if many of object types are supported.
	*/
	virtual istd::IChangeable* GetBackObject(int offsetPos = 0, const QByteArray* typeIdPtr = NULL) const = 0;

	/**
		Find set of objects.
	*/
	virtual void SelectObjects(
				ObjectList& result,
				bool doAppend = false,
				int offsetPos = 0,
				const QByteArray* typeIdPtr = NULL) const = 0;

	/**
		Get object at the front of queue and remove it from queue.
		It means, this object will be overtaken by caller.
		\param	offsetPos	position from the front.
		\param	typeIdPtr	optional object ID, if many of object types are supported.
	*/
	virtual istd::IChangeable* PopFrontObject(int offsetPos = 0, const QByteArray* typeIdPtr = NULL) = 0;
	/**
		Get object at the end of queue and remove it from queue.
		It means, this object will be overtaken by caller.
		\param	offsetPos	position from the end.
		\param	typeIdPtr	optional object ID, if many of object types are supported.
	*/
	virtual istd::IChangeable* PopBackObject(int offsetPos = 0, const QByteArray* typeIdPtr = NULL) = 0;
};


} // namespace ibase


#endif // !ibase_IObjectQueue_included


