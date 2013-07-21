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


#ifndef icomp_CComponentMetaDescriptionEncoder_included
#define icomp_CComponentMetaDescriptionEncoder_included


// Qt includes
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QMap>


namespace icomp
{


/**
	Class to decode/encode the component category into human readable text.
*/
class CComponentMetaDescriptionEncoder
{
public:
	CComponentMetaDescriptionEncoder(const QString& metaDescription);

	/**
		Get meta keys using in the meta-description.
	*/
	const QStringList& GetMetaKeys() const;

	/**
		Get value list for the given key.
	*/
	const QStringList& GetValues(const QString& key = QString()) const;

	/**
		Get the keyword list.
	*/
	const QStringList& GetUnassignedKeywords() const;

private:
	typedef QMap<QString, QStringList> MetaValuesMap;

	MetaValuesMap m_metaValuesMap;
	QStringList m_metaKeys;
	QStringList m_keywords;
	QStringList m_unassignedKeywords;
};


} // namespace icomp


#endif // !icomp_CComponentMetaDescriptionEncoder_included


