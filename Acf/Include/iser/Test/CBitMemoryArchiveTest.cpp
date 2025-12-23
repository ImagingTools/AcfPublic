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


#include <iser/Test/CBitMemoryArchiveTest.h>


// ACF includes
#include <itest/CStandardTestExecutor.h>


void CBitMemoryArchiveTest::BasicBitSerializationTest()
{
	// Write data
	BoolModel writeModel;
	writeModel.value = true;

	iser::CBitMemoryWriteArchive writeArchive;
	QVERIFY(writeModel.Serialize(writeArchive));

	// Read data
	BoolModel readModel;
	iser::CBitMemoryReadArchive readArchive(writeArchive);
	QVERIFY(readModel.Serialize(readArchive));

	// Verify
	QCOMPARE(readModel.value, true);
}


void CBitMemoryArchiveTest::MultipleBoolsTest()
{
	// Write data
	MultiBoolModel writeModel;
	writeModel.value1 = true;
	writeModel.value2 = false;
	writeModel.value3 = true;

	iser::CBitMemoryWriteArchive writeArchive;
	QVERIFY(writeModel.Serialize(writeArchive));

	// Read data
	MultiBoolModel readModel;
	iser::CBitMemoryReadArchive readArchive(writeArchive);
	QVERIFY(readModel.Serialize(readArchive));

	// Verify
	QVERIFY(readModel == writeModel);
	QCOMPARE(readModel.value1, true);
	QCOMPARE(readModel.value2, false);
	QCOMPARE(readModel.value3, true);
}


void CBitMemoryArchiveTest::MixedDataTest()
{
	// Write data
	MixedModel writeModel;
	writeModel.boolValue = true;
	writeModel.intValue = 42;

	iser::CBitMemoryWriteArchive writeArchive;
	QVERIFY(writeModel.Serialize(writeArchive));

	// Read data
	MixedModel readModel;
	iser::CBitMemoryReadArchive readArchive(writeArchive);
	QVERIFY(readModel.Serialize(readArchive));

	// Verify
	QVERIFY(readModel == writeModel);
	QCOMPARE(readModel.boolValue, true);
	QCOMPARE(readModel.intValue, 42);
}


I_ADD_TEST(CBitMemoryArchiveTest);
