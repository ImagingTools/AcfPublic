/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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

// ACF includes
#include <iser/ISerializable.h>
#include <iser/CArchiveTag.h>


namespace icomm
{


class CHeartbeatQuestion: virtual public iser::ISerializable
{
public:
	/**
		Construct heartbeat for broadcast.
	*/
	CHeartbeatQuestion();

	/**
		Construct heartbeat for normal check.
	*/
	CHeartbeatQuestion(
				quint32 questionId,
				const QString& applicationName,
				const QString& applicationType);

	/**
		Get name of application.
	*/
	const QString& GetApplicationName() const;

	/**
		Set name of application.
	*/
	void SetApplicationName(const QString& name);

	/**
		Get type of application.
	*/
	const QString& GetApplicationType() const;

	/**
		Set type of application.
	*/
	void SetApplicationType(const QString& appType);

	/**
		Gets ID of this question.
		This ID will be mirrored in answer object.
		Client application can use it to identify it with request.
	*/
	quint32 GetQuestionId() const;

	/**
		Gets ID of this question.
		\sa GetQuestionId()
	*/
	void SetQuestionId(quint32 questionId);

	bool operator==(const CHeartbeatQuestion& question);
	bool operator!=(const CHeartbeatQuestion& question);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	qint32 m_questionId;
	QString m_applicationName;
	QString m_applicationType;
};


// inline methods

inline const QString& CHeartbeatQuestion::GetApplicationName() const
{
	return m_applicationName;
}


inline void CHeartbeatQuestion::SetApplicationName(const QString& name)
{
	m_applicationName = name;
}


inline const QString& CHeartbeatQuestion::GetApplicationType() const
{
	return m_applicationType;
}


inline void CHeartbeatQuestion::SetApplicationType(const QString& appType)
{
	m_applicationType = appType;
}


inline quint32 CHeartbeatQuestion::GetQuestionId() const
{
	return m_questionId;
}


inline void CHeartbeatQuestion::SetQuestionId(quint32 questionId)
{
	m_questionId = questionId;
}


inline bool CHeartbeatQuestion::operator!=(const CHeartbeatQuestion& question)
{
	return !operator==(question);
}


} // namespace icomm


