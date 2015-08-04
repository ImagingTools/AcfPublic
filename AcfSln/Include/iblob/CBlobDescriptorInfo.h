/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// Qt includes
#include <QtCore/QString>
#include <QtCore/QList>


namespace iblob
{


class CBlobDescriptorInfo
{
public:
	enum BlobDescriptorType
	{
		BDT_PERIMETER,
		BDT_AREA,
		BDT_CIRCULARITY,
		BDT_USER = 1000
	};

	CBlobDescriptorInfo(
				int descriptorType, 
				const QString& fullName, 
				const QString& shortName,
				const QString& description = QString());

	QString GetFullName() const;
	QString GetShortName() const;
	QString GetDescription() const;
	int GetDescriptorType() const;

private:
	int m_descriptorType;
	QString m_fullName;
	QString m_shortName;
	QString m_description;
};


// public inline methods

inline QString CBlobDescriptorInfo::GetFullName() const
{
	return m_fullName;
}


inline QString CBlobDescriptorInfo::GetShortName() const
{
	return m_shortName;
}


inline QString CBlobDescriptorInfo::GetDescription() const
{
	return m_description;
}


inline int CBlobDescriptorInfo::GetDescriptorType() const
{
	return m_descriptorType;
}


typedef QList<CBlobDescriptorInfo> BlobDescriptorInfoList;


} // namespace iblob





