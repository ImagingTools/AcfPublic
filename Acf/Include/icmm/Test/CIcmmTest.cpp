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


#include <icmm/Test/CIcmmTest.h>


// ACF includes
#include <itest/CStandardTestExecutor.h>
#include <icmm/icmm.h>


void CIcmmTest::IsCmykTest()
{
	// Test CMYK colorants - should return true
	QVERIFY(icmm::IsCmyk(icmm::CU_CYAN));
	QVERIFY(icmm::IsCmyk(icmm::CU_DARK_CYAN));
	QVERIFY(icmm::IsCmyk(icmm::CU_LIGHT_CYAN));
	QVERIFY(icmm::IsCmyk(icmm::CU_MAGENTA));
	QVERIFY(icmm::IsCmyk(icmm::CU_DARK_MAGENTA));
	QVERIFY(icmm::IsCmyk(icmm::CU_LIGHT_MAGENTA));
	QVERIFY(icmm::IsCmyk(icmm::CU_YELLOW));
	QVERIFY(icmm::IsCmyk(icmm::CU_DARK_YELLOW));
	QVERIFY(icmm::IsCmyk(icmm::CU_LIGHT_YELLOW));
	QVERIFY(icmm::IsCmyk(icmm::CU_BLACK));
	QVERIFY(icmm::IsCmyk(icmm::CU_LIGHT_BLACK));
	QVERIFY(icmm::IsCmyk(icmm::CU_LIGHT_LIGHT_BLACK));

	// Test non-CMYK colorants - should return false
	QVERIFY(!icmm::IsCmyk(icmm::CU_NONE));
	QVERIFY(!icmm::IsCmyk(icmm::CU_ECG));
	QVERIFY(!icmm::IsCmyk(icmm::CU_SPOT));
}


I_ADD_TEST(CIcmmTest);


