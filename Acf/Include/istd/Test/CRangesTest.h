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
#include <QtTest/QtTest>

// ACF includes
#include <istd/TRanges.h>
#include <itest/CStandardTestExecutor.h>


class CRangesTest: public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();

	// Constructor tests
	void DefaultConstructorTest();
	void RangeConstructorTest();
	
	// Basic property tests
	void IsEmptyTest();
	void ResetTest();
	void GetSetBeginStateTest();
	
	// Switch point tests
	void InsertSwitchPointTest();
	void GetSwitchPointsTest();
	
	// Membership tests
	void IsInsidePointTest();
	void IsInsideRangeTest();
	void IsInsideRangesTest();
	
	// Inversion tests
	void GetInvertedTest();
	void InvertTest();
	
	// Union tests
	void GetUnionRangesTest();
	void UnionRangesTest();
	void UnionRangeTest();
	
	// Intersection tests
	void GetIntersectionRangesTest();
	void IntersectionRangesTest();
	void IntersectionRangeTest();
	
	// Morphological operations
	void ErodeTest();
	void DilateTest();
	void RemoveGapsTest();
	
	// Translation test
	void ShiftRangesTest();
	
	// Conversion tests
	void GetAsListTest();
	
	// Operator tests
	void EqualityOperatorTest();
	void HashTest();
	
	// CIntRanges specific tests
	void CIntRangesTest();

	void cleanupTestCase();
};
