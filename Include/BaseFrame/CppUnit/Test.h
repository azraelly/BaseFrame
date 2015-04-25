//
// File: Test.h
//
// Date: 2015/04/25 10:16
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

#ifndef CppUnit_Test_INCLUDED
#define CppUnit_Test_INCLUDED


#include "CppUnit.h"
#include <string>


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


class TestResult;


/*
 * A Test can be run and collect its results.
 * See TestResult.
 *
 */
class BaseFrame_API Test
{
public:
	virtual ~Test() = 0;
	virtual void run(TestResult* result) = 0;
	virtual int countTestCases() = 0;
	virtual std::string toString() = 0;
};


inline Test::~Test()
{
}


// Runs a test and collects its result in a TestResult instance.
inline void Test::run(TestResult *result)
{
}


// Counts the number of test cases that will be run by this test.
inline int Test::countTestCases()
{
	return 0; 
}


// Returns the name of the test instance.
inline std::string Test::toString()
{
	return "";
}


} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft


#endif // CppUnit_Test_INCLUDED
