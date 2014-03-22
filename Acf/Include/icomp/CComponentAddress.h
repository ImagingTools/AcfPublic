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


#ifndef icomp_CComponentAddress_included
#define icomp_CComponentAddress_included


// Qt includes
#include <QtCore/QByteArray>

// ACF includes
#include "iser/ISerializable.h"


namespace icomp
{


/**
	Represents global address of component.
	The component address contains of global package ID and component ID inside this package.

	\ingroup ComponentConcept
*/
class CComponentAddress: public iser::ISerializable
{
public:
	CComponentAddress();
	CComponentAddress(const QByteArray& packageId, const QByteArray& componentId);

	/**
		Check if this address is valid.
	*/
	bool IsValid() const;

	const QByteArray& GetPackageId() const;
	void SetPackageId(const QByteArray& id);

	const QByteArray& GetComponentId() const;
	void SetComponentId(const QByteArray& id);

	QString ToString() const;
	bool FromString(const QString& address);

	bool operator==(const CComponentAddress& address) const;
	bool operator!=(const CComponentAddress& address) const;
	bool operator<(const CComponentAddress& address) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	friend uint qHash(const CComponentAddress& address);

private:
	QByteArray m_packageId;
	QByteArray m_componentId;
};


// inline methods

inline const QByteArray& CComponentAddress::GetPackageId() const
{
	return m_packageId;
}


inline void CComponentAddress::SetPackageId(const QByteArray& id)
{
	m_packageId = id;
}


inline const QByteArray& CComponentAddress::GetComponentId() const
{
	return m_componentId;
}


inline void CComponentAddress::SetComponentId(const QByteArray& id)
{
	m_componentId = id;
}


inline bool CComponentAddress::operator==(const CComponentAddress& address) const
{
	return ((m_packageId == address.m_packageId) && (m_componentId == address.m_componentId));
}


inline bool CComponentAddress::operator!=(const CComponentAddress& address) const
{
	return ((m_packageId != address.m_packageId) || (m_componentId != address.m_componentId));
}


inline bool CComponentAddress::operator<(const CComponentAddress& address) const
{
	if (m_packageId == address.m_packageId){
		return m_componentId < address.m_componentId;
	}

	return m_packageId < address.m_packageId;
}


// related functions

inline uint qHash(const icomp::CComponentAddress& address)
{
	return qHash(address.m_packageId) + qHash(address.m_packageId);
}


} // namespace icomp


#endif // !icomp_CComponentAddress_included


