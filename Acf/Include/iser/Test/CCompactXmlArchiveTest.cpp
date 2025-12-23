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


#include <iser/Test/CCompactXmlArchiveTest.h>


// ACF includes
#include <itest/CStandardTestExecutor.h>


void CCompactXmlArchiveTest::BasicCompactXmlSerializationTest()
{
	// Write data
	SimpleModel writeModel;
	writeModel.value = 99;

	iser::CCompactXmlMemWriteArchive writeArchive;
	QVERIFY(writeModel.Serialize(writeArchive));
	QByteArray xmlData = writeArchive.GetString();

	// Read data
	SimpleModel readModel;
	iser::CCompactXmlMemReadArchive readArchive(xmlData);
	QVERIFY(readModel.Serialize(readArchive));

	// Verify
	QCOMPARE(readModel.value, 99);
}


void CCompactXmlArchiveTest::CompactXmlComplexDataTest()
{
	// Write data
	ComplexModel writeModel;
	writeModel.intValue = 777;
	writeModel.doubleValue = 123.456;
	writeModel.stringValue = "Compact XML Test";

	iser::CCompactXmlMemWriteArchive writeArchive;
	QVERIFY(writeModel.Serialize(writeArchive));
	QByteArray xmlData = writeArchive.GetString();

	// Read data
	ComplexModel readModel;
	iser::CCompactXmlMemReadArchive readArchive(xmlData);
	QVERIFY(readModel.Serialize(readArchive));

	// Verify
	QVERIFY(readModel == writeModel);
	QCOMPARE(readModel.stringValue, QString("Compact XML Test"));
}


void CCompactXmlArchiveTest::CompactXmlArrayTest()
{
	// Write data
	ArrayModel writeModel;
	writeModel.numbers << 1.1 << 2.2 << 3.3 << 4.4;

	iser::CCompactXmlMemWriteArchive writeArchive;
	QVERIFY(writeModel.Serialize(writeArchive));
	QByteArray xmlData = writeArchive.GetString();

	// Read data
	ArrayModel readModel;
	iser::CCompactXmlMemReadArchive readArchive(xmlData);
	QVERIFY(readModel.Serialize(readArchive));

	// Verify
	QVERIFY(readModel == writeModel);
	QCOMPARE(readModel.numbers.size(), 4);
}


I_ADD_TEST(CCompactXmlArchiveTest);
