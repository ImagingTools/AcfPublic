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


#include <iprm/Test/CSelectionParamTest.h>


// ACF includes
#include <istd/TDelPtr.h>
#include <iser/CMemoryReadArchive.h>
#include <iser/CMemoryWriteArchive.h>


void CSelectionParamTest::initTestCase()
{
}


void CSelectionParamTest::GetSetTest()
{
	QVERIFY(m_param.GetSelectedOptionIndex() == iprm::ISelectionParam::NO_SELECTION);

	int selectionIndex = 1;
	m_param.SetSelectedOptionIndex(selectionIndex);
	QVERIFY(m_param.GetSelectedOptionIndex() == selectionIndex);
}


void CSelectionParamTest::ResetTest()
{
	if (m_param.GetSupportedOperations() & istd::IChangeable::SO_RESET){
		int selectionIndex = 1;
		m_param.SetSelectedOptionIndex(selectionIndex);
		QVERIFY(m_param.GetSelectedOptionIndex() == selectionIndex);

		QVERIFY(m_param.ResetData());
		QVERIFY(m_param.GetSelectedOptionIndex() == iprm::ISelectionParam::NO_SELECTION);
	}
}


void CSelectionParamTest::SerializeTest()
{
	iser::CMemoryWriteArchive writeArchive(nullptr);

	int selectionIndex = 1;
	m_param.SetSelectedOptionIndex(selectionIndex);
	QVERIFY(m_param.GetSelectedOptionIndex() == selectionIndex);

	QVERIFY(m_param.Serialize(writeArchive));

	QVERIFY(m_param.SetSelectedOptionIndex(iprm::ISelectionParam::NO_SELECTION));
	QVERIFY(m_param.GetSelectedOptionIndex() == iprm::ISelectionParam::NO_SELECTION);

	iser::CMemoryReadArchive readArchive(writeArchive);
	QVERIFY(m_param.Serialize(readArchive));

	QVERIFY(m_param.GetSelectedOptionIndex() == selectionIndex);
}


void CSelectionParamTest::CopyFromTest()
{
	iprm::CSelectionParam param;

	int selectionIndex = 42;
	param.SetSelectedOptionIndex(selectionIndex);
	QVERIFY(param.GetSelectedOptionIndex() == selectionIndex);

	QVERIFY(m_param.CopyFrom(param));

	QVERIFY(m_param.GetSelectedOptionIndex() == selectionIndex);
}


void CSelectionParamTest::CloneTest()
{
	if (m_param.GetSupportedOperations() & istd::IChangeable::SO_CLONE){
		int selectionIndex = 42;
		m_param.SetSelectedOptionIndex(selectionIndex);
		QVERIFY(m_param.GetSelectedOptionIndex() == selectionIndex);

		istd::TDelPtr<iprm::CSelectionParam> clonePtr;
		QVERIFY(clonePtr.SetCastedOrRemove(m_param.CloneMe()));
		QVERIFY(clonePtr.IsValid());

		QVERIFY(clonePtr->GetSelectedOptionIndex() == selectionIndex);
	}
}


void CSelectionParamTest::IsEqualTest()
{
	if (m_param.GetSupportedOperations() & istd::IChangeable::SO_RESET){
		if (m_param.GetSupportedOperations() & istd::IChangeable::SO_COMPARE){
			int selectionIndex = 42;
			m_param.SetSelectedOptionIndex(selectionIndex);
			QVERIFY(m_param.GetSelectedOptionIndex() == selectionIndex);

			iprm::CSelectionParam param;
			param.SetSelectedOptionIndex(selectionIndex);
			QVERIFY(param.GetSelectedOptionIndex() == selectionIndex);

			QVERIFY(m_param.IsEqual(param));
		}
	}
}


void CSelectionParamTest::cleanupTestCase()
{
}


I_ADD_TEST(CSelectionParamTest);
