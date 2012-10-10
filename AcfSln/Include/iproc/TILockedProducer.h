/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iproc_TILockedProducer_included
#define iproc_TILockedProducer_included


// ACF includes
#include "istd/IPolymorphic.h"

#include "iproc/iproc.h"


namespace iproc
{


/**
	Template interface for providers of cached data.
	Cached data are accessible in transaction blocks between lock and unlock operation.
	This data are accessed using abstract key object.
	Please note that \c Key class must implement standard STL operators needed to use it as QMap key.
*/
template <class Key, class CacheObject>
class TILockedProducer: virtual public istd::IPolymorphic
{
public:
	/**
		Begin of accessing to cached element.
		\return	cached object, if it was possible to produce it for specified key.
	*/
	virtual const CacheObject* ProduceLockedObject(const Key& key) = 0;

	/**
		End of accessing to cached element.
	*/
	virtual void UnlockObject(const CacheObject* objectPtr) = 0;
};


} // namespace iproc


#endif // !iproc_TILockedProducer_included


