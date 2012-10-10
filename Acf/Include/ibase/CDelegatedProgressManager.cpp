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


#include "ibase/CDelegatedProgressManager.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace ibase
{


CDelegatedProgressManager::CDelegatedProgressManager()
:	m_nextSessionId(0),
	m_progressSum(0.0),
	m_cancelableSessionsCount(0),
	m_slaveManagerPtr(NULL),
	m_slaveSessionId(-1)
{
}


CDelegatedProgressManager::CDelegatedProgressManager(
			IProgressManager* slaveManagerPtr,
			const QByteArray& progressId,
			const QString& description,
			bool isCancelable)
:	m_slaveManagerPtr(slaveManagerPtr),
	m_nextSessionId(0),
	m_progressSum(0.0),
	m_cancelableSessionsCount(0)
{
	m_slaveSessionId = m_slaveManagerPtr->BeginProgressSession(progressId, description, isCancelable);
	if (m_slaveSessionId < 0){
		m_slaveManagerPtr = NULL;
	}
}


CDelegatedProgressManager::~CDelegatedProgressManager()
{
	if (m_slaveManagerPtr != NULL){
		m_slaveManagerPtr->EndProgressSession(m_slaveSessionId);
	}

	m_slaveManagerPtr = NULL;
	m_slaveSessionId = -1;
}


double CDelegatedProgressManager::GetCumulatedProgress() const
{
	if (m_progressMap.isEmpty()){
		return 0.0;
	}

	return m_progressSum / m_progressMap.size();
}


// reimplemented (ibase::IProgressManager)

int CDelegatedProgressManager::BeginProgressSession(
			const QByteArray& /*progressId*/,
			const QString& /*description*/,
			bool isCancelable)
{
	istd::CChangeNotifier notifier(this, CF_SESSIONS_NUMBER | CF_PROGRESS_CHANGED);

	int id = m_nextSessionId++;
	m_progressSum = 0.0;

	ProgressInfo& info = m_progressMap[id];
	info.progress = 0;
	info.isCancelable = isCancelable;

	if (isCancelable){
		if (m_cancelableSessionsCount == 0){
			OnCancelable(true);
		}

		++m_cancelableSessionsCount;
	}

	return id;
}


void CDelegatedProgressManager::EndProgressSession(int sessionId)
{
	istd::CChangeNotifier notifier(this, CF_SESSIONS_NUMBER | CF_PROGRESS_CHANGED);

	ProgressMap::iterator iter = m_progressMap.find(sessionId);
	I_ASSERT(iter != m_progressMap.constEnd());

	const ProgressInfo& info = iter.value();
	m_progressSum -= info.progress;

	if (info.isCancelable){
		--m_cancelableSessionsCount;

		if (m_cancelableSessionsCount == 0){
			OnCancelable(false);
		}
	}

	m_progressMap.erase(iter);
}


void CDelegatedProgressManager::OnProgress(int sessionId, double currentProgress)
{
	I_ASSERT(m_progressMap.contains(sessionId));

	istd::CChangeNotifier notifier(this, CF_PROGRESS_CHANGED);

	ProgressInfo& value = m_progressMap[sessionId];

	m_progressSum += currentProgress - value.progress;
	value.progress = currentProgress;
}


bool CDelegatedProgressManager::IsCanceled(int /*sessionId*/) const
{
	if (m_slaveManagerPtr != NULL){
		return m_slaveManagerPtr->IsCanceled(m_slaveSessionId);
	}

	return false;
}


// protected methods

int CDelegatedProgressManager::GetOpenSessionsCount() const
{
	return int(m_progressMap.size());
}


void CDelegatedProgressManager::OnCancelable(bool /*cancelState*/)
{
}


// reimplemented (istd::IChangeable)

void CDelegatedProgressManager::OnEndChanges(int /*changeFlags*/, istd::IPolymorphic* /*changeParamsPtr*/)
{
	if (m_slaveManagerPtr != NULL){
		m_slaveManagerPtr->OnProgress(m_slaveSessionId, GetCumulatedProgress());
	}
}


} // namespace ibase


