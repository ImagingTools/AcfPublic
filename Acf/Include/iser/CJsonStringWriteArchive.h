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
#include <QtCore/QTextStream>

// ACF includes
#include <iser/CTextWriteArchiveBase.h>


namespace iser
{


/**
	Implementation of an ACF Archive serializing to JSON string
*/
class CJsonStringWriteArchive: public iser::CTextWriteArchiveBase
{
public:
	typedef iser::CTextWriteArchiveBase BaseClass;

	CJsonStringWriteArchive(
				QByteArray& inputString,
				const iser::IVersionInfo* versionInfoPtr = NULL,
				QJsonDocument::JsonFormat jsonFormat = QJsonDocument::Compact);

	virtual ~CJsonStringWriteArchive();

	// reimplemented (iser::IArchive)
	virtual bool IsTagSkippingSupported() const;
	virtual bool BeginTag(const iser::CArchiveTag& tag);
	virtual bool BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count);
	virtual bool EndTag(const iser::CArchiveTag& tag);
	virtual bool Process(QString& value);

	using BaseClass::Process;

protected:
	void WriteTag(const iser::CArchiveTag& tag, QString separator, bool isWriteTag = true);

	// reimplemented (iser::CTextWriteArchiveBase)
	virtual bool WriteTextNode(const QByteArray& text);

private:
	QTextStream m_stream;
	bool m_firstTag;
	QJsonDocument::JsonFormat m_jsonFormat;

	QByteArray m_currentAttribute;

	bool m_serializeHeader;
	iser::CArchiveTag m_rootTag;

	bool m_isSeparatorNeeded;	// idicate that separator must be added before something is outputted
	bool m_allowAttribute;		// indicate if attribute outputting is allowed now

	QList<const iser::CArchiveTag*> m_tagsStack;
};


} // namespace iser


