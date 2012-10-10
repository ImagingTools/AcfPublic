/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iser_TCopySerializedWrap_included
#define iser_TCopySerializedWrap_included


// ACF includes
#include "istd/IChangeable.h"
#include "istd/TUpdateManagerWrap.h"


namespace iser
{


/// @cond DOCUMENT_ALL
/**
	Try copy of two objects using of serialization.

	\ingroup Persistence
	\ingroup Helpers
*/
extern bool CopyByArchive(const istd::IChangeable& object, istd::IChangeable& result);
/// @endcond


template <class Base>
class TCopySerializedWrap: public istd::TUpdateManagerWrap<Base>
{
public:
	typedef istd::TUpdateManagerWrap<Base> BaseClass;

	// pseudo-reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const istd::IChangeable& object);
};


// public methods

// pseudo-reimplemented (istd::IChangeable)

template <class Base>
bool TCopySerializedWrap<Base>::CopyFrom(const istd::IChangeable& object)
{
	if (BaseClass::CopyFrom(object)){
		return true;
	}
	else{
		return CopyByArchive(object, *this);
	}
}


} // namespace iser


#endif // !iser_TCopySerializedWrap_included


