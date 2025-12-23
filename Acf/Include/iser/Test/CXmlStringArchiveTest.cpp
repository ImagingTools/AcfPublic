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


#include <iser/Test/CXmlStringArchiveTest.h>


// ACF includes
#include <itest/CStandardTestExecutor.h>


void CXmlStringArchiveTest::BasicXmlSerializationTest()
{
	// Write data
	SimpleModel writeModel;
	writeModel.value = 42;

	iser::CXmlStringWriteArchive writeArchive;
	QVERIFY(writeModel.Serialize(writeArchive));
	QByteArray xmlData = writeArchive.GetString();

	// Read data
	SimpleModel readModel;
	iser::CXmlStringReadArchive readArchive(xmlData);
	QVERIFY(readModel.Serialize(readArchive));

	// Verify
	QCOMPARE(readModel.value, 42);
}


void CXmlStringArchiveTest::XmlPrimitiveTypesTest()
{
	// Write data
	ComplexModel writeModel;
	writeModel.intValue = 123;
	writeModel.doubleValue = 456.789;
	writeModel.boolValue = true;

	iser::CXmlStringWriteArchive writeArchive;
	QVERIFY(writeModel.Serialize(writeArchive));
	QByteArray xmlData = writeArchive.GetString();

	// Read data
	ComplexModel readModel;
	iser::CXmlStringReadArchive readArchive(xmlData);
	QVERIFY(readModel.Serialize(readArchive));

	// Verify
	QVERIFY(readModel == writeModel);
	QCOMPARE(readModel.intValue, 123);
	QCOMPARE(readModel.boolValue, true);
}


void CXmlStringArchiveTest::XmlArraySerializationTest()
{
	// Write data
	ArrayModel writeModel;
	writeModel.items << 1 << 2 << 3 << 4 << 5;

	iser::CXmlStringWriteArchive writeArchive;
	QVERIFY(writeModel.Serialize(writeArchive));
	QByteArray xmlData = writeArchive.GetString();

	// Read data
	ArrayModel readModel;
	iser::CXmlStringReadArchive readArchive(xmlData);
	QVERIFY(readModel.Serialize(readArchive));

	// Verify
	QVERIFY(readModel == writeModel);
	QCOMPARE(readModel.items.size(), 5);
	QCOMPARE(readModel.items[0], 1);
	QCOMPARE(readModel.items[4], 5);
}


I_ADD_TEST(CXmlStringArchiveTest);
