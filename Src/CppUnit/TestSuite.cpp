//
// File: TestSuite.cpp
//
// Date: 2015/04/25 10:21
//
// Library: BaseFrame
//
// Brief: Basic definitions for the OpenSoft Basic library.
// 
//
// Copyright (c) 2011-2015, Applied Informatics Software azraelly.
// and opensoft.
//
// Author: linyang
// Contact: 119745743@qq.com
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "BaseFrame/CppUnit/TestSuite.h"
#include "BaseFrame/CppUnit/TestResult.h"


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


// Deletes all tests in the suite.
void TestSuite::deleteContents()
{
	for (std::vector<Test*>::iterator it = _tests.begin(); it != _tests.end(); ++it)
		delete *it;
}


// Runs the tests and collects their result in a TestResult.
void TestSuite::run(TestResult *result)
{
	for (std::vector<Test*>::iterator it = _tests.begin(); it != _tests.end(); ++it) 
	{
		if (result->shouldStop ())
			break;

		Test *test = *it;
		test->run(result);
	}
}


// Counts the number of test cases that will be run by this test.
int TestSuite::countTestCases()
{
	int count = 0;

	for (std::vector<Test*>::iterator it = _tests.begin (); it != _tests.end (); ++it)
		count += (*it)->countTestCases();

	return count;
}

} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft
