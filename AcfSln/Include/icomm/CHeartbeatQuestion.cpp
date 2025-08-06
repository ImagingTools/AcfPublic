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


#include <icomm/CHeartbeatQuestion.h>


// ACF includes
#include <istd/CChangeNotifier.h>
#include <iser/IArchive.h>


namespace icomm
{


CHeartbeatQuestion::CHeartbeatQuestion()
:	m_questionId(-1)
{
}


CHeartbeatQuestion::CHeartbeatQuestion(
				quint32 questionId,
				const QString& applicationName,
				const QString& applicationType)
	:m_questionId(questionId),
	m_applicationName(applicationName),
	m_applicationType(applicationType)
{
}


bool CHeartbeatQuestion::operator==(const CHeartbeatQuestion& question)
{
	return			(m_applicationName == question.m_applicationName) &&
					(m_applicationType == question.m_applicationType) &&
					(m_questionId == question.m_questionId);
}


// reimplemented (iser::ISerializable)

bool CHeartbeatQuestion::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag applicationNameTag("ApplicationName", "Name of application");
	static iser::CArchiveTag applicationTypeTag("ApplicationType", "Type of application");
	static iser::CArchiveTag questionIdTag("QuestionId", "ID of this question");

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);

	bool result = true;

	result = result && archive.BeginTag(applicationNameTag);
	result = result && archive.Process(m_applicationName);
	result = result && archive.EndTag(applicationNameTag);

	result = result && archive.BeginTag(applicationTypeTag);
	result = result && archive.Process(m_applicationType);
	result = result && archive.EndTag(applicationTypeTag);

	result = result && archive.BeginTag(questionIdTag);
	result = result && archive.Process(m_questionId);
	result = result && archive.EndTag(questionIdTag);

	return result;
}


} // namespace icomm


