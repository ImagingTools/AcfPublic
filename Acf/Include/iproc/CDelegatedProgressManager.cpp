/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iproc/CDelegatedProgressManager.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iproc
{


CDelegatedProgressManager::CDelegatedProgressManager()
:	m_isCanceled(false),
	m_nextSessionId(-1),
	m_progressSum(0.0),
	m_cancelableSessionsCount(0),
	m_slaveManagerPtr(NULL),
	m_slaveSessionId(-1)
{
}


CDelegatedProgressManager::CDelegatedProgressManager(
			IProgressManager* slaveManagerPtr,
			const std::string& progressId,
			const istd::CString& description,
			bool isCancelable)
:	m_slaveManagerPtr(slaveManagerPtr)
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
	return m_progressSum / m_progressMap.size();
}


// reimplemented (iproc::IProgressManager)

int CDelegatedProgressManager::BeginProgressSession(
			const std::string& /*progressId*/,
			const istd::CString& /*description*/,
			bool isCancelable)
{
	if (m_isCanceled){
		return -1;
	}

	istd::CChangeNotifier notifier(this, CF_SESSIONS_NUMBER | CF_PROGRESS_CHANGED);

	int id = m_nextSessionId++;

	ProgressInfo& info = m_progressMap[id];
	info.progress = 0;
	info.isCancelable = isCancelable;

	if (isCancelable){
		++m_cancelableSessionsCount;
	}

	return id;
}


void CDelegatedProgressManager::EndProgressSession(int sessionId)
{
	istd::CChangeNotifier notifier(this, CF_SESSIONS_NUMBER | CF_PROGRESS_CHANGED);

	ProgressMap::iterator iter = m_progressMap.find(sessionId);
	I_ASSERT(iter != m_progressMap.end());

	const ProgressInfo& info = iter->second;
	m_progressSum -= info.progress;

	if (info.isCancelable){
		--m_cancelableSessionsCount;
	}

	m_progressMap.erase(iter);

	if (m_progressMap.empty()){
		m_progressSum = 0;
		m_isCanceled = false;
	}
}


void CDelegatedProgressManager::OnProgress(int sessionId, double currentProgress)
{
	istd::CChangeNotifier notifier(this, CF_PROGRESS_CHANGED);

	ProgressMap::iterator iter = m_progressMap.find(sessionId);
	I_ASSERT(iter != m_progressMap.end());

	m_progressSum += currentProgress - iter->second.progress;
	iter->second.progress = currentProgress;
}


bool CDelegatedProgressManager::IsCanceled(int /*sessionId*/) const
{
	if (m_slaveManagerPtr != NULL){
		return m_slaveManagerPtr->IsCanceled(m_slaveSessionId);
	}

	return false;
}


// protected methods

// reimplemented (istd::IChangeable)

void CDelegatedProgressManager::OnEndChanges(int /*changeFlags*/, istd::IPolymorphic* /*changeParamsPtr*/)
{
	if (m_slaveManagerPtr != NULL){
		m_slaveManagerPtr->OnProgress(m_slaveSessionId, GetCumulatedProgress());
	}
}


} // namespace iproc


