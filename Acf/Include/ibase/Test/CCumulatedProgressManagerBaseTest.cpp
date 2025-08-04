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


#include <ibase/Test/CCumulatedProgressManagerBaseTest.h>


// ACF includes
#include <ibase/CCumulatedProgressManagerBase.h>


void CCumulatedProgressManagerBaseTest::DoOverflowTest1()
{
	ibase::CCumulatedProgressManagerBase progress;

	std::unique_ptr<ibase::IProgressLogger> loggerPtr = progress.StartProgressLogger();
	loggerPtr->OnProgress(1);

	std::unique_ptr<ibase::IProgressManager> subtaskPtr = progress.CreateSubtaskManager("subtask1", "", 0.5);
	std::unique_ptr<ibase::IProgressLogger> subtaskLoggerPtr = subtaskPtr->StartProgressLogger();
	subtaskLoggerPtr->OnProgress(1);

	double cumulatedProgress = progress.GetCumulatedProgress();

	QVERIFY(qFuzzyCompare(cumulatedProgress, 1.5));
}


I_ADD_TEST(CCumulatedProgressManagerBaseTest);


