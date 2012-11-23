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


#ifndef ibase_CMessage_included
#define ibase_CMessage_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include "istd/IInformationProvider.h"

#include "iser/ISerializable.h"


namespace ibase
{


/**
	Basic implementation of the istd::IInformationProvider interface
*/
class CMessage:
			virtual public istd::IInformationProvider,
			virtual public iser::ISerializable
{
public:
	CMessage();
	CMessage(	istd::IInformationProvider::InformationCategory category,
				int id,
				const QString& text,
				const QString& source,
				int flags = 0);

	virtual void SetCategory(istd::IInformationProvider::InformationCategory category);
	virtual void SetText(const QString& text);
	virtual void SetSource(const QString& source);

	// reimplemented (istd::IInformationProvider)
	virtual QDateTime GetInformationTimeStamp() const;
	virtual InformationCategory GetInformationCategory() const;
	virtual int GetInformationId() const;
	virtual QString GetInformationDescription() const;
	virtual QString GetInformationSource() const;
	virtual int GetInformationFlags() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const istd::IChangeable& object);
	virtual istd::IChangeable* CloneMe() const;

protected:
	istd::IInformationProvider::InformationCategory m_category;
	int m_id;
	QString m_text;
	QString m_source;
	int m_flags;

	QDateTime m_timeStamp;
};


// inline methods

// reimplemented (istd::IInformationProvider)

inline QDateTime CMessage::GetInformationTimeStamp() const
{
	return m_timeStamp;
}


inline istd::IInformationProvider::InformationCategory CMessage::GetInformationCategory() const
{
	return m_category;
}


inline int CMessage::GetInformationId() const
{
	return m_id;
}


inline QString CMessage::GetInformationDescription() const
{
	return m_text;
}


inline QString CMessage::GetInformationSource() const
{
	return m_source;
}


inline int CMessage::GetInformationFlags() const
{
	return m_flags;
}


} // namespace ibase


#endif // !ibase_CMessage_included


