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


#include "CBitManipTest.h"


// protected slots

void CBitManipTest::initTestCase()
{
}


void CBitManipTest::GetFirstBitIndexTest()
{
	const istd::CBitManip& bitManip = istd::CBitManip::instance;
	
	// Test bit 0 (first bit)
	quint32 value1 = 0x00000001;
	int index1 = bitManip.GetFirstBitIndex(value1);
	QVERIFY(index1 == 0);
	
	// Test bit 1
	quint32 value2 = 0x00000002;
	int index2 = bitManip.GetFirstBitIndex(value2);
	QVERIFY(index2 == 1);
	
	// Test bit 4
	quint32 value3 = 0x00000010;
	int index3 = bitManip.GetFirstBitIndex(value3);
	QVERIFY(index3 == 4);
	
	// Test bit 8
	quint32 value4 = 0x00000100;
	int index4 = bitManip.GetFirstBitIndex(value4);
	QVERIFY(index4 == 8);
	
	// Test bit 16
	quint32 value5 = 0x00010000;
	int index5 = bitManip.GetFirstBitIndex(value5);
	QVERIFY(index5 == 16);
	
	// Test multiple bits set (should return first bit)
	quint32 value6 = 0x00000003;  // bits 0 and 1 set
	int index6 = bitManip.GetFirstBitIndex(value6);
	QVERIFY(index6 == 0);
	
	quint32 value7 = 0x00000006;  // bits 1 and 2 set
	int index7 = bitManip.GetFirstBitIndex(value7);
	QVERIFY(index7 == 1);
}


void CBitManipTest::GetFirstBitIndexEdgeCasesTest()
{
	const istd::CBitManip& bitManip = istd::CBitManip::instance;
	
	// Test with no bits set (should return -1)
	quint32 value1 = 0x00000000;
	int index1 = bitManip.GetFirstBitIndex(value1);
	QVERIFY(index1 == -1);
	
	// Test with highest bit set
	quint32 value2 = 0x80000000;
	int index2 = bitManip.GetFirstBitIndex(value2);
	QVERIFY(index2 == 31);
	
	// Test with all bits set
	quint32 value3 = 0xFFFFFFFF;
	int index3 = bitManip.GetFirstBitIndex(value3);
	QVERIFY(index3 == 0);  // First bit is bit 0
}


void CBitManipTest::cleanupTestCase()
{
}


I_ADD_TEST(CBitManipTest);
