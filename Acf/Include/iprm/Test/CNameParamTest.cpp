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


#include <iprm/Test/CNameParamTest.h>


// ACF includes
#include <istd/TDelPtr.h>
#include <iser/CMemoryReadArchive.h>
#include <iser/CMemoryWriteArchive.h>


void CNameParamTest::initTestCase()
{
}


void CNameParamTest::GetSetTest()
{
	QVERIFY(m_param.GetName().isEmpty());

	m_param.SetName(m_refValue);

	QVERIFY(m_param.GetName() == m_refValue);
}


void CNameParamTest::ResetTest()
{
	QVERIFY(m_param.GetName() == m_refValue);

	QVERIFY(m_param.ResetData());

	QVERIFY(m_param.GetName().isEmpty());
}


void CNameParamTest::SerializeTest()
{
	iser::CMemoryWriteArchive writeArchive(nullptr);

	m_param.SetName(m_refValue);

	QVERIFY(m_param.Serialize(writeArchive));

	QVERIFY(m_param.ResetData());
	QVERIFY(m_param.GetName().isEmpty());

	iser::CMemoryReadArchive readArchive(writeArchive);
	QVERIFY(m_param.Serialize(readArchive));

	QVERIFY(m_param.GetName() == m_refValue);
}


void CNameParamTest::CopyFromTest()
{
	iprm::CNameParam param;

	QVERIFY(m_param.GetName() == m_refValue);
	QVERIFY(param.GetName().isEmpty());

	QVERIFY(param.CopyFrom(m_param));

	QVERIFY(param.GetName() == m_refValue);
}


void CNameParamTest::CloneTest()
{
	QVERIFY(m_param.GetName() == m_refValue);

	istd::TUniqueInterfacePtr<iprm::CNameParam> clonePtr;
	QVERIFY(clonePtr.MoveCastedPtr(m_param.CloneMe()));
	QVERIFY(clonePtr.IsValid());

	QVERIFY(clonePtr->GetName() == m_refValue);
}


void CNameParamTest::IsEqualTest()
{
	iprm::CNameParam param;
	param.SetName(m_refValue);

	QVERIFY(m_param.IsEqual(param));
}


void CNameParamTest::cleanupTestCase()
{
}


I_ADD_TEST(CNameParamTest);
