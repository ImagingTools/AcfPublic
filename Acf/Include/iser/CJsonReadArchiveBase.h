/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#pragma once


// Qt includes
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QtCore/QVector>

// ACF includes
#include <iser/CTextReadArchiveBase.h>


namespace iser
{


/**
	Implementation of an ACF archive deserializing from a JSON string

	\note	As to simplify decoding of some more complicated data structures support
			for special annotation tags was added. They are used for guiding the 
			deserialization algorithm in some special cases.
*/
class CJsonReadArchiveBase : public iser::CTextReadArchiveBase
{
public:
	typedef CTextReadArchiveBase BaseClass;

	// reimplemented (iser::IArchive)
	virtual bool BeginTag(const iser::CArchiveTag& tag);
	virtual bool BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count);
	virtual bool EndTag(const iser::CArchiveTag& tag);
	virtual bool Process(QString& value);

protected:
	bool InitArchive(const QByteArray& inputString);
	bool ReadStringNode(QString& text);

	// reimplemented (iser::CTextReadArchiveBase)
	virtual bool ReadTextNode(QByteArray& text);

protected:
	QJsonDocument m_document;
		
	QVector<QJsonObject::const_iterator> m_objectsStack;

	bool m_isNewFormat;			// idicate that new format is enabled
	bool m_allowAttribute;		// indicate if attribute outputting is allowed now

	QByteArray m_currentAttribute;

	typedef QList<const iser::CArchiveTag*> TagsList;
	TagsList m_tagsStack;
};


} // namespace iser


