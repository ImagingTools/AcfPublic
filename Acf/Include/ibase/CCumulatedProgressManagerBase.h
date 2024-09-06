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


// STL includes
#include <vector>
#include <map>

// Qt includes
#include <QtCore/QMutex>

// ACF includes
#include <ibase/IProgressManager.h>


namespace ibase
{


/**
	Progress manager delegating cumulated progress result to another manager.
	It allows to access cumulated progress and list of tasks beeing curently processed.
*/
class CCumulatedProgressManagerBase: virtual public ibase::IProgressManager
{
public:
	struct TaskInfo
	{
		QByteArray id;
		QString description;
	};

	/**
		Create cumulated progress manager.
	*/
	CCumulatedProgressManagerBase(const TaskInfo& defaultTaskInfo = {"", ""});
	virtual ~CCumulatedProgressManagerBase();

	/**
		Set information of the default task.
	*/
	void SetDefaultTaskInfo(const TaskInfo& defaultTaskInfo);

	/**
		Get final progress beeing result of all task progress.
	*/
	double GetCumulatedProgress() const;
	/**
		Get list of current processed tasks.
		\param	preferSorted	Flag indicating, that the task list should be sorted from the most important to less important.
		\param	maxCount		Maximal number of tasks should be returned.
	*/
	std::vector<TaskInfo> GetProcessedTasks(bool preferSorted = false, int maxCount = -1) const;

	bool IsCancelable() const;
	bool IsCanceled() const;
	void SetCanceled(bool state = true);

	// reimplemented (ibase::IProgressManager)
	void ResetProgressManager() override;
	std::unique_ptr<IProgressManager> CreateSubtaskManager(
				const QByteArray& taskId,
				const QString& taskDescription,
				double weight = 1.0) override;
	std::unique_ptr<IProgressLogger> StartProgressLogger(bool isCancelable = false) override;

protected:
	// Methods designed to be overriden
	virtual void OnProgressChanged(double cumulatedValue);
	virtual void OnTasksChanged();

	class TaskBase: virtual public istd::IPolymorphic
	{
	public:
		TaskBase(CCumulatedProgressManagerBase* parentPtr, const TaskInfo& taskInfo, double weight, bool isCancelable);
		virtual ~TaskBase();

		void StopLogging();

	protected:
		CCumulatedProgressManagerBase* m_parentPtr;
	};
	friend class SubTaskManager;

	// low level communication with logger and manager
	virtual void OpenTask(TaskBase* taskPtr, const TaskInfo& taskInfo, double weight, bool isCancelable);
	virtual void CloseTask(TaskBase* taskPtr);
	virtual void ReportTaskProgress(TaskBase* taskPtr, double progress);

	void TryUpdateCumulatedProgress();

private:
	struct ProgressInfo
	{
		double progress = 0;
		double weight = 1;
		bool isCancelable = false;
		TaskInfo taskInfo;
	};

	class Logger: public TaskBase, public ibase::IProgressLogger
	{
	public:
		Logger(CCumulatedProgressManagerBase* parentPtr, const TaskInfo& taskInfo, bool isCancelable);

		// reimplemented (ibase::IProgressLogger)
		void OnProgress(double currentProgress) override;
		bool IsCanceled() const override;
	};

	TaskInfo m_defaultTaskInfo;

	std::map<TaskBase*, ProgressInfo> m_openTasks;

	double m_currentProgress;

	double m_closedTaskSum;
	double m_maxProgressSum;
	bool m_isProgressLoggerStarted;

	int m_cancelableCounter;
	bool m_isCanceled;

	mutable QMutex m_tasksMutex;
};


} // namespace ibase


