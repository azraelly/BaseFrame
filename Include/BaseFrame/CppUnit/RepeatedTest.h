//
// File: RepeatedTest.h
//
// Date: 2015/04/25 10:15
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

#ifndef CppUnit_RepeatedTest_INCLUDED
#define CppUnit_RepeatedTest_INCLUDED


#include "CppUnit.h"
#include "Guards.h"
#include "TestDecorator.h"


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


class Test;
class TestResult;


/*
 * A decorator that runs a test repeatedly.
 * Does not assume ownership of the test it decorates
 *
 */
class BaseFrame_API RepeatedTest: public TestDecorator
{
	REFERENCEOBJECT (RepeatedTest)

public:
	RepeatedTest(Test* test, int timesRepeat): TestDecorator (test), _timesRepeat (timesRepeat) 
	{
	}

	int countTestCases();
	std::string toString();
	void run(TestResult *result);

private:
	const int _timesRepeat;
};


// Counts the number of test cases that will be run by this test.
inline RepeatedTest::countTestCases ()
{
	return TestDecorator::countTestCases() * _timesRepeat;
}


// Returns the name of the test instance.
inline std::string RepeatedTest::toString()
{
	return TestDecorator::toString() + " (repeated)";
}


// Runs a repeated test
inline void RepeatedTest::run(TestResult *result)
{
	for (int n = 0; n < _timesRepeat; n++) 
	{
		if (result->shouldStop())
			break;

		TestDecorator::run(result);
	}
}

} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft

#endif // CppUnit_RepeatedTest_INCLUDED
