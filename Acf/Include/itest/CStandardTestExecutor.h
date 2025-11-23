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
#include <QtCore/QObject>
#include <QtCore/QVector>

// ACF includes
#include <istd/TSmartPtr.h>
#include <itest/ITestExecutor.h>


namespace itest
{


/**
	Standard implementation of ITestExecutor with static test registration
*/
class CStandardTestExecutor: virtual public ITestExecutor
{
public:
	// reimplemented (ITestExecutor)
	virtual int RunTests(int argc, char *argv[]) override;

public:
	template <class TestObject>
	class TestRegistrator
	{
	public:
		TestRegistrator(const QString& name)
		{
			TestPtr testPtr(new TestObject);

			testPtr->setObjectName(name);

			AddTest(testPtr);
		}
	};

private:
	typedef istd::TSmartPtr<QObject> TestPtr;
	typedef QVector<TestPtr> TestInstances;

	static TestInstances& GetTests();
	static bool FindTest(const QString& name);
	static void AddTest(TestPtr test);
};


} // namespace itest

#define I_ADD_TEST(className) const itest::CStandardTestExecutor::TestRegistrator<className> className##_AddTest(#className);


