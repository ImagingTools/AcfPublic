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
#include <istd/TRange.h>
#include <itest/CStandardTestExecutor.h>


class CRangeTest: public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();

	// Constructor tests
	void ConstructorTest();
	void CopyConstructorTest();
	
	// Basic property tests
	void IsValidTest();
	void IsEmptyTest();
	void IsValidNonEmptyTest();
	void GetSetMinMaxTest();
	void GetLengthTest();
	void GetAbsMinMaxValueTest();
	
	// Validation tests
	void GetValidatedTest();
	void ValidateTest();
	
	// Contains tests
	void ContainsValueTest();
	void ContainsRangeTest();
	
	// Intersection tests
	void IsIntersectedByTest();
	void IsOutsideOfTest();
	void GetIntersectionTest();
	void IntersectionTest();
	
	// Union tests
	void GetUnionTest();
	void UniteTest();
	
	// Translation tests
	void GetTranslatedTest();
	void TranslateTest();
	
	// Expansion tests
	void GetExpandedTest();
	void ExpandTest();
	
	// Distance and clipping tests
	void GetDistanceTest();
	void GetNearestInsideTest();
	void GetClippedValueTest();
	void GetClippedRangeTest();
	
	// Alpha/mapping tests
	void GetValueFromAlphaTest();
	void GetAlphaFromValueTest();
	void GetMappedToTest();
	
	// Apply tests
	void GetApplyTest();
	void GetInvertApplyTest();
	void GetInvertedTest();
	
	// Interpolation tests
	void SetInterpolatedTest();
	
	// Operator tests
	void EqualityOperatorTest();
	void AssignmentOperatorTest();
	void MultiplicationOperatorTest();
	void DivisionOperatorTest();
	
	// Static method tests
	void GetNullTest();
	void GetInvalidTest();
	void GetValidTest();
	
	// Reset test
	void ResetTest();
	
	// CIntRange specific tests
	void CIntRangeTest();

	void cleanupTestCase();
};
