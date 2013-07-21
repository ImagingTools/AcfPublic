/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef istd_TSingleFactory_included
#define istd_TSingleFactory_included


// Qt includes
#include <QtCore/QByteArray>

// ACF includes
#include "istd/TIFactory.h"


namespace istd
{


/**
	Template based object factory interface.
*/
template <class Interface, class Implementation>
class TSingleFactory: virtual public TIFactory<Interface>
{
public:
	typedef Implementation ImplementationType;
	typedef TIFactory<Interface> FactoryInterface;

	explicit TSingleFactory(const QByteArray& keyId);

	// reimplemented (istd::IFactoryInfo)
	virtual IFactoryInfo::KeyList GetFactoryKeys() const;

	// reimplemented (istd::TIFactory)
	virtual Interface* CreateInstance(const QByteArray& keyId = "") const;

private:
	QByteArray m_keyId;
};


// public methods

template <class Interface, class Implementation>
TSingleFactory<Interface, Implementation>::TSingleFactory(const QByteArray& keyId)
:	m_keyId(keyId)
{

}


// reimplemented (istd::TIFactory)

template <class Interface, class Implementation>
IFactoryInfo::KeyList TSingleFactory<Interface, Implementation>::GetFactoryKeys() const
{
	typename TIFactory<Interface>::KeyList retVal;

	retVal.push_back(m_keyId);

	return retVal;
}


template <class Interface, class Implementation>
Interface* TSingleFactory<Interface, Implementation>::CreateInstance(const QByteArray& keyId) const
{
	if (keyId.isEmpty() || (keyId == m_keyId)){
		return new Implementation;
	}

	return NULL;
}


} // namespace istd


#endif // !istd_TSingleFactory_included


