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


#include "CJsonMemoryWriteArchiveTest.h"


// ACF includes
#include <istd/TDelPtr.h>
#include <iser/CMemoryReadArchive.h>
#include <iser/CMemoryWriteArchive.h>


void CJsonMemoryWriteArchiveTest::initTestCase()
{
	m_metaInfo.SetMetaInfo(0, QByteArray("Test ByteArray"));
	m_metaInfo.SetMetaInfo(1, QString("Test String"));
	m_metaInfo.SetMetaInfo(2, int(10));
	m_metaInfo.SetMetaInfo(3, double(10.0));
}


void CJsonMemoryWriteArchiveTest::WriteTest()
{
	{
		iser::CJsonMemWriteArchive writeArchive(m_buffer);
		QVERIFY(m_metaInfo.Serialize(writeArchive));
	}
}

void CJsonMemoryWriteArchiveTest::ReadTest()
{
	idoc::CStandardDocumentMetaInfo metaInfo;
	iser::CJsonMemReadArchive readArchive(m_buffer);
	QVERIFY(metaInfo.Serialize(readArchive));
	QVERIFY(m_metaInfo.IsEqual(metaInfo));
}

void CJsonMemoryWriteArchiveTest::_Test()
{
	m_buffer.clear();

	Model model;

	model.value = 10;

	{
		iser::CJsonMemWriteArchive writeArchive(m_buffer);
		QVERIFY(model.Serialize(writeArchive));
	}

	model.value = 0;

	iser::CJsonMemReadArchive readArchive(m_buffer);
	QVERIFY(model.Serialize(readArchive));
}


void CJsonMemoryWriteArchiveTest::cleanupTestCase()
{
}


I_ADD_TEST(CJsonMemoryWriteArchiveTest);
