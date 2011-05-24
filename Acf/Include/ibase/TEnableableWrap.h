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


#ifndef ibase_TEnableableWrap_included
#define ibase_TEnableableWrap_included


#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"

#include "ibase/ibase.h"


namespace ibase
{


/**
	Basic implementation of IEnabled interface.

	\ingroup Helpers
*/
template <class Base>
class TEnableableWrap: virtual public Base
{
public:
	typedef Base BaseClass;

	TEnableableWrap();

	// pseudo-reimplemented (istd::IEnableable)
	virtual bool IsEnabled() const;
	virtual bool IsEnablingAllowed() const;
	virtual void SetEnabled(bool isEnabled = true);

protected:
	/**
		Serialize state of enable flag.
	*/
	virtual bool SerializeEnabled(iser::IArchive& archive);

private:
	bool m_isEnabled;
};


// public methods

template <class Base>
TEnableableWrap<Base>::TEnableableWrap()
{
	m_isEnabled = true;
}


// pseudo-reimplemented (istd::IEnableable)

template <class Base>
bool TEnableableWrap<Base>::IsEnabled() const
{
	return m_isEnabled;
}


template <class Base>
bool TEnableableWrap<Base>::IsEnablingAllowed() const
{
	return true;
}


template <class Base>
void TEnableableWrap<Base>::SetEnabled(bool isEnabled)
{
	if (IsEnablingAllowed() && (isEnabled != m_isEnabled)){
		istd::CChangeNotifier changePtr(this);
	
		m_isEnabled = isEnabled;
	}
}


// protected methods

template <class Base>
bool TEnableableWrap<Base>::SerializeEnabled(iser::IArchive& archive)
{
	static iser::CArchiveTag enabledTag("IsEnabled", "Object enabled state");

	bool retVal = archive.BeginTag(enabledTag);
	retVal = retVal && archive.Process(m_isEnabled);
	retVal = retVal && archive.EndTag(enabledTag);

	return retVal;
}


} // namespace ibase


#endif // ibase_TEnableableWrap_included


