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


#ifndef iser_IObject_included
#define iser_IObject_included


// ACF includes
#include <istd/TIFactory.h>
#include <iser/ISerializable.h>


namespace iser
{


/**
	Common interface for factorisable model objects.

	\ingroup Persistence
*/
class IObject: virtual public ISerializable
{
public:
	virtual QByteArray GetFactoryId() const;
};


// public methods 

inline QByteArray IObject::GetFactoryId() const
{
	static QByteArray emptyId;

	return emptyId;
}


// public typedefs

typedef istd::TIFactory<IObject> IObjectFactory;


} // namespace iser


#endif // !iser_IObject_included

