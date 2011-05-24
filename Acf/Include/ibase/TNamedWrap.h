/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_TNamedWrap_included
#define ibase_TNamedWrap_included


#include "ibase/ibase.h"


#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"

#include "istd/INamed.h"
#include "istd/TChangeNotifier.h"


namespace ibase
{


/**
	Template based implementation of a named object. 
	This class is a pseudo-implementation of istd::INamed interface.

	\ingroup Helpers
*/
template <class BaseClass>
class TNamedWrap: virtual public BaseClass
{
public:
	// peudeo-reimplemented (istd::INamed)
	virtual const istd::CString& GetName() const;
	virtual void SetName(const istd::CString& name);

protected:
	virtual bool SerializeName(iser::IArchive& archive);

protected:
	istd::CString m_name;
};



// peudeo-reimplemented (istd::INamed)

template <class BaseClass>
const istd::CString& TNamedWrap<BaseClass>::GetName() const
{
	return m_name;
}


template <class BaseClass>
void TNamedWrap<BaseClass>::SetName(const istd::CString& name)
{
	if (m_name != name){
		istd::CChangeNotifier changePtr(this);

		m_name = name;
	}
}


// protected members

template <class BaseClass>
bool TNamedWrap<BaseClass>::SerializeName(iser::IArchive& archive)
{
	static iser::CArchiveTag nameTag("Name", "Object name");

	bool retVal = archive.BeginTag(nameTag);
	retVal = retVal && archive.Process(m_name);
	retVal = retVal && archive.EndTag(nameTag);

	return retVal;
}


typedef ibase::TNamedWrap<istd::INamed> CNamed;


} // namespace ibase


#endif // ibase_TNamedWrap_included
