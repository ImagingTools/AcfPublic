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


#include <iser/Test/CJsonMemoryReadArchiveTest.h>


// ACF includes
#include <istd/TDelPtr.h>
#include <iser/CJsonMemReadArchive.h>
#include <iser/CJsonMemWriteArchive.h>
#include <itest/CStandardTestExecutor.h>


void CJsonMemoryReadArchiveTest::DoTest()
{
	Model model;
	model.value = 42;
	iser::CJsonMemWriteArchive writeArchive;
	QVERIFY(model.Serialize(writeArchive));
	QByteArray data = writeArchive.GetData();

	Model model2;
	model2.value = 0;

	iser::CJsonMemReadArchive readArchive(data);
	QVERIFY(model2.Serialize(readArchive));
	QVERIFY(model2.value == 42);
}


void CJsonMemoryReadArchiveTest::DoArrayTest()
{
	QList<double> data1;
	data1 << 1.0 << 1.1 << 1.2;
	QList<double> data2;
	data2 << 2.0 << 2.1 << 2.2;
	QList<QList<double>> modelData;
	modelData << data1 << data2;

	NestedArray model(modelData);
	iser::CJsonMemWriteArchive writeArchive;
	QVERIFY(model.Serialize(writeArchive));
	QByteArray data = writeArchive.GetData();

	NestedArray model2;

	iser::CJsonMemReadArchive readArchive(data);
	QVERIFY(model2.Serialize(readArchive));
	QVERIFY(model2 == model);
}

I_ADD_TEST(CJsonMemoryReadArchiveTest);
