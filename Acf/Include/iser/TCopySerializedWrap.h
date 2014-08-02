/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


namespace iser
{


/// @cond DOCUMENT_ALL
/**
	Try copy of two objects using of serialization.

	\ingroup Persistence
*/
extern bool CopyByArchive(const istd::IChangeable& object, istd::IChangeable& result);
/**
	Compare two objects using coparision of serialized streams.

	\ingroup Persistence
*/
extern bool CompareByArchive(const istd::IChangeable& object1, const istd::IChangeable& object2);
/// @endcond


template <class Base>
class TCopySerializedWrap: public Base
{
public:
	typedef Base BaseClass;

	// pseudo-reimplemented (istd::IChangeable)
	virtual int GetSupportedOperations() const;
	virtual bool CopyFrom(const istd::IChangeable& object, istd::IChangeable::CompatibilityMode mode = istd::IChangeable::CM_WITHOUT_REFS);
	virtual bool IsEqual(const istd::IChangeable& object) const;
};


// public methods

// pseudo-reimplemented (istd::IChangeable)

template <class Base>
int TCopySerializedWrap<Base>::GetSupportedOperations() const
{
	return BaseClass::GetSupportedOperations() | istd::IChangeable::SO_COPY | istd::IChangeable::SO_COMPARE;
}


template <class Base>
bool TCopySerializedWrap<Base>::CopyFrom(const istd::IChangeable& object, istd::IChangeable::CompatibilityMode mode)
{
	if (BaseClass::CopyFrom(object, mode)){
		return true;
	}
	else if (mode == BaseClass::CM_WITHOUT_REFS){
		return CopyByArchive(object, *this);
	}
	else{
		return false;
	}
}


template <class Base>
bool TCopySerializedWrap<Base>::IsEqual(const istd::IChangeable& object) const
{
	if ((BaseClass::GetSupportedOperations() & istd::IChangeable::SO_COMPARE) != 0){
		return BaseClass::IsEqual(object);
	}

	return CompareByArchive(object, *this);
}


} // namespace iser


#endif // !iser_TCopySerializedWrap_included


